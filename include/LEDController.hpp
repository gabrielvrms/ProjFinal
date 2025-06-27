#ifndef LED_CONTROLLER_HPP
#define LED_CONTROLLER_HPP

#include <Arduino.h>

class LEDController {
public:
    LEDController(uint8_t greenPin, uint8_t yellowPin, uint8_t redPin);
    void update(float distance);
    void turnAllOff();
    void systemCheck();

private:
    uint8_t greenPin;
    uint8_t yellowPin;
    uint8_t redPin;
    
    // Distance thresholds
    const float greenZone = 50.0;
    const float yellowZone = 35.0;
    const float orangeZone = 25.0;
    const float redZone = 15.0;
};

#endif