#include <LiquidCrystal.h>
#include <RGBLiquidCrystal.h>

RGBLiquidCrystal lcd(13, 12,  // RS, Enable
                     5, 4, 3, 2, // D4, D5, D6, D7
                     6, 9, 10, 11); // R, G, B, Contrast

const int out = 8;

void setup() {
    pinMode(out, OUTPUT);

    lcd.begin(16, 2);
    lcd.setColor(RGBLiquidCrystal::BLUE);
    lcd.print("Testing the 4-Logic");
}

void flash() {
    lcd.setCursor(0, 0);
    lcd.print("HIGH");
    
    digitalWrite(out, HIGH);
    delay(150);
    digitalWrite(out, LOW);
    
    lcd.setCursor(0, 0);
    lcd.print("LOW ");
}

boolean done=false;
void loop() {
    if (!done) {
      lcd.clear();
      for (int i = 0; i < 35; i++)
          flash();
      done = true;
    }

    lcd.setCursor(0, 0);
    lcd.print("_DONE_");
}
