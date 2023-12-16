#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_SSD1306.h>

// Connect to the two encoder outputs!
#define ENCODER_A   2
#define ENCODER_B   3

// These let us convert ticks-to-RPM
#define GEARING    0.8 // 4.1 for speed 50, 1.45 for speed 100; 1.75
#define ENCODERMULT 48

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// And connect a DC motor to port M1
Adafruit_DCMotor *dcmotor = AFMS.getMotor(1); //our DC motor on M#
int ByteReceived;
float wheel_diam = 2.5;   //inches
float card_length = 3.5;  //inches
float revs = card_length/wheel_diam;
volatile unsigned long count = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  pinMode(ENCODER_B, INPUT_PULLUP);
  pinMode(ENCODER_A, INPUT_PULLUP);
  // initialize hardware interrupts
  attachInterrupt(0, encoderEvent, CHANGE);
  delay(100);

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");  Serial.println("Begun");
  // turn on motor M1
  dcmotor->setSpeed(180);
  delay(50);
}


void loop() {
  delay(50);
  if (Serial.available() > 0) {
    ByteReceived = Serial.read();

    //If ENTER was pressed on the serial command line
    if (ByteReceived == 10){    
      delay(100);
      deal(dcmotor);
    }
  }

}
// encoder event for the interrupt call
void encoderEvent() {
  if (digitalRead(ENCODER_A) == HIGH) {
    if (digitalRead(ENCODER_B) == LOW) {
      count--;
    } else {
      count++;
    }
  } else {
    if (digitalRead(ENCODER_B) == LOW) {
      count++;
    } else {
      count--;
    }
  }
}
 
void deal(Adafruit_DCMotor *motor){
  count = 0;
  while (count < revs * GEARING * ENCODERMULT) {
    motor-> run(FORWARD);
    Serial.println(count);
    delay(30);
  }
  motor-> run(RELEASE);
  delay(700);
  motor-> run(BACKWARD);
  delay(700);
  motor-> run(RELEASE);
  count = 0;
}
