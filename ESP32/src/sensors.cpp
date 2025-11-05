#include "sensors.h"

MQ2Sensor::MQ2Sensor(int p) : pin(p) {}

void MQ2Sensor::begin() {
  pinMode(pin, INPUT);
}

int MQ2Sensor::readValue() {
  return analogRead(pin);
}

bool MQ2Sensor::isDetected(int threshold) {
  int value = readValue();
  return value > threshold; // ví dụ: vượt ngưỡng -> có khí gas
}

// -----------------------------

SmokeSensor::SmokeSensor(int p) : pin(p) {}

void SmokeSensor::begin() {
  pinMode(pin, INPUT);
}

int SmokeSensor::readValue() {
  return analogRead(pin);
}

bool SmokeSensor::isDetected(int threshold) {
  int value = readValue();
  return value > threshold; // ví dụ: vượt ngưỡng -> có khói
}
