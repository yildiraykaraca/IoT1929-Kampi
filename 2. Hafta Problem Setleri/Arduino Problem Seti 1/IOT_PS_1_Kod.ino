/* 
 *  Yıldıray KARACA IoT1929 Kampı Hafta 2 İçin IOT Problem Seti 1 Çözümü.
 *  mail: yildiraykaraca@icloud.com
 *  github: https://github.com/yildiraykaraca
*/
#define BLYNK_PRINT Serial      // Blynk İçin Kullanılan Nesneleri Tanımladık.
#include <ESP8266WiFi.h>        // ESP8266WiFi Kütüphanesini Dahil Ettik.
#include <BlynkSimpleEsp8266.h> // BlynkSimpleEsp8266 Kütüphanesini Dahil Ettik.

char auth[] = "Blynk_Token_Kodu";    // Blynk Uygulamasının Bize Göndermiş Olduğu Kodu Buraya Yazıyoruz.
char ssid[] = "Ağ_Adı";              // Modem Ağ Adımızı Bu Alana Yazdık.
char pass[] = "Ağ_Şifresi";          // Modem Ağ Şifremizi Bu Alana Yazdık.

#define Yesil_Led D6                         // "Yesil_Led" Adında D6 Numaralı Pine Bağlı Değişken Oluştur.
#define Kirmizi_Led D7                       // "Kirmizi_Led" Adında D7 Numaralı Pine Bağlı Değişken Oluştur.
#define Mavi_Led D8                          // "Mavi_Led" Adında D8 Numaralı Pine Bağlı Değişken Oluştur.
int butonDurumu;                             // Şaka İçin butonDurumu Adında Değişken Tanımladım.

void setup()  // Yüklendiğinde
{
  Serial.begin(9600);            // 9600 baud Seri Haberleşmeyi Başlattık.
  Blynk.begin(auth, ssid, pass); // Blynki Başlatıp Ağa Bağladık.
  pinMode(Yesil_Led, OUTPUT);           // Nodemcu Üzerinden D6 Pinini Çıkış Olarak Belirttik.
  pinMode(Kirmizi_Led, OUTPUT);           // Nodemcu Üzerinden D7 Pinini Çıkış Olarak Belirttik.
  pinMode(Mavi_Led, OUTPUT);           // Nodemcu Üzerinden D8 Pinini Çıkış Olarak Belirttik.
}

BLYNK_WRITE(V0)  //Tanımladığımız V0 Pinine Yaz.
{             
 butonDurumu= param.asInt(); // butonDurumunu Değişkeni Uygulama Üzerinden 0 veya 1 Olarak Değer Alacak. Bu Değeri Değişkene Atadık.
 if(butonDurumu==1) // Eğer butonDurumu Değişkeni 1 Değerine Eşit İse Yani Buton Aktif Olduğunda
    {
      digitalWrite(Yesil_Led , HIGH); // Yeşil LED'i Yak
      delay(5000);           // 5000 Milisaniye = 5 Saniye Bekle.
      digitalWrite(Yesil_Led , LOW);  // Yeşil LED'i Söndür.
      digitalWrite(Kirmizi_Led , HIGH); // Kırmızı LED'i Yak.
      delay(5000);           // 5000 Milisaniye = 5 Saniye Bekle. 
      digitalWrite(Kirmizi_Led , LOW);  // Kırmızı LED'i Söndür.
      digitalWrite(Mavi_Led , HIGH); // Mavi LED'i Yak.
      delay(5000);           // 5000 Milisaniye = 5 Saniye Bekle.
      digitalWrite(Mavi_Led , LOW);  // Mavi LED'i Söndür.
    }
else // Değilse
    {
     digitalWrite(Yesil_Led , LOW); // Yeşil LED'i Söndür.
     digitalWrite(Kirmizi_Led , LOW); // Kırmızı LED'i Söndür.
     digitalWrite(Mavi_Led , LOW);   // Mavi LED'i Söndür.
    }
}

void loop()  // Sonsuz Döngü.
{ 
  Blynk.run();  // Blynk Uygulamasını Sürekli Aktif Tuttuk.                          
}
