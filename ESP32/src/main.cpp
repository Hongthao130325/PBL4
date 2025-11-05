#include <Arduino.h>
#include "config.h"
#include "sensors.h"
#include "actuators.h"
#include "mqtt_config.h"

// --- Tạo đối tượng ---
MQ2Sensor gasSensor(MQ2_PIN);
SmokeSensor smokeSensor(SMOKE_PIN);
Relay relay(RELAY_PIN);
Pump pump(RELAY_PIN);
ServoDoor door1(SERVO1_PIN);
ServoDoor door2(SERVO2_PIN);

unsigned long lastCheck = 0;

void setup() {
  Serial.begin(115200);
  gasSensor.begin();
  smokeSensor.begin();
  relay.begin();
  pump.begin();
  door1.begin();
  door2.begin();
  
  setup_wifi();
  client.setServer(MQTT_SERVER, MQTT_PORT);
  Serial.println("🚀 ESP32 IoT Fire/Gas Safety System started!");
}

void loop() {
  if (!client.connected()) reconnect_mqtt();
  client.loop();

  if (millis() - lastCheck > 2000) {
    lastCheck = millis();

    int gasVal = gasSensor.readValue();
    int smokeVal = smokeSensor.readValue();

    Serial.printf("Gas: %d | Smoke: %d\n", gasVal, smokeVal);

    mqtt_publish(MQTT_TOPIC_GAS, String(gasVal));
    mqtt_publish(MQTT_TOPIC_SMOKE, String(smokeVal));

    bool danger = gasSensor.isDetected(GAS_THRESHOLD) || smokeSensor.isDetected(SMOKE_THRESHOLD);
    if (danger) {
      Serial.println("🔥 Danger detected! Activating system...");
      relay.on();
      pump.start();
      door1.open();
      door2.open();
      mqtt_publish(MQTT_TOPIC_STATUS, "ALERT");
    } else {
      relay.off();
      pump.stop();
      door1.close();
      door2.close();
      mqtt_publish(MQTT_TOPIC_STATUS, "SAFE");
    }
  }
}
