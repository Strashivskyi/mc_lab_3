void setTimer1()
{
  if (key == 'A') {
    digitalWrite(buzzerPin, 1);
    delay(50);
    digitalWrite(buzzerPin, 0);
    hourString = "";
    minuteString = "";
    timeString = "";
    lcd.clear();
    key = customKeypad.getKey();

    if (key) {
      digitalWrite(buzzerPin, 1);
      delay(50);
      digitalWrite(buzzerPin, 0);
    }

    while (key != '#' || key != '*') {
      key = customKeypad.getKey();
      setupTimer1();
      key = customKeypad.getKey();
      if (key == '#') {
        digitalWrite(buzzerPin, 1);
        delay(100);
        digitalWrite(buzzerPin, 0);
        delay(50);
        digitalWrite(buzzerPin, 1);
        delay(100);
        digitalWrite(buzzerPin, 0);
        checkTimer1();
        return;
      }
      if (key == '*') {
        lcd.print("Action cancelled");
        delay(500);
        digitalWrite(buzzerPin, 1);
        delay(1500);
        digitalWrite(buzzerPin, 0);
        return;
      }
    }
  }
}
