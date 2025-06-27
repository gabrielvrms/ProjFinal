#ifndef ULTRASONIC_SENSOR_HPP
#define ULTRASONIC_SENSOR_HPP

#include <Arduino.h>

class UltrasonicSensor {
public:
    UltrasonicSensor(uint8_t trigPin, uint8_t echoPin);
    float measureDistance();
    bool isDistanceValid(float distance);

private:
    uint8_t trigPin;
    uint8_t echoPin;
    const float minDistance = 2.0;    // 2cm
    const float maxDistance = 400.0;  // 400cm (4m)
};

#endif