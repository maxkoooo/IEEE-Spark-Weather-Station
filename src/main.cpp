#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_BMP085.h>
#include <SPI.h>
#include "thebetterone.h"


Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);

  bmp.begin();


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
  /*
  int RAIN = analogRead(RN);
  Serial.println(RAIN);
  lcd_clear();
  lcd_send_int("Rain:", RAIN);
  delay(500);
  */

  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  lcd_clear();
  lcd_send_int("Temp=",bmp.readTemperature());
  lcd_send_string("*C");
  delay(1000);
  
  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");
  
  lcd_clear();
  lcd_send_int("Pres=",bmp.readPressure());
  lcd_send_string("Pa");
  delay(1000);

  // Calculate altitude assuming 'standard' barometric
  // pressure of 1013.25 millibar = 101325 Pascal
  Serial.print("Altitude = ");
  Serial.print(bmp.readAltitude());
  Serial.println(" meters");
  
  lcd_clear();
  lcd_send_int("Alt=",bmp.readAltitude());
  lcd_send_string("m");
  delay(1000);

  Serial.print("Pressure at sealevel (calculated) = ");
  Serial.print(bmp.readSealevelPressure());
  Serial.println(" Pa");
  
  lcd_clear();
  lcd_send_int("SeaLvl=",bmp.readSealevelPressure());
  lcd_send_string("Pa");
  delay(1000);

  Serial.print("Real altitude = ");
  Serial.print(bmp.readAltitude(101500));
  Serial.println(" meters");
  
  lcd_clear();
  lcd_send_int("Real Alt=",bmp.readAltitude(101500));
  lcd_send_string("m");
  delay(1000);
  
  Serial.println();
}

