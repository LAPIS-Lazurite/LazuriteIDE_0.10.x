#include "SimpleRTC_ide.h"		// Additional Header

/* FILE NAME: SimpleRTC.c
 *
 * This example code is in the public domain.
 *
 * Modified by Yoshiyuki Tanaka for Lazurite RTC library.
 */
 
#define SECOND ( 50 )
#define MINUTE ( 59 )
#define HOUR   ( 23 )
#define DAY    ( 31 )
#define MONTH  ( 12 )
#define YEAR   ( 16 )

void initRTC() {
  Serial.println("RTC started.");
  RTC.begin();                           // initialize RTC
  RTC.setTime(HOUR, MINUTE, SECOND);     // Set the time
  RTC.setDate(DAY, MONTH, YEAR);         // Set the date
}

void setup() {
  Serial.begin(115200);

  initRTC();
}

void loop() {
  delay(1000);

  // Print date...
  print2digits(RTC.getDay());
  Serial.print("/");
  print2digits(RTC.getMonth());
  Serial.print("/");
  print2digits(RTC.getYear());
  Serial.print(" ");

  // ...and time
  print2digits(RTC.getHours());
  Serial.print(":");
  print2digits(RTC.getMinutes());
  Serial.print(":");
  print2digits(RTC.getSeconds());

  Serial.println(" ");
}

void print2digits(int number) {
  if (number < 10) {
    Serial.print("0"); // print a 0 before if the number is < than 10
  }
  Serial.print_long((long)number, DEC);
}
