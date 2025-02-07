#include <wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include "GravityTDS.h"

float temperature = 25, tdsValue = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

GravityTDS gravityTds;
#define TdsSensorPin A0;

// Define pins
#define motorPin1 9
#define motorPin2 10
#define motorPin3 11
#define motorPin4 12
#define relayPin 2

// Define button pins
#define buttonPin1 3
#define buttonPin2 4
#define buttonPin3 5
#define buttonPin4 6

// define variables to store analog value
int buttonvalue1;
int buttonvalue2;
int buttonvalue3;
int buttonvalue4;

void setup()
{
    // initialize serial communication
    Serial.begin(9600);
}

// Initialize motor pins as outputs
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);

// inialize relay pin as output
pinMode(relayPin, OUTPUT);

// Initialize button pins as inputs
pinMode(buttonPin1, INPUT);
pinMode(buttonPin2, INPUT);
pinMode(buttonPin3, INPUT);
pinMode(buttonPin4, INPUT);

// Inialize the LCD
lcd.begin();
lcd.backlight();

// Start serial communication
Serial.begin(9600);

// Initialize the TDS sensor
gravityTds.setPins(TdsSensorPin);
gravityTds.serAdcRange(1024);
gravityTds.begin();
}

void loop()
{
    buttonvalue1 = digitalRead(buttonPin1);
    buttonvalue2 = digitalRead(buttonPin2);
    buttonvalue3 = digitalRead(buttonPin3);
    buttonvalue4 = digitalRead(buttonPin4);
}

// print analog values to serial monitor
Serial.print("B1: ");
Serial.print(buttonvalue1);
Serial.print("B2: ");
Serial.print(buttonvalue2);
Serial.print("B3: ");
Serial.print(buttonvalue3);
Serial.print("B4: ");
Serial.print(buttonvalue4);

// process analog values and control motor accordingly
digitalWrite(motorPin1, HIGH);

digitalWrite(motorPin2, LOW);

digitalWrite(motorPin3, HIGH);

digitalWrite(motorPin4, LOW);

// Turn on forward relay

digitalWrite(relayPin, HIGH);

} else if (buttonvalue2 <=0) {

// Move reverse

digitalWrite(motorPin1, LOW);

digitalWrite(motorPin2, HIGH);

digitalWrite(motorPin3, LOW);

digitalWrite(motorPin4, HIGH);

// Turn off relay

digitalWrite(relayPin, LOW);

} else if (buttonvalue3 <=0) {

// Turn right

digitalWrite(motorPin1, LOW);

digitalWrite(motorPin2, HIGH);

digitalWrite(motorPin3, HIGH);

digitalWrite(motorPin4, LOW);

// Turn on right relay

digitalWrite(relayPin, HIGH);

} else if (buttonvalue4 <=0) {

// Turn left

digitalWrite(motorPin1, HIGH);

digitalWrite(motorPin2, LOW);

digitalWrite(motorPin3, LOW);

digitalWrite(motorPin4, HIGH);

// Turn on left 

digitalWrite(relayPin, HIGH);

} else {

// Stop

digitalWrite(motorPin1, LOW);

digitalWrite(motorPin2, LOW);

digitalWrite(motorPin3, LOW);

digitalWrite(motorPin4, LOW);

// Turn off all relays

digitalWrite(relayPin, LOW);

}

delay(100);

}

Void sensor()

{

//temperature = read Temperature(); //add your tempera

gravityTds.setTemperature (temperature); // set the

gravityTds.update(); //sample and calculate

tdsValue = gravityTds.getTdsValue(); // then get t

Serial.print(tdsValue,0);

Serial.println("ppm");

// delay(1000);

// Display TDS value on the LCD

lcd.clear();

lcd.setCursor(0, 0);

1cd.print("TDS Value : ");

lcd.setCursor(0, 1);

lcd.print(tdsValue);

delay(500); // Adjust delay as needed

}
