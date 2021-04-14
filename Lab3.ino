#include <Keypad.h>
#include <LiquidCrystal.h>
#define RS A8
#define RW A9
#define EN A10
#define D4 A4
#define D5 A5
#define D6 A6
#define D7 A7
LiquidCrystal lcd(RS, RW, EN, D4, D5, D6, D7);
char key;
const int buzzerPin = 10;
const byte rowsNumber = 4;
const byte colsNumber = 4;
char hexaKeys[rowsNumber][colsNumber] = {
    { '1', '2', '3', 'A' },
    { '4', '5', '6', 'B' },
    { '7', '8', '9', 'C' },
    { '*', '0', '#', 'D' }
};
byte rowPins[rowsNumber] = {22, 23, 24, 25};
byte colPins[colsNumber] = {29, 28, 27, 26};
int hours1;
int hours2;
int minutes1;
int minutes2;
int seconds1;
int seconds2;
String hourString;
String minuteString;
int i = 0;

bool launchedTimer1 = false;
bool launchedTimer2 = false;

String timeString;
char minuteCharArray[50];
void tickTimer1(void);
void tickTimer2(void);
void displayTimers(void);
void checkTimer1(void);
void checkTimer2(void);
void setupTimer1(void);
void setupTimer2(void);
void setTimer1(void);
void setTimer2(void);
void startTimer1(void);
void startTimer2(void);


Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, rowsNumber, colsNumber);

void setup()
{

    pinMode(buzzerPin, OUTPUT);
    cli(); 
    TCCR3A = 0; 
    TCCR3B = 0;
    OCR3A = 15624;
    TCCR3B |= (1 << WGM12); 
    TCCR3B |= (1 << CS10);
    TCCR3B |= (1 << CS12);
    TIMSK3 |= (1 << OCIE3A); 
    sei(); 
    lcd.begin(16,2);
    lcd.print("ALGO 3");
    delay(1000);
    lcd.clear();
    lcd.noBlink();
    Serial.begin(9600);
}

void loop()
{

    key = customKeypad.getKey();
    lcd.clear();
    setTimer1();
    lcd.clear();
    displayTimers();
    startTimer1();
    setTimer2();
    startTimer2();
}

ISR(TIMER3_COMPA_vect)
{
    if (launchedTimer1 != false) {
        tickTimer1();
    }

    if (launchedTimer2 != false) {
        tickTimer2();
    }
}

void tickTimer1()
{

    if (seconds1 != 0 || minutes1 != 0 || hours1 != 0) {

        if (hours1 >= 0 && minutes1 == 0 && seconds1 == 0) {
            minutes1 = 60;
            hours1 -= 1;
        }

        if (hours1 >= 0 && minutes1 > 0 && seconds1 == 0) {
            minutes1 -= 1;
            seconds1 = 60;
        }
        if (hours1 == 0 && minutes1 == 0 && seconds1 == 1) {
            for (int i = 0; i <= 20; i++) {
                digitalWrite(buzzerPin, 1);
                delay(60000);
                digitalWrite(buzzerPin, 0);
                delay(10000);
            }
        }

        if (hours1 >= 0 && minutes1 >= 0 && seconds1 > 0) {
            seconds1 -= 1;
        }
    }
}

void tickTimer2()
{

    if (seconds2 != 0 || minutes2 != 0 || hours2 != 0) {

        if (hours2 >= 0 && minutes2 == 0 && seconds2 == 0) {
            minutes2 = 60;
            hours2 -= 1;
        }

        if (hours2 >= 0 && minutes2 > 0 && seconds2 == 0) {
            minutes2 -= 1;
            seconds2 = 60;
        }
        if (hours2 == 0 && minutes2 == 0 && seconds2 == 1) {

            for (int i = 0; i <= 20; i++) {
                digitalWrite(buzzerPin, 1);
                delay(60000); 
                digitalWrite(buzzerPin, 0);
                delay(10000);
            }
        }
        if (hours2 >= 0 && minutes2 >= 0 && seconds2 > 0) {
            seconds2 -= 1;
        }
    }
}
