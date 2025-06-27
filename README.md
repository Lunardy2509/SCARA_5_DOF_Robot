# 🤖 SCARA 5 DOF Robot Arm

This repository contains an **Arduino-based SCARA (Selective Compliance Assembly Robot Arm)** with 5 Degrees of Freedom, designed for educational and competitive use. Built from open-source resources, this project has been used as a **prototype** for:

- 🏆 **KRTMI** (Kontes Robot Tematik Indonesia)
- 🏫 University workshops & demonstrations
- 📷 Computer vision experiments

---

## 🧠 Project Goals

- Develop a functional 5-DOF robotic arm using low-cost, open-source hardware
- Support learning in mechatronics, embedded programming, and robotics kinematics
- Create a base platform for automation tasks and vision-integrated robotics

---

## 🛠️ Features

- 🎯 5 Degrees of Freedom robotic arm (SCARA-type)
- 🧠 Controlled via Arduino-compatible microcontroller
- ⚙️ Manual or semi-automated movement via joystick/buttons
- 🧩 Compatible with computer vision for object sorting or pick-and-place
- 🛠️ Modular and 3D-printable structure

---

## 📁 Repository Structure

```bash
SCARA_5_DOF_Robot/
├── 3D_Design/               # STL or CAD files for printable arm parts
├── code/                    # Arduino code for robotic arm control
│   └── scara_control.ino
├── documentation/           # Reports, kinematic diagrams, project context
└── README.md
```

## 🧰 Hardware Components
| Component               | Description                              |
| ----------------------- | ---------------------------------------- |
| Arduino Uno/Nano        | Microcontroller for motor control        |
| Servo Motors (x5)       | For joint actuation                      |
| Power Supply (5V–6V)    | External power source for servos         |
| Joystick Module         | For manual positioning (optional)        |
| Push Buttons (optional) | For mode switching or recording movement |
| 3D-Printed Frame        | Arm body components                      |
| Breadboard & Wires      | For prototyping connections              |

## 🚀 Getting Started
### 1. Prepare the Hardware
3D-print all arm components using the files in `3D_Design/`
Assemble the robotic arm using standard fasteners and servo mounts
Connect all components according to the circuit diagram (see `documentation/`)

### 2. Upload the Code
Open `code/scara_control.ino` in the Arduino IDE
Select your board and COM port
Upload the code to your Arduino

## 📐 Kinematics & Control
This SCARA arm uses basic forward/inverse kinematics for positioning. You can modify the code to support:
- Angle-to-position mapping
- Object tracking (if paired with vision input)
- Recording & replaying movement sequences

## 📚 Use Cases
- 🤖 Robotics education (universities, clubs, and high schools)
- 🎓 Kinematics and control systems lab demos
- 🏁 Robotics competitions (e.g., KRTMI)
- 🔍 Research in computer vision and automation

## 📝 License
This project is open-source and intended for educational use. Original design files are based on publicly available open hardware models.

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
