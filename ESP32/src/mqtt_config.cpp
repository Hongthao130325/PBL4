#include "mqtt_config.h"

WiFiClient espClient;
PubSubClient client(espClient);

// ===== Hàm kết nối WiFi =====
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Đang kết nối tới WiFi: ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Chờ kết nối WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("✅ WiFi đã kết nối!");
  Serial.print("Địa chỉ IP: ");
  Serial.println(WiFi.localIP());
}

// ===== Hàm kết nối lại MQTT khi mất kết nối =====
void reconnect_mqtt() {
  while (!client.connected()) {
    Serial.print("Đang kết nối tới MQTT broker... ");
    if (client.connect("ESP32_Client")) {
      Serial.println("✅ Kết nối MQTT thành công!");
      // Subcribe topic nếu cần
      client.subscribe("esp32/control");
    } else {
      Serial.print("❌ Lỗi, mã lỗi = ");
      Serial.print(client.state());
      Serial.println(" → Thử lại sau 5 giây.");
      delay(5000);
    }
  }
}

// ===== Hàm publish dữ liệu lên MQTT =====
void mqtt_publish(const char* topic, const String& payload) {
  if (!client.connected()) {
    reconnect_mqtt();
  }
  client.loop();
  client.publish(topic, payload.c_str());
}
