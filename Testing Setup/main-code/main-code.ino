#include <Wire.h>
#include <Arduino.h> 

#include <Adafruit_MotorShield.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_SSD1306.h>


int ByteReceived;

// Connect to the two encoder outputs!
#define ENCODER_A   2
#define ENCODER_B   3

// These let us convert ticks-to-RPM
#define GEARING    0.8 // 4.1 for speed 50, 1.45 for speed 100; 1.75
#define ENCODERMULT 48


//Encoder Data for card shooter
float wheel_diam = 2.5;   //inches
float card_length = 3.5;  //inches
float revs = card_length/wheel_diam;
volatile unsigned long count = 0;


int player = 4;

//Everything for Dealing
const int SW1 = 4; //Pin Number for Dealing button
const unsigned long DEBOUNCE_INTERVAL = 100; // Adjust debounce interval as needed 
uint32_t debounce_time = 0; 
bool SW1_went_back_low = false; 
int currentMode = 0; // current mode (initialize as 0) 
bool isSweepComplete = true; 
int isUp = 1; 


//Adding Player Count
const int SW2 = 5; // Replace with the actual pin number for your button 
uint32_t debounce_time2 = 0; 
bool SW2_went_back_low = false; 
int currentMode2 = 0; // current mode (initialize as 0) 
bool isSweepComplete2 = true; 
int isUp2 = 1; 

//Decreasing Player Count
const int SW3 = 6; // Replace with the actual pin number for your button 
uint32_t debounce_time3 = 0; 
bool SW3_went_back_low = false; 
int currentMode3 = 0; // current mode (initialize as 0) 
bool isSweepComplete3 = true; 
int isUp3 = 1; 




/*
 * main code lives here. MVP currently, deals to 4 people hardcoded. 
*/

//Initializing all our objects
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); //Our motor shield
Adafruit_DCMotor *dcmotor = AFMS.getMotor(1); //our DC motor on M#
Adafruit_StepperMotor *stepmotor = AFMS.getStepper(200, 2); //Nema 17 datasheet says they have 200 steps/revolution. Next parameter is port #. m1 & m2 is port 1, m3 & m4 is port 2
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD Screen woith I2C address 0x27, 16 column and 2 rows

void setup() {

  //Setting up Serial & Checking Motor Shield Connection
  Serial.begin(9600);           // set up Serial library at 9600 bps
   if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found."); 


  //buttons
  pinMode(SW1, INPUT_PULLUP); // Configure the button pin as input with pull-up resistor. Button to add change player count
  pinMode(SW2, INPUT_PULLUP); // Configure the button pin as input with pull-up resistor Button to deal card. 

  //LCD
  lcd.init(); // initialize the lcd
  lcd.backlight();


  //Set speed for motors
  stepmotor -> setSpeed(120);  // 10 rpm   
  dcmotor->setSpeed(185);

  //Encoder Setup
  pinMode(ENCODER_B, INPUT_PULLUP);
  pinMode(ENCODER_A, INPUT_PULLUP);
  // initialize hardware interrupts
  attachInterrupt(0, encoderEvent, CHANGE);
  delay(100);
}

//Superloop
void loop() {

  //Calculate total number of players
  

  lcd.setCursor(0, 0);         
  lcd.print("Auto Dealer");
  lcd.setCursor(0, 1);
  String playerText = "Player Count: ";
  lcd.print(playerText += player);




//Rn too lazy to stick a button on a breadboard so using serial monitor as a button. Press enter to trigger a card getting dealt
   if (Serial.available() > 0)
 {
   ByteReceived = Serial.read();
   }



   
   //To deal Cards
   if (ByteReceived == 10 || debounceButtonPress1(SW1)) { 

    //LCD Display
    lcd.clear();                 // clear display
    lcd.setCursor(0, 0);         
    lcd.print("Button Pressed:");
    lcd.setCursor(0, 1);         
    lcd.print("Dealing Hands");
    
    Serial.println("Button pressed."); 
    int degree = 360/(player);



    //deal everyone 2 cards

    //Deal one card to each player

    //Nested for loops break this for some bizarre reason......

  int totalTurns = player;
     for (int i = 1; i < totalTurns; ++i){
      turn(stepmotor, degree);
      delay(400);
      deal(dcmotor);
      delay(400);
     }
    turn(stepmotor, degree);

    for (int i = 1; i < totalTurns; ++i){
      turn(stepmotor, degree);
      delay(400);
      deal(dcmotor);
      delay(400);
     }

 
    lcd.clear();                 // clear display
    lcd.setCursor(0, 0);         
    lcd.print("Finished Dealing:");
    lcd.setCursor(0, 1);         
    lcd.print("Take Your Hands");
    delay(2000);
    lcd.clear();                 // clear display

    

  }


  //Adding Players
  if (debounceButtonPress2(SW2)) { 
    add();
    
      
    }


  if (debounceButtonPress3(SW3)) { 
    minus();
    
      
    }

}


//Functions
void deal(Adafruit_DCMotor *motor){
  count = 0;
  while (count < revs * GEARING * ENCODERMULT) {
    motor-> run(BACKWARD);
    Serial.println(count);
    delay(25);
  }
  motor-> run(RELEASE);
  delay(700);
  motor-> run(FORWARD);
  delay(700);
  motor-> run(RELEASE);
  count = 0;
}




void turn (Adafruit_StepperMotor *motor, int degree){

    /* Turns dealer once*/
  motor -> step(degree * 4, BACKWARD, SINGLE);
}




void add(){
    /*Increases player count. If Current ceiling for players is 8 */
  if (player == 8){
    player = 8;
  }
  else {
    player+=1;
  }
}



void minus(){
    /*decreases player count.  Current floor for players is 4 */
  if (player == 4){
    player = 4;
  }
  else {
    player-=1;
  }
}


bool debounceButtonPress1(int buttonPin) { 
    /*Function to debounce pins */
  uint32_t t = millis(); 
  bool SW1_high; 
  // Debounce solution - prevents microsecond double tapping 
  if (t >= debounce_time + DEBOUNCE_INTERVAL) { 
    SW1_high = digitalRead(buttonPin) == LOW; 
    if (SW1_went_back_low && SW1_high) {  
      debounce_time = t; 
      SW1_went_back_low = false; 
      return true; // Button press detected  
    } else if (!SW1_went_back_low && !SW1_high) { 
      SW1_went_back_low = true; 
    }
  } 
  return false; // Button press not detected 
} 


bool debounceButtonPress2(int buttonPin) { 
    /*Function to debounce pins */
  uint32_t t2 = millis(); 
  bool SW2_high; 
  // Debounce solution - prevents microsecond double tapping 
  if (t2 >= debounce_time2 + DEBOUNCE_INTERVAL) { 
    SW2_high = digitalRead(buttonPin) == LOW; 
    if (SW2_went_back_low && SW2_high) {  
      debounce_time2 = t2; 
      SW2_went_back_low = false; 
      return true; // Button press detected  
    } else if (!SW2_went_back_low && !SW2_high) { 
      SW2_went_back_low = true; 
    }
  } 
  return false; // Button press not detected 
}


bool debounceButtonPress3(int buttonPin) { 
    /*Function to debounce pins */
  uint32_t t3 = millis(); 
  bool SW3_high; 
  // Debounce solution - prevents microsecond double tapping 
  if (t3 >= debounce_time3 + DEBOUNCE_INTERVAL) { 
    SW3_high = digitalRead(buttonPin) == LOW; 
    if (SW3_went_back_low && SW3_high) {  
      debounce_time3 = t3; 
      SW3_went_back_low = false; 
      return true; // Button press detected  
    } else if (!SW3_went_back_low && !SW3_high) { 
      SW3_went_back_low = true; 
    }
  } 
  return false; // Button press not detected 
}


// encoder event for the interrupt call
void encoderEvent() {
  if (digitalRead(ENCODER_A) == HIGH) {
    if (digitalRead(ENCODER_B) == LOW) {
      count++;
    } else {
      count--;
    }
  } else {
    if (digitalRead(ENCODER_B) == LOW) {
      count--;
    } else {
      count++;
    }
  }
}
