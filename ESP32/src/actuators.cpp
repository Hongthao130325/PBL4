#include "actuators.h"

// ===== Relay =====
Relay::Relay(int p) : pin(p) {}

void Relay::begin() {
    pinMode(pin, OUTPUT);
    off();
}

void Relay::on() {
    digitalWrite(pin, HIGH);
}

void Relay::off() {
    digitalWrite(pin, LOW);
}

// ===== Pump =====
Pump::Pump(int p) : relayPin(p) {}

void Pump::begin() {
    pinMode(relayPin, OUTPUT);
    stop();
}

void Pump::start() {
    digitalWrite(relayPin, HIGH);
}

void Pump::stop() {
    digitalWrite(relayPin, LOW);
}

// ===== ServoDoor =====
ServoDoor::ServoDoor(int p) : pin(p) {}

void ServoDoor::begin() {
    servo.attach(pin);
    close();
}

void ServoDoor::open() {
    servo.write(90);   // góc mở (bạn có thể chỉnh 90 -> góc mong muốn)
}

void ServoDoor::close() {
    servo.write(0);    // góc đóng
}
