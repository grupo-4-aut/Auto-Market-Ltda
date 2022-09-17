//SERVO MOTOR
#include <Servo.h>

#define SERVO 6

Servo s; // Variável Servo
int pos; // Posição Servo
//SERVO MOTOR

//SENSOR INFRAVERMELHO
const int pinoLed = 4; //PINO DIGITAL UTILIZADO PELO LED
const int pinoSensor = 8; //PINO DIGITAL UTILIZADO PELO SENSOR
//SENSOR INFRAVERMELHO

void setup() {
  //SENSOR INFRAVERMELHO
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA
  digitalWrite(pinoLed, LOW); //LED INICIA DESLIGADO
  //SENSOR INFRAVERMELHO

  //SERVO MOTOR
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0);
  //SERVO MOTOR
}

void loop() {
  //SENSOR INFRAVERMELHO
  if (digitalRead(pinoSensor) == LOW) { //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
    digitalWrite(pinoLed, HIGH); //ACENDE O LED
    //SERVO MOTOR
    delay(1000);
    if (digitalRead(pinoSensor) == LOW) {
      for (pos = 0; pos < 90; pos++)
      {
        s.write(pos);
        delay(5);
      }
      delay(1000);
      for (pos = 90; pos >= 0; pos--)
      {
        s.write(pos);
        delay(5);
      }
    }
    //SERVO MOTOR

  } else { //SENÃO, FAZ
    digitalWrite(pinoLed, LOW); //APAGA O LED
  }
  //SENSOR INFRAVERMELHO
}
