#include <wifi_mgmr_ext.h>

// Kết nối Wifi
wifi_mgmr_sta_connect(char *ssid, char *psk, char *pmk, uint8_t *mac, uint8_t band);

// Lấy IP
void wifi_mgmr_sta_ip_get(uint32_t *ip, uint32_t *gw, uint32_t *mask);

// Lấy MAC Address
void wifi_mgmr_sta_mac_get(uint8_t mac[6]);

// Bật chế độ Station
wifi_mgmr_sta_enable(void);