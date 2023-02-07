
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(11, 10); //...(RX, TX);


// pin declaration
#define SERVO1 5
#define SERVO2 6
#define SERVO3 7
#define SERVO4 4
const int motor_pin = 13;
#define CAPACITIVO 12 //sensor que detecta a caixa
//const int ir1 = 8;
//const int ir2 = 9;
//const int ir3 = 12;


// vars
Servo silo1;
Servo silo2;
Servo silo3;
Servo ySaida;

int servo_pos;
int any_product_lack = 1;

int product_here = 1;
int wanted_product = 1;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

 // pinMode(ir1, INPUT);
  pinMode(motor_pin, OUTPUT);
  digitalWrite(motor_pin, LOW);

  silo1.attach(SERVO1);    //prox motor correia
  silo2.attach(SERVO2);
  silo3.attach(SERVO3);
  ySaida.attach(SERVO4);
  Serial.begin(9600);
  silo1.write(0);
  silo2.write(0);
  silo3.write(0);
  ySaida.write(45);
}

void loop() {

  /*
  E → LIGA MOTOR ESTEIRA
  F → DESLIGA MOTOR ESTEIRA
  L → MOTOR 1
  M → MOTOR 2
  N → MOTOR 3
  Q → MOTOR 1 e 2
  W → MOTOR 1 e 3
  R → MOTOR 2 e 3
  T → MOTOR 1, 2 e 3
  O → MOTOR SAIDA DELIVERY
  S → MOTOR SAIDA LOJA FISICA
  U → MOTOR SAIDA REINICIA - AO CONCLUIR COMPRA
  */

  if (BT.available()) {
    char c = BT.read();
  //if (Serial.available()) {
    //char c = Serial.read();
    Serial.println(c);

    //MOTOR ESTEIRA
    if(c == 'E'){
      digitalWrite(motor_pin, HIGH);
    }

    else if(c == 'F'){
      digitalWrite(motor_pin, LOW);
    }

    //MOTOR SAIDA DELIVERY
    else if(c == 'O'){
      ySaida.write(0);
    }

    //MOTOR SAIDA LOJA FISICA
    else if(c == 'S'){
      ySaida.write(90);
    }

    //MOTOR SAIDA REINICIA - AO CONCLUIR COMPRA
    else if(c == 'U'){
      ySaida.write(45);
    }

    //MOTOR 1
    else if (c == 'L') {
      digitalWrite(motor_pin, HIGH);
      delay(1800);  //TEMPO PRODUTO 1
      digitalWrite(motor_pin, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        silo1.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        silo1.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_pin, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_pin, LOW);
    } 

    //MOTOR 2
    else if (c == 'M') {
      digitalWrite(motor_pin, HIGH);
      delay(3600);  //TEMPO PRODUTO 2
      digitalWrite(motor_pin, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        silo2.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        silo2.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_pin, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_pin, LOW);
    }

    //MOTOR 3
    else if (c == 'N') {
      digitalWrite(motor_pin, HIGH);
      delay(5100);  //TEMPO PRODUTO 3
      digitalWrite(motor_pin, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        silo3.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        silo3.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_pin, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_pin, LOW);
    }

    //MOTOR 1 E MOTOR 2
    else if (c == 'Q') {
      digitalWrite(motor_pin, HIGH);
      delay(1800);  //TEMPO PRODUTO 1
      digitalWrite(motor_pin, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        silo1.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        silo1.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_pin, HIGH);
      delay(1650);  //TEMPO PRODUTO 2
      digitalWrite(motor_pin, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        silo2.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        silo2.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_pin, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_pin, LOW);
    }

    //MOTOR 1 E MOTOR 3
    else if (c == 'W') {
      digitalWrite(motor_pin, HIGH);
      delay(1800);  //TEMPO PRODUTO 1
      digitalWrite(motor_pin, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        silo1.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        silo1.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_pin, HIGH);
      delay(3300);  //TEMPO PRODUTO 3
      digitalWrite(motor_pin, LOW);
      
      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        silo3.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        silo3.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_pin, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_pin, LOW);
    }

    //MOTOR 2 E MOTOR 3
    else if (c == 'R') {
      digitalWrite(motor_pin, HIGH);
      delay(3500);  //TEMPO PRODUTO 2
      digitalWrite(motor_pin, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        silo2.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        silo2.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_pin, HIGH);
      delay(1600);  //TEMPO PRODUTO 3
      digitalWrite(motor_pin, LOW);
      
      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        silo3.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        silo3.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_pin, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_pin, LOW);
    }

    //MOTOR 1, 2 e 3
    else if (c == 'T') {
      digitalWrite(motor_pin, HIGH);
      delay(1800);  //TEMPO PRODUTO 1
      digitalWrite(motor_pin, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        silo1.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        silo1.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_pin, HIGH);
      delay(1600);  //TEMPO PRODUTO 2
      digitalWrite(motor_pin, LOW);
      
      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        silo2.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        silo2.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_pin, HIGH);
      delay(1600);  //TEMPO PRODUTO 3
      digitalWrite(motor_pin, LOW);
      
      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        silo3.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        silo3.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_pin, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_pin, LOW);
    }
  }
}
