#ifndef MQTT_CONFIG_H
#define MQTT_CONFIG_H

#include <WiFi.h>
#include <PubSubClient.h>
#include "config.h"

// Cấu hình WiFi & MQTT
#define WIFI_SSID "your_wifi_name"
#define WIFI_PASSWORD "your_password"
#define MQTT_SERVER "broker.hivemq.com"
#define MQTT_PORT 1883

extern WiFiClient espClient;
extern PubSubClient client;

void setup_wifi();
void reconnect_mqtt();
void mqtt_publish(const char* topic, const String& payload);

#endif
