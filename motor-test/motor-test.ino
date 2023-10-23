#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_PWMServoDriver.h"

  Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
  Adafruit_StepperMotor *motor = AFMS.getStepper(200, 1);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");



  motor -> setSpeed(10);  // 10 rpm   

  delay(1000);
}

void loop() {
  motor -> step(100, FORWARD, SINGLE); 
    delay(1000);
  motor-> step(100, BACKWARD, SINGLE); 
    delay(1000);


}
