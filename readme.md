# IR Receiver Remote Button Detection of DD Free Dish Remote with ESP32 (PlatformIO)

This project for detect button presses from an IR remote control. It leverages the `IRremoteESP8266` library for decoding IR signals and PlatformIO as the development environment.

---

## Features

- Detects IR remote control button presses
- Prints button decoded values via serial monitor

---

## Hardware Required

- ESP32 development board
- IR receiver module (e.g., KY-022)
- IR Remote (DD Free Dish Remote)
- Jumper wires
- Breadboard (optional)

---

## Wiring

Connect the IR receiver to your ESP32 as follows:

| IR Receiver Pin | ESP32 Pin       | Description                |
|-------------------|-----------------|----------------------------|
| VCC               | 3.3V or 5V      | Power (check your IR receiver) |
| GND               | GND             | Ground                     |
| OUT               | GPIO 21 (or other chosen pin) | IR signal output |

*Note:* Use a GPIO pin that supports input interrupts.

---


## Getting Started

1.  **Clone the repository:**

    Open your terminal or command prompt and use the following command to clone the project:

    ```bash
    git clone https://github.com/akarshit-1609/IR_Receiver_Remote_Button_Detection_with_ESP32.git
    ```

2.  **Open in PlatformIO:**

    Open the cloned project in your preferred IDE with the PlatformIO extension installed (e.g., VS Code).

3.  **Configure Variables:**

    Before uploading the code to your ESP32, you need to configure some variables, particularly the GPIO pin.

    *   **Locate the configuration:** Open the `src/main.cpp` file.
    *   **Find the variable:** Look for a line similar to this:

        ```c++
        int RECV_PIN = 21; // Replace with your sensor GPIO pin
        ```

    *   **Replace the value:** Change the `21` to the actual GPIO pin number where your signal pin is connected on your ESP32 board. Refer to your ESP32 board's pinout diagram if you are unsure.

4.  **Build and Upload:**

    *   Connect your ESP32 board to your computer via USB.
    *   In PlatformIO, click the "Build" button to compile the project.
    *   Click the "Upload" button to upload the compiled code to your ESP32.

---

## Project Structure

*   `platformio.ini`: PlatformIO configuration file.
*   `src/main.cpp`: The main source code file.
*   `lib/`: (Optional) Directory for external libraries.

---


## Usage

Once the code is uploaded, open serial monitor and press dd free dish remote button in front of ir receiver.

---

## Demo

https://github.com/user-attachments/assets/a348673c-91fe-4535-a362-809165002de3

---

## Troubleshooting

- Make sure the IR receiver is properly connected.
- Check that your remote control is working by testing with another device.
- Ensure the correct GPIO pin is used and configured as input.

---

## References

- [IRremoteESP8266 Library](https://github.com/crankyoldgit/IRremoteESP8266)
- [ESP32 Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/)
