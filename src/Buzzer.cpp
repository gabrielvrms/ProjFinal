#include "Buzzer.hpp"
#include <Arduino.h>

Buzzer::Buzzer(uint8_t pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void Buzzer::beep(int frequency, int duration) const {
    tone(pin, frequency, duration);
    delay(duration);
}

void Buzzer::update(float distance) {
    if (distance > greenZone) {
        noTone(pin);
    } 
    else if (distance > yellowZone) {
        beep(baseFrequency, longBeep);
    } 
    else if (distance > orangeZone) {
        beep(baseFrequency, mediumBeep);
    } 
    else if (distance > redZone) {
        beep(baseFrequency, shortBeep);
    }
}