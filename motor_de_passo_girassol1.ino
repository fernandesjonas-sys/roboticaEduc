// C++ code
//
#include <Servo.h>
Servo motor1;
int sensor1 = A0;
int sensor2 = A1;
int led1 = 2;
int leituraS1 = 0;
int leituraS2 =0;
int posicao = 90;
int tolerancia = 60;
int limiteMinimo = 60;
int limiteMaximo = 140;
int sentido = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(led1, OUTPUT);
  motor1.attach(7);
  motor1.write(posicao);
  
}

void loop()
{
  leituraS1 = analogRead(sensor1);
  leituraS2 = analogRead(sensor2);
  int diferenca = leituraS1 - leituraS2;
  int novaPosicao = posicao;
  if (diferenca > tolerancia){
  novaPosicao = posicao + sentido;
   } else if (diferenca < -tolerancia){
  novaPosicao = posicao - sentido;
  }
  novaPosicao = constrain(novaPosicao, limiteMinimo, limiteMaximo);
  if (novaPosicao != posicao) {
    posicao = novaPosicao;
    motor1.write(posicao);
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
  Serial.print("LDR 1: ");
  Serial.print(leituraS1);
  Serial.print(" | LDR 2: ");
  Serial.print(leituraS2);
  Serial.print(" | Angulo: ");
  Serial.println(posicao);
  
  delay(30);
}
