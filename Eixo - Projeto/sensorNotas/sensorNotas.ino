//Programa: Leitor de cedulas
//Grupo: Diego, Pablo, Leonardo e Adamo
 
#include <Wtv020sd16p.h>

//Pinos de conexao do modulo TCS230
const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;
 
//Variaveis cores
int red = 0;
int green = 0;
int blue = 0;

//constantes do wtv020SD
int resetPin = 4;  //Pino Reset
int clockPin = 5;  //Pino clock
int dataPin = 6;   //Pino data (DI)
int busyPin = 7;   //Pino busy


Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);
 
void setup() {
  //Inicializa o modulo WTV020
  wtv020sd16p.reset();

  //Definindo função das portas
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  Serial.begin(9600);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
}
 
void loop() {
  //Detecta a cor
  color();
  
  //Mostra valores no serial monitor
  Serial.print("Vermelho :");
  Serial.print(red, DEC);
  Serial.print(" Verde : ");
  Serial.print(green, DEC);
  Serial.print(" Azul : ");
  Serial.print(blue, DEC);
  Serial.println();
 
  //Verifica se é nota de 2 reais
  if (blue > 190 && green < 90 && red < green) {
    Serial.println("NOTA DE DOIS REAIS");
    wtv020sd16p.playVoice(0);
    //Reproduz o arquivo 1
    wtv020sd16p.asyncPlayVoice(1);
    delay(3000); 
    wtv020sd16p.stopVoice();
    delay(2000);
  }
  
    //Verifica se é nota de 5 reais
  if (blue < 100 && green < 60 && red > 130) {
    Serial.println("NOTA DE CINCO REAIS");
    Serial.println("Reproduzindo 0002.ad4");
    wtv020sd16p.playVoice(0);
    //Reproduz o arquivo 2
    wtv020sd16p.asyncPlayVoice(2);
    delay(3000);
    wtv020sd16p.stopVoice();
    delay(2000);
  }
  
    //Verifica se é nota de 10 reais
  if (blue < 110 && green < 110 && red > 230 ) {
    Serial.println("NOTA DE DEZ REAIS");
    Serial.println("Reproduzindo 0003.ad4");
    wtv020sd16p.playVoice(0);
    //Reproduz o arquivo 3
    wtv020sd16p.asyncPlayVoice(3);
    delay(3000);
    wtv020sd16p.stopVoice();
    delay(2000);
  }
  
    //Verifica se é nota de 20 reais
  if (blue < 50 && green > 150 && red > 200) {
    Serial.println("NOTA DE VINTE REAIS");
    Serial.println("Reproduzindo 0004.ad4");
    wtv020sd16p.playVoice(0);
    //Reproduz o arquivo 4
    wtv020sd16p.asyncPlayVoice(4);
    delay(3000);
    wtv020sd16p.stopVoice();
    delay(2000);
  }

    //Verifica se é nota de 50 reais
  if (blue > 70 && green > 150 && red > 200) {
    Serial.println("NOTA DE CINQUENTA REAIS");
    Serial.println("Reproduzindo 0005.ad4");
    wtv020sd16p.playVoice(0);
    //Reproduz o arquivo 5
    wtv020sd16p.asyncPlayVoice(5);
    delay(3000);
    wtv020sd16p.stopVoice();
    delay(2000);
  }

    //Verifica se é nota de 100 reais
  if (blue > 200 && green < 165 && red < 60) {
    Serial.println("NOTA DE CEM REAIS");
    Serial.println("Reproduzindo 0006.ad4");
    wtv020sd16p.playVoice(0);
    //Reproduz o arquivo 6
    wtv020sd16p.asyncPlayVoice(6);
    delay(3000);
    wtv020sd16p.stopVoice();
    delay(2000);
  }
 
  Serial.println(); //dar um espaço
 
}

 //Função da identificação das cores
 
void color() {
  //Rotina que le o valor das cores
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //count OUT, pRed, RED
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  //count OUT, pBLUE, BLUE
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  //count OUT, pGreen, GREEN
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
