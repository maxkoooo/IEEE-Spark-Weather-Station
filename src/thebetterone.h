#pragma once

#define RS 13  //RS Pin
#define EN 12  //EN for enable Pin
#define DB4 4  //DB04 Pin
#define DB5 5  //DB05 Pin
#define DB6 6  //DB06 Pin
#define DB7 7  //DB07 Pin

#define RN A0

void lcdinit();
void lcd_clear();
void lcd_send_string(char *str);
void lcd_send_int(char *description, int num);