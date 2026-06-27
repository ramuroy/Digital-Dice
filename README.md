# 🎲 **Digital Dice using Arduino**  

This project is a **fun and interactive Digital Dice** built using an **Arduino**, a **7-segment display**, and a **push button**. Press the button and the system generates a **random number between 1 and 6** and displays it on the **7-segment display**, just like rolling a real dice! 🎲✨  

---

## 🛠️ **Components Used**  
- 🔹 **Arduino Uno** – Microcontroller to generate random numbers and control the display.  
- 🔹 **7-Segment Display (common-cathode)** – Displays the dice number (1-6).  
- 🔹 **Push Button** – Triggers the dice roll.  
- 🔹 **Resistors (≈220–330 Ω, one per segment) & Wires** – For the display segments and connections.  

---

## 🔌 **Wiring**  
| Arduino Pin | Connects to |
|-------------|-------------|
| D2 | Push button → other leg to **GND** (uses `INPUT_PULLUP`, active-low) |
| D3 – D9 | 7-segment segments **a – g**, each via a current-limiting resistor |
| GND | 7-segment **common cathode** |

> The segment patterns assume a **common-cathode** display (a segment lights when its Arduino pin is HIGH).

---

## ⚙️ **How It Works**  
1️⃣ On each **button press** (debounced — one roll per press), the **Arduino generates a random number** between **1 and 6**.  
2️⃣ The number is then **shown on the 7-segment display**.  
3️⃣ The system **waits for the next press** to roll again.  

---

## 📝 **Features**  
✅ **Simulates a real dice roll** 🎲  
✅ **Displays random numbers (1-6) on a 7-segment display**  
✅ **Debounced, edge-detected button — exactly one roll per press**  
✅ **Perfect for board games and interactive projects**  

---

## 🌍 **Applications**  
🔹 **Electronic Dice for Board Games** – Replace traditional dice in games.  
🔹 **Random Number Generator** – Can be used in various fun experiments.  
🔹 **STEM Learning Project** – Great for learning about Arduino, randomness, and displays.  
🔹 **Interactive Gaming** – Integrate into custom games or classroom activities.  

---

This simple yet fun project is perfect for **DIY gaming setups** and **Arduino beginners**! 🚀🎲
