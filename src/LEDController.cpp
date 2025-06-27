#include "LEDController.hpp"
#include <Arduino.h>

LEDController::LEDController(uint8_t greenPin, uint8_t yellowPin, uint8_t redPin) 
    : greenPin(greenPin), yellowPin(yellowPin), redPin(redPin) {
    pinMode(greenPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(redPin, OUTPUT);
    turnAllOff();
}

void LEDController::update(float distance) {
    turnAllOff();
    
    if (distance > greenZone) {
        // All off
    } 
    else if (distance > yellowZone) {
        digitalWrite(greenPin, HIGH);
    } 
    else if (distance > orangeZone) {
        digitalWrite(greenPin, HIGH);
        digitalWrite(yellowPin, HIGH);
    } 
    else if (distance > redZone) {
        digitalWrite(greenPin, HIGH);
        digitalWrite(yellowPin, HIGH);
        digitalWrite(redPin, HIGH);
    }
}

void LEDController::turnAllOff() {
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
}

void LEDController::systemCheck() {
    digitalWrite(greenPin, HIGH);
    delay(200);
    digitalWrite(yellowPin, HIGH);
    delay(200);
    digitalWrite(redPin, HIGH);
    delay(200);
    turnAllOff();
    delay(200);
}