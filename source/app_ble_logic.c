#include "app_conf.h"
#include <cJSON.h>
#include <stdio.h>
#include <string.h>
#include <hal_sys.h> // Để reboot

extern void storage_save_wifi(char*, char*);
extern void control_relay(int); // Hàm bên main

// Hàm này được gọi khi có data gửi vào Characteristic WRITE
void ble_process_data_received(uint8_t *data, uint16_t len) {
    // Parse JSON
    cJSON *root = cJSON_Parse((char*)data);
    if (!root) {
        printf("[BLE] JSON Parse Error\r\n");
        return;
    }

    // --- 1. XỬ LÝ WIFI CONFIG (Provisioning) ---
    cJSON *ssid = cJSON_GetObjectItem(root, "ssid");
    cJSON *pass = cJSON_GetObjectItem(root, "pass");
    
    if (ssid && pass) {
        printf("[BLE] Got Wifi Credentials. Saving & Rebooting...\r\n");
        storage_save_wifi(ssid->valuestring, pass->valuestring);
        
        // Phản hồi OK cho App
        // ble_send_notify("{\"result\":\"wifi_saved\"}"); 
        
        vTaskDelay(1000);
        hal_reboot(); // Reset để kết nối Wifi mới
    }

    // --- 2. XỬ LÝ ĐIỀU KHIỂN (Offline Control) ---
    cJSON *cmd = cJSON_GetObjectItem(root, "cmd");     // "on"/"off"
    cJSON *token = cJSON_GetObjectItem(root, "token"); // Token bảo mật
    
    if (cmd && token) {
        // KIỂM TRA BẢO MẬT: So khớp Token với Flash
        if (strcmp(token->valuestring, g_cfg.device_token) == 0) {
            printf("[BLE] Token Valid. Execute: %s\r\n", cmd->valuestring);
            
            int state = (strcmp(cmd->valuestring, "on") == 0) ? 1 : 0;
            control_relay(state);
            
            // ble_send_notify("{\"status\":\"success\"}");
        } else {
            printf("[BLE] AUTH FAILED! Wrong Token.\r\n");
            // ble_send_notify("{\"error\":\"auth_fail\"}");
        }
    }
    
    cJSON_Delete(root);
}