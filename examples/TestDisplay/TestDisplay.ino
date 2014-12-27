/*
 * Test and demostrate the capabilities of the LCD_Helper library.
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <LCD_Helper.h>

// set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcdisplay(0x27,20,4);

// Range of Values available for testing
const int MAX_VALUES = 9;
unsigned int intVals[MAX_VALUES];
unsigned long longVals[MAX_VALUES];

// Display settings
const uint8_t DISPLAY_LENGTH = 9;
display_t display_positions[DISPLAY_LENGTH] = {
    { 0, 0,"BL:", 3, 0, 3},
    {10, 0,"BR:",13, 0, 3},
    { 0, 1,"EL:", 3, 1, 3},
    { 6, 1,  ":", 7, 1, 3},
    {10, 1,"ER:",13, 1, 3},
    {16, 1,  ":",17, 1, 3},
    { 0, 2, "M:", 2, 2, 3},
    { 0, 3,"NU:", 3, 3, 3},
    {10, 3,"NS:",13, 3, 3},
};

// Define how long the delay should be between value changes
const unsigned long DELAY_TIME = 4000;  // 4 seconds

void setup()
{
  // Generate some values
  for (int pos = 0; pos<MAX_VALUES; pos++) {
    intVals[pos]=(pos+1)*(pos+1);
    longVals[pos]=(pos+2)*(pos+3);
  }
  
  // initialize the lcd 
  lcdisplay.init();

  // Print the labels
  displayLabels(&lcdisplay, DISPLAY_LENGTH, display_positions);

}

void loop()
{
  // Display the long values as left justified
  displayValuesLeft(&lcdisplay, DISPLAY_LENGTH, display_positions, longVals);

  delay(DELAY_TIME);  // Wait before making the next change
  
  // Display the int values as right justified
  displayValuesRight(&lcdisplay, DISPLAY_LENGTH, display_positions, intVals);

  delay(DELAY_TIME);  // Wait before making the next change
  
  // Display a single value as left justified
  displayValueLeft(&lcdisplay, display_positions, 0, 1);
  
  // Display a single value as left justified
  displayValueLeft(&lcdisplay, display_positions, 2, 11);
  
  // Display a single value as left justified
  displayValueLeft(&lcdisplay, display_positions, 3, 111);

  // Display a single value as left justified
  // Remember if the number overflows it will not truncate.
  displayValueLeft(&lcdisplay, display_positions, 6, 1111);
  
  delay(DELAY_TIME);  // Wait before making the next change
  
  // Display the long values as right justified
  displayValuesRight(&lcdisplay, DISPLAY_LENGTH, display_positions, longVals);
  
  delay(DELAY_TIME);  // Wait before making the next change
  
  // Display the values as left justified
  displayValuesLeft(&lcdisplay, DISPLAY_LENGTH, display_positions, intVals);

  delay(DELAY_TIME);  // Wait before making the next change
  
  // Display a single value as right justified
  displayValueRight(&lcdisplay, display_positions, 1, 2);

  // Display a single value as right justified
  displayValueRight(&lcdisplay, display_positions, 4, 22);

  // Display a single value as right justified
  displayValueRight(&lcdisplay, display_positions, 5, 222);

  // Display a single value as right justified
  // Remember if the number overflows it will not truncate.
  displayValueRight(&lcdisplay, display_positions, 6, 2222);

  delay(DELAY_TIME);  // Wait before making the next change
  
}

