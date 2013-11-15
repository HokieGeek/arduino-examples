#include <LiquidCrystal.h>
#include <RGBLiquidCrystal.h>

RGBLiquidCrystal lcd(13, 12,  // RS, Enable
                     5, 4, 3, 2, // D4, D5, D6, D7
                     6, 9, 10, 11); // R, G, B, Contrast

const int potPin = A5;

typedef enum {
  NONE, CONTRAST, COLOR
} function_type;

function_type ftype = COLOR;
function_type lastFtype = NONE;
int lastVal = -1;
boolean changeColor = true;

const int dpCS = 8;
const int dpSiPin = 11;
// const int dpPA = 1;
// const int dpPB = 0;
// const int dpPW = 8;
const int dpPBa = A5;
const int dpPWa = A4;
const int dpPAa = A3;

void setup() {
  pinMode(potPin, INPUT);

  pinMode(dpSiPin, OUTPUT);
  // pinMode(dpPA, INPUT);
  // pinMode(dpPB, INPUT);
  // pinMode(dpPW, INPUT);
  pinMode(dpPAa, INPUT);
  pinMode(dpPBa, INPUT);
  pinMode(dpPWa, INPUT);
  pinMode(dpCS, INPUT);

  lcd.begin(16, 2);
  // lcd.noCursor();
  lcd.print("Started LCD test");

  Serial.begin(9600);
}

int siVal = 0;

void loop() {

  digitalWrite(dpCS, LOW);
  analogWrite(dpSiPin, siVal);
  digitalWrite(dpCS, HIGH);
  delay(30);
  // int pA = digitalRead(dpPA);
  // int pB = digitalRead(dpPB);
  // int pW = digitalRead(dpPW);
  int pA = analogRead(dpPAa);
  int pB = analogRead(dpPBa);
  int pW = analogRead(dpPWa);


  lcd.clear();
  lcd.print(siVal);
  lcd.print(", B:");
  lcd.print(pW);
  /*
  lcd.print("A:");
  lcd.print(pA);
  lcd.print("W:");
  lcd.print(pW);
  */
  siVal++;
  if (siVal > 255) siVal = 0;
  delay(1000);
/*
  switch (ftype) {
  case CONTRAST: {
    if (lastFtype != ftype) {
      lcd.setCursor(0, 0);
      lcd.print("Contrast:");
      lastFtype = ftype;
    }
    int val = analogRead(potPin);//map(analogRead(potPin), 0, 1023, 0, 255);
    if (val != lastVal) {
      // lcd.setContrast(val);
      lcd.setCursor(0, 1);
      lcd.print("    ");
      lcd.setCursor(0, 1);
      lcd.print(val);
      lastVal = val;
    }
    }
    break;
  case COLOR:
    //if (lastVal
    if (lastFtype != ftype) {
      lcd.setCursor(0, 0);
      lcd.print("COLOR:");
      lastFtype = ftype;
    }
    if (changeColor) {
      lcd.setColor(RGBLiquidCrystal::BLUE);
      int* currentColor = lcd.getColor();

      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("RGB: ");
      lcd.print(currentColor[0]);
      lcd.print(",");
      lcd.print(currentColor[1]);
      lcd.print(",");
      lcd.print(currentColor[2]);
      changeColor = false;
    }
    break;
  }
    */

/*
  if (Serial.available()) {
    delay(100); // so we don't read to quickly
    lcd.clear();
    lcd.setCursor(16,0);
    lcd.autoscroll();
    while (Serial.available() > 0) {
        lcd.print(Serial.read());
        delay(300);
    }
  }
*/

/*
  // set the cursor to (0,0):
  lcd.setCursor(0, 0);
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
   lcd.print(thisChar);
   delay(500);
  }

  // set the cursor to (16,1):
  lcd.setCursor(16,1);
  // set the display to automatically scroll:
  lcd.autoscroll();
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();
  
  // clear screen for the next loop:
  lcd.clear();
*/
}


