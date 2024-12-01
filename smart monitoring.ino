// Define the analog pins for the two soil moisture sensors
const int moistureSensor1Pin = A0;  // Sensor 1 connected to analog pin A0
const int moistureSensor2Pin = A1;  // Sensor 2 connected to analog pin A1

// Define the digital pin for the LED
const int ledPin = 13;  // LED connected to digital pin 13

// Define the threshold value for moisture level
const int moistureThreshold = 250;  // Below this level, the soil is considered dry

// Variables to store moisture levels
int moistureLevel1 = 0;
int moistureLevel2 = 0;

void setup() {
  // Start the serial communication at 9600 baud rate
  Serial.begin(9600);
  
  // Configure sensor pins as inputs
  pinMode(moistureSensor1Pin, INPUT);
  pinMode(moistureSensor2Pin, INPUT);

  // Configure the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read analog values from the soil moisture sensors
  moistureLevel1 = analogRead(moistureSensor1Pin);
  moistureLevel2 = analogRead(moistureSensor2Pin);

  // Send the moisture levels via Serial in a comma-separated format (e.g., "500,600")
  Serial.print(moistureLevel1);
  Serial.print("first@andsecond ,");
  Serial.println(moistureLevel2);

  // Check if both sensors are below the threshold
  if (moistureLevel1 < moistureThreshold || moistureLevel2 < moistureThreshold) {
    // Turn the LED on if both moisture levels are below the threshold
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn the LED off if any moisture level is above the threshold
    digitalWrite(ledPin, LOW);
  }

  // Wait for 2 seconds before reading again
  delay(2000);
}
