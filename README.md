# IoT Labs — Arduino learning repository

This repository contains a set of hands-on Arduino lab exercises covering common sensors, actuators, and displays. Each lab is organized into its own folder and includes sketches, wiring diagrams, and a list of required libraries.

Repository structure (top-level folders):

- `Lab 1 - Blinking LED/` — basic LED blink examples and wiring diagram.
- `Lab 2 - Temperature/` — temperature sensor examples (DHT22 and LM35).
- `Lab 3 - RGB_LED & Buzzer/` — RGB LED control and buzzer examples.
- `Lab 4 - LCD & OLED display/` — character LCD and OLED display sketches (subfolders for LCD and OLED).
- `Lab 5 - Potentiometer & Button/` — potentiometer and push-button interaction examples.

Each lab folder typically contains:

- `Sketch.ino` or similarly named Arduino sketch files.
- `Diagram.json` or images with wiring diagrams.
- `Libraries.txt` listing libraries required for the sketches.

Getting started

Running in Wokwi (quick simulator)

Wokwi (https://wokwi.com) is a browser-based Arduino simulator that's great for testing sketches without hardware. Many of the labs in this repo can be run in Wokwi with minimal changes.

Basic steps:

1. Open https://wokwi.com and choose "Arduino UNO" (or the board used by a lab).
2. Copy the sketch code from a lab's `Sketch.ino` into Wokwi's editor (or drag the sketch file into the Wokwi editor area).
3. If a lab uses external libraries (listed in `Libraries.txt`), add them in Wokwi by clicking the "Libraries" button and searching for the library (Wokwi supports many common libraries such as Adafruit GFX). If a library is missing, you can sometimes paste the library source files into the Wokwi project.
4. Recreate the wiring in the Wokwi schematic editor. If a `Diagram.json` is present, Wokwi can import some diagram formats — otherwise rewire components manually using the editor.
5. Click "Start Simulation" to run the sketch. Use Wokwi's serial monitor and virtual components (LEDs, sensors) to interact and verify behavior.

Tips for Wokwi

- If a sketch refers to hardware not available in Wokwi, consider stubbing sensor reads or using mock values for testing.
- For I2C displays (like I2C LCDs or OLEDs), Wokwi provides virtual modules; wire SDA/SCL accordingly and set the correct I2C address in the sketch.
- When a library isn't available in Wokwi's library list, try copying the minimal required source files into the project or test with simplified code that doesn't require the library.

Using a real Arduino:
1. Install the Arduino IDE (or PlatformIO for VS Code).
2. Open the lab folder you want to try (for example `Lab 1 - Blinking LED`) in the Arduino IDE.
3. Install any libraries listed in that lab's `Libraries.txt`. For the Arduino IDE you can install them via Sketch → Include Library → Manage Libraries... or by adding them to your sketchbook `libraries` folder.
4. Select your board and port, then upload the sketch.

Notes and recommendations

- Use the `Libraries.txt` file in each lab folder as the source of required libraries. Common libraries used across the repo include Adafruit GFX and LiquidCrystal I2C.
- If you use PlatformIO, create a `platformio.ini` in the lab folder or at the workspace root and add the library dependencies there.
- Consider adding a top-level `.gitattributes` to normalize line endings if contributors use different OSes.

Most lab folders include a `LICENSE` file (MIT by default). Check the specific lab folder for licensing details.

Enjoy tinkering and learning!

