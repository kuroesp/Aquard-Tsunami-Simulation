int lowerThreshold = 400;
int upperThreshold = 500;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Servo.h>

Servo myServo;

// Sensor pins
#define sensorPower 7
#define sensorPin A0

// Value for storing water level
int level = 0;
int val = 0;
int tones[] = {0, 277, 293, 311, 329, 349, 369, 392, 415, 440, 466, 493, 523 ,554};

// Declare pins to which LEDs are connected
int redLED = 2;
int yellowLED = 3;
int greenLED = 4;
int Buzzer = 5;
int trigpin = 12;
int echopin = 8;

float distance;
float maxDistance = 0;
float minDistance = 1000;

int Tx = 11;
int Rx = 10;
SoftwareSerial bluetooth(Tx, Rx);

unsigned long lastUpdateTime = 0;
const unsigned long updateInterval = 1000; // update tiap 1 detik
bool firstReading = true;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Water");
  lcd.setCursor(0, 1);
  lcd.print("Analyzer");
  delay(2000);
  lcd.clear();

  

  
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(Buzzer, LOW);

  bluetooth.begin(9600);
}

void loop() {

  myServo.write(0);
  delay(200);

  myServo.write(100);
  delay(200);

  myServo.write(0);
  delay(200);
  
  distance = getDistance();

  if (distance >= 5 && distance <= 100) {
    if (firstReading) {
      maxDistance = distance;
      minDistance = distance;
      firstReading = false;
    }

    if (distance > maxDistance) maxDistance = distance;
    if (distance < minDistance) minDistance = distance;

    float amplitude = (maxDistance - minDistance) / 2.0;

    // Baca sensor air
    level = readSensor();

    // Tentukan status berdasarkan threshold
    String status = "";
    if (level == 0) {
      status = "Kosong";
    }
    else if (level > 0 && level <= lowerThreshold) {
      status = "Rendah";
    }
    else if (level > lowerThreshold && level <= upperThreshold) {
      status = "Sedang";
    }
    else if (level > upperThreshold) {
      status = "Tinggi";
    }

    // === Tampilkan ke Serial Monitor (untuk debugging) ===
    Serial.print("Level=");
    Serial.print(level);
    Serial.print(" | Amp=");
    Serial.print(amplitude, 2);
    Serial.print(" cm | Status=");
    Serial.println(status);

    // === Kirim data ke Bluetooth (format: level,amplitudo,status) ===
    bluetooth.print(level);
    bluetooth.print(",");
    bluetooth.print(amplitude, 2);
    bluetooth.print(",");
    bluetooth.println(status);

    // === Output ke LCD ===
    lcd.setCursor(0, 0);
    lcd.print("Level:");
    lcd.print(status);
    lcd.print("    "); // hapus sisa teks

    lcd.setCursor(0, 1);
    lcd.print("Amp:");
    lcd.print(amplitude, 2);
    lcd.print("cm   ");

    // === Kontrol LED dan Buzzer ===
    if (status == "Kosong") {
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, LOW);
      noTone(Buzzer);
    }
    else if (status == "Rendah") {
      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, LOW);
      noTone(Buzzer);
    }
    else if (status == "Sedang") {
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(greenLED, LOW);
      tone(Buzzer, tones[4]);
      delay(100);
      noTone(Buzzer);
    }
    else if (status == "Tinggi") {
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, HIGH);
      tone(Buzzer, tones[10]);
    }

    // Reset min/max tiap interval
    if (millis() - lastUpdateTime >= updateInterval) {
      maxDistance = distance;
      minDistance = distance;
      lastUpdateTime = millis();
    }
  } else {
    Serial.println("Invalid distance reading!");
  }

  delay(200);
}

int readSensor() {
  digitalWrite(sensorPower, HIGH);
  delay(10);
  val = analogRead(sensorPin);
  digitalWrite(sensorPower, LOW);
  return val;
}

float getDistance() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  long duration = pulseIn(echopin, HIGH, 30000); 
  if (duration == 0) {
    return 999;
  }
  float distanceCm = duration * 0.034 / 2.0;
  return distanceCm;
}

