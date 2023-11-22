#include <Arduino.h>
#include "thebetterone.h"

void etoggle(){
    // toggles e
    digitalWrite(EN, HIGH);
    delay(1);
    digitalWrite(EN, LOW);
    delay(1);    
}

void send_to_lcd(unsigned char bit, int rs){
    digitalWrite(RS, rs); //rs 1 for data, rs 0 for command

    digitalWrite(DB7, ((bit >> 3) & 0x01));
    digitalWrite(DB6, ((bit >> 2) & 0x01));
    digitalWrite(DB5, ((bit >> 1) & 0x01));
    digitalWrite(DB4, ((bit >> 0) & 0x01));

    etoggle();
}

void lcd_send_cmd(unsigned char cmd){
    unsigned char bit;

    /* send upper nibble */
    bit = ((cmd >> 4) & 0x0f);
    send_to_lcd(bit, 0);
    /* send lower nibble */
    bit = ((cmd) & 0x0f);
    send_to_lcd(bit, 0);
}

void lcd_send_data(unsigned char data){
    unsigned char bit;

    /* send upper nibble */
    bit = ((data >> 4) & 0x0f);
    send_to_lcd(bit, 1);
    /* send lower nibble */
    bit = ((data) & 0x0f);
    send_to_lcd(bit, 1);
}

void lcdinit(){ //initialises all the pins

// Function set (3 pulses)
    delay(50);
    lcd_send_cmd(0x03);
    delay(5);
    lcd_send_cmd(0x03);
    delay(1);
    lcd_send_cmd(0x03);
    delay(10);

//Function set interface to 4 bit        
    lcd_send_cmd(0x02);
    delay(10);

// Set number of display lines and character font
    lcd_send_cmd(0x28);    //N - Number of lines F - Font (0 = 5x8, 1 = 5x10)
    delay(1);
// Display off
    lcd_send_cmd(0x08);
    delay(1);

// Display clear
    lcd_send_cmd(0x01);
    delay(1);

// Entry mode set
    lcd_send_cmd(0x06);
    delay(1);

//Turn display on
    lcd_send_cmd(0x0C);
}

void lcd_clear(){
    lcd_send_cmd(0x01);
    delay(1);
}

void lcd_send_string(char *str) {
	while (*str) {
		lcd_send_data(*str);
        str++;
	}
}

void lcd_send_int(char *description, int num){
    char buffer[20];
    sprintf(buffer, "%s: %d", description, num);
    lcd_send_string(buffer);
}
