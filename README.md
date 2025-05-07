# 📟 IR Remote-Controlled 7-Segment Display

This Arduino project uses an **IR remote** to control a **single-digit 7-segment display**. When you press number buttons (1–9) on a compatible remote, the corresponding number appears on the display.

## 🔧 Features

- Detects IR signals using the `IRremote` library
- Displays numbers (0–9) on a 7-segment display
- Custom brightness control
- Easy to adapt for more digits or other remote codes

## 🧰 Hardware Requirements

- Arduino Uno (or compatible board)
- IR receiver module (e.g., TSOP4838)
- 7-segment common cathode display
- IR remote (with known key codes)
- Jumper wires
- Breadboard

## 📦 Libraries Used

- [`IRremote`](https://github.com/Arduino-IRremote/Arduino-IRremote) – For reading signals from the IR remote
- `SevenSeg.h` – For controlling the 7-segment display (a third-party library; make sure it's available or implemented correctly)

## 🖥️ Pin Connections

| Component         | Arduino Pin |
|------------------|-------------|
| IR Receiver (OUT) | D3          |
| 7-Segment Seg A–G | D10–D6, D11, D12 |
| Digit Common Pin  | D4          |

> Make sure the 7-segment display is **common cathode**.

## 🚀 Getting Started

1. Install the required libraries:
   - `IRremote` from Library Manager
   - `SevenSeg` (install manually if needed)

2. Upload the code using the Arduino IDE.

3. Open the **Serial Monitor** at 9600 baud to view remote code values and debug output.

4. Press buttons 1–9 on your IR remote to display the number on the 7-segment display.

## 🧪 Testing

To check your own remote’s codes:
- Uncomment the `Serial.println(IR.decodedIRData.decodedRawData, HEX);` line
- Press remote buttons and read the output in the Serial Monitor
- Replace the hardcoded values in the code with those from your own remote if needed

## 📝 Notes

- `flag` is used to prevent repetitive serial prints of the same number.
- `delay(1500)` prevents spamming the IR receiver with repeat signals.
