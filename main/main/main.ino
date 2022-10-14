#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);

  lcd.print("Ask to");
  lcd.setCursor(0, 1);
  lcd.print(" the crystal ball.");
}

void loop() {
  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState){
    if(switchState == LOW){
      reply = random(8);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("it says :");
      lcd.setCursor(0, 1);

      switch (reply) {
        case 0:
          lcd.print("yes.");
        break;
        case 1:
          lcd.print("it might be right.");
        break;
        case 2:
          lcd.print("meh.");
        break;
        case 3:
          lcd.print("absolutely !");
        break;
        case 4:
          lcd.print("i don't think so");
        break;
        case 5:
          lcd.print("lol");
        break;
        case 6:
          lcd.print("u'll die soon");
        break;
        case 7:
          lcd.print("nop");
        break;
      }
    }
  }
  prevSwitchState = switchState;
}
