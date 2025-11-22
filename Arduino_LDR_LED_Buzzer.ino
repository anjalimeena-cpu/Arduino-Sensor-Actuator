int ldrPin = A0;
int ledPin = 8;
int buzzerPin = 9;

int ledThreshold = 350;     // LED turns ON below this (dark)
int buzzerThreshold = 450;  // Buzzer turns ON when it's even darker

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // LED control
  if (ldrValue < ledThreshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Buzzer control
  if (ldrValue < buzzerThreshold) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  delay(200);
}
