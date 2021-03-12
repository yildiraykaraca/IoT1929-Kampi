/* 
 *  Yıldıray KARACA IoT1929 Kampı İçin Arduino Problem Seti 3 Gerçek Devre Üzerindeki Çözümü.
 *  mail: yildiraykaraca@icloud.com
 *  github: https://github.com/yildiraykaraca
*/
 
#include "DHT.h"                //DHT Kütüphanesini Dahil Ettim.
#define dhtSensorPin 2          // 2 Numaralı Pini dhtSensorPini Olarak Tanımladım.
#define DHTTYPE DHT11           // DHT Sensör Tipini Belirttim.
DHT dht(dhtSensorPin, DHTTYPE); // DHT11 Sensörümü Belirterek dht Adını Verdim.
int nemOku;                  // nemOku Adında Bir Değişken Tanımladım.
int celsiusOku;              // celsiusOku Adında Bir Değişken Tanımladım.
int fahrenheitOku;           // fahrenheitOku Adında Bir Değişken Tanımladım.
int kelvinOku;               // kelvinOku Adında Bir Değişken Tanımladım.

void setup()                    // Yüklendiğinde

{
 Serial.begin(9600);            // Seri Haberleşmeyi Başlattım.
 dht.begin();                   // dht Adını Verdiğim DHT11 Sensörünü Başlattım.
}

void loop()                     // Sonsuz Döngü
{
   nemOku = dht.readHumidity();           // Nem Değerini Oluşturduğum Değişkene Atadım.
   celsiusOku = dht.readTemperature();    // Celsius Değerini Oluşturduğum Değişkene Atadım.
   fahrenheitOku = ((9/5*celsiusOku)+32); // Celsius'tan Gelen Veri İle Fahrenheit Hesapladım ve Değişkene Atadım.
   kelvinOku = (celsiusOku+273);          // Celsius'tan Gelen Veri İle Kelvin Hesapladım ve Değişkene Atadım.
   
   Serial.println("**************************************************************"); // Ekranı Süsledim :) Karışmaması İçin
   Serial.println("Nem Degeri: " + String(nemOku));                                  // Değişkenden Gelen Veriyi String'e Dönüştürerek + Operatörü İle Ekrana Yazdırdım.
   Serial.println("Celsius Degeri: " + String(celsiusOku));                          // Değişkenden Gelen Veriyi String'e Dönüştürerek + Operatörü İle Ekrana Yazdırdım.
   Serial.println("Fahrenheit Degeri: " + String(fahrenheitOku));                    // Değişkenden Gelen Veriyi String'e Dönüştürerek + Operatörü İle Ekrana Yazdırdım.
   Serial.println("Kelvin Degeri: " + String(kelvinOku));                            // Değişkenden Gelen Veriyi String'e Dönüştürerek + Operatörü İle Ekrana Yazdırdım.
   Serial.println("**************************************************************"); // Tekrar Ekranı Süsledim :) Karışmaması İçin   
   delay(2500);                                                                      // 2 Saniye Aralıkla Ölç.
}
