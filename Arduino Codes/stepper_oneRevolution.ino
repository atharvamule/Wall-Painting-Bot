
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 10, 11, 12, 7);

//int dir1 = 12;
//int dir2 = 11;
int pwm1 = A5;
int pwm2 = A7;

void setup() {

//pinMode(dir1,OUTPUT);
//pinMode(dir2,OUTPUT);
pinMode(pwm1,OUTPUT);
pinMode(pwm2,OUTPUT);
  
  // set the speed at 60 rpm:
  myStepper.setSpeed(1000);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(100);

  // step one revolution in the other direction:
  //Serial.println("counterclockwise");
  //myStepper.step(-stepsPerRevolution);
  //delay(500);
}
