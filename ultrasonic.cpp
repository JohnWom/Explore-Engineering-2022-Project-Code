#include "ultrasonic.h"



void ultrasonic_setup() {
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

long ultrasonic_read() {
  long duration, cm, in;
  
  //Sends out echo
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  
  pinMode(echo_pin, INPUT);
  duration = pulseIn(echo_pin, HIGH);  //pulseIn records time signal is HIGH state for in microseconds

  cm = (duration/2) / 29.1;  // over 2 because it hits the object and comes back
  in = (duration/2) / 74;    // over conversion factor of speed of sound in unit/second
  return in //only output either cm or in
}
