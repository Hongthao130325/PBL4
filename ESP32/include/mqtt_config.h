#ifndef MQTT_CONFIG_H
#define MQTT_CONFIG_H
#include <Arduino.h> 

// WiFi
#define WIFI_SSID       "TenWiFiCuaBan"
#define WIFI_PASSWORD   "MatKhauWiFi"

// MQTT Broker
#define MQTT_SERVER     "test.mosquitto.org"
#define MQTT_PORT       1883

// Topics
#define TOPIC_SENSOR    "pccc/sensor"
#define TOPIC_ALERT     "pccc/alert"
#define TOPIC_CONTROL   "pccc/control"

#endif
