#include <Arduino.h> 
#include <Wire.h>
#include <Adafruit_MotorShield.h>

const int SW1 =5; // Replace with the actual pin number for your button 
const unsigned long DEBOUNCE_INTERVAL = 50; // Adjust debounce interval as needed 
uint32_t debounce_time = 0; 
bool SW1_went_back_low = false; 
int currentMode = 0; // current mode (initialize as 0) 
bool isSweepComplete = true; 
int isUp = 1; 

int player = 0;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); //Our motor shield



void setup() { 


  pinMode(SW1, INPUT_PULLUP); // Configure the button pin as input with pull-up resistor 


  
  Serial.begin(9600); // Initialize serial communication 
  while (!Serial); // Wait for Serial Monitor to open 
  Serial.println("Arduino is ready."); 


} 



void loop() { 

  // Check for button press 

  if (debounceButtonPress(SW1)) { 

    Serial.println("Button pressed."); 
    player+=1;
    

  } 

}  


bool debounceButtonPress(int buttonPin) { 
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
