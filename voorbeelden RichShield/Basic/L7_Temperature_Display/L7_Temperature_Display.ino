/************************************************* ************************************************** ******
* OPEN-SMART Rich Shield Lesson 7: Temperature measurement and display
* Through the NTC temperature measurement module to obtain the temperature, and display on the digital tube. 
*
* The following functions are available:
* temper.getTemperature(); // get the temperature value, and return float-point number 
*
* displayTemperature(int8_t temperature); // display temperature, at the end of the value of the word added C is the degree of Celsius
*
* disp.init(); // initialization
* disp.display(int8_t DispData []); // display the numbers in the array
* // For example, the array is {1,2,3,4}, then show 1234
************************************************** ************************************************** *****/

#include <Wire.h>

#include "RichShieldTM1637.h"
#include "RichShieldNTC.h"

#define NTC_PIN A1  //SIG pin of NTC module connect to A1 of IO Shield, that is pin A1 of OPEN-SMART UNO R3
NTC temper(NTC_PIN);

#define CLK 10  //CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
#define DIO 11  //DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK, DIO);

void setup() {
  disp.init();  //The initialization of the display
  delay(1000);  //
}

void loop() {
  float celsius;
  celsius = temper.getTemperature();  //get temperature
  disp.display(celcius);
  delay(1000);  //delay 1000ms
}
