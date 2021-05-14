#include <Arduino.h>

#define SERIAL_BAUDS 115200

#include "motor.h"

#ifndef LED_BUILTIN
  #define LED_BUILTIN PC13
#endif

#define LED_PIN LED_BUILTIN
#define LED_TIME 1000
unsigned long ledTimer = 0;
bool blinkState = false;

//
// setup function
// 

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(SERIAL_BAUDS);

  // front left & right
  // set direction pins mode as output
  pinMode(frontLeftMotorForward, OUTPUT);
  pinMode(frontLeftMotorBackward, OUTPUT);
  pinMode(frontRightMotorForward, OUTPUT);
  pinMode(frontRightMotorBackward, OUTPUT);

  // set velocity pins mode as output
  //pinMode(frontLeftMotorEn, PWM);
  //pinMode(frontRightMotorEn, PWM);
  pinMode(frontLeftMotorEn, OUTPUT);
  pinMode(frontRightMotorEn, OUTPUT);

  // assure that motors are stoped
  bodyMotorsControl(0, 0);
  delay(3000);

}


//
// loop function
// 

void loop()
{

  bodyMotorsControl(4096, 4096);

  // activity led
  if(millis() > ledTimer) {
    ledTimer = millis() + LED_TIME;
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
  }

}