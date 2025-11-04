#include <Arduino.h>
#include "actuators.h"
#include "sensors.h"

#include <Servo.h>

// Servo pan-tilt
Servo servoPan;
Servo servoTilt;
const int panPin = 12;
const int tiltPin = 13;

// Relay / MOSFET cho bơm/van
const int pumpPin = 14;

// E-Stop
const int eStopPin = 27;

// Còi + đèn
const int alarmPin = 26;

void setup() {
  Serial.begin(115200);

  // Setup servo
  servoPan.attach(panPin);
  servoTilt.attach(tiltPin);

  // Setup pump/relay
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);

  // Setup E-Stop
  pinMode(eStopPin, INPUT_PULLUP);

  // Setup alarm
  pinMode(alarmPin, OUTPUT);
  digitalWrite(alarmPin, LOW);
}

void loop() {
  // 1. Kiểm tra E-Stop
  if(digitalRead(eStopPin) == LOW) {
    emergencyStop();
    return; // dừng tất cả
  }

  // 2. Điều khiển servo pan-tilt (ví dụ demo)
  servoPan.write(90);
  servoTilt.write(45);
  delay(1000);

  // 3. Kích hoạt bơm/van
  digitalWrite(pumpPin, HIGH);
  delay(500);
  digitalWrite(pumpPin, LOW);
  delay(500);

  // 4. Còi + đèn báo động
  digitalWrite(alarmPin, HIGH);
  delay(200);
  digitalWrite(alarmPin, LOW);
  delay(200);
}

void emergencyStop() {
  // Tắt hết thiết bị
  digitalWrite(pumpPin, LOW);
  digitalWrite(alarmPin, LOW);
  servoPan.write(0);
  servoTilt.write(0);
  Serial.println("E-Stop activated! All systems OFF.");
  while(1) delay(1000); // dừng vô hạn
}
