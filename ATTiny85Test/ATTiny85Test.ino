#include <LiquidCrystal.h>
#include <RGBLiquidCrystal.h>

RGBLiquidCrystal lcd(13, 12,  // RS, Enable
                     5, 4, 3, 2, // D4, D5, D6, D7
                     6, 9, 10, 11); // R, G, B, Contrast

const int digitalInputPin = 7;
const int analogInputPin = 11;
const int digitalOutputPin = 8;
const int analogOutputPin = A5;

void setup() {

    pinMode(digitalInputPin, OUTPUT);
    pinMode(analogInputPin, OUTPUT);
    pinMode(digitalOutputPin, INPUT);
    pinMode(analogOutputPin, INPUT);

    lcd.begin(16, 2);
    lcd.setColor(RGBLiquidCrystal::BLUE);
    lcd.print("Testing the ATTiny85");
}

int currentAnalogVal = 0;
void loop() {
    int analogVal = analogRead(analogOutputPin);
    int digitalVal = digitalRead(digitalOutputPin);

    digitalWrite(digitalInputPin, !digitalVal);
    analogWrite(analogInputPin, currentAnalogVal);
    currentAnalogVal++;
    if (currentAnalogVal > 255) currentAnalogVal = 0;
    delay(50);

    lcd.clear();
    lcd.print("Digital: ");
    lcd.print(digitalVal);
    lcd.setCursor(0, 1);
    lcd.print("Analog:  ");
    lcd.print(analogVal);
    lcd.print("/");
    lcd.print(currentAnalogVal);
    delay(500);
}
