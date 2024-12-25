int const led = 13;
int const inSensor = 2;
int const outSensor = 10;
int count = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(inSensor, INPUT);
  pinMode(outSensor, INPUT);
  Serial.begin(9600);
}
void loop() {
  // Check if someone is entering (IR sensor 1)
  if (digitalRead(inSensor) == HIGH) {
    count++;
    Serial.println("Person entered. Count: " + String(count));
    // Adjust delay to debounce the sensor if needed
  }

  // Check if someone is leaving (IR sensor 2)
  if (digitalRead(outSensor) == HIGH) {
    count--;
    Serial.println("Person left. Count: " + String(count));
   // Adjust delay to debounce the sensor if needed
  }

  // Update the LED based on the count
  if (count >= 1) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}