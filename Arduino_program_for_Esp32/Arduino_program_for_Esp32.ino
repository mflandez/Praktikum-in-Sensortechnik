#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include "BluetoothSerial.h"

// vdd to vdd, gnd to 3.3, SCL to 22, SDA to 21, ADDR to gnd. How the pins from the ADS1115 are connected to the Esp32

//Adafruit_ADS1115 ads(0x48);
Adafruit_ADS1115 ads;
float Voltage = 0.0;
BluetoothSerial SerialBT; // BTobject

float x = 0.0;
unsigned long myTime;

void setup(void) 
{
  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  ads.setGain(GAIN_TWOTHIRDS);    // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default); We use this one if we desire to have input between 0 and 5 V
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV

  // bluetooth initialize
  Serial.begin(115200);
  SerialBT.begin("Esp32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  // 16 bit ADC initialize
if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
}

void loop(void) 
{
 

int16_t adc0;
  //averaging of the last 3 measurements to control sharp peaks, also does the work of a low pass filter
  x = (2.0 * x + ads.readADC_SingleEnded(0)) / 3; 
  // Calculates the Volts for the measured input
  Voltage = ads.computeVolts((int)x);
  // calculates the current time in milliseconds
  myTime = millis();
  // prints onto Bluetooth serial the current time
    SerialBT.print(myTime); // Comment this line when wanting to use Arduino IDE Tracer
  // prints a comma to separate time and voltage
   SerialBT.print(",");  // Comment this line when wanting to use Arduino IDE Tracer
  // prints the current measured voltage
  SerialBT.println(Voltage, 3);  

delay(1);
}
