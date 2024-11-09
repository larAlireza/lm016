#include <LiquidCrystal.h>

// تعریف پین‌های LCD به Arduino
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long previousMillis = 0; 
const long interval = 1000; // فاصله زمانی برای به‌روزرسانی هر 1 ثانیه
int seconds = 0;
int minutes = 0;
int hours = 0;

void setup() {
  lcd.begin(16, 2); // تنظیمات LCD با 16 ستون و 2 خط
  lcd.print("Clock:"); // نمایش متن ثابت "Clock"
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    seconds++;
    if (seconds == 60) {
      seconds = 0;
      minutes++;
      if (minutes == 60) {
        minutes = 0;
        hours++;
        if (hours == 24) {
          hours = 0;
        }
      }
    }
    
    // پاک کردن و نمایش زمان
    lcd.setCursor(0, 1); // انتقال به خط دوم
    if (hours < 10) lcd.print("0");
    lcd.print(hours);
    lcd.print(":");
    if (minutes < 10) lcd.print("0");
    lcd.print(minutes);
    lcd.print(":");
    if (seconds < 10) lcd.print("0");
    lcd.print(seconds);
  }
}
