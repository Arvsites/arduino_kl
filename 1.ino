#include <Servo.h>

Servo servo1;
Servo servo2;
int trigPin = 8; // назначаем имя для Pin8
int echoPin = 9; // назначаем имя для Pin9
 
void setup() { 
  Serial.begin (9600); // подключаем монитор порта
  pinMode(trigPin, OUTPUT); // назначаем trigPin (Pin8), как выход
  pinMode(echoPin, INPUT); // назначаем echoPin (Pin9), как вход
  servo1.attach(10);
  servo2.attach(11);
} 
 
void loop() { 
  int duration, cm; // назначаем переменную "cm" и "duration" для показаний датчика
  digitalWrite(trigPin, LOW); // изначально датчик не посылает сигнал
  delayMicroseconds(2); // ставим задержку в 2 ммикросекунд

  digitalWrite(trigPin, HIGH); // посылаем сигнал
  delayMicroseconds(10); // ставим задержку в 10 микросекунд
  digitalWrite(trigPin, LOW); // выключаем сигнал

  duration = pulseIn(echoPin, HIGH); // включаем прием сигнала

  cm = duration / 58; // вычисляем расстояние в сантиметрах

  if(cm>0 and cm<10){
    servo1.write(0);
    servo2.write(90);
  }
  else{
    servo1.write(90);
    servo2.write(0);
  }
  
  Serial.print(cm); // выводим расстояние в сантиметрах
  Serial.println(" cm");

}
