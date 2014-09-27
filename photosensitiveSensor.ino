const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = A0;
int blueSensorValue = A2;
int greenSensorValue = A1;

void setup()
{
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
}

void loop()
{
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  Serial.print("Raw Sensor Value \t Red: ");
  Serial.print(redSensorValue);
  Serial.print(" \t Blue: ");
  Serial.print(blueSensorValue);
  Serial.print(" \t Green: ");
  Serial.println(greenSensorValue);
  
  redValue = 255 - (redSensorValue / 4);
  greenValue = 255 - (greenSensorValue / 4);
  blueValue = 255 - (blueSensorValue / 4);

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("  \t Blue: ");
  Serial.print(blueValue);
  Serial.print("  \t Green: ");
  Serial.println(redValue);

  analogWrite(redLEDPin, redValue);
  analogWrite(blueLEDPin, blueValue);
  analogWrite(greenLEDPin, greenValue);
  delay(1000);

}


