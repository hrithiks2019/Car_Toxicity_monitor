#include "CO2Sensor.h"
#include <LiquidCrystal.h>
#include "MQ7.h"



MQ7 mq7(A0,5.0);
LiquidCrystal lcd(8,9,4,5,6,7);
CO2Sensor co2Sensor(A1, 0.99, 100);


void setup() {
	pinMode(7, OUTPUT); // Buzzer Pin
    Serial.begin(9600);
	Serial.println("CAiR Monitoring System");
	delay(20);
	Serial.println("=== Initialized ===");
	co2Sensor.calibrate();
	lcd.begin(16,2);
	Serial.begin(115200);
	lcd.home();
	lcd.setCursor(2,0);
	lcd.print("CAiR Monitor");
	digitalWrite(7, LOW);

}

void loop() {
    
	int co_val = mq7.getPPM();
	int co2_val = co2Sensor.read();
	delay(100);
	if (co_val > 100)
	{
		Serial.println("Air Toxicity is High");
		Serial.println("High Levels of Carbon Monoxide is found");
		digitalWrite(7, HIGH);
		lcd.setCursor(2,0);
		lcd.print("Alert: Co high");
	}
	else if (co2_val > 1500)
	{
		Serial.println("Air Toxicity is High");
		Serial.println("High Levels of Carbon di-oxide is found");
		digitalWrite(7, HIGH);
		lcd.setCursor(2,0);
		lcd.print("Alert: Co2 high");
	}
	else
	{
		lcd.setCursor(2,0);
		lcd.print("CAiR Monitor");
		Serial.println("Air Toxicity is LOW");
		Serial.println("Carbon di-oxide and Carbon Monoxide lvls are Below Threshold");
	}
	
	lcd.setCursor(1,1);
	lcd.print("Co:");
	lcd.print(co_val);
	lcd.print(" PPm");
	Serial.print("Co lvl:");
	Serial.print(co_val);
	Serial.println(" PPM");
	lcd.print(" ");
	lcd.setCursor(1,1);
	lcd.print("Co2:");
	lcd.print(co2_val);
	lcd.print(" PPm");
	lcd.print("  .");
	Serial.print("Co2 lvl:");
	Serial.print(co2_val);
	Serial.println(" PPM");
	lcd.clear();
	delay(400);
}
