void setup() {
  // put your setup code here, to run once:
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

    //MOTOR ESTEIRA
    if(c == 'E'){
      digitalWrite(motor_esteira, HIGH);
    }

    else if(c == 'F'){
      digitalWrite(motor_esteira, LOW);
    }

    //MOTOR SAIDA DELIVERY
    else if(c == 'O'){
      motorsaida.write(0);
    }

    //MOTOR SAIDA LOJA FISICA
    else if(c == 'S'){
      motorsaida.write(90);
    }

    //MOTOR SAIDA REINICIA - AO CONCLUIR COMPRA
    else if(c == 'U'){
      motorsaida.write(45);
    }

    //MOTOR 1
    else if (c == 'L') {
      digitalWrite(motor_esteira, HIGH);
      delay(1000);  //TEMPO PRODUTO 1
      digitalWrite(motor_esteira, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        motor1.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        motor1.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_esteira, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_esteira, LOW);
    } 

    //MOTOR 2
    else if (c == 'M') {
      digitalWrite(motor_esteira, HIGH);
      delay(2000);  //TEMPO PRODUTO 2
      digitalWrite(motor_esteira, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        motor1.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        motor1.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_esteira, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_esteira, LOW);
    }

    //MOTOR 3
    else if (c == 'N') {
      digitalWrite(motor_esteira, HIGH);
      delay(3000);  //TEMPO PRODUTO 3
      digitalWrite(motor_esteira, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        motor1.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        motor1.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_esteira, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_esteira, LOW);
    }

    //MOTOR 1 E MOTOR 2
    else if (c == 'Q') {
      digitalWrite(motor_esteira, HIGH);
      delay(1000);  //TEMPO PRODUTO 1
      digitalWrite(motor_esteira, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        motor1.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        motor1.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_esteira, HIGH);
      delay(1000);  //TEMPO PRODUTO 2
      digitalWrite(motor_esteira, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        motor2.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        motor2.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_esteira, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_esteira, LOW);
    }

    //MOTOR 1 E MOTOR 3
    else if (c == 'W') {
      digitalWrite(motor_esteira, HIGH);
      delay(1000);  //TEMPO PRODUTO 1
      digitalWrite(motor_esteira, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        motor1.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        motor1.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_esteira, HIGH);
      delay(2000);  //TEMPO PRODUTO 3
      digitalWrite(motor_esteira, LOW);
      
      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        motor3.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        motor3.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_esteira, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_esteira, LOW);
    }

    //MOTOR 2 E MOTOR 3
    else if (c == 'R') {
      digitalWrite(motor_esteira, HIGH);
      delay(2000);  //TEMPO PRODUTO 2
      digitalWrite(motor_esteira, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        motor2.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        motor2.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_esteira, HIGH);
      delay(1000);  //TEMPO PRODUTO 3
      digitalWrite(motor_esteira, LOW);
      
      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        motor3.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        motor3.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_esteira, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_esteira, LOW);
    }

    //MOTOR 1, 2 e 3
    else if (c == 'T') {
      digitalWrite(motor_esteira, HIGH);
      delay(1000);  //TEMPO PRODUTO 1
      digitalWrite(motor_esteira, LOW);

      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        motor1.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        motor1.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_esteira, HIGH);
      delay(1000);  //TEMPO PRODUTO 2
      digitalWrite(motor_esteira, LOW);
      
      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        motor2.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        motor2.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_esteira, HIGH);
      delay(1000);  //TEMPO PRODUTO 3
      digitalWrite(motor_esteira, LOW);
      
      for (servo_pos = 0; servo_pos < 180; servo_pos++) {
        motor3.write(servo_pos);
        delay(5);
      }
      delay(1000);
      for (servo_pos = 180; servo_pos >= 0; servo_pos--) {
        motor3.write(servo_pos);
        delay(5);
      }

      digitalWrite(motor_esteira, HIGH);
      delay(10000);  //TEMPO PRODUTO CAIR
      digitalWrite(motor_esteira, LOW);
    }
  }
}
