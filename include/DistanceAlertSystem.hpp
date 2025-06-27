#ifndef DISTANCE_ALERT_SYSTEM_HPP
#define DISTANCE_ALERT_SYSTEM_HPP

#include "UltrasonicSensor.hpp"
#include "Buzzer.hpp"
#include "LEDController.hpp"

#include <Arduino.h>

class DistanceAlertSystem {
public:
    DistanceAlertSystem();
    void initialize();
    void run();

private:
    UltrasonicSensor sensor;
    Buzzer buzzer;
    LEDController leds;
    
    const unsigned long measureInterval = 100; // ms
    unsigned long lastMeasurement = 0;
    
    void performSystemCheck();
};

#endif