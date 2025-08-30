# 🚜 Coco Treat | Arduino Motor & Spray Control System

This project is an **Arduino-based control system** for a simple robot with:
- **Two DC motors** for forward (up) and backward (down) movement
- **A spray pump toggle** (ON/OFF with a button)
- **LED indicators** for movement and spray status
- **Serial debugging messages** to monitor activity

---

## ⚙️ Features
- **Move Up** → Motors drive forward, movement LED ON  
- **Move Down** → Motors drive backward, movement LED ON  
- **Stop** → Motors stop when no button is pressed  
- **Spray Toggle** → Single button press turns spray ON, next press turns it OFF  
- **Indicators** →  
  - `movementIndicator` LED shows robot movement  
  - `pumpIndicator` LED shows spray ON/OFF status  

---

## 🛠️ Hardware Requirements
- Arduino Uno / Nano / Mega  
- L298N (or compatible) Motor Driver  
- 2 × DC Motors  
- 1 × Pump Motor (for spray)  
- 3 × Push Buttons (Up, Down, Spray toggle)  
- 2 × LEDs (Movement, Pump indicator)  
- Resistors (for LEDs, if required)  
- Power supply for motors (separate from Arduino recommended)  

---

## 📌 Pin Configuration
### Signal Inputs
| Button           | Pin |
|------------------|-----|
| Move Up          | 7   |
| Move Down        | 6   |
| Spray Toggle     | 5   |

### Indicators
| Indicator          | Pin |
|--------------------|-----|
| Movement Indicator | 3   |
| Pump Indicator     | 2   |

### Motor Driver (L298N)
| Motor Driver | Arduino Pin |
|--------------|-------------|
| ENA          | 8   |
| IN1          | 9   |
| IN2          | 10  |
| IN3          | 11  |
| IN4          | 12  |
| ENB          | 13  |

---

## ▶️ How It Works
1. **Press Move Up button** → Motors spin forward, movement LED ON, "Moving UP" prints on Serial Monitor.  
2. **Press Move Down button** → Motors spin backward, movement LED ON, "Moving DOWN" prints on Serial Monitor.  
3. **Release all buttons** → Motors stop, all indicators OFF, "STOP" prints.  
4. **Press Spray button** → Spray toggles ON/OFF, LED shows pump state, Serial Monitor prints "Spray ON/OFF".  

---

## 🔧 Setup Instructions
1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/Arduino-Motor-Spray-Control.git
2. Open `MotorSprayControl.ino` in the Arduino IDE.
3. Select your Arduino board and COM port.
4. Upload the code.
5. Open **Serial Monitor** at `9600 baud` to view debug messages.