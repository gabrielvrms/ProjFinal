#include "DistanceAlertSystem.hpp"
#include <Arduino.h>

DistanceAlertSystem::DistanceAlertSystem()
    : sensor(13, 12),  // TRIG_PIN, ECHO_PIN
      buzzer(8),       // BUZZER_PIN
      leds(2, 3, 4) {  // GREEN, YELLOW, RED pins
}

void DistanceAlertSystem::initialize() {
    Serial.begin(115200);
    Serial.println("\nDistance Alert System - Initializing...");
    performSystemCheck();
    Serial.println("System ready. Starting normal operation...\n");
}

void DistanceAlertSystem::run() {
    if (millis() - lastMeasurement >= measureInterval) { // Check if it's time to measure distance
        lastMeasurement = millis(); // Update the last measurement time
        
        float distance = sensor.measureDistance(); // Measure distance from the ultrasonic sensor
        
        if (sensor.isDistanceValid(distance)) { // Check if the distance is within valid range
            leds.update(distance); // Update LEDs based on distance
            buzzer.update(distance); // Update buzzer based on distance
        } else {
            Serial.println("Invalid distance reading!");
        }
    }
}

void DistanceAlertSystem::performSystemCheck() {
    Serial.println("Performing system check...");
    leds.systemCheck();
    buzzer.beep(466, 100);
    delay(100);
    buzzer.beep(932, 100);
}