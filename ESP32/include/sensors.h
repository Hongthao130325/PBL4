#ifndef SENSORS_H
#define SENSORS_H
#include <Arduino.h> 

#define MQ2_PIN 34   // Cảm biến khói/gas gắn vào chân analog

int readGasSensor() {
  int gasValue = analogRead(MQ2_PIN);
  return gasValue;
}

bool isFireDetected(int threshold = 1800) {
  return analogRead(MQ2_PIN) > threshold;
}

#endif
