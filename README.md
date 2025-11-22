# Arduino Sensor–Actuator Integration  
### LDR Sensor with LED and Buzzer Outputs

This project implements a real-time sensor–actuator system using an LDR (Light Dependent Resistor) as the analog input sensor and two actuators: an LED and a buzzer. The system reads light intensity values through the LDR and activates the actuators based on predefined threshold levels.  
This work demonstrates analog sensing, threshold-based decision making, and hardware interfacing on the Arduino platform.

---

## 🔧 Components Used
- Arduino UNO  
- LDR (Light Dependent Resistor)  
- 10kΩ resistor (for voltage divider)  
- LED + 220Ω resistor  
- Active Buzzer   
- Jumper wires  
- Breadboard  

---

## 📡 Working Principle
The LDR forms a voltage divider whose output voltage varies with the surrounding light intensity.  
The Arduino reads this analog value from pin **A0** and performs the following logic:

- If **LDR < 350** → LED turns **ON**  
- If **LDR < 450** → Buzzer turns **ON**  
- Otherwise, both actuators remain **OFF**

Two separate thresholds are used to demonstrate multi-actuator control based on sensor intensity levels.

---

## 🛠 Circuit Connections
**LDR Sensor:**
- LDR → 5V  
- LDR → A0  
- 10k resistor → A0 to GND  

**LED Actuator:**  
- Long leg → Digital Pin **8**  
- Short leg → GND via **220Ω** resistor  

**Buzzer Actuator:**  
- Positive (+) → Digital Pin **9**  
- Negative (–) → GND  

A Tinkercad schematic and real circuit image are included in the `/images` folder.

---

## 💻 Arduino Code
```cpp
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
