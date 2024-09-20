const int micPins[6] = {2, 3, 4, 5, 6, 7};  // Digital pins for 6 microphones
unsigned long previousMillis = 0;  // Timer to control the output frequency
const long interval = 500;         // Interval to update random values (500ms)

void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud rate

  // Set each microphone pin as an output (since we're simulating their behavior)
  for (int i = 0; i < 6; i++) {
    pinMode(micPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();  // Get current time in milliseconds
  
  // Update the simulated microphone outputs at regular intervals
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Reset the timer
    
    // Generate random values for each microphone
    for (int i = 0; i < 6; i++) {
      int randomValue = random(0, 2);  // Generate a random value (0 or 1)
      digitalWrite(micPins[i], randomValue);  // Set the digital pin to HIGH or LOW
      
      // Send the value to the serial monitor
      Serial.print(randomValue);
      if (i < 5) {
        Serial.print(",");  // Add comma between values
      }
    }
    
    // End the line after all microphone values are sent
    Serial.println();
  }
}
