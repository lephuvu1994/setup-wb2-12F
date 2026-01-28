smart_switch_pro/
├── Makefile                <-- File build hệ thống
├── proj_config.mk          <-- Cấu hình bật/tắt tính năng (Feature flags)
├── include/
│   ├── app_conf.h          <-- Định nghĩa Struct dữ liệu & Global Variable
│   ├── app_func.h          <-- Khai báo hàm (Header)
│   └── wifi_mgmr_ext.h     <-- (SDK Header có sẵn)
├── smart_switch_pro/
│   ├── main.c              <-- Luồng chính + Watchdog + State Machine
│   ├── app_storage.c       <-- Xử lý EasyFlash (Lưu Config)
│   ├── app_ble_logic.c     <-- Xử lý Logic nhận dữ liệu từ Bluetooth
│   ├── app_http.c          <-- Xử lý gọi API (Bootstrap & Active)
│   └── app_wifi_mqtt.c     <-- Xử lý Wifi & MQTT