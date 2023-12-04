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
#define GEARING     1.75  // 4.1 for speed 50, 1.45 for speed 100; 1.75
#define ENCODERMULT 48


//Everything for Adding Player Count
const int SW1 = 4; // Replace with the actual pin number for your button 
const unsigned long DEBOUNCE_INTERVAL = 50; // Adjust debounce interval as needed 
uint32_t debounce_time = 0; 
bool SW1_went_back_low = false; 
int currentMode = 0; // current mode (initialize as 0) 
bool isSweepComplete = true; 
int isUp = 1; 
int player = 0;

//Encoder Data for card shooter
float wheel_diam = 2.5;   //inches
float card_length = 3.5;  //inches
float revs = card_length/wheel_diam;
volatile unsigned long count = 0;


//Button to deal
const int SW2 = 3; // Replace with the actual pin number for your button 
uint32_t debounce_time2 = 0; 
bool SW2_went_back_low = false; 
int currentMode2 = 0; // current mode (initialize as 0) 
bool isSweepComplete2 = true; 
int isUp2 = 1; 




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
  stepmotor -> setSpeed(100);  // 10 rpm   
  dcmotor->setSpeed(100);

  //Encoder Setup
  pinMode(ENCODER_B, INPUT_PULLUP);
  pinMode(ENCODER_A, INPUT_PULLUP);
  // initialize hardware interrupts
  attachInterrupt(0, encoderEvent, CHANGE);
  delay(100);
}

//Superloop
void loop() {




//Rn too lazy to stick a button on a breadboard so using serial monitor as a button. Press enter to trigger a card getting dealt
   if (Serial.available() > 0)
 {
   ByteReceived = Serial.read();
   
   }
   //To deal Cards
   if (ByteReceived == 10 || debounceButtonPress1(SW1)) { 
    Serial.println("Button pressed."); 
    //add();
    //stepmotor -> step(180, FORWARD, SINGLE);
    deal(dcmotor);

      //deal twice
    
        turn(stepmotor, 100);
        delay(400);
        deal(dcmotor);
        delay(1000);
      
      //skip the burn pile
      //turn(STEPmotor, 100);
      delay(400);
  




    //LCD Display
    lcd.setCursor(0, 0);         
    lcd.print("Button Pressed: Dealing");
    lcd.setCursor(0, 1);         
    lcd.print("Dealing");
    delay(2000);
    lcd.clear();                 // clear display

  } 

}


//Functions
void deal(Adafruit_DCMotor *motor){
  count = 0;
  while (count < revs * GEARING * ENCODERMULT) {
    motor-> run(BACKWARD);
    Serial.println(count);
    delay(5);
  }
  motor-> run(RELEASE);
  delay(1000);
  motor-> run(FORWARD);
  delay(1000);
  motor-> run(RELEASE);
}




void turn (Adafruit_StepperMotor *motor, int degree){

    /* Turns dealer once*/
  motor -> step(degree, FORWARD, SINGLE);
}




void add(){
    /*Increases player count. If Current ceiling for players is 8 */
  if (player == 8){
    player = 4;
  }
  else {
    player+=1;
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
  uint32_t t = millis(); 
  bool SW2_high; 
  // Debounce solution - prevents microsecond double tapping 
  if (t >= debounce_time2 + DEBOUNCE_INTERVAL) { 
    SW2_high = digitalRead(buttonPin) == LOW; 
    if (SW2_went_back_low && SW2_high) {  
      debounce_time2 = t; 
      SW2_went_back_low = false; 
      return true; // Button press detected  
    } else if (!SW2_went_back_low && !SW2_high) { 
      SW2_went_back_low = true; 
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
