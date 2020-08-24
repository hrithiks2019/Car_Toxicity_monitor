#ifndef MQ7_h
#define MQ7_h

#define coefficient_A 19.32
#define coefficient_B -0.64

//Load resistance 10 Kohms on the sensor potentiometer
#define R_Load 10.0

class MQ7 {
	private:
		uint8_t analogPin;
		float v_in;
		float voltageConversion(int);
	public:
		MQ7(uint8_t, float);
		float getPPM();
		float getSensorResistance();
		float getRatio();
};

#endif