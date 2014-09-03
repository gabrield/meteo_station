#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
 
// Data wire is plugged into pin 10 on the Arduino
#define ONE_WIRE_BUS 12
#define LED_PIN      13
#define LDR_PIN		 A7
#define RAIN_PIN     11


 
// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);


void blink()
{
  digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);               // wait for a second
  digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(300); 
  return;
}



void setup(void)
{
  // start serial port
  Serial.begin(9600);
  //Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
  pinMode(LED_PIN, OUTPUT);
  pinMode(RAIN_PIN, INPUT);

  //Setup the starting light level limits

  blink();
  blink();
  blink();
}

 

double Light (int pin){

int valport = analogRead(pin);

  double Vout = (valport * 0.0048828125);
  //int lux=500/(10*((5-Vout)/Vout));//use this equation if the LDR is in the upper part of the divider
  double lux = 500 / (10 * ((5 - Vout) / Vout));
  return lux;
}

void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  //Serial.print(" Requesting temperatures...");
  //unsigned int rain_val = analogRead(A0);
  int  rain = digitalRead(RAIN_PIN);
  sensors.requestTemperatures(); // Send the command to get temperatures
  float light = Light(LDR_PIN);
  
  //Serial.print("Temperature for Device 1 is: ");
  //Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"? 
  // You can have more than one IC on the same bus. 
  // 0 refers to the first IC on the wire
    Serial.print("[");
    Serial.print(sensors.getTempCByIndex(0));
    Serial.print(",");
    Serial.print(rain);
    Serial.print(",");
    //Serial.print(rain_val*2);
	//Serial.print(",");
	Serial.print(light);
    Serial.println("]");
	//Serial.println("Eita merda!!!");
    blink();
    //Sleepy::loseSomeTime(5000); 
    delay(10);
}

