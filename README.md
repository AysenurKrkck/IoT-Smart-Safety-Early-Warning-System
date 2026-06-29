# IoT-Smart-Safety-Early-Warning-System

[🇹🇷 Türkçe Açıklama İçin Tıklayın](#-türkçe-içindekiler) | [🇺🇸 Click For English Description](#-english-table-of-contents)

---

## 🇹🇷 Türkçe İçindekiler
- [Proje Hakkında](#proje-hakkında)
- [Özellikler (v1.0.0)](#özellikler-v100)
- [Kullanılan Donanımlar](#kullanılan-donanımlar)
- [Kurulum ve Çalıştırma](#kurulum-ve-çalıştırma)

### Proje Hakkında
Ev ve endüstriyel ortamlarda oluşabilecek temel fiziksel tehditleri (Gaz kaçağı, yangın/yüksek sıcaklık ve su baskını) erkenden tespit ederek yerel olarak alarm üreten akıllı bir güvenlik istasyonudur. 

Projenin bu ilk versiyonu (v1.0.0), donanım entegrasyonu ve tamamen yerel (local) çalışan kesintisiz alarm mekanizmasına odaklanmaktadır. Bir sonraki versiyonda (v2.0.0) sisteme bulut veri takibi (Blynk) eklenecektir.

### Özellikler (v1.0.0)
- **Gaz & Duman Tespiti:** MQ Gaz Sensörü ile ortamdaki yanıcı gazların ve dumanın analog takibi.
- **SSıcaklık Takibi:** DHT11 sensörü ile yangın kaynaklı ani sıcaklık artışlarının tespiti.
- **Su Baskını Erken Uyarısı:** Yağmur/Sıvı seviye sensörü ile su sızıntılarının anında yakalanması.
- **Görsel/İşitsel Alarm:** Kritik eşikler aşıldığında aktifleşen flaşör LED (Kırmızı) ve kesik kesik çalan yüksek sesli Buzzer uyarısı.
- **Güvenli Durum İndikatörü:** Her şey yolundayken sistemin aktif olduğunu gösteren Yeşil LED.

### Kullanılan Donanımlar
- ESP32 DevKitV1
- MQ Gaz Sensörü
- DHT11 Sıcaklık ve Nem Sensörü
- Yağmur / Su Baskını Sensörü (3-Pin Dijital Çıkışlı)
- 5V Aktif Buzzer
- Kırmızı ve Yeşil LED (220Ω Dirençler ile)

### Kurulum ve Çalıştırma
1. Donanım bağlantılarını yukarıdaki tabloya göre breadboard üzerinde tamamlayın.
2. Bilgisayarınıza Arduino IDE'yi kurun ve ESP32 kart kütüphanelerini ekleyin.
3. Kütüphane yöneticisinden `DHT sensor library` (Adafruit) kütüphanesini yükleyin.
4. `Smart_Safety___Early_Warning_System.ino` kodunu ESP32'nize yükleyin.
5. Seri Port Ekranını (Baud Rate: 115200) açarak sensör kalibrasyonlarını takip edin.

---

## 🇺🇸 English Table of Contents
- [About the Project](#about-the-project)
- [Features (v1.0.0)](#features-v100)
- [Hardware Components](#hardware-components)
- [Installation and Setup](#installation-and-setup)

### About the Project
It is an intelligent security station that detects fundamental physical threats (gas leaks, fire/high temperature, and flooding) that may occur in residential and industrial environments at an early stage and generates local alarms

This initial version (v1.0.0) of the project focuses on hardware integration and a seamless, fully local alarm mechanism. Cloud-based data monitoring (Blynk) will be implemented in the next version (v2.0.0).

### Features (v1.0.0)
- **Gas & Smoke Detection:** Real-time analog monitoring of flammable gases and smoke using the MQ sensor.
- **Temperature Monitoring:** Sudden fire spike detection via the DHT11 temperature sensor.
- **Flood Early Warning:** Immediate detection of water leaks using a rain/liquid level sensor.
- **Visual/Audible Alarm:** Flashing Red LED and an intermittent loud Buzzer alert triggered upon exceeding critical thresholds.
- **Safe Status Indicator:** A solid Green LED indicating that the system is armed and environment is safe.

### Hardware Components
- ESP32 DevKitV1
- MQ Gas Sensor
- DHT11 Temperature and Humidity Sensor
- Rain / Water Flood Sensor (3-Pin Digital Output)
- 5V Active Buzzer
- Red and Green LEDs (with 220Ω resistors)

### Installation and Setup
1. Complete the hardware wiring on a breadboard according to the configuration table above.
2. Install Arduino IDE on your computer and add the ESP32 board library.
3. Install the `DHT sensor library` (by Adafruit) via the Library Manager.
4. Upload the `Smart_Safety___Early_Warning_System.ino` sketch to your ESP32.
5. Open the Serial Monitor (Baud Rate: 115200) to monitor live sensor calibration data.

## 🔗 Sosyal Medya / Social Media
Bu ve benzeri projelerin yapım aşamalarını ve detaylarını görmek için: / To see the making-of and details of this and similar projects:
👉 **Instagram:** [@TechByAysenur](https://www.instagram.com/TechByAysenur)

---
*Geliştirici / Developer: Ayşenur Karaküçük*
