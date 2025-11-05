#ifndef CONFIG_H
#define CONFIG_H
#define CONFIG_H

// Pin định nghĩa
#define RELAY_PIN 32
#define SERVO1_PIN 18
#define SERVO2_PIN 19
#define MQ2_PIN 34
#define SMOKE_PIN 33
#define BUTTON_PIN 25

// Ngưỡng
#define GAS_THRESHOLD 500
#define SMOKE_THRESHOLD 500

// MQTT Topics
#define MQTT_TOPIC_GAS "esp32/gas"
#define MQTT_TOPIC_SMOKE "esp32/smoke"
#define MQTT_TOPIC_STATUS "esp32/status"

#endif
