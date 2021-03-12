/* 
 *  Yıldıray KARACA IoT1929 Kampı İçin Arduino Problem Seti 4 Çözümü.
 *  mail: yildiraykaraca@icloud.com
 *  github: https://github.com/yildiraykaraca
*/
 
#define POT A0   // A0 Pinini POT Adında Tutturdum.
#define DC 3     // 3. Pini DC Adında Tutturdum.
#define LED 2    // 2. Pini LED Adında Tutturdum.

int Pot_Deger=0; // Potansiyometre Değeri İçin Oluşturduğum Değişken.
int Rpm_Deger=0; // Ledi Yaktırmak İçin Kullanacağım Değişken.
  
void setup()
{
      pinMode(DC,OUTPUT);    // DC Motor çıkış.
      pinMode(LED,OUTPUT);   // LED bir çıkış.
      Serial.begin(9600);    // Seri Haberleşmeyi Başlattım.
}

void loop()
{
   Pot_Deger=analogRead(POT); // Potansiyometre Değerini Okuyup Oluşturduğum Değikenime Atadım.
   Pot_Deger= map(Pot_Deger, 0, 1023, 0, 255); // PWM Pini 0-255 Arasında İşlem Yaptığından Oranı Sabitleyerek Pot Değeriyle Oranladım.
      
   analogWrite(DC,Pot_Deger); // Oranladığım Pot Değerinden Gelen PWM İçin Uygun Değeri DC Motora Yazdırdım.
      
   Rpm_Deger=map(Pot_Deger, 0, 255, 0, 5555); // Oranladığım Değer 0,255 olduğundan Rpmi Hesaplamak İçin Oran Orantı Yaptım.  
   
      
   if(Rpm_Deger>2700)         // Eğer Rpm Değeri 2700 Den Yüksek ise 
   {
     digitalWrite(LED, HIGH); //Ledi Yak
   }  
   
   else   // Değilse
   { 
     digitalWrite(LED,LOW); // Ledi Kapat 
   }
     
   Serial.print("POT DEGERI: " + String(Pot_Deger));   // POT Değerini Seri Monitöre Yazdırdım.
   Serial.println(" RPM HIZI: " + String(Rpm_Deger));  // RPM Değerini Seri Monitöre Yazdırdım 
  
   delay(250); // 250 Milisaniye = 0.25 Saniye Bekle
}
