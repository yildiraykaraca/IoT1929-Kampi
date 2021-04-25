/* 
 *  Yıldıray KARACA IoT1929 Kampı Hafta 2 İçin IOT Problem Seti 2 Çözümü.
 *  mail: yildiraykaraca@icloud.com
 *  github: https://github.com/yildiraykaraca
*/
#define BLYNK_PRINT Serial // Blynk İçin Kullanılan Nesneleri Tanımladık.
#include <ESP8266WiFi.h>   // ESP8266WiFi Kütüphanesini Dahil Ettik.
#include <BlynkSimpleEsp8266.h> // BlynkSimpleEsp8266 Kütüphanesini Dahil Ettik.
#include <Servo.h> // Servo Kütüphanesini Dahil Ettik.

char auth[] = "Blynk_Token_Kodu"; // Blynk Uygulamasının Bize Göndermiş Olduğu Kodu Buraya Yazıyoruz.
char ssid[] = "Ağ_Adı";           // Modem Ağ Adımızı Bu Alana Yazdık.
char pass[] = "Ağ_Şifresi";       // Modem Ağ Şifremizi Bu Alana Yazdık.

Servo servo; // Servo Motorumuza "servo" adını verdik. 

void setup() // Yüklendiğinde
{
  Serial.begin(9600);            // 9600 baud Seri Haberleşmeyi Başlattık.
  Blynk.begin(auth, ssid, pass); // Blynki Başlatıp Ağa Bağladık.
  servo.attach(15);              //Servo Motoru Bağladığımız Pini Belirledik, D8'de Yazılabilir (15 Numaralı Pin NodeMCU'da D8 Pinine Karşılık Gelmekte) 
}

BLYNK_WRITE(V1) //Tanımladığımız V1 Pinine Yaz.
{
   servo.write(param.asInt()); // Blynk Üzerinden Bar ile 0-180 Aralığında Seçtiğimiz Değere Göre Motoru Hareket Ettirdik.
}
BLYNK_WRITE(V2) //Tanımladığımız V2 Pinine Yaz.
{
  servo.write(0); // Blynk Üzerinden Tanımladığımız Buton İle Motor 0 Derece'ye Hareket Etsin.
}
BLYNK_WRITE(V3) //Tanımladığımız V3 Pinine Yaz.
{
  servo.write(45); // Blynk Üzerinden Tanımladığımız Buton İle Motor 45 Derece'ye Hareket Etsin.
}
BLYNK_WRITE(V4) //Tanımladığımız V4 Pinine Yaz.
{
  servo.write(90); // Blynk Üzerinden Tanımladığımız Buton İle Motor 90 Derece'ye Hareket Etsin.
}
BLYNK_WRITE(V5) //Tanımladığımız V5 Pinine Yaz.
{ 
  servo.write(180); // Blynk Üzerinden Tanımladığımız Buton İle Motor 180 Derece'ye Hareket Etsin.
}

void loop() // Sonsuz Döngü.
{
  Blynk.run(); // Blynk Uygulamasını Sürekli Aktif Tuttuk.
}
