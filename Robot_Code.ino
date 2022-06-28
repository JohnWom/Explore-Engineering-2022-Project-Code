// Robot Description
//      ||
//   O-/  \-O 
//    |    |
//    \    /
// 0-M1   M2-O  

// good additions:
// forward/reverse for time


// includes & defines =============================================================================
#include "ultrasonic.h"

#define Motor_1_FWD 4  //Pin for motor 1 forward
#define Motor_1_REV 5  //Pin for motor 1 reverse
#define Motor_2_FRW 6  //Pin for motor 2 forward 
#define Motor_3_REV 7  //Pin for motor 2 reverse


// Function Prototypes ==================================================================

void forward(); //Moves the car forward

void reverse(); //Moves the car in reverse

void right();   //Turns the car right

void left()l    //Turns the car left

void stop_for_time(int); //Stops for given time

void finished(); //Stops forever

void foward_until_distance(int); // moves forward until ultrasonic measures distance

// Global Variables =====================================================================



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(Motor_1_FWD, OUTPUT);
  pinMode(Motor_1_REV, OUTPUT);
  pinMode(Motor_2_FWD, OUTPUT);
  pinMode(Motor_2_REV, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //example code to go forward turn right, move, then turn left

  forward();
  forward();
  forward();
  right();
  forward();
  left();
  forward();

  finished();

}


// Function Definitions =================================================================

void forward() {
  digital.write(Motor_1_FWD, HIGH);
  digital.write(Motor_2_FWD, HIGH);
  delay(500); //delay is in milliseconds
  digital.write(Motor_1_FWD, LOW);
  digital.write(Motor_2_FWD, LOW);
}


void reverse() {
  digital.write(Motor_1_REV, HIGH);
  digital.write(Motor_2_REV, HIGH);
  delay(500); //delay is in milliseconds
  digital.write(Motor_1_REV, LOW);
  digital.write(Motor_2_REV, LOW);
}

void right() {
  digital.write(Motor_1_FWD, HIGH);
  digital.write(Motor_2_REV, HIGH);
  delay(500); //delay is in milliseconds
  digital.write(Motor_1_FWD, LOW);
  digital.write(Motor_2_FWD, LOW);
}

void left() {
  digital.write(Motor_1_REV, HIGH);
  digital.write(Motor_2_FWD, HIGH);
  delay(500); //delay is in milliseconds
  digital.write(Motor_1_REV, LOW);
  digital.write(Motor_2_FWD, LOW);
}
//all those could be factored

void stop_for_time(int t) {
  delay(t);
}

void finished() {
  while(true);
}
 
void foward_until_finished(int d) {  // d is min distance
  long m = ultrasonic_read(); //real-time measured distance
  while (m > d) {
    forward();
    m = ultrasonic_read();
  }
}
