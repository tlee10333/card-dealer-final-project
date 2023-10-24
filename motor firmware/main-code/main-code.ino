#include <Wire.h>
#include <Adafruit_MotorShield.h>
int ByteReceived;
/*
 * main code lives here. MVP currently, deals to 4 people hardcoded. 
*/

//Initializing all our objects
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); //Our motor shield
Adafruit_DCMotor *dcmotor = AFMS.getMotor(2); //our DC motor on M#
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
  stepmotor -> setSpeed(20);  // 10 rpm   
  dcmotor->setSpeed(30);
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
  stepmotor -> step(25, FORWARD, SINGLE); // currently split rotation into 8 stops
  delay(100);
  dcmotor-> run(FORWARD);
  delay(1000);
  dcmotor-> run(RELEASE);
  delay(1000);


   }
    
   }




}
