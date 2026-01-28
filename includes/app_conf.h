#ifndef __APP_CONF_H__
#define __APP_CONF_H__

#include <stdint.h>

// ==================================================
// 1. CẤU HÌNH PHẦN CỨNG (HARDWARE PIN)
// ==================================================
// Tùy vào mạch thật của bạn, sửa số GPIO ở đây
#define GPIO_PIN_RELAY      11  // Chân điều khiển Relay (Ví dụ GPIO 11)
#define GPIO_PIN_BUTTON     12  // Chân nút nhấn Reset (Ví dụ GPIO 12)
#define GPIO_PIN_LED        14  // Chân đèn báo trạng thái

// ==================================================
// 2. CẤU HÌNH SERVER MẶC ĐỊNH (BOOTSTRAP)
// ==================================================
// Domain mồi để lấy config thật (Hardcode)
#define DEFAULT_BOOTSTRAP_DOMAIN "http://api.my-iot-server.com" 

// ==================================================
// 3. STRUCT DỮ LIỆU TOÀN CỤC (QUAN TRỌNG)
// ==================================================
typedef struct {
    // --- A. Wifi Credential (Nạp qua BLE) ---
    char ssid[33];
    char pass[65];
    
    // --- B. Server Config (Lấy từ API Bootstrap) ---
    char api_host[128];  // VD: http://prod-api.com
    char mqtt_host[128]; // VD: mqtt.prod.com
    int  mqtt_port;      // VD: 1883
    
    // --- C. Identity (Lấy từ API Active) ---
    int  device_stt;       // Số thứ tự quản lý (Anti-Clone)
    char device_token[65]; // Token bảo mật (Check BLE & MQTT)
    uint8_t is_activated;  // Cờ báo: 0=Chưa, 1=Rồi
    
    // --- D. Runtime State ---
    uint8_t relay_state;   // 0: OFF, 1: ON
} app_config_t;

// Khai báo biến toàn cục (được định nghĩa thực tế trong app_storage.c)
extern app_config_t g_cfg;

// Sự kiện Event Group (Dùng để đồng bộ Wifi/BLE)
// (Nếu dùng FreeRTOS EventGroup)
// extern EventGroupHandle_t app_event_group;
// #define EVENT_GOT_WIFI  (1 << 0)

#endif