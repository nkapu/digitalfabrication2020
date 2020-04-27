int Button = 0;

int cm = 0;

int i = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(2, INPUT);
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  Button = digitalRead(2);
  if (Button == HIGH) {
    while (1 == 1) {
      cm = 0.01723 * readUltrasonicDistance(7, 7);
      if (cm < 100) {
        digitalWrite(11, LOW);
        digitalWrite(6, LOW);
        digitalWrite(13, LOW);
        Serial.println(cm);
        delay(1000); // Wait for 1000 millisecond(s)
      } else {
        digitalWrite(13, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(6, HIGH);
        Serial.println(cm);
        delay(1000); // Wait for 1000 millisecond(s)
      }
    }
  }
}