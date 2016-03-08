
//*****************VIBRATION MOTOR AND FLEXI SENSOR FULLY CALIBRATED************************//
// PINS
const int motorPin = 11;
const int flexiPin = A0;
//VALUES
int motorSpeed = 0;
int motorPower = 0;
int sensor = 0;
int flexiMin = 680;
int flexiMax = 850;
void setup()
{

	pinMode(motorPin,OUTPUT);
	pinMode(flexiPin, INPUT);
	Serial.begin(9600);

}

void loop()
{
	sensor = analogRead(flexiPin);
	if (sensor < flexiMin)
	{
		motorSpeed = 0;
		digitalWrite(motorPin, LOW);
	}

	if (flexiMin <= sensor && sensor <= flexiMax)
	{
		motorSpeed = map(sensor, flexiMin, flexiMax, 50, 255);
		analogWrite(motorPin, motorSpeed);
		motorPower = map(sensor, flexiMin, flexiMax, 0, 100);
	}

	Serial.print("sensor value :" );
	Serial.println(sensor);
	Serial.print("motorPower: ");
	Serial.print(motorPower);
	Serial.println("%");
	delay(500);
}


//********************************SERVO and FLEXI CODE**********************************//
//void loop()
//{
//	int flexposition;    // Input value from the analog pin.
//	int servoposition;   // Output value to the servo.
//
//	// Read the position of the flex sensor (0 to 1023):
//
//	flexposition = analogRead(flexpin);
//
//	servoposition = map(flexposition, 600, 900, 0, 180);
//	servoposition = constrain(servoposition, 0, 180);
//
//
//
//	servo1.write(servoposition);
//
//
//	Serial.print("sensor: ");
//	Serial.print(flexposition);
//	Serial.print("  servo: ");
//	Serial.println(servoposition);
//
//
//	delay(20);  // wait 20ms between servo updates
//}
//


//***********************SENSOR TEST*****************************************//

//
//void setup()
//{
//	// initialize serial communications
//	Serial.begin(9600);
//}

//void loop()
//{
//	int sensor, degrees;
//
//	// read the voltage from the voltage divider (sensor plus resistor)
//	sensor = analogRead(0);
//	// convert the voltage reading to inches
//	// the first two numbers are the sensor values for straight (768) and bent (853)
//	// the second two numbers are the degree readings we'll map that to (0 to 90 degrees)
//	degrees = map(sensor, 680, 850, 0, 90);
//	// note that the above numbers are ideal, your sensor's values will vary
//	// to improve the accuracy, run the program, note your sensor's analog values
//	// when it's straight and bent, and insert those values into the above function.
//
//	// print out the result
//	Serial.print("analog input: ");
//	Serial.print(sensor, DEC);
//	Serial.print("   degrees: ");
//	Serial.println(degrees, DEC);
//
//	// pause before taking the next reading
//	delay(100);
//}