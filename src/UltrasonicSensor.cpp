#include "UltrasonicSensor.hpp"
#include <Arduino.h>

UltrasonicSensor::UltrasonicSensor(uint8_t trigPin, uint8_t echoPin) 
    : trigPin(trigPin), echoPin(echoPin) {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW);
}

float UltrasonicSensor::measureDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    unsigned long duration = pulseIn(echoPin, HIGH, 30000);
    float distance = duration * 0.0343 / 2;
    
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    return distance;
}

bool UltrasonicSensor::isDistanceValid(float distance) {
    return distance >= minDistance && distance <= maxDistance;
}