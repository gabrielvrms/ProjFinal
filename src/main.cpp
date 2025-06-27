#include "DistanceAlertSystem.hpp"

DistanceAlertSystem alertSystem;

void setup() {
    alertSystem.initialize();
}

void loop() {
    alertSystem.run();
}