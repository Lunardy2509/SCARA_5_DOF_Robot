<details>
<summary>Click to view Documentation Images</summary>
  
| | | |
|---|---|---|
| ![1](https://github.com/Lunardy2509/SCARA_5_DOF_Robot/blob/main/documentation/IMG_4944.jpg) | ![2](https://github.com/Lunardy2509/SCARA_5_DOF_Robot/blob/main/documentation/IMG-20240519-WA0004.jpg) | ![3](https://github.com/Lunardy2509/SCARA_5_DOF_Robot/blob/main/documentation/IMG_5194.jpg) |

</details>

# 🤖 SCARA 5 DOF Robot Arm

This repository contains an **Arduino-based SCARA (Selective Compliance Assembly Robot Arm)** with 5 Degrees of Freedom, designed for educational and competitive use. Built from open-source resources, this project has been used as a **prototype** for:

- 🏆 Kontes Robot Tematik Indonesia (KRTMI)
- 🏫 University workshops & robotics labs
- 📷 Computer vision and automation demos

---

## 🧠 Project Goals

- Develop a working SCARA-type robotic arm with 5 DOF
- Introduce students to robotic kinematics, control, and mechatronics
- Provide a low-cost platform for learning automation and vision-guided tasks

---

## 🛠️ Features

- 🎯 5 Degrees of Freedom robotic arm (servo-driven)
- 🧠 Arduino-based control with optional joystick or PC interface
- 🧩 Modular 3D-printed frame
- 🛠️ Ready for integration with Python/vision systems
- 🗂️ Clean code and documentation structure

---

## 📁 Repository Structure

```bash
SCARA_5_DOF_Robot/
├── 3D_Design/               # Printable STL/CAD files
├── code/                    # Arduino source code
│   └── scara_control.ino
├── documentation/           # Reports, kinematic diagrams
└── README.md                # You're here
```

## 🧰 Hardware Components
| Component          | Quantity | Description                        |
| ------------------ | -------- | ---------------------------------- |
| Arduino Uno/Nano   | 1        | Main microcontroller               |
| Servo Motors       | 5        | For each degree of freedom         |
| Power Supply       | 1        | 5–6V external (not Arduino 5V pin) |
| Joystick Module    | Optional | Manual control input               |
| 3D-Printed Parts   | -        | Frame, base, joints                |
| Breadboard & Wires | -        | Wiring and prototyping             |

## 🚀 Getting Started
## 1. Print and Assemble
- Use files in `3D_Design/files/` to 3D-print components
- Refer to `images/` or `documentation/` for physical assembly guidance

## 2. Flash the Arduino
- Open `code/scara_control.ino` in Arduino IDE
- Connect your board via USB

## 📚 Library Installation Guide
To ensure proper compilation in Arduino IDE, install the following libraries:
| Library Name              | Use                            | How to Install                                   |
| ------------------------- | ------------------------------ | ------------------------------------------------ |
| `Servo` (by Arduino)      | Controls standard hobby servos | Included by default in Arduino IDE               |
| `AccelStepper` (optional) | Stepper/trajectory control     | Arduino IDE → Library Manager → Search & Install |
| `SoftwareSerial`          | If using serial joystick input | Built-in or available via Library Manager        |
You can install libraries via **Arduino IDE > Tools > Manage Libraries...**, then search for the name and click **Install**.

## 🧮 Kinematics
- Forward/inverse kinematics logic is applied directly in the Arduino code
- For advanced motion planning, consider adapting the code with Python or ROS integration

## 📚 Use Cases
- 💡 STEM & Robotics education
- 🏁 Robotics competitions (e.g., KRTMI)
- 🧪 Prototyping for pick-and-place automation
- 🔍 Computer vision + arm coordination experiments

## 📝 License & Attribution
- Original mechanical design inspired by JJrobots SCARA arm on Thingiverse
- Electronics, control logic, and documentation developed by this project team
- Licensed for educational, non-commercial use

## 📬 Contact
- GitHub: [@Lunardy2509](https://github.com/Lunardy2509)
- Email: ferdilunardy@gmail.com

⭐️ If this project helped your learning or research, consider starring or forking the repo to support its development!

---

Would you like to:
- Add a **.gif or video demo** section?
- Include **inverse kinematics equations** in the documentation?
- Add a section for **ESP32 or wireless upgrades**?

Just let me know!
