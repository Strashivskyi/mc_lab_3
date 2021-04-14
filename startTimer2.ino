void startTimer2()
{
  if (key == 'D') {
    digitalWrite(buzzerPin, 1);
    delay(50);
    digitalWrite(buzzerPin, 0);
    key = customKeypad.getKey();
    if (launchedTimer2 == false) {
      launchedTimer2 = true;
      lcd.clear();
      lcd.print("Timer 2 started");
      delay(1000);
      lcd.clear();
      return;
    }
    else if (launchedTimer2 == true) {
      launchedTimer2 = false;
      lcd.clear();
      lcd.print("Timer 2 stopped");
      hours2 = 0;
      seconds2 = 0;
      minutes2 = 0;
      delay(1000);
      lcd.clear();
      return;
    }
  }
}
