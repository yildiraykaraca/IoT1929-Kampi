/* 
 *  Yıldıray KARACA IoT1929 Kampı İçin Arduino Problem Seti 3 Tinkercad Üzerindeki Çözümü.
 *  mail: yildiraykaraca@icloud.com
 *  github: https://github.com/yildiraykaraca
*/
 
#define NemSensor A0      // Tinkercad'de Nem Sensörü Olmadığından POT'u Kontrol Edilebilir NEM Gibi Düşündüm :)
#define SicaklikSensor A1 // TMP36 İle Veri Okuyacağız.

void setup() //Yüklendiğinde
{
 	pinMode (NemSensor , INPUT) ;        // Değer Okuyacağımızdan POT Giriş. 
    pinMode (SicaklikSensor , INPUT ); // Değer Okuyacağımızdan TMP36 Giriş.
  	Serial.begin( 9600 ) ;             // Seri Haberleşmeyi Başlattık.
}

void loop() //Sonsuz Döngü
{
	int Sicaklik = analogRead(SicaklikSensor) ;                       // TMP36' Dan Gelen Veriyi Okuyarak Sicaklik Değişkenine Atadık.
    double Sicaklik_Deger = map( Sicaklik , 20 , 358 , -40 , 125) ; // Seri Monitörde 20,358 Değerini Gördüğümüzden TMP36 Ya Bu Değeri Oranladık ve Değeri Yeni Değişkene Atadık.
    
  	double Kelvin = (Sicaklik_Deger + 273);                         // Celsius Değerine 273 Ekleyerek Kelvini Hesapladık ve Bunu Ayrı  Değişkene Atadık.
    double Fahrenheit = ((1.8*Sicaklik_Deger)+273);                 // Celsius Değerine Göre Fahrenheit Hesapladık ve Bunu Ayrı Değişkene Atadık.
  
    int Nem_Miktari = analogRead(NemSensor);                        //POT Değerini Okuttuk ve Değişkene Atadık.
    int Nem = map( Nem_Miktari , 0 , 1023 , 0 , 150);               // Pot 0,1023 Arası Değer Verdiğinden Max Nemi 150 Baz Alarak Oranladık.  
      
    Serial.println("**********************************");
    Serial.println("Celsius: " + String(Sicaklik_Deger));           // Celsius'u Stringe Dönüştürerek Ekrana Yazdırdık.
    Serial.println("Kelvin: " + String(Kelvin)); 		                // Kelvin Değişkenini Stringe Dönüştürerek Ekrana Yazdırdık.
    Serial.println("Fahrenheit: " + String(Fahrenheit));            // Fahrenheit Değişkenini Stringe Dönüştürerek Ekrana Yazdırdık.
    Serial.println("Nem: " + String(Nem)); 				                  // Nem Değişkenini Stringe Dönüştürerek Ekrana Yazdırdık.
  	Serial.println("**********************************");
  	delay(1500);                                                    // 1.5 Saniye Beklettik.
}
