/*
 * Set up display to define layout of servo status.
 */
#include <LiquidCrystal_I2C.h>
#include "LCD_Helper.h"

/*
 * Set up the labels on the display.
 * Only needed to be done once during setup.
 */
void displayLabels(LiquidCrystal_I2C *lcd, uint8_t length, struct display_t *labels) {
  lcd->clear();
  lcd->backlight();
  display_t label;
  for (int l = 0; l<length; l++) {
    label = labels[l];
    lcd->setCursor(label.label_col,label.label_row);
    lcd->print(label.label);
  }
}


/*
 * Display each of the values in the array.
 * Values will be printed left justfied.
 */
void displayValuesLeft(LiquidCrystal_I2C *lcd, uint8_t length, struct display_t *value_locs, unsigned int values[]) {
  display_t value_loc;
  for (int l = 0; l<length; l++) {
    displayValueLeft(lcd, value_locs, l, values[l]);
  }
}
void displayValuesLeft(LiquidCrystal_I2C *lcd, uint8_t length, struct display_t *value_locs, unsigned long values[]) {
  display_t value_loc;
  for (int l = 0; l<length; l++) {
    displayValueLeft(lcd, value_locs, l, values[l]);
  }
}

/*
 * Display each of the values in the array using padding.
 * Values will be printed right justfied.
 */
void displayValuesRight(LiquidCrystal_I2C *lcd, uint8_t length, struct display_t *value_locs, unsigned int values[]) {
  display_t value_loc;
  for (int l = 0; l<length; l++) {
    displayValueRight(lcd, value_locs, l, values[l]);
  }
}
void displayValuesRight(LiquidCrystal_I2C *lcd, uint8_t length, struct display_t *value_locs, unsigned long values[]) {
  display_t value_loc;
  for (int l = 0; l<length; l++) {
    displayValueRight(lcd, value_locs, l, values[l]);
  }
}


/*
 * Display a single value at the location specified.
 * Values will be printed left justfied.
 */
void displayValueLeft(LiquidCrystal_I2C *lcd, struct display_t *value_locs, uint8_t pos, unsigned long value) {
    display_t value_loc = value_locs[pos];
    lcd->setCursor(value_loc.value_col,value_loc.value_row);
    char nstr[value_loc.value_len+1];
    lcd->print(int2LeftString(value,value_loc.value_len, ' ', nstr));
}

/*
 * Display a single value at the location specified using padding.
 * Values will be printed right justfied.
 */
void displayValueRight(LiquidCrystal_I2C *lcd, struct display_t *value_locs, uint8_t pos, unsigned long value) {
    display_t value_loc = value_locs[pos];
    lcd->setCursor(value_loc.value_col,value_loc.value_row);
    char nstr[value_loc.value_len+1];
    lcd->print(int2RightString(value,value_loc.value_len, ' ', nstr));
}


/*
 * Convert a number into a string and pad the right with filler.
 */
extern char *int2LeftString(unsigned long n, uint8_t len, char fill, char *nstr) {
  utoa(n, nstr, 10);
  int nlen = strlen(nstr);
  while (nlen < len) {
    nstr[nlen++] = fill;   // Need to pad remaining with fill
  }
  nstr[nlen] = 0;
  
  return nstr;
}

/*
 * Convert a number into a left padded string of a specified length.
 */
extern char *int2RightString(unsigned long n, uint8_t len, char fill, char *nstr) {
  utoa(n, nstr, 10);
  int nlen = strlen(nstr);
  int flen = len;
  if (nlen < len) {
    // Need to pad with fill
    while (nlen >= 0) {
      nstr[flen--] = nstr[nlen--];   // Slide everything over to make room
    }
    while (flen >= 0) {
      nstr[flen--] = fill;
    }
  }
  
  return nstr;
}


