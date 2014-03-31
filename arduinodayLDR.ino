#include <LiquidCrystal.h>

////////////////////////////////////////////////////////////////////////////////////////////////
//  Este programinha lê os dados vindo de um LDR(Light Dependent Resistor) e verifica se está //
//  muito claro ou muito escuro, enviando essa verificação para o LCD e acendendo os LEDs     //
//  correspondentes.                                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////

#define       rawLDR 3            //Definindo a constante do LDR
double        inte;               //Variável que irá receber os dados do LDR 
int           led1 = 8;           //Variável que irá definir a saída do primeiro led
int           led2 = 7;           //Variável que irá definir a saída do segundo led
LiquidCrystal lcd(12,11,5,4,3,2); //Inicializando o LCD Display

void setup(){
  //Definindo os pinos dos LEDs como saída
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  //Iniciando o Display
  lcd.begin(16,2);
}

void loop() {
  inte = analogRead(rawLDR); //Lendo os dados do LDR e colocando-os na variável inte
  lcd.clear();               //Limpa as linhas do LCD e seta o Cursor em (0,0)
  lcd.print("Intensidade:"); //Escreve na primeira linha
  lcd.setCursor(0,1);        //Seta o cursor para o começo da segunda linha
  //  Verifica os dados vindo do LDR em inte, escreve no LCD se está 
  //  Escuro, Claro ou Bom e acende os respectivo LEDs
  if (inte < 700) {
    //Se inte for menor que 700
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    lcd.print("Escuro");
  } else if (inte > 800) {
    //Se inte for maior que 800
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    lcd.print("Claro");
    //Se inte for menor que 800 e maior que 700
  } else {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    lcd.print("Bom");
  }
  
}
