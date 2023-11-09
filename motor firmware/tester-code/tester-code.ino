#include <Wire.h>
#include <Adafruit_MotorShield.h>

/*
Tester Code that has been verified to work on known good hardware (DC motor, Stepper motor, and Adafruit motorshield). Use this code to test all hardware is working. Only modifications needed is to switch
ports that the motors are connected to. Tester code will run stepper & dc motor at the same time. Note that stepper motors can get really hot really quickly. 
*/

//Initializing all our objects
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); //Our motor shield
Adafruit_DCMotor *dcmotor = AFMS.getMotor(1); //our DC motor on M#
Adafruit_StepperMotor *stepmotor = AFMS.getStepper(200, 2); //Nema 17 datasheet says they have 200 steps/revolution. Next parameter is port #. m1 & m2 is port 1, m3 & m4 is port 2

void setup() {

  //Setting up Serial & Checking Motor Shield Connection
  Serial.begin(9600);           // set up Serial library at 9600 bps
   if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");  


  //Set speed for motors
  stepmotor -> setSpeed(10);  // 10 rpm   
  dcmotor->setSpeed(30);
}

//Superloop
void loop() {
  stepmotor -> step(100, FORWARD, SINGLE); 
  dcmotor-> run(FORWARD);
  delay(1000);



}
