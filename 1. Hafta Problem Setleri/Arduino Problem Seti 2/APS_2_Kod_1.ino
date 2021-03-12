/* 
 *  Yıldıray KARACA IoT1929 Kampı İçin Arduino Problem Seti 2 Çözümü.
 *  mail: yildiraykaraca@icloud.com
 *  github: https://github.com/yildiraykaraca
*/
#define Kirmizi 2 //"Kirmizi" Adında 2 Numaralı Pine Bağlı Değişken Oluştur.
#define Sari 3    //"Sari" Adında 3 Numaralı Pine Bağı Değişken Oluştur.
#define Yesil 4   //"Yesil" Adında 4 Numaralı Pine Bağlı Değişken Oluştur.


void setup() // Yüklendiğinde
{
  for(int i = 2 ; i<5; i++) //Pin Numaralarını Baz Alarak Döngü Tanımladım.
  {
  pinMode(i,OUTPUT); //Döngüden Gelen Pin Numaralarında Led Olduğundan Ötürü Çıkış Gösterdim.
  }
}

void loop() // Sonsuz Döngüde.
{
  digitalWrite(Kirmizi, HIGH); //Kırmızı LED'i Yak.
  delay(10000);                //10000 Milisaniye = 10 Saniye Bekle.
   
  digitalWrite(Sari, HIGH);    //Sarı LED'i Yak.
  delay(12000);                //12000 Milisaniye = 12 Saniye Bekle.
  
  digitalWrite(Kirmizi, LOW);  //Kırmızı LED'i Söndür.
  digitalWrite(Sari, LOW);     //Sarı LED'i Söndür.
  
  digitalWrite(Yesil, HIGH);   //Yeşil LED'i Yak.
  delay(5000);                 //5000 Milisaniye = 5 Saniye Bekle.
  digitalWrite(Yesil, LOW);    //Yeşil LED'i Söndür.
}
