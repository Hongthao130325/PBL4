#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

class MQ2Sensor {
private:
  int pin;
public:
  MQ2Sensor(int p);
  void begin();
  int readValue();
  bool isDetected(int threshold);
};

class SmokeSensor {
private:
  int pin;
public:
  SmokeSensor(int p);
  void begin();
  int readValue();
  bool isDetected(int threshold);
};

#endif
