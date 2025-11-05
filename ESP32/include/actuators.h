#ifndef ACTUATORS_H
#define ACTUATORS_H

#include "Arduino.h"
#include <Servo.h>

class Relay {
private:
  int pin;
public:
  Relay(int p);
  void begin();
  void on();
  void off();
};

class Pump {
private:
  int relayPin;
public:
  Pump(int p);
  void begin();
  void start();
  void stop();
};

class ServoDoor {
private:
  Servo servo;
  int pin;
public:
  ServoDoor(int p);
  void begin();
  void open();
  void close();
};

#endif
