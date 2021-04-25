/* 
 *  Yıldıray KARACA IoT1929 Kampı Hafta 3 İçin Arduino Problem Seti 1 Çözümü.
 *  mail: yildiraykaraca@icloud.com
 *  github: https://github.com/yildiraykaraca
*/
#include <SPI.h>     //SPI Kütüphanesini Dahil Ettik.
#include <MFRC522.h> //MFRC522 Kütüphanesini Dahil Ettik.

#define SS_PIN D4  //RC522 Modülü Chip Select Pinini (SDA) Tanımlıyoruz.
#define RST_PIN D3 //RC522 Modülü Reset Pinini Tanımlıyoruz.

int YesilLed = D0;   //Kirmizi Led'imizi Tanımlıyıp Değişkene Atadık.
int KirmiziLed = D8; //Yeşil Led'imizi Tanımlıyıp Değişkene Atadık.

//KARTLARI TANIMLADIK
byte Kullanici1[4] = {151, 111, 244, 216}; //RFID Kartı UID Numarası.
byte Kullanici2[4] = {92, 204, 95, 34};    //RFID Anahtar UID Numarası.
byte Kullanici3[4] = {21, 132, 178, 219};  //Üniversite Kimliği UID Numarası. (Örnek Kart).

// byte Kullanici4[4] = {144 203 105 122};   //Otobüs Kartı UID Numarası. (Örnek Kart - Devre Dışı). 

MFRC522 rfid(SS_PIN, RST_PIN);  //RC522 Modülü Ayarlarını Yaptık. 

void setup()  //Yüklendiğinde.
{
  Serial.begin(9600);  //9600 Baud Seri Haberleşmeyi Başlattık.

  SPI.begin();               //SPI İletişimini Başlattık.
  rfid.PCD_Init();           //RC522 Modülünü Başlattık.
  
  pinMode(YesilLed, OUTPUT);   //Yeşil Led'i Çıkış Gösterdik.
  pinMode(KirmiziLed, OUTPUT); //Kırmızı Led'i Çıkış Gösterdik.
}

void KartYazdir()  // Kart ID Alması İçin Fonksiyon.
{
  Serial.print("ID Numarasi: ");  // Seri Porta Yaz.
  for (int sayac = 0; sayac < 4; sayac++)  // 
  {
    Serial.print(rfid.uid.uidByte[sayac]); //Gelen Kart Verisini Dizi Olarak Seri Porta Yaz.
    Serial.print(" ");                     //Aralarına Birer Boşluk Bırak.
  }
  Serial.println("");                      //Alt Satıra Geç.
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) //Eğer Yeni Kartın Okunmasını Bekleyene Kadar.
    return;                          //Dön
  if (!rfid.PICC_ReadCardSerial())   //Eğer Kart'ın ID 'si Okununcaya Kadar.
    return;                          //Dön
  
  if (  rfid.uid.uidByte[0] == Kullanici1[0] && //Eğer Okunan Kartın 0. Dizisi Eşitse Kullanici1'in 0. Dizisine VE.
        rfid.uid.uidByte[1] == Kullanici1[1] && //Eğer Okunan Kartın 1. Dizisi Eşitse Kullanici1'in 1. Dizisine VE.
        rfid.uid.uidByte[2] == Kullanici1[2] && //Eğer Okunan Kartın 2. Dizisi Eşitse Kullanici1'in 2. Dizisine VE.
        rfid.uid.uidByte[3] == Kullanici1[3]    //Eğer Okunan Kartın 3. Dizisi Eşitse Kullanici1'in 3. Dizisine.
     ) 

     {
          Serial.println("_____________________________________________"); //Seri Porta Yaz.
          Serial.println("Daire No:3");                                    //Seri Porta Yaz.
          Serial.println("Hoşgeldiniz: Sayın Yıldıray K.");                //Seri Porta Yaz.
          KartYazdir();                                                    //Kartın UID'sini Yazdırmak İçin Olan Fonksiyonu Çağır ve Kartın UID'sini Yaz.
          digitalWrite(YesilLed, HIGH);                                    //Yeşil Led'i Yak.
          delay(500);                                                      //500 Milisaniye - 0.5 Saniye Bekle.
          digitalWrite(YesilLed, LOW);                                     //Yeşil Led'i Söndür.
          Serial.println("İyi Günler...!");                                //Seri Porta Yaz.
          Serial.println("_____________________________________________"); //Seri Porta Yaz.
          Serial.println(" ");                                             //Seri Portta Bir Boşluk Bırak.
     } 

  else if (  rfid.uid.uidByte[0] == Kullanici2[0] &&  //Değilse Eğer Okunan Kartın 0. Dizisi Eşitse Kullanici2'in 0. Dizisine VE.
             rfid.uid.uidByte[1] == Kullanici2[1] &&  //Değilse Eğer Okunan Kartın 1. Dizisi Eşitse Kullanici2'in 1. Dizisine VE.
             rfid.uid.uidByte[2] == Kullanici2[2] &&  //Değilse Eğer Okunan Kartın 2. Dizisi Eşitse Kullanici2'in 2. Dizisine VE.
             rfid.uid.uidByte[3] == Kullanici2[3]     //Değilse Eğer Okunan Kartın 3. Dizisi Eşitse Kullanici2'in 3. Dizisine.
          ) 
          {
          Serial.println("_____________________________________________"); //Seri Porta Yaz.
          Serial.println("Daire No:5");                                    //Seri Porta Yaz.
          Serial.println("Hoşgeldiniz: Sayın Yusuf A.");                   //Seri Porta Yaz.
          KartYazdir();                                                    //Kartın UID'sini Yazdırmak İçin Olan Fonksiyonu Çağır ve Kartın UID'sini Yaz.
          digitalWrite(YesilLed, HIGH);                                    //Yeşil Led'i Yak.
          delay(500);                                                      //500 Milisaniye - 0.5 Saniye Bekle.
          digitalWrite(YesilLed, LOW);                                     //Yeşil Led'i Söndür.
          Serial.println("İyi Günler...!");                                //Seri Porta Yaz.
          Serial.println("_____________________________________________"); //Seri Porta Yaz.
          Serial.println(" ");                                             //Seri Portta Bir Boşluk Bırak.
         } 
  else if (  rfid.uid.uidByte[0] == Kullanici3[0] && //Değilse Eğer Okunan Kartın 0. Dizisi Eşitse Kullanici3'in 0. Dizisine VE.
             rfid.uid.uidByte[1] == Kullanici3[1] && //Değilse Eğer Okunan Kartın 1. Dizisi Eşitse Kullanici3'in 1. Dizisine VE.
             rfid.uid.uidByte[2] == Kullanici3[2] && //Değilse Eğer Okunan Kartın 2. Dizisi Eşitse Kullanici3'in 2. Dizisine VE.
             rfid.uid.uidByte[3] == Kullanici3[3]    //Değilse Eğer Okunan Kartın 3. Dizisi Eşitse Kullanici3'in 3. Dizisine.
          ) 
          {
          Serial.println("_____________________________________________"); //Seri Porta Yaz.
          Serial.println("Daire No:7");                                    //Seri Porta Yaz.
          Serial.println("Hoşgeldiniz: Sayın Bensu N.");                   //Seri Porta Yaz.
          KartYazdir();                                                    //Kartın UID'sini Yazdırmak İçin Olan Fonksiyonu Çağır ve Kartın UID'sini Yaz.
          digitalWrite(YesilLed, HIGH);                                    //Yeşil Led'i Yak.
          delay(500);                                                      //500 Milisaniye - 0.5 Saniye Bekle.
          digitalWrite(YesilLed, LOW);                                     //Yeşil Led'i Söndür.
          Serial.println("İyi Günler...!");                                //Seri Porta Yaz.
          Serial.println("_____________________________________________"); //Seri Porta Yaz.
          Serial.println(" ");                                             //Seri Portta Bir Boşluk Bırak.
              
          }

// 4. Kullanıcıyı Devre Dışı Bıraktık. 
/* 
    else if ( rfid.uid.uidByte[0] == Kullanici4[0] && //Değilse Eğer Okunan Kartın 0. Dizisi Eşitse Kullanici4'in 0. Dizisine VE.
              rfid.uid.uidByte[1] == Kullanici4[1] && //Değilse Eğer Okunan Kartın 1. Dizisi Eşitse Kullanici4'in 1. Dizisine VE.
              rfid.uid.uidByte[2] == Kullanici4[2] && //Değilse Eğer Okunan Kartın 2. Dizisi Eşitse Kullanici4'in 2. Dizisine VE.
              rfid.uid.uidByte[3] == Kullanici4[3]    //Değilse Eğer Okunan Kartın 3. Dizisi Eşitse Kullanici4'in 3. Dizisine VE.
          ) 
          {
          Serial.println("_____________________________________________");
          Serial.println("Daire No:5");
          Serial.println("Hoşgeldiniz: Sayın Bensu N.");
          KartYazdir();
          digitalWrite(YesilLed, HIGH);
          delay(500);
          digitalWrite(YesilLed, LOW);
          Serial.println("İyi Günler...!");
          Serial.println("_____________________________________________");
          Serial.println(" ");
         }  
*/
  else  // Değilse Hiç Bir Koşul Sağlanmadığı Takdirde.                
         { 
         Serial.println("_____________________________________________"); //Seri Porta Yaz.
         Serial.println("Yetkisiz Kart");                                 //Seri Porta Yaz.
         KartYazdir();                                                    //Kartın UID'sini Yazdırmak İçin Olan Fonksiyonu Çağır ve Kartın UID'sini Yaz.
         Serial.println("Kart Tanimlanmadi ! ");                          //Seri Porta Yaz.     
         Serial.println("Giris Basarisiz. ");                             //Seri Porta Yaz.
         Serial.println("_____________________________________________"); //Seri Porta Yaz.
         Serial.println(" ");                                             //Seri Portta Bir Boşluk Bırak.

         for(int i=0; i<4; i++) // i Değişkeni 4 Ten Küçük Oluncaya Kadar.
         {
         digitalWrite(KirmiziLed, HIGH); // Kırmızı Led'i Yak.
         delay(100);                     // 100 Milisaniye 0.1 Saniye Bekle.
         digitalWrite(KirmiziLed, LOW);  // Kırmızı Led'i Söndür.
         delay(100);                     // 100 Milisaniye 0.1 Saniye Bekle.         
         }

         }
  rfid.PICC_HaltA(); //RFID Yeni Bir Kart Okumaya Hazır.
}
