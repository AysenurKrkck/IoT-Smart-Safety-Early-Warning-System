#include <DHT.h> // Include DHT sensor library / DHT sensör kütüphanesini dahil ediyoruz

// --- Pin Definitions / Pin Tanımlamaları ---
#define DHTPIN 4          // DHT11 Data pin connected to GPIO 4 / DHT11 Data pini GPIO 4'e bağlı
#define DHTTYPE DHT11     // Sensor type specified as DHT11 / Sensör tipi DHT11 olarak belirlendi
#define MQ_PIN 34         // MQ Gas Sensor connected to Analog Pin GPIO 34 / MQ Gaz Sensörü Analog GPIO 34 pinine bağlı
#define RAIN_PIN 19       // Rain/Water Sensor DO connected to GPIO 19 / Yağmur/Su Sensörü DO bacağı GPIO 19 pinine bağlı
#define BUZZER_PIN 25     // Active Buzzer connected to GPIO 25 / Aktif Buzzer GPIO 25 pinine bağlı
#define RED_LED 26        // Red Alarm LED connected to GPIO 26 / Kırmızı Alarm LED'i GPIO 26 pinine bağlı
#define GREEN_LED 27      // Green Safe Status LED connected to GPIO 27 / Yeşil Güvenli Durum LED'i GPIO 27 pinine bağlı

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor / DHT sensörünü başlatıyoruz

// --- Threshold Settings / Eşik Değer Ayarları ---
int gasThreshold = 1300;   // Critical analog gas threshold (0-4095) / Kritik analog gaz eşiği (0-4095 arası)
float tempThreshold = 45.0; // Critical temperature threshold in Celsius / Santigrat cinsinden kritik sıcaklık eşiği

void setup() {
  Serial.begin(115200); // Start serial communication at 115200 baud / Seri haberleşmeyi 115200 baud hızında başlatıyoruz
  
  // Set pin modes / Pin modlarını ayarlıyoruz
  pinMode(RAIN_PIN, INPUT);     // Rain sensor pin set as Input / Yağmur sensörü pini Giriş olarak ayarlandı
  pinMode(BUZZER_PIN, OUTPUT);  // Buzzer pin set as Output / Buzzer pini Çıkış olarak ayarlandı
  pinMode(RED_LED, OUTPUT);     // Red LED pin set as Output / Kırmızı LED pini Çıkış olarak ayarlandı
  pinMode(GREEN_LED, OUTPUT);   // Green LED pin set as Output / Yeşil LED pini Çıkış olarak ayarlandı
  
  dht.begin(); // Start the DHT11 sensor / DHT11 sensörünü aktif ediyoruz

  // --- MQ Sensor Preheat Protocol / MQ Sensörü Isınma Beklemesi ---
  // MQ sensors require a short warm-up period to stabilize readings.
  // MQ sensörleri kararlı ölçüm yapmak için ilk açılışta kısa bir ısınma süresine ihtiyaç duyar.
  Serial.println("Sistem baslatiliyor... MQ Sensoru isiniyor (10sn)...");
  for (int i = 0; i < 10; i++) {
    digitalWrite(GREEN_LED, HIGH); // Blink green LED during preheat / Isınma esnasında yeşil LED'i yakıp söndür
    delay(500);
    digitalWrite(GREEN_LED, LOW);
    delay(500);
  }
  Serial.println("Sistem Aktif! Gaz, Yangin ve Su Baskini Izleme Basladi...");
}

void loop() {
  // Read sensor values / Sensör verilerini okuyoruz
  int gasValue = analogRead(MQ_PIN);        // Read analog value from gas sensor / Gaz sensöründen analog değer oku
  float temperature = dht.readTemperature(); // Read temperature in Celsius / Sıcaklığı Santigrat olarak oku
  int rainStatus = digitalRead(RAIN_PIN);    // Read digital status from rain sensor (LOW=Water, HIGH=Dry) / Yağmur sensöründen dijital durumu oku (LOW=Su var, HIGH=Kuru)

  // Check if DHT sensor reading failed / DHT sensörünün okunup okunamadığını kontrol et
  if (isnan(temperature)) {
    Serial.println("Hata: DHT sensoru okunamadi!");
    return; // Skip the rest of the loop if sensor fails / Sensör okunamadıysa loop'un kalanını atla
  }

  // --- Print data to Serial Monitor / Verileri Seri Port Ekranına Yazdırma ---
  Serial.print("Gaz: "); Serial.print(gasValue);
  Serial.print(" | Sicaklik: "); Serial.print(temperature);
  Serial.print(" | Su Durumu: "); Serial.println(rainStatus == LOW ? "SU BASKINI TESPIT EDILDI!" : "Kuru");

  // --- CRITICAL ALARM LOGIC / KRİTİK ALARM DURUMU ---
  // Trigger alarm if gas exceeds threshold OR temperature is too high OR water is detected (LOW)
  // Gaz eşiği geçildiyse VEYA sıcaklık fırladıysa VEYA su algılandıysa (rainStatus == LOW ise) alarmı tetikle
  if (gasValue > gasThreshold || temperature > tempThreshold || rainStatus == LOW) {
    digitalWrite(GREEN_LED, LOW); // Turn off the safe status LED / Güvenli durum LED'ini söndür
    
    // Create an aggressive flasher and intermittent buzzer effect / Agresif bir flaşör ve kesik kesik buzzer efekti oluştur
    digitalWrite(RED_LED, HIGH);   // Turn on Red LED and Buzzer / Kırmızı LED ve Buzzer'ı aç
    digitalWrite(BUZZER_PIN, HIGH);
    delay(150);
    digitalWrite(RED_LED, LOW);    // Turn off Red LED and Buzzer / Kırmızı LED ve Buzzer'ı kapat
    digitalWrite(BUZZER_PIN, LOW);
    delay(150);
  } 
  else {
    // --- SAFE STATE / HER ŞEY YOLUNDA ---
    digitalWrite(GREEN_LED, HIGH); // Turn on Green LED to show system is armed / Sistemin aktif olduğunu göstermek için Yeşil LED'i yak
    digitalWrite(RED_LED, LOW);    // Ensure alarm components are turned off / Alarm bileşenlerinin kapalı olduğundan emin ol
    digitalWrite(BUZZER_PIN, LOW);
    delay(500); // Wait half a second before next scan / Bir sonraki taramadan önce yarım saniye bekle
  }
}
