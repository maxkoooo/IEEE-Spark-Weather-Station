#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "thebetterone.h"


void setup() {
  Serial.begin(9600);

  // initialise pins
  pinMode(RS, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(DB4, OUTPUT);
  pinMode(DB5, OUTPUT);
  pinMode(DB6, OUTPUT);
  pinMode(DB7, OUTPUT);

  // Initialise LCD
  lcdinit();

  lcd_send_string("hello world");
}

void loop() {
  int RAIN = analogRead(RN);
  Serial.println(RAIN);
  lcd_clear();
  lcd_send_int("Rain:", RAIN);
  delay(500);
}

