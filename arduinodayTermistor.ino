#include <math.h>

/////////////////////////////////////////////////////////////////////////
// Programa para calcular a temperatura ambiente utilizando a equação  //
// de Steinhart-Hart para termistores e enviar por Serial.             //
/////////////////////////////////////////////////////////////////////////

#define     Term 0  //Definindo a constante do termistor
double      temp;   //Variável que irá receber os dados do LDR


double Thermistor(int RawADC) {
  //Equação de Steinhart-Hart para termistores
  double Temp;
  Temp = log(10000.0*((1024.0/RawADC-1))); 
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;              // Convertendo Kelvin para Celcius
//  Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convertendo Celcius para Fahrenheit
  return Temp;
}

void setup() {
  //Iniciando a porta Serial em 9600 baud
  Serial.begin(9600);
}

void loop() {
  temp = Thermistor(analogRead(Therm))  //Lendo os dados vindo do Termistor e transformando-os em Celsius
  //Printando a temperatura em Celsius no Serial
  Serial.print("Celsius: ");
  Serial.print("temp");
  Serial.println("ºC");
}
