#include "UltrasonicSensor.hpp"
#include <Arduino.h>

UltrasonicSensor::UltrasonicSensor(uint8_t trigPin, uint8_t echoPin) 
    : trigPin(trigPin), echoPin(echoPin) {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW);
}

float UltrasonicSensor::measureDistance() { // Measure distance using the ultrasonic sensor
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); // Ensure the trigger pin is low for at least 2 microseconds
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Send a 10 microsecond pulse to trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW); 
    
    unsigned long duration = pulseIn(echoPin, HIGH, 30000);
    float distance = duration * 0.0343 / 2; // Convert to cm (speed of sound is 343 m/s, divided by 2 for round trip)
    
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    return distance;
}

bool UltrasonicSensor::isDistanceValid(float distance) {
    return distance >= minDistance && distance <= maxDistance;
}   