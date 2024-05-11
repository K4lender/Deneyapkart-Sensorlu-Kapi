/*
*   Hareket Sensörlü Kapı 
*/
#include <Deneyap_Servo.h>      // Deneyap Servo kütüphanesi eklenmesi 
#include <Deneyap_MesafeOlcerIsikAlgilayici.h> 

Servo servo1;                   // 1. servo motor için class tanımlanması
Servo servo2;                   // 2. servo motor için class tanımlanması
ProximityAL mesafe;

int yakinlik;
int mesafedegeri;

void setup() {  
  Serial.begin(115200);
  servo1.attach(D0);            // 1. servo motorun D3 pinin ve 0 kanal ayarlanması  /*attach(pin, channel=0, freq=50, resolution=12) olarak belirlenmiştir. Kullandığınız motora göre değiştirebilirsiniz */
  servo2.attach(D1,1);         // 2. servo motorun D4 pinin ve 1 kanal ayarlanması
  //isik.begin(0x23);
  mesafe.begin(0x23);

}

void loop() { 
  mesafedegeri = mesafe.getPSvalue();
  yakinlik = map(mesafedegeri, 2047, 0, 0, 2047); 
  Serial.print("Mesafe = ");
  Serial.println(yakinlik);
  
  if(yakinlik < 1800){
    servo1.write(90);
    servo2.write(0);
  }
  else {
    servo1.write(0);
    servo2.write(90);
  }
  delay(100);
}
