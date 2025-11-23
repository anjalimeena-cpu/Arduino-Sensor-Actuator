int ldrPin = A0;
int ledPin = 8;
int buzzerPin = 9;

// PERFECT thresholds for your LDR values:
int thresholdOn  = 380;  // touching
int thresholdOff = 550;  // hand away

bool state = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Smooth values
  int v1 = analogRead(ldrPin);
  delay(3);
  int v2 = analogRead(ldrPin);
  delay(3);
  int v3 = analogRead(ldrPin);
  int value = (v1 + v2 + v3) / 3;

  Serial.println(value);

  // Hysteresis logic
  if (!state && value < thresholdOn) {
    state = true;   
  }
  else if (state && value > thresholdOff) {
    state = false;  
  }

  // LED
  digitalWrite(ledPin, state ? HIGH : LOW);

  // Buzzer
  if (state) tone(buzzerPin, 1000);
  else noTone(buzzerPin);

  delay(100);
}
