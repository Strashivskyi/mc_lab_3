void startTimer1()
{
  if (key == 'C') {
    digitalWrite(buzzerPin, 1);
    delay(50);
    digitalWrite(buzzerPin, 0);
    key = customKeypad.getKey();
    if (launchedTimer1 == false) {
      launchedTimer1 = true;
      lcd.clear();
      lcd.print("Timer 1 started");
      delay(1000);
      lcd.clear();
      return;
    }
    else if (launchedTimer1 == true) {
      launchedTimer1 = false;
      lcd.clear();
      lcd.print("Timer 1 stopped");
      hours1 = 0;
      seconds1 = 0;
      minutes1 = 0;
      delay(1000);
      lcd.clear();
      return;
    }
  }
}
