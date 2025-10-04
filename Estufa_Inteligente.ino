#include <LiquidCrystal_I2C.h>

#include <Wire.h>


#define endereco   0x27
#define colunas 16
#define linhas  2

LiquidCrystal_I2C lcd (endereco, colunas, linhas);

void setup() {
  pinMode(4, OUTPUT);
  lcd.init();
  lcd.backlight();

}

void loop() {
  
    digitalWrite(4, HIGH);
    lcd.print("ESTADO DA BOMBA:");
    lcd.setCursor(0, 1);
    lcd.print("Bomba Desligada");
    delay(2000);
    lcd.clear();
    digitalWrite(4, LOW);
    lcd.print("ESTADO DA BOMBA:");
    lcd.setCursor(0, 1);
    lcd.print("Bomba Desligada");
    delay(2000);
    lcd.clear();
}
