/* 
 *  Yıldıray KARACA IoT1929 Kampı Hafta 2 İçin Arduino Problem Seti 3 Çözümü.
 *  mail: yildiraykaraca@icloud.com
 *  github: https://github.com/yildiraykaraca
*/
#include <Joystick.h> // Joystick Kütüphanesini Dahil Ettik.
#include <Servo.h>    // Servo Motor Kütüphanesini Dahil Ettik.

Servo servoMotor180; // 1. Servo Motorumuza servoMotor180 Adını Verdik.
Servo servoMotor90;  // 2. Servo Motorumuza servoMotor90 Adını Verdik.

Joystick_ Joystick;  // Joystick'i Oluşturduk.

const bool initAutoSendState=true; // Oyun Denetleyicisinin Durumunu Güncelledik ve Başlattık.

void setup()  // Yüklendiğinde
{
 Joystick.begin();           // Joystick'i Başlattık.
 servoMotor180.attach(5);    // 1. Servo Motorumuzu 5 Numaralı Pine Bağladık ve Kurulumunu Belirttik.
 servoMotor90.attach(6);     // 2. Servo Motorumuzu 6 Numaralı Pine Bağladık ve Kurulumunu Belirttik.
 Serial.begin(9600);         // 9600 baud Seri Haberleşmeyi Başlattık.
}

void loop() // Sonsuz Döngü
{
  int X_Deger = analogRead(A0); // X_Deger Adında Değişken Tanımlayıp A0 Pinine Bağladığımız 1. Potansiyometre Değerini Okuyup Bu Değişkene Atadık.
  X_Deger= map(X_Deger, 0,1023, 0,180); // Potansiyometre 0-1023 Arasında Değer Aldığından Ötürü Bunu Derece Olarak 180 Derece Döndürmek İçin Max 180'e Oranladık.
  Joystick.setXAxis(X_Deger);           // JoyStick İçin X Ekseni Değerini Ayarladık.
  servoMotor180.write(X_Deger);           // servoMotor1 'e X_Degerini Yazdırdık.
  
  int Y_Deger = analogRead(A1); // Y_Deger Adında Değişken Tanımlayıp A1 Pinine Bağladığımız 2. Potansiyometre Değerini Okuyup Bu Değişkene Atadık.
  Y_Deger = map(Y_Deger, 0,1023, 0,90); // Potansiyometre 0-1023 Arasında Değer Aldığından Ötürü Bunu Derece Olarak 90 Derece Döndürmek İçin Max 180'e Oranladık.
  Joystick.setYAxis(Y_Deger);  // JoyStick İçin Y Ekseni Değerini Ayarladık.
  servoMotor90.write(Y_Deger);  // servoMotor2 'e Y_Degerini Yazdırdık.
   
  Serial.println("Motor 1 Açı Degeri:" + String(X_Deger)); // Motorun Açı Değerini Seri Monitöre Yaz.
  Serial.println("Motor 2 Açı Degeri:" + String(Y_Deger)); // Motorun Açı Değerini Seri Monitöre Yaz.
  delay(50); // 50 Mili Saniye Bekle.
}
