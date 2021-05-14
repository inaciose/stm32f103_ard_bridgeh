
#ifndef BRIDGEH_MOTOR_H
#define BRIDGEH_MOTOR_H

// front motors pins
#define AIN1 PC14
#define AIN2 PC15
#define AIN3 PA0
#define AIN4 PA1
#define AENA PB0
#define AENB PB1

// Front LeftMotor
#define frontLeftMotorEn AENA
#define frontLeftMotorForward AIN1
#define frontLeftMotorBackward AIN2

// Front RightMotor
#define frontRightMotorEn AENB
#define frontRightMotorForward AIN4
#define frontRightMotorBackward AIN3


void bodyMotorsControl( int frontLeftMotorPwmOut, int frontRightMotorPwmOut);

void setBodyMotorFrontLeftForward(void);

void setBodyMotorFrontLeftBackward(void);

void setBodyMotorFrontRightForward(void);

void setBodyMotorFrontRightBackward(void);

void setBodyMotorFrontLeftStop(void);

void setBodyMotorFrontRightStop(void);

void setBodyMotorFrontLeftBrake(void);

void setBodyMotorFrontRightBrake(void);


#endif