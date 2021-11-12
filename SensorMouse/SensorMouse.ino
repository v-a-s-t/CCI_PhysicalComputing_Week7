/*
 * This sketch takes a sensor input and controls the 
 * x axis of your cursor.
 * NOTE: There is a safety switch programmed in. Please 
 * jump pin 12 to GND with a jumper cable to enable the 
 * mouse movement. 
 * 
 * Let the chaos begin.
 */
// Include mouse library
#include "Mouse.h"

// Define pins and constants
#define SAFETYSWITCH_PIN 12
#define SENSOR 0
// Change this to your sensor's "resting" value
#define SENSOR_RESTING 512

void setup() {
  // Define safety switch pin. Disables mouse if off
  pinMode(SAFETYSWITCH_PIN, INPUT_PULLUP);
  // Begin mouse madness
  Mouse.begin();
}

void loop() {
  // Read safety switch
  int safetySwitchVal = digitalRead(SAFETYSWITCH_PIN);
  if (safetySwitchVal == LOW) {
    // If switch is pressed, read sensor and write to 
    // mouse x
    int sensorValue = analogRead(SENSOR);
    int changeX = sensorValue - SENSOR_RESTING;
    Mouse.move(changeX, 0);
    delay(50);
  }
}
