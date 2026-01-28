#ifndef __APP_FUNC_H__
#define __APP_FUNC_H__

#include <stdint.h>

// ==================================================
// NHÓM 1: STORAGE (app_storage.c)
// ==================================================
void storage_init(void);
void storage_load_all(void);
void storage_factory_reset(void);

// Lưu từng phần (để tối ưu tốc độ ghi)
void storage_save_wifi(char *ssid, char *pass);
void storage_save_bootstrap(char *api, char *mqtt, int port);
void storage_save_identity(int stt, char *token);


// ==================================================
// NHÓM 2: BLUETOOTH (app_ble_logic.c)
// ==================================================
// Bắt đầu phát sóng Bluetooth (Advertising)
void app_ble_start(void);

// Dừng phát sóng (khi đã có Wifi ổn định)
void app_ble_stop(void);

// Xử lý dữ liệu nhận được từ App điện thoại (JSON)
void ble_process_data_received(uint8_t *data, uint16_t len);


// ==================================================
// NHÓM 3: HTTP API (app_http.c)
// ==================================================
// Gọi API lấy config server (Bootstrap)
// Return: 1 (Success), 0 (Fail)
int app_api_bootstrap(void);

// Gọi API kích hoạt thiết bị (Activation)
// Return: 1 (Success), 0 (Fail), -1 (Quota Exceeded)
int app_api_activate(char *mac_str);


// ==================================================
// NHÓM 4: MQTT (app_wifi_mqtt.c)
// ==================================================
void app_mqtt_start(void);
void app_mqtt_stop(void);
// Gửi trạng thái hiện tại lên MQTT
void app_mqtt_publish_state(int state);


// ==================================================
// NHÓM 5: HÀM ĐIỀU KHIỂN CHUNG (Nằm ở main.c)
// ==================================================
// Các module khác (như BLE/MQTT) cần gọi hàm này để bật tắt Relay
void control_relay(int on);

#endif