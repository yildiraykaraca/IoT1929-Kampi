// IOTSPS
#define BLYNK_PRINT Serial   
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include "DHT.h"

char auth[] ="Blynk_Token_Kodu";               //Blynk Token Kodumuzu Giriyoruz.
char ssid[] = "Ağ_Adı";                        //Wifi Adımızı Giriyoruz.
char pass[] = "Ağ_Şifresi";                    //WiFi Şifremizi Giriyoruz.

#define dhtSensorPin D4 
#define DHTTYPE DHT11
#define RolePin D0 //Rölem LOW'Da Çalışmaktadır.
DHT dht(dhtSensorPin, DHTTYPE);

int sensorDurum = 0;
int sonDurum = 0;
int toprakSensorDegeri;   

SimpleTimer timer;

void setup()
{
  Serial.begin(9600); //9600 baud seri haberleşmeyi başlat
  Blynk.begin(auth, ssid, pass); //blynki başlat.
  pinMode(toprakSensorPin, INPUT); // Toprak Sensörünün Digital Pinini Giriş Ayarladık.
  dht.begin(); // dht yi başlattık.
  Blynk.begin(auth, ssid, pass); //Blynk Başlat
}

void DhtDeger()
{
  float nem = dht.readHumidity(); //Nem değerini oku nem değişkenine ata.
  float sicaklik = dht.readTemperature(); //Sıcaklık Değerini oku sicaklik değişkenine ata.

  if (isnan(nem) || isnan(sicaklik))  //nem veya sicaklik verisi değer döndürmediğinde,
  {  
    Serial.println("DHT Sensörleri Okunamadı ya da Çalışmıyor."); // Seri porta yaz
    return; // Dön
  }
 
  Blynk.virtualWrite(V5, nem);  //V5' pinine nem değerlerini yazdır.
  Blynk.virtualWrite(V6, sicaklik);  //V6 pinine sıcaklık değerlerini yazdır.
}

void ToprakDeger()
{
toprakSensorDegeri=analogRead(A0); // Toprak Nemini Oku Değişkene Ata
Serial.println("Toprak Nem Değeri:"); // Seri Porta Yaz.
Serial.print(toprakSensorDegeri);     // Seri Porta Yaz.

sensorDurum = digitalRead(toprakSensorPin); // sensodrDurumu 1 Ya da 0 Değer Alacak.
Serial.println(sensorDurum); //Seri Porta sensör Durumunu Yaz.
delay(100); // 100 MiliSaniye Bekle.

Blynk.virtualWrite(V1, toprakSensorDegeri); // Blynk V1 Pinine Yaz.
delay(1000); //1 Saniye Bekle
}
BLYNK_WRITE(V0)
{
digitalWrite(RolePin,param.asInt()); // Sula Butonu
}

void loop()
{
  Blynk.run(); // Blynk Çalıştır.
  timer.run(); // Timer'ı Çalıştır.
  DhtDeger(); // Dht Deger Fonksiyonunu Çağır.
  ToprakDeger(); // Fonksiyonu Çağır.
  
  if (sensorDurum == 1 && SonDurum == 0 && toprakSensorDegeri>600) 
  {
  Serial.println("Çiçek Sulanıyor....");
  digitalWrite(RolePin,LOW); // Röle Aktif
  SonDurum = 1; 
  delay(1000);
  else if (sensorDurum == 1 && SonDurum==1 toprakSensorDegeri<600)
  {
  Serial.println("Çiçek Sulandı....")
  digitalWrite(RolePin,HIGH); // Röle Kapalı
  SonDurum = 1; 
  }
  else
  {
  Serial.println("Durum Güncellendi.");
  SonDurum = 0;
  delay(1000);
  }
  delay(100);
  } 
}
