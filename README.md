# setup-wb2-12F

brew install git wget make cmake python3
pip3 install bflb-iot-tool


mkdir -p ~/Documents/bl602_official
cd ~/Documents/bl602_official
# 2. Clone Official SDK (Bản gốc của Bouffalo Lab)
git clone https://github.com/bouffalolab/bl_iot_sdk.git

# 3. Tải lại Toolchain chuẩn cho macOS (để đảm bảo sạch sẽ)
wget https://dev.bouffalolab.com/media/upload/download/toolchain_riscv_sifive_macos.zip

# 4. Giải nén và đổi tên
unzip toolchain_riscv_sifive_macos.zip
mv toolchain_riscv_sifive_macos toolchain
rm toolchain_riscv_sifive_macos.zip

# Cấp quyền thực thi
chmod -R 755 ~/Documents/bl602_official/toolchain

# Gỡ bỏ "vòng kim cô" Gatekeeper của Apple
sudo xattr -r -d com.apple.quarantine ~/Documents/bl602_official/toolchain


nano ~/.zshrc
```Xóa các dòng cũ liên quan đến BL602 đi, và thay bằng đoạn này:
Bash
# --- BL602 OFFICIAL SDK CONFIG ---
export BL60X_SDK_PATH=~/Documents/bl602_official/bl_iot_sdk
export PATH=$PATH:~/Documents/bl602_official/toolchain/bin

source ~/.zshrc

```
Check: 
riscv64-unknown-elf-gcc -v
```
