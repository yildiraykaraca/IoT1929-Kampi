/* 
 *  Yıldıray KARACA IoT1929 Kampı İçin Arduino Problem Seti 5 Çözümü.
 *  mail: yildiraykaraca@icloud.com
 *  github: https://github.com/yildiraykaraca
*/

#include <Servo.h> // Servo Kütüphanesini Dahil Ettik.
#define servoPin 3 // ServoPin ni 3. Pin Olarak Tanımladım.
Servo servoMotor;  // Servo Motora servoMotor Olarak Çağıracağım.
void setup()    
{
  servoMotor.attach(servoPin);  //servoMotor Kurulumunu Belirttim.
   servoMotor.write(0);         //servoMotoru Kurulumda 0 Dereceye Aldım.
}

void loop()

{
 
  for(int ileri=0; ileri<180; ileri = ileri+15) // 180 Derece Oluncaya Kadar 15 Arttır.
  
  {
    servoMotor.write(ileri); // servoMotoru Döngü Boyunca Hareket Ettir.
    delay(1000);             // 1000 Milisaniye = 1 Saniye Bekle.
  }
  
  // Servo Motor 180 Dereceye Kadar Döndü...
  
  for(int geri=180; geri>0; geri = geri-30) // 0 Derece Oluncaya Kadar -30 Azalt.
  
  {
   servoMotor.write(geri);   //servoMotoru Döngü Boyunca Hareket Ettir.
    delay(1000);             //1000 Milisaniye = 1 Saniye Bekle.
  }
}
