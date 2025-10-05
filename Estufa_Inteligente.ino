//Bibliotecas
#include <LiquidCrystal_I2C.h> 
#include <Wire.h>

//Configura I2C
#define endereco   0x27
#define colunas 16
#define linhas  2

//Chamada do display
LiquidCrystal_I2C lcd (endereco, colunas, linhas);

bool umidade(int estado);

void setup() {

  //Leds
  pinMode(4, OUTPUT); // Verde
  pinMode(5, OUTPUT); // Amarelo
  pinMode(6, OUTPUT); // Azul

  //Sensor
  pinMode(8, INPUT); //Sensor de umidade

  //Configuração do display
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

}

void loop() {
  
    int retorno_umisolo, estado;
    
    retorno_umisolo =  umidade(estado);

  //Solo seco - nível alto no sensor
  if (retorno_umisolo == 1){
    lcd.print("BOMBA LIGADA:");
    lcd.setCursor(0, 1);
    lcd.print("SOLO SECO");
    delay(2000);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
    //Solo úmido - nível baixo no sensor
    else{
    lcd.print("BOMBA DESLIGADA:");
    lcd.setCursor(0, 1);
    lcd.print("SOLO UMIDO");
    delay(2000);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    }
    lcd.clear();
}

  //Leitura do sensor e retorno
  bool umidade(int estado){

    int leitura;

        leitura = digitalRead(8);
          Serial.print("Umidade: ");
          Serial.println(leitura);
          delay(1000);

        return leitura;
  
  }
