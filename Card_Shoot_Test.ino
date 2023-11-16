#include <Wire.h>
#include <Adafruit_MotorShield.h>
int ByteReceived;
float wheel_diam = 2.5;   //inches
float card_length = 3.5;  //inches

// struct gameParameters {
//     uint8_t playerCount;
//     uint8_t angle;
//   };
/*
 * main code lives here. MVP currently, deals to 4 people hardcoded. 
*/

//Initializing all our objects
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); //Our motor shield
Adafruit_DCMotor *dcmotor = AFMS.getMotor(4); //our DC motor on M#
Adafruit_DCMotor *spinMotor = AFMS.getMotor(3);
// Adafruit_StepperMotor *stepmotor = AFMS.getStepper(200, 1); //Nema 17 datasheet says they have 200 steps/revolution. Next parameter is port #. m1 & m2 is port 1, m3 & m4 is port 2

void setup() {

  //Setting up Serial & Checking Motor Shield Connection
  Serial.begin(9600);           // set up Serial library at 9600 bps
   if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found."); 
  // gameParameters state = {4, 200/4};  

    



  //Set speed for motors
  // stepmotor -> setSpeed(20);  // 10 rpm   
  dcmotor->setSpeed(250);
}

//Superloop
void loop() {


//Rn too lazy to stick a button on a breadboard so using serial monitor as a button. Press enter to trigger a card getting dealt
   if (Serial.available() > 0)
 {
   ByteReceived = Serial.read();

  //If ENTER was pressed on the serial command line
   if (ByteReceived == 10){
    //Stepping & shooting out card
    
    // turn(stepmotor, 25); // currently split rotation into 8 stops
    delay(100);
    deal(dcmotor);
    // spin(spinMotor);
    // deal(dcmotor);
   }
    
  }

}


//Functions

void deal(Adafruit_DCMotor *motor){
    // float rps = 10/4.3;
    // int time = ((card_length/wheel_diam) / rps) * 1000;
    // time = time * 0.75;
    motor-> run(BACKWARD);
    delay(200); //time
    motor-> run(RELEASE);
    delay(100);
    motor-> run(FORWARD);
    delay(700);
    motor-> run(RELEASE);
    delay(100);
}

void spin(Adafruit_DCMotor *motor){
    motor->setSpeed(40);
    motor->run(FORWARD);
    delay(2000);
    motor->run(RELEASE);
}


// void turn (Adafruit_StepperMotor *motor, int degree){
//   motor -> step(degree, FORWARD, SINGLE);
// }