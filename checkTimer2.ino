void checkTimer2()
{

    lcd.clear();
    minuteString.toCharArray(minuteCharArray, 50);
    minutes2 = atoi(minuteCharArray);


    if (minutes2 > 59) {
        hours2 = 0;
        minutes2 = 0;
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
