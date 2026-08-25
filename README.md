<div align ="center">
  
  # 🤖 AQUARD Smart Water Analyzer
  ### Simulation wave and amplitudo realtime
  
  
  <img src="img/preview.jpg" width="400">

  
</div>

## ✨ Table of Contents
- [Credits AQUARD Team](#credits-aquard-team)
- [Why this project exists?](#%E2%80%8D-why-this-project-exists)
- [Project Introduction](#-project-introduction)
- [Features](#ⓘ-features)
- [Hardware & Software](#%EF%B8%8F-hardware--software)
- [AQUARD Architecture](#_-aquard-architecture)
- [Pin Connections](#-pin-connections)
- [Documentations](#documentations)


## Credits AQUARD Team

#### Ahmad Naufal Fadhlurrahman as Embedded Engineer
#### Yusuf Arif Endy as Mechanical Designer 
#### Syahril as Material Engineer
#### Nurli Avrilia Putri as Project Presenter
#### Chesya Rahmadani as Project Presenter 
#### Fitri Nurhalizah as Project Presenter 

## 👨🏻‍💻 Why this project exists? 


## ֎🇦🇮 Project Introduction

In regions like the Riau Islands, exploring coastal areas and the open sea is a common part of daily life. This reality prompted a critical question: what would happen if a tsunami or major natural disaster struck this archipelagic province?

To address this, we developed a prototype device for tsunami and flood disaster detection equipped with a water level sensor. If drastic water level fluctuations occur, an integrated buzzer alarm is automatically triggered to issue an early warning. Furthermore, the system utilizes ultrasonic sensors to measure wave amplitude in real-time, with automated software calculations.

Overall, AQUARD provides a tsunami and flood simulation tool designed for physics education—helping users calculate wave amplitude while understanding the working mechanism of an early detection disaster prototype. We hope to further scale and refine this prototype in design and performance, ultimately creating a meaningful impact for coastal communities, particularly in the Riau Islands.

## ⓘ Features
- Alarm indicator led & buzzer
- Real-time Amplitudo Value
- Real-time Water sensor
- Servo wave generator
- House Miniatur

## 🛠️ Hardware & Software 
### Hardware : 
- Arduino UNO
- Buzzer
- Switch button
- LCD 16X2 with I2C
- Ultrasonic Sensor
- Water Sensor
- Servo 360 degres
- 2 Battery Lithium
- Battery Case
- Wires (Female & Male)
- Breadboard
- 3 Resistor 1 Ohm
- Impraboard (Base) Opsional 
- Plastic Box (Base) Opsional
- Popsicle Stick (Base) Opsional

### Software : 
- Arduino IDE

## >_ AQUARD Architecture
- SETUP : When system get power supply from USB or battery, Script will be setup program.

### Amplitudo Calculation
- RELEASE TRIG : After setup ready, ultrasonic sensor will release Trig signal in front of sensor
- CATCH FROM ECHO : Then, Echo signal will be catched the Trig signal again.
- AUTOMATED CALCULATIONS : Program will be calculate values, and show the value in the lcd 16x2 realtime.
  
### Wave Detector
- WAVE GENERATOR : Servo will swing the water and makes waves
- WATER DETECTOR : If the water reach a water sensor, led will be turn on depends water sensor value, higher the water sensor, threes led will be turn on simultaneously with the buzzer. 



## 🔌 Pin Connections

### Battery Lithium - Arduino Uno : 
| Battery  | Arduino Pin |  Descriptions |
|-------|------------|-------|
| + | Vin |  |
| - | GND |  |

### Arduino Uno - Breadboard : 
| Arduino Pin  | Breadboard Pin |  Descriptions |
|-------|------------|-------|
| 5V | First Red rail |  |
| GND | First Blue rail |  |

### Arduino Uno - Ultrasonik Sensor Pin : 
| Arduino Pin  | Ultrasonik Pin |  Descriptions |
|-------|------------|-------|
| 12 | TRIG |  |
| 8 | ECHO |  |
| GND | GND | Breadboard | 
| Red Rail | VCC | Breadboard | 

### Arduino Uno - Led : 
| Arduino Pin  | Led Pin |  Descriptions |
|-------|------------|-------|
| 2 | Long side | Red Led |
| 3 | Long Side | Yellow Led |
| 4 | Long Side | Green Led | 

### Arduino Uno - Water Sensor : 
| Arduino Pin  | Water sensor Pin |  Descriptions |
|-------|------------|-------|
| Red Rail | + | Breadboard |
| Blue Raul | - | Breadboard |
| A0 | S |  | 

### Arduino Uno - Servo : 
| Arduino Pin | Servo Pin |  Descriptions |
|-------|------------|-------|
| Red Rail  | + | Breadboard |
| Blue Rail | - | Breadboard |
| 7 | PWM | Orange Pin | 

## Documentations 

### FIRST PROTOTYPE : 

https://drive.google.com/drive/folders/1AatNiTcXAbDibuHpVddpoUjBiqA5ix4g

### SECOND PROTOTYPE :

https://www.instagram.com/reel/DNsdzH3ZMoB/?utm_source=ig_web_copy_link&igsi=MzRlODBiNWFlZA==







