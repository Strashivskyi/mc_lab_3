void checkTimer1()
{

    lcd.clear();
    minuteString.toCharArray(minuteCharArray, 50);
    minutes1 = atoi(minuteCharArray);

    if (minutes1 > 59) {
        hours1 = 0;
        minutes1 = 0;
        hourString = "";
        minuteString = "";
        timeString = "";
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("WRONG DATA");
        digitalWrite(buzzerPin, 1);
        delay(1500);
        digitalWrite(buzzerPin, 0);
        delay(1500);
        return;
    }

    hourString = "";
    minuteString = "";
}
