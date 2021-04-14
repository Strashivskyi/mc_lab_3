void setupTimer1()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Timer 1 setup:");
  lcd.setCursor(0, 1);
  lcd.print(timeString);
  delay(50);
  while (timeString.length() != 5) {
    key = customKeypad.getKey();
    if (hourString.length() < 3) {
      if (key == '*') {
        digitalWrite(buzzerPin, 1);
        delay(1500);
        digitalWrite(buzzerPin, 0);
        minuteString = "";
        hourString = "";
        timeString = "";
        return;
      }
      if (key) {
        digitalWrite(buzzerPin, 1);
        delay(50);
        digitalWrite(buzzerPin, 0);
      }
      if (isdigit(key)) {
        hourString += String(key);
        delay(100);
      }
      lcd.setCursor(0, 1);
      lcd.print(hourString);
      lcd.setCursor(2, 1);
      lcd.print(":");

    }

    if (minuteString.length() < 3 && hourString.length() == 2) {
      key = customKeypad.getKey();
      if (key == '*') {
        digitalWrite(buzzerPin, 1);
        delay(1500);
        digitalWrite(buzzerPin, 0);
        minuteString = "";
        hourString = "";
        timeString = "";
        return;
      }
      if (key) {
        digitalWrite(buzzerPin, 1);
        delay(50);
        digitalWrite(buzzerPin, 0);
      }
      if (isdigit(key)) {
        minuteString += String(key);
        delay(100);
      }
      lcd.setCursor(3, 1);
      lcd.print(minuteString);
    }
    timeString = hourString + ":" + minuteString;
  }
  lcd.clear();
}
