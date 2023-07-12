
#include<Servo.h>
#include<LiquidCrystal_I2C.h>
#include <Wire.h>

int sensor = 6;
Servo servo1;
LiquidCrystal_I2C lcd(0x27, 16, 2);//LCD Ekranımızın I2C adresinin "0x27" olduğunu ve 2 satır 16 sütundan oluştuğunu tanımlıyoruz

void setup() {
  servo1.attach(7);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  lcd.init(); //LCD Ekranımızı başlatıyoruz
  lcd.backlight();}

void loop() {
  int Yagmur = digitalRead(sensor); 
  
 
  
  if(Yagmur == HIGH){
    lcd.clear(); //LCD Ekranımızı temizliyoruz
    lcd.print("Yagmur: "); //LCD Ekranımızın ilk satırına "Yagmur:" yazısını yazdırıyoruz
    lcd.setCursor(0, 1); //LCD Ekranımızda "Yagmur: " yazısı ile yağmur durumunu belirten yazılar aynı satıra sığmayacağı için bir satır boşluk bırakıyoruz
    lcd.print("Yagmiyor"); //LCD Ekranımızın alt satırına "Yagmiyor" yazısını yazdırıyoruz
    Serial.println("Yağmur Yağmıyor"); //Seri Ekranımıza "Yağmur Yağmıyor" yazısını yazdırıyoruz
    servo1.write(0);
  
  }
  
  if(Yagmur == LOW){
    lcd.clear(); //LCD Ekranımızı temizliyoruz
    lcd.print("Yagmur: "); //LCD Ekranımızın ilk satırına "Yagmur:" yazısını yazdırıyoruz
    lcd.setCursor(0, 1); //LCD Ekranımızda "Yagmur: " yazısı ile yağmur durumunu belirten yazılar aynı satıra sığmayacağı için bir satır boşluk bırakıyoruz
    lcd.print("Yagiyor"); //LCD Ekranımızın alt satırına "Yagiyor" yazısını yazdırıyoruz
    Serial.println("Yağmur Yağıyor"); //Seri Ekranımıza "Yağmur Yağıyor" yazısını yazdırıyoruz
    servo1.write(180);
  }
   
   delay(1000); //Sensörümüzün sağlıklı ölçümler yapabilmesi için ölçümler arasına 300 milisaniyelik bir bekleme süresi bırakıyoruz
}