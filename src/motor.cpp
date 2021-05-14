#include <Arduino.h>

#include "motor.h"

void bodyMotorsControl( int frontLeftMotorPwmOut, int frontRightMotorPwmOut) {

  // brake control vars
  static bool leftBrake = false;
  static bool rightBrake = false;

  // set motor front left direction & speed
  if(frontLeftMotorPwmOut == 0) {

    if(leftBrake) {
      setBodyMotorFrontLeftBrake();
      //setBodyMotorLeftStop();
      //#pwmWrite(frontLeftMotorEn,64000);
      analogWrite(frontLeftMotorEn, 4095);            
    } else {
      //setBodyMotorLeftBrake();
      setBodyMotorFrontLeftStop();
      //pwmWrite(frontLeftMotorEn, 0);
      analogWrite(frontLeftMotorEn, 0); 
    }
    
  } else if(frontLeftMotorPwmOut > 0) {
    setBodyMotorFrontLeftForward();
    //wmWrite(frontLeftMotorEn, frontLeftMotorPwmOut);
    analogWrite(frontLeftMotorEn, frontLeftMotorPwmOut);            
  } else {
    setBodyMotorFrontLeftBackward();
    //pwmWrite(frontLeftMotorEn, abs(frontLeftMotorPwmOut));    
    analogWrite(frontLeftMotorEn, abs(frontLeftMotorPwmOut));            
  }
  
  // set motor right direction & speed
  if(frontRightMotorPwmOut == 0) {

    if(rightBrake) {
      setBodyMotorFrontRightStop();
      //setBodyMotorRightBrake();
      //pwmWrite(frontRightMotorEn, 64000);
      analogWrite(frontRightMotorEn, 4095);            
    } else {
      setBodyMotorFrontRightStop();
      //setBodyMotorRightBrake();
      //pwmWrite(frontRightMotorEn, 0);
      analogWrite(frontRightMotorEn, 0);            
    }

  } else if(frontRightMotorPwmOut > 0) {
    setBodyMotorFrontRightForward();
    //pwmWrite(frontRightMotorEn, frontRightMotorPwmOut);
    analogWrite(frontRightMotorEn, frontRightMotorPwmOut);            
  } else {
    setBodyMotorFrontRightBackward();    
    //pwmWrite(frontRightMotorEn, abs(frontRightMotorPwmOut));
    analogWrite(frontRightMotorEn, abs(frontRightMotorPwmOut));            
  }
  
}



//
// Front left & right
//

void setBodyMotorFrontLeftForward() {
  digitalWrite(frontLeftMotorForward, HIGH);
  digitalWrite(frontLeftMotorBackward, LOW);
}

void setBodyMotorFrontLeftBackward() {
  digitalWrite(frontLeftMotorForward, LOW);
  digitalWrite(frontLeftMotorBackward, HIGH);
}

void setBodyMotorFrontRightForward() {
  digitalWrite(frontRightMotorForward, HIGH);
  digitalWrite(frontRightMotorBackward, LOW);
}

void setBodyMotorFrontRightBackward() {
  digitalWrite(frontRightMotorForward, LOW);
  digitalWrite(frontRightMotorBackward, HIGH);
}

void setBodyMotorFrontLeftStop() {
  digitalWrite(frontLeftMotorForward, LOW);
  digitalWrite(frontLeftMotorBackward, LOW);
}

void setBodyMotorFrontRightStop() {
  digitalWrite(frontRightMotorForward, LOW);
  digitalWrite(frontRightMotorBackward, LOW);
}

void setBodyMotorFrontLeftBrake() {
  digitalWrite(frontLeftMotorForward, HIGH);
  digitalWrite(frontLeftMotorBackward, HIGH);
}

void setBodyMotorFrontRightBrake() {
  digitalWrite(frontRightMotorForward, HIGH);
  digitalWrite(frontRightMotorBackward, HIGH);
}
