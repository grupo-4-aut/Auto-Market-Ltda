
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(11, 10);


// pin declaration
#define SERVO1 6

const int motor_pin = 4;
const int ir1 = 8;
const int ir2 = 9;
const int ir3 = 12;


// vars
Servo s;
int servo_pos;
int any_product_lack = 1;

int product_here = 1;
int wanted_product = 1;

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(ir1, INPUT);
  pinMode(motor_pin, OUTPUT);
  digitalWrite(motor_pin, LOW);

  s.attach(SERVO1);
  Serial.begin(9600);
  s.write(0);
}

void servo() {
  //Serial.println("objeto na frente do sensor infravermelho");
  //Serial.println("servo ligado");

  // aciona o servo motor para a abertura da comporta
  for (servo_pos = 0; servo_pos < 90; servo_pos++)
  {
    s.write(servo_pos);
    delay(5);
  }
  delay(1000);
  for (servo_pos = 90; servo_pos >= 0; servo_pos--)
  {
    s.write(servo_pos);
    delay(5);
  }
}


void abrir_comporta() {
  if (digitalRead(ir1) == LOW)
  {
    servo();
  } else if (digitalRead(ir2) == LOW) {
    servo();
  } else if (digitalRead(ir3) == LOW) {
    servo();
  }
  delay(2000);
  digitalWrite(motor_pin, HIGH);
}


void loop()
{
  
  if (BT.available()) {
    char c = BT.read();
    Serial.println(c);
    if (c == 'q') {
      digitalWrite(motor_pin, LOW);
      servo();
      delay(3000);
    } else if (c == 't') {
      digitalWrite(motor_pin, LOW);
      delay(3000);
      digitalWrite(motor_pin, HIGH);
      delay(3000);
      digitalWrite(motor_pin, LOW);
    }
  }
  // checa se a caixa esta posicionada
  if (digitalRead(ir1) == LOW && (product_here == wanted_product))
  {

    //Serial.println("objeto na frente do sensor infravermelho");
    //Serial.println("motor desligado");
    digitalWrite(motor_pin, LOW);

    delay(1000);

    abrir_comporta();

    delay(2000);
    
    wanted_product = 0;
    digitalWrite(motor_pin, HIGH);
  }
  

  // aciona a esteira caso ainda exista algum produto a ser colocado na caixa
  else if (any_product_lack)
  {
    //Serial.println("servos desligados");
    //liga o motor
    digitalWrite(motor_pin, HIGH);
    //Serial.println("motor ligado");
    wanted_product = 1;
  }
  
}
