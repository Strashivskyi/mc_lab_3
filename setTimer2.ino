void setTimer2()
{
  if (key == 'B') {
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
      setupTimer2();
      key = customKeypad.getKey();
      if (key == '#') {
        digitalWrite(buzzerPin, 1);
        delay(100);
        digitalWrite(buzzerPin, 0);
        delay(50);
        digitalWrite(buzzerPin, 1);
        delay(100);
        digitalWrite(buzzerPin, 0);
        checkTimer2();
        return;
      }
      if (key == '*') {
        digitalWrite(buzzerPin, 1);
        delay(1500);
        digitalWrite(buzzerPin, 0);
        return;
      }
    }
  }
}
