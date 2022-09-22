#include <Servo.h>

// pin declarations
#define SERVO 6

const int motor_pin = 4;
const int infrared1_pin = 8;

// vars
Servo s;
int servo_pos;
int any_product_lack = 1;

int product_here = 1;
int wanted_product = 1;

void setup()
{

    pinMode(infrared1_pin, INPUT);
    pinMode(pinoEsteira, OUTPUT);
    digitalWrite(motor_pin, LOW);

    s.attach(SERVO);
    Serial.begin(9600);
    s.write(0);
}

void loop()
{

    if (digitalRead(infrared1_pin) == LOW && product_here == wanted_product)
    {

        Serial.println("objeto na frente do sensor");
        Serial.println("esteira desligada");
        digitalWrite(motor_pin, LOW);

        delay(1000);

        if (digitalRead(infrared1_pin) == LOW)
        {

            Serial.println("objeto na frente do sensor");
            Serial.println("servo rodando");

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

        delay(2000);
    }

    else if (any_product_lack)
    {
        Serial.println("esteira");
        digitalWrite(motor_pin, HIGH);
    }
}
