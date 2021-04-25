/* 
 *  Yıldıray KARACA IoT1929 Kampı İçin Arduino Problem Seti 1 Çözümü.
 *  mail: yildiraykaraca@icloud.com
 *  github: https://github.com/yildiraykaraca
*/
void setup()
{ 
  for(int LedSirasi = 2; LedSirasi<=6; LedSirasi++) //Pin Numaralarını Baz Alarak Döngü Tanımladım.
  {
    pinMode(LedSirasi, OUTPUT); //Döngüden Gelen Pin Numaralarında Led Olduğundan Ötürü Çıkış Gösterdim.
  }  
}
 
void loop() // Sonsuz Döngü.
{
   for(int Led_Sirasi_Sol =2; Led_Sirasi_Sol<=6; Led_Sirasi_Sol++) //Sol Led Pin Sırasını Baz Alarak Sağa Doğru Döngü Kurdum.
   {
     digitalWrite(Led_Sirasi_Sol, HIGH); //Döngüden Gelen Ledi Yak.
     delay(500); //Led Yandıktan Sonra 0.5 Saniye Bekle.
     digitalWrite(Led_Sirasi_Sol, LOW); //Döngüden Gelen Ledi Söndür.
     //delay(500); //Led Söndükten Sonra 0.5 Saniye Bekle.
   }
    for(int Led_Sirasi_Sag=6; Led_Sirasi_Sag>=2; Led_Sirasi_Sag--) //Sağ Led Pin Sırasını Baz Alarak Sola Doğru Döngü Kurdum.
     {
     digitalWrite(Led_Sirasi_Sag, HIGH); // Döngüden Gelen Ledi Yak.
     delay(500);  //Led Yandıktan Sonra 0.5 Saniye Bekle.
     digitalWrite(Led_Sirasi_Sag, LOW); //Döngüden Gelen Ledi Söndür.
   //delay(500);  //Led Söndükten Sonra 0.5 Saniye Bekle.
     }   
}
