#include <Wire.h>
#include <Adafruit_MotorShield.h>

const byte interruptPin = 2;
volatile byte state = LOW;
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); //Our motor shield

uint8_t player;
uint8_t ByteReceived;
void setup() {

   pinMode (interruptPin, INPUT_PULLUP) ;

   attachInterrupt ( digitalPinToInterrupt ( interruptPin ), add, CHANGE ) ;

   Serial.begin(9600);           // set up Serial library at 9600 bps
   if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found."); 

} 

void loop() {
  Serial.println(player);

}

void add() 

{

   player+=1;

}
