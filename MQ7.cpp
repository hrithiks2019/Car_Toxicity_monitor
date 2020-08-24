#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include <avr/io.h>
    #include "WProgram.h"
#endif

#include "MQ7.h"

MQ7::MQ7(uint8_t pin, float v_input){
  analogPin = pin;
  v_in = v_input;
}


float MQ7::getPPM(){
  return (float)(coefficient_A * pow(getRatio(), coefficient_B));
}


float MQ7::voltageConversion(int value){
  return (float) value * (v_in / 1023.0);
}


float MQ7::getRatio(){
  int value = analogRead(analogPin);
  float v_out = voltageConversion(value);
  return (v_in - v_out) / v_out;
}

float MQ7::getSensorResistance(){
  return R_Load * getRatio();
}