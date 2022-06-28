#ifndef
#define ULTRASONIC.H

// Ultrasonic Sensor
#define trigger_pin 4
#define echo_pin 5

// Function Prototypes =====================================================

void ultrasonic_setup(); //runs setup for sensor

long ultrasonic_read(); //reads distance
