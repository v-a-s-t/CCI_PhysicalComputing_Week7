/*
 * This sketch takes in an angle from serial and writes it
 * to a servo motor. 
 * 
 * p5 sketch: https://editor.p5js.org/mikevanis/sketches/H0j5ydZel
 * 
 */

// Include servo library
#include <Servo.h>

// Define servo pin
#define SERVO_PIN 9

// Define servo library instance
Servo myServo;

void setup() {
  // Open serial port
  Serial.begin(115200);

  // Initialise pins
  pinMode(13, OUTPUT);
  myServo.attach(SERVO_PIN);
}

void loop() {
  // If data has come through the serial
  if (Serial.available() > 0) {
    // Read serial byte
    byte inByte = Serial.read();
    // Constrain byte for servo
    inByte = constrain(inByte, 0, 180);
    // Write to servo!
    myServo.write(inByte);
    // Bonus - dim the onboard LED
    analogWrite(13, map(inByte, 0, 180, 0, 255));
  }
}
