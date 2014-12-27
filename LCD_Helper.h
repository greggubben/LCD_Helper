/*
 * Set up display to define layout of servo status.
 */
 
#ifndef LCD_Helper_h
#define LCD_Helper_h

typedef struct display_t {
  uint8_t label_col;
  uint8_t label_row;
  char *label;
  uint8_t value_col;
  uint8_t value_row;
  uint8_t value_len;
} display_t;


/*
 * Set up the labels on the display.
 * Only needed to be done once during setup.
 */
void displayLabels(LiquidCrystal_I2C *lcd, uint8_t length, struct display_t *labels);


/*
 * Display each of the values in the array.
 * Values will be printed left justfied.
 */
void displayValuesLeft(LiquidCrystal_I2C *lcd, uint8_t length, struct display_t *value_locs, unsigned int values[]);
void displayValuesLeft(LiquidCrystal_I2C *lcd, uint8_t length, struct display_t *value_locs, unsigned long values[]);

/*
 * Display each of the values in the array using padding.
 * Values will be printed right justfied.
 */
void displayValuesRight(LiquidCrystal_I2C *lcd, uint8_t length, struct display_t *value_locs, unsigned int values[]);
void displayValuesRight(LiquidCrystal_I2C *lcd, uint8_t length, struct display_t *value_locs, unsigned long values[]);


/*
 * Display a single value at the location specified.
 * Values will be printed left justfied.
 */
void displayValueLeft(LiquidCrystal_I2C *lcd, struct display_t *value_locs, uint8_t pos, unsigned long value);

/*
 * Display a single value at the location specified using padding.
 * Values will be printed right justfied.
 */
void displayValueRight(LiquidCrystal_I2C *lcd, struct display_t *value_locs, uint8_t pos, unsigned long value);


/*
 * Convert a number into a string and pad the right with filler.
 */
extern char *int2LeftString(unsigned long n, uint8_t len, char fill, char *nstr);

/*
 * Convert a number into a left padded string of a specified length.
 */
extern char *int2RightString(unsigned long n, uint8_t len, char fill, char *nstr);

#endif

