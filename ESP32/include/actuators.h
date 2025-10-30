#ifndef ACTUATORS_H
#define ACTUATORS_H
#include <Arduino.h> 

#include <Servo.h>

#define RELAY_PIN  26
#define BUZZER_PIN 27
#define SERVO_PIN  14

Servo gateServo;

void setupActuators() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  gateServo.attach(SERVO_PIN);
}

void activateAlarm(bool on) {
  digitalWrite(BUZZER_PIN, on ? HIGH : LOW);
}

void controlPump(bool on) {
  digitalWrite(RELAY_PIN, on ? HIGH : LOW);
}

void openGate() {
  gateServo.write(90); // mở
}

void closeGate() {
  gateServo.write(0); // đóng
}

#endif
