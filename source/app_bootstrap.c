#include "app_data.h"
#include "app_http.h" // Wrapper socket giống bài trước

// Gọi: GET http://boot.my-iot-server.com/config
// Trả về: {"api": "...", "mqtt": "..."}
int get_dynamic_config() {
    char url[128];
    sprintf(url, "%s/config", DEFAULT_BOOTSTRAP_DOMAIN);
    
    char *resp = http_get_request(url); // Hàm tự viết
    if (!resp) return 0;

    cJSON *json = cJSON_Parse(resp);
    cJSON *api = cJSON_GetObjectItem(json, "api");
    cJSON *mqtt = cJSON_GetObjectItem(json, "mqtt");

    if (api && mqtt) {
        strcpy(g_cfg.api_host, api->valuestring);
        strcpy(g_cfg.mqtt_host, mqtt->valuestring);
        printf("[BOOT] Got Config: API=%s, MQTT=%s\r\n", g_cfg.api_host, g_cfg.mqtt_host);
        return 1;
    }
    return 0;
}