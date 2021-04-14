void displayTimers()
{
    lcd.clear();
    lcd.print("Timer1: " + String(hours1) + ":" + String(minutes1) + ":" + String(seconds1));
    lcd.setCursor(0, 1);
    lcd.print("Timer2: " + String(hours2) + ":" + String(minutes2) + ":" + String(seconds2));
    delay(100);
}
