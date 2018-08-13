# Teensy Arcade Keyboard
Easily configurable code for a Teensy 3.6 for use as a 2-player controller by emulating a keyboard.

## Requirements

1) [A Teensy](https://www.pjrc.com/store/teensy36.html) - The code is meant for a Teensy 3.6 out-of-the-box but can be easily modified for any Teensy by changing the pin assignments.
2) [The Arduino IDE](https://www.arduino.cc/en/Main/Software)
3) [The Teensyduino Arduino Add-On](https://www.pjrc.com/teensy/td_download.html)

## Configuration

### Globals
| Name | Description | Default |
| ---- | ----------- | ------- |
| `LED_PIN` | The pin responsible for the built-in LED. Default is for the Teensy 3.6 | `13` |
| `DEBOUNCE_TIME` | In ms, how much time to allow for debouncing | `20` |

### Pins
Layout (Teensy 3.6):
```
           _______USB_______
  Ground  |(gnd)         (X)|  
          |(0)           (X)|  
          |(1)           (X)|  
   P1_UP  |(2)          (23)|  P2_UP
 P1_DOWN  |(3)          (22)|  P2_DOWN
 P1_LEFT  |(4)          (21)|  P2_LEFT
P1_RIGHT  |(5)          (20)|  P2_RIGHT
   P1_B1  |(6)          (19)|  P2_B1
   P1_B2  |(7)          (18)|  P2_B2
   P1_B3  |(8)    ___   (17)|  P2_B3
   P1_B4  |(9)   |   |  (16)|  P2_B4
   P1_B5  |(10)  | I |  (15)|  P2_B5
   P1_B6  |(11)  | C |  (14)|  P2_B6
          |(12)  |   |  (13)|  LED (built-in)
          |(X)   |___| (gnd)|  Ground
          |(24)          (X)|
          |(25)          (X)|
   P1_B7  |(26)         (39)|  P2_B7
   P1_B8  |(27)         (38)|  P2_B8
    P1_A  |(28)         (37)|  P2_A
    P1_B  |(29)         (36)|  P2_B
P1_START  |(30)         (35)|  P2_START
 P1_COIN  |(31)         (34)|  P2_COIN
          |(32)         (33)|  
           -----------------
```
Note: Default pin assignments put P1 and P2 buttons directly across the board from each other (mirrored).

| Name | Description | Pin (default) |
| ---- | ----------- | ------------- |
| `P1_UP_PIN` | Player 1 Joystick Up | `2` |
| `P1_DOWN_PIN` | Player 1 Joystick Down | `3` |
| `P1_LEFT_PIN` | Player 1 Joystick Left | `4` |
| `P1_RIGHT_PIN` | Player 1 Joystick Right | `5` |
| `P1_B1_PIN` | Player 1 Button 1 | `6` |
| `P1_B2_PIN` | Player 1 Button 2 | `7` |
| `P1_B3_PIN` | Player 1 Button 3 | `8` |
| `P1_B4_PIN` | Player 1 Button 4 | `9` |
| `P1_B5_PIN` | Player 1 Button 5 | `10` |
| `P1_B6_PIN` | Player 1 Button 6 | `11` |
| `P1_B7_PIN` | Player 1 Button 7 | `26` |
| `P1_B8_PIN` | Player 1 Button 8 | `27` |
| `P1_A_PIN` | Player 1 Button "A" | `28` |
| `P1_B_PIN` | Player 1 Button "B" | `29` |
| `P1_START_PIN` | Player 1 Start Button | `30` |
| `P1_COIN_PIN` | Player 1 Coin/Select Button | `31` |
| `P2_UP_PIN` | Player 2 Joystick Up | `23` |
| `P2_DOWN_PIN` | Player 2 Joystick Down | `22` |
| `P2_LEFT_PIN` | Player 2 Joystick Left | `21` |
| `P2_RIGHT_PIN` | Player 2 Joystick Right | `20` |
| `P2_B1_PIN` | Player 2 Button 1 | `19` |
| `P2_B2_PIN` | Player 2 Button 2 | `18` |
| `P2_B3_PIN` | Player 2 Button 3 | `17` |
| `P2_B4_PIN` | Player 2 Button 4 | `16` |
| `P2_B5_PIN` | Player 2 Button 5 | `15` |
| `P2_B6_PIN` | Player 2 Button 6 | `14` |
| `P2_B7_PIN` | Player 2 Button 7 | `39` |
| `P2_B8_PIN` | Player 2 Button 8 | `38` |
| `P2_A_PIN` | Player 2 Button "A" | `37` |
| `P2_B_PIN` | Player 2 Button "B" | `36` |
| `P2_START_PIN` | Player 2 Start Button | `35` |
| `P2_COIN_PIN` | Player 2 Coin/Select Button | `34` |


### Keys
The default keyboard layout is based on the layout listed in the RetroPie documentation.
Take a look [here](https://github.com/RetroPie/RetroPie-Setup/wiki/Keyboard-Controllers#keyboard-mode-default-keys) if your desire to know more has intensified...

Layout (Player 1):
```
 ___        (Start)       (Coin)
| 0 | (B1) (B3) (B5) (B7)
|___| (B2) (B4) (B6) (B8)

0 = Stick (up/down/left/right)
```

| Name | Description (default) | Key (default) |
| ---- | ----------- | ------------- |
| `P1_UP_KEY` | Up Arrow Key | `KEY_UP` |
| `P1_DOWN_KEY` | Down Arrow Key | `KEY_DOWN` |
| `P1_LEFT_KEY` | Left Arrow Key | `KEY_LEFT` |
| `P1_RIGHT_KEY` | Right Arrow Key | `KEY_RIGHT` |
| `P1_B1_KEY` | Left Control Key | `MODIFIERKEY_CTRL` |
| `P1_B2_KEY` | Left Alt Key | `MODIFIERKEY_ALT` |
| `P1_B3_KEY` | Spacebar Key | `KEY_SPACE` |
| `P1_B4_KEY` | Left Shift Key | `MODIFIERKEY_SHIFT` |
| `P1_B5_KEY` | Z Key | `KEY_Z` |
| `P1_B6_KEY` | X Key | `KEY_X` |
| `P1_B7_KEY` | C Key | `KEY_C` |
| `P1_B8_KEY` | V Key | `KEY_V` |
| `P1_A_KEY` | P Key | `KEY_P` |
| `P1_B_KEY` | Enter Key | `KEY_ENTER` |
| `P1_START_KEY` | 1 Key | `KEY_1` |
| `P1_COIN_KEY` | 5 Key | `KEY_5` |
| `P2_UP_KEY` | R Key | `KEY_R` |
| `P2_DOWN_KEY` | F Key | `KEY_F` |
| `P2_LEFT_KEY` | D Key | `KEY_D` |
| `P2_RIGHT_KEY` | G Key | `KEY_G` |
| `P2_B1_KEY` | A Key | `KEY_A` |
| `P2_B2_KEY` | S Key | `KEY_S` |
| `P2_B3_KEY` | Q Key | `KEY_Q` |
| `P2_B4_KEY` | W Key | `KEY_W` |
| `P2_B5_KEY` | I Key | `KEY_I` |
| `P2_B6_KEY` | K Key | `KEY_K` |
| `P2_B7_KEY` | J Key | `KEY_J` |
| `P2_B8_KEY` | L Key | `KEY_L` |
| `P2_A_KEY` | Tab Key | `KEY_TAB` |
| `P2_B_KEY` | Escape Key | `KEY_ESC` |
| `P2_START_KEY` | 2 Key | `KEY_2` |
| `P2_COIN_KEY` | 6 Key | `KEY_6` |

## Wiring
All buttons should have a shared ground. The Teensy 3.6 has 2 ground pins you can use (Show in diagram above).

Each button should connect directly to the corresponding pin show in the diagram. No additional resistors are needed.
The buttons should short on press (most micro-switches have two ways to connect cables, make sure you've connected the right pins).

```
T|gnd-------Button 1------Button 2----- etc
e|             |             |
e|button1_pin__|             |
n|                           |
s|button2_pin________________|
y|

```

## Arduino IDE
* Make sure that the correct Teensy is selected as the device.
  * From the Menu: Tools -> Board -> Teensy 3.6
* Set the USB Type to "Keyboard"
  * From the Menu: Tools -> USB Type -> Keyboard.
  * This is required for the Keyboard imports to work.
