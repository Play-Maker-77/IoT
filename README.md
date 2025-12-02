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

1. Install the Arduino IDE (or PlatformIO for VS Code).
2. Open the lab folder you want to try (for example `Lab 1 - Blinking LED`) in the Arduino IDE.
3. Install any libraries listed in that lab's `Libraries.txt`. For the Arduino IDE you can install them via Sketch → Include Library → Manage Libraries... or by adding them to your sketchbook `libraries` folder.
4. Select your board and port, then upload the sketch.

Notes and recommendations

- Use the `Libraries.txt` file in each lab folder as the source of required libraries. Common libraries used across the repo include Adafruit GFX and LiquidCrystal I2C.
- If you use PlatformIO, create a `platformio.ini` in the lab folder or at the workspace root and add the library dependencies there.
- Consider adding a top-level `.gitattributes` to normalize line endings if contributors use different OSes.

Contributing

If you want to improve lab content, add sketches, or fix wiring diagrams, please open a pull request. When adding new libraries, prefer adding them to the lab's `Libraries.txt` and include install instructions if they're not available through the Arduino Library Manager.

License

Most lab folders include a `LICENSE` file (MIT by default). Check the specific lab folder for licensing details.

Enjoy tinkering and learning!

