/* Arcade Control Board v1.0.0
   This code emulates a Keyboard and maps a 2-player joystick configuration for use with arcade emulators.
   Note: You must select "Keyboard" from the "Tools > USB Type" menu
   Author: David Khudaverdyan <khudaverdyan.david@gmail.com>
   License: MIT
   **Based on the Keyboard example provided by Arduino**
*/

#include <Bounce.h>

// The arcadeButton struct helps us organize all the buttons!
typedef struct {
  int pin;
  int key;
  Bounce bounce;
  bool pressed;
} arcadeButton;

/* General Configs */
#define LED_PIN 13 // Which pin is the LED on? This is 13 for the Teensy 3.6
#define DEBOUNCE_TIME 20 // In ms, increase this value if you see unintentional double-taps

/* Player 1 Pin Assignments */
#define P1_UP_PIN 2
#define P1_DOWN_PIN 3
#define P1_LEFT_PIN 4
#define P1_RIGHT_PIN 5
#define P1_B1_PIN 6
#define P1_B2_PIN 7
#define P1_B3_PIN 8
#define P1_B4_PIN 9
#define P1_B5_PIN 10
#define P1_B6_PIN 11
#define P1_B7_PIN 26 // Not used for current config
#define P1_B8_PIN 27 // Not used for current config
#define P1_A_PIN 28 // Not used for current config
#define P1_B_PIN 29 // Not used for current config
#define P1_START_PIN 30
#define P1_COIN_PIN 31

/* Player 2 Pin Assignments */
#define P2_UP_PIN 23
#define P2_DOWN_PIN 22
#define P2_LEFT_PIN 21
#define P2_RIGHT_PIN 20
#define P2_B1_PIN 19
#define P2_B2_PIN 18
#define P2_B3_PIN 17
#define P2_B4_PIN 16
#define P2_B5_PIN 15
#define P2_B6_PIN 14
#define P2_B7_PIN 39 // Not used for current config
#define P2_B8_PIN 38 // Not used for current config
#define P2_A_PIN 37 // Not used for current config
#define P2_B_PIN 36 // Not used for current config
#define P2_START_PIN 35
#define P2_COIN_PIN 34

/* Player 1 Keyboard Emulation Assignments */
#define P1_UP_KEY KEY_UP
#define P1_DOWN_KEY KEY_DOWN
#define P1_LEFT_KEY KEY_LEFT
#define P1_RIGHT_KEY KEY_RIGHT
#define P1_B1_KEY MODIFIERKEY_CTRL
#define P1_B2_KEY MODIFIERKEY_ALT
#define P1_B3_KEY KEY_SPACE
#define P1_B4_KEY MODIFIERKEY_SHIFT
#define P1_B5_KEY KEY_Z
#define P1_B6_KEY KEY_X
#define P1_B7_KEY KEY_C // Not used for current config
#define P1_B8_KEY KEY_V // Not used for current config
#define P1_A_KEY KEY_P // Not used for current config
#define P1_B_KEY KEY_ENTER // Not used for current config
#define P1_START_KEY KEY_1
#define P1_COIN_KEY KEY_5

/* Player 2 Keyboard Emulation Assignments */
#define P2_UP_KEY KEY_R
#define P2_DOWN_KEY KEY_F
#define P2_LEFT_KEY KEY_D
#define P2_RIGHT_KEY KEY_G
#define P2_B1_KEY KEY_A
#define P2_B2_KEY KEY_S
#define P2_B3_KEY KEY_Q
#define P2_B4_KEY KEY_W
#define P2_B5_KEY KEY_I
#define P2_B6_KEY KEY_K
#define P2_B7_KEY KEY_J // Not used for current config
#define P2_B8_KEY KEY_L // Not used for current config
#define P2_A_KEY KEY_TAB // Not used for current config
#define P2_B_KEY KEY_ESC // Not used for current config
#define P2_START_KEY KEY_2
#define P2_COIN_KEY KEY_6

/* Array of arcadeButton structs */
arcadeButton arcade_buttons[] = {
  // Player 1 structs:
  {P1_UP_PIN, P1_UP_KEY, Bounce(P1_UP_PIN, DEBOUNCE_TIME), false},
  {P1_DOWN_PIN, P1_DOWN_KEY, Bounce(P1_DOWN_PIN, DEBOUNCE_TIME), false},
  {P1_LEFT_PIN, P1_LEFT_KEY, Bounce(P1_LEFT_PIN, DEBOUNCE_TIME), false},
  {P1_RIGHT_PIN, P1_RIGHT_KEY, Bounce(P1_RIGHT_PIN, DEBOUNCE_TIME), false},
  {P1_B1_PIN, P1_B1_KEY, Bounce(P1_B1_PIN, DEBOUNCE_TIME), false},
  {P1_B2_PIN, P1_B2_KEY, Bounce(P1_B2_PIN, DEBOUNCE_TIME), false},
  {P1_B3_PIN, P1_B3_KEY, Bounce(P1_B3_PIN, DEBOUNCE_TIME), false},
  {P1_B4_PIN, P1_B4_KEY, Bounce(P1_B4_PIN, DEBOUNCE_TIME), false},
  {P1_B5_PIN, P1_B5_KEY, Bounce(P1_B5_PIN, DEBOUNCE_TIME), false},
  {P1_B6_PIN, P1_B6_KEY, Bounce(P1_B6_PIN, DEBOUNCE_TIME), false},
  {P1_B7_PIN, P1_B7_KEY, Bounce(P1_B7_PIN, DEBOUNCE_TIME), false},
  {P1_B8_PIN, P1_B8_KEY, Bounce(P1_B8_PIN, DEBOUNCE_TIME), false},
  {P1_A_PIN, P1_A_KEY, Bounce(P1_A_PIN, DEBOUNCE_TIME), false},
  {P1_B_PIN, P1_B_KEY, Bounce(P1_B_PIN, DEBOUNCE_TIME), false},
  {P1_START_PIN, P1_START_KEY, Bounce(P1_START_PIN, DEBOUNCE_TIME), false},
  {P1_COIN_PIN, P1_COIN_KEY, Bounce(P1_COIN_PIN, DEBOUNCE_TIME), false},

  // Player 2 structs:
  {P2_UP_PIN, P2_UP_KEY, Bounce(P2_UP_PIN, DEBOUNCE_TIME), false},
  {P2_DOWN_PIN, P2_DOWN_KEY, Bounce(P2_DOWN_PIN, DEBOUNCE_TIME), false},
  {P2_LEFT_PIN, P2_LEFT_KEY, Bounce(P2_LEFT_PIN, DEBOUNCE_TIME), false},
  {P2_RIGHT_PIN, P2_RIGHT_KEY, Bounce(P2_RIGHT_PIN, DEBOUNCE_TIME), false},
  {P2_B1_PIN, P2_B1_KEY, Bounce(P2_B1_PIN, DEBOUNCE_TIME), false},
  {P2_B2_PIN, P2_B2_KEY, Bounce(P2_B2_PIN, DEBOUNCE_TIME), false},
  {P2_B3_PIN, P2_B3_KEY, Bounce(P2_B3_PIN, DEBOUNCE_TIME), false},
  {P2_B4_PIN, P2_B4_KEY, Bounce(P2_B4_PIN, DEBOUNCE_TIME), false},
  {P2_B5_PIN, P2_B5_KEY, Bounce(P2_B5_PIN, DEBOUNCE_TIME), false},
  {P2_B6_PIN, P2_B6_KEY, Bounce(P2_B6_PIN, DEBOUNCE_TIME), false},
  {P2_B7_PIN, P2_B7_KEY, Bounce(P2_B7_PIN, DEBOUNCE_TIME), false},
  {P2_B8_PIN, P2_B8_KEY, Bounce(P2_B8_PIN, DEBOUNCE_TIME), false},
  {P2_A_PIN, P2_A_KEY, Bounce(P2_A_PIN, DEBOUNCE_TIME), false},
  {P2_B_PIN, P2_B_KEY, Bounce(P2_B_PIN, DEBOUNCE_TIME), false},
  {P2_START_PIN, P2_START_KEY, Bounce(P2_START_PIN, DEBOUNCE_TIME), false},
  {P2_COIN_PIN, P2_COIN_KEY, Bounce(P2_COIN_PIN, DEBOUNCE_TIME), false}
};

// Having numButtons defined at compile-time lets us vary
// the size of the array without manually setting the size.
#define numButtons (sizeof(arcade_buttons)/sizeof(arcadeButton))

// The num_inputs variable keeps track of the current number of active inputs
int num_inputs;

/* Set initialization options */
void setup() {
  // The LED pin needs to be set to OUTPUT so we can control it
  pinMode(LED_PIN, OUTPUT);

  // This is using a pullup resistor configuration. The buttons should be connected to
  // the specified pin and ground. When the path between the pin and ground is closed
  // this is seen as "LOW" which is considered a button press.
  // The Teensy has built-in pullup resistors, so the button should be wired directly to the pin
  /* Loop through all the buttons and set the inputs to INPUT_PULLUP */
  for (unsigned int i = 0; i < numButtons; i++) {
    pinMode(arcade_buttons[i].pin, INPUT_PULLUP);
  }

  num_inputs = 0; // Set the initial configuration to 0, no buttons are being pressed

  digitalWrite(LED_PIN, HIGH); // Turn on the LED on startup, this should turn off once the event loop starts
}

void loop() {
  // The event loop runs faster than buttons can be pressed, so we can check all the buttons each loop
  for (unsigned int i = 0; i < numButtons; i++) {
    arcade_buttons[i].bounce.update(); // This updates the values within the Bounce object
    // Check if we have a "falling edge" on a button, that is when it has been pressed down
    if (arcade_buttons[i].bounce.fallingEdge()) {
      // Check to see if we have already "pressed" this button
      if (!arcade_buttons[i].pressed) {
        // Send the corresponding keyboard press to the attached computer
        Keyboard.press(arcade_buttons[i].key);
        // Set the "pressed" value to "true" and increment the number of active inputs
        arcade_buttons[i].pressed = true;
        num_inputs ++;
      }
      // Check if we have a "rising edge" on a button, that is when it has been let go
    } else if (arcade_buttons[i].bounce.risingEdge()) {
      // Check to see if we had "pressed" this button
      if (arcade_buttons[i].pressed) {
        // Send the corresponding keyboard release to the attached computer
        Keyboard.release(arcade_buttons[i].key);
        // Set the "pressed" value to "false" and decrement the number of active inputs
        arcade_buttons[i].pressed = false;
        num_inputs --;
      }
    }

  }

  // Check the number of active inputs, if any buttons are pressed, turn on the LED
  if (num_inputs > 0) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}

