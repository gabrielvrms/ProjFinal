#ifndef BUZZER_HPP
#define BUZZER_HPP

#include <Arduino.h>

class Buzzer {
public:
    Buzzer(uint8_t pin);
    void beep(int frequency, int duration) const;
    void update(float distance);

private:
    uint8_t pin;
    const int baseFrequency = 466;
    const int shortBeep = 15;
    const int mediumBeep = 250;
    const int longBeep = 400;
    
    // Distance thresholds
    const float greenZone = 50.0;
    const float yellowZone = 35.0;
    const float orangeZone = 25.0;
    const float redZone = 15.0;
};

#endif