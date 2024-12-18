// ###########################################################################################################################################
// #
// # Code for the printables AWSW "Custom 16 button macro keyboard" project:
// # https://www.printables.com/model/1111030-custom-16-button-macro-keyboard
// #
// # Code by https://github.com/AWSW-de
// #
// # Released under license: GNU General Public License v3.0: https://github.com/AWSW-de/Custom-16-button-macro-keyboard#GPL-3.0-1-ov-file
// #
// ###########################################################################################################################################


// ###########################################################################################################################################
// # Includes:
// #
// # You will need to add the following libraries to your Arduino IDE to use the project:
// # - ezButton                ArduinoGetStarted    (V1.0.6)           https://arduinogetstarted.com/tutorials/arduino-button-library
// #
// ###########################################################################################################################################


// ###########################################################################################################################################
// Version: V1.0.0 - 15.12.2024
// ###########################################################################################################################################


// ###########################################################################################################################################
#include <ezButton.h>  // ezButton library >>> https://arduinogetstarted.com/tutorials/arduino-button-library
#include <Keyboard.h>  // Arduino default library
// ###########################################################################################################################################


// ###########################################################################################################################################
// By the Arduino keyboard library supported keyboard layouts set in the void_setup startup function:
//  KeyboardLayout_de_DE
//  KeyboardLayout_en_US
//  KeyboardLayout_es_ES
//  KeyboardLayout_fr_FR
//  KeyboardLayout_it_IT
//  KeyboardLayout_pt_PT
//  KeyboardLayout_sv_SE
//  KeyboardLayout_da_DK
//  KeyboardLayout_hu_HU
// ###########################################################################################################################################


// ###########################################################################################################################################
const int BUTTON_NUM = 16;         // Amount of keyboard switches in this button array
const int DEFAULTWAITVALUE = 100;  // Default wait value after each key press to give the computer the time to react to the received command
const int BUTTON_01_PIN = 2;       // Keyboard switch 1 (upper left from the front view)
const int BUTTON_02_PIN = 3;       // Keyboard switch 2
const int BUTTON_03_PIN = 4;       // Keyboard switch 3
const int BUTTON_04_PIN = 5;       // Keyboard switch 4
const int BUTTON_05_PIN = 6;       // Keyboard switch 5
const int BUTTON_06_PIN = 7;       // Keyboard switch 6
const int BUTTON_07_PIN = 8;       // Keyboard switch 7
const int BUTTON_08_PIN = 9;       // Keyboard switch 8
const int BUTTON_09_PIN = 10;      // Keyboard switch 9
const int BUTTON_10_PIN = 16;      // Keyboard switch 10
const int BUTTON_11_PIN = 14;      // Keyboard switch 11
const int BUTTON_12_PIN = 15;      // Keyboard switch 12
const int BUTTON_13_PIN = A0;      // Keyboard switch 13
const int BUTTON_14_PIN = A1;      // Keyboard switch 14
const int BUTTON_15_PIN = A2;      // Keyboard switch 15
const int BUTTON_16_PIN = A3;      // Keyboard switch 16
// ###########################################################################################################################################


// ###########################################################################################################################################
ezButton buttonArray[] = {  // Create the button array
  ezButton(BUTTON_01_PIN),
  ezButton(BUTTON_02_PIN),
  ezButton(BUTTON_03_PIN),
  ezButton(BUTTON_04_PIN),
  ezButton(BUTTON_05_PIN),
  ezButton(BUTTON_06_PIN),
  ezButton(BUTTON_07_PIN),
  ezButton(BUTTON_08_PIN),
  ezButton(BUTTON_09_PIN),
  ezButton(BUTTON_10_PIN),
  ezButton(BUTTON_11_PIN),
  ezButton(BUTTON_12_PIN),
  ezButton(BUTTON_13_PIN),
  ezButton(BUTTON_14_PIN),
  ezButton(BUTTON_15_PIN),
  ezButton(BUTTON_16_PIN)
};
// ###########################################################################################################################################


// ###########################################################################################################################################
void setup() {                             // Startup function
  Serial.begin(115200);                    // Init serial monitor
  Keyboard.begin(KeyboardLayout_de_DE);    // Init keyboard in DE language layout. For other language layouts see list above
  for (byte i = 0; i < BUTTON_NUM; i++) {  // Init the keyboard switches and set their debounce time value
    buttonArray[i].setDebounceTime(50);    // set debounce time to x milliseconds
  }
}
// ###########################################################################################################################################


// ###########################################################################################################################################
void loop() {                                                   // Runtime function
  for (byte i = 0; i < BUTTON_NUM; i++) buttonArray[i].loop();  // MUST call the loop() function first
  for (byte i = 0; i < BUTTON_NUM; i++) {                       // Catch switch button press events (not used in this code)
    if (buttonArray[i].isPressed()) {                           // Button press event - is not used in this code to avoid multiple callups
      // Serial.print("The button ");
      // Serial.print(i + 1);
      // Serial.println(" is pressed");
    }
    if (buttonArray[i].isReleased()) {  // Button release event
      // Serial.print("The button ");
      // Serial.print(i + 1);
      // Serial.println(" is released");
      button_action(i + 1);  // Start action on button release (Called here on button releease to avoid severall calls when the button is pressed longer...)
    }
  }
}
// ###########################################################################################################################################


// ###########################################################################################################################################
// Command references for the keyboard commands:
// #############################################
// Arduino keyboard:   https://reference.arduino.cc/reference/en/language/functions/usb/keyboard/
// Keyboard modifiers: https://reference.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
// Ascii code numbers: https://docs.arduino.cc/built-in-examples/communication/ASCIITable/ >>> https://www.asciitable.com/
// ###########################################################################################################################################


// ###########################################################################################################################################
void button_action(int pressedbuttonnumber) {  // Button actions function with the send keyboard acions for each keyboard swith:
  switch (pressedbuttonnumber) {
    case 1:  // Use CTRL+C:
      {
        Keyboard.press(KEY_LEFT_CTRL);  // Press and hold the LEFT CTRL key
        Keyboard.press('c');            // Press and hold the 'c' key
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.releaseAll();          // Release both of the above keys
        break;
      }
    case 2:  // Use CTRL+V:
      {
        Keyboard.press(KEY_LEFT_CTRL);  // Press and hold the LEFT CTRL key
        Keyboard.press('v');            // Press and hold the 'v' key
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.releaseAll();          // Release both of the above keys
        break;
      }
    case 3:  // Use CTRL+X:
      {
        Keyboard.press(KEY_LEFT_CTRL);  // Press and hold the LEFT CTRL key
        Keyboard.press('x');            // Press and hold the 'x' key
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.releaseAll();          // Release both of the above keys
        break;
      }
    case 4:  // Use CTRL+Z:
      {
        Keyboard.press(KEY_LEFT_CTRL);  // Press and hold the LEFT CTRL key
        Keyboard.print('z');            // Press and hold the 'z' key
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.releaseAll();          // Release both of the above keys
        break;
      }
    case 5:  // If: ( if (variable1 == variable2) {} )
      {
        Keyboard.print("if");        // if
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("(");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("var1");      // text
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(61);          // =
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(61);          // =
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("var2");      // text
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(")");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("{");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        Keyboard.print("}");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release the Enter key
        break;
      }
    case 6:  // Else: ( else {} )
      {
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("else");      // else
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("{");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // Press the Enter key
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release the Enter key
        Keyboard.press(KEY_RETURN);  // Press the Enter key
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release the Enter key
        Keyboard.print("}");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release the Enter key
        break;
      }
    case 7:  // For loop: ( for (int i = 0; i >= 5; i++) {} )
      {
        Keyboard.print("f");         // for
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("o");         // for
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("r");         // for
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("(");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("i");         // int
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("n");         // int
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("t");         // int
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("i");         // i
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(61);          // =
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("0");         // 0
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(59);          // ;
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("i");         // i
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(60);          // <
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(61);          // =
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("5");         // 5
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(59);          // ;
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("i");         // i
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(43);          // +
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(43);          // +
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(")");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("{");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        Keyboard.print("}");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        break;
      }
    case 8:  // Switch: ( switch case with 5 int values )
      {
        Keyboard.print("s");            // switch
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print("w");            // switch
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print("i");            // switch
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print("t");            // switch
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print("c");            // switch
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print("h");            // switch
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print(" ");            // blank
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print("(");            // bracket
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print("v");            // switch variable
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print("a");            // switch variable
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print("r");            // switch variable
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print(")");            // bracket
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print(" ");            // blank
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.print("{");            // bracket
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.press(KEY_RETURN);     // enter
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.releaseAll();          // Release all keys
        for (int i = 1; i <= 5; i++) {  // Repeat actions 5 times
          Keyboard.print("c");          // case
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.print("a");          // case
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.print("s");          // case
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.print("e");          // case
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.print(" ");          // blank
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.print(i);            // 1
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.write(58);           // :
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.print(" ");          // blank
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.print("{");          // bracket
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.press(KEY_RETURN);   // enter
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.releaseAll();        // Release all keys
          Keyboard.press(KEY_RETURN);   // enter
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.releaseAll();        // Release all keys
          Keyboard.print("b");          // break
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.print("r");          // break
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.print("e");          // break
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.print("a");          // break
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.print("k");          // break
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.write(59);           // ;
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.press(KEY_RETURN);   // enter
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.releaseAll();        // Release all keys
          Keyboard.print("}");          // bracket
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.press(KEY_RETURN);   // enter
          delay(DEFAULTWAITVALUE);      // Wait
          Keyboard.releaseAll();        // Release all keys
        }
        Keyboard.print("}");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        break;
      }
    case 9:  // Do While loop: ( do { // some actions } while (condition); )
      {
        Keyboard.print("d");         // do
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("o");         // do
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("{");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        Keyboard.write(47);          // /
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(47);          // /
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("s");         // some
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("o");         // some
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("m");         // some
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("e");         // some
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("a");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("c");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("t");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("i");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("o");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("n");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("s");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("}");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("while");     // while
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("(");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("c");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("o");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("n");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("d");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("i");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("t");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("i");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("o");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("n");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(")");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(59);          // ;
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        break;
      }
    case 10:  // While loop: ( while (condition) { // some actions } )
      {
        Keyboard.print("while");     // while
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("(");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("c");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("o");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("n");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("d");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("i");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("t");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("i");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("o");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("n");         // condition
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(")");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("{");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        Keyboard.write(47);          // /
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(47);          // /
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("s");         // some
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("o");         // some
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("m");         // some
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("e");         // some
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("a");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("c");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("t");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("i");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("o");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("n");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("s");         // actions
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("}");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        break;
      }
    case 11:  // Void ( void functionname() {} )
      {
        Keyboard.print("void");      // void
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("f");         // function
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("u");         // function
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("n");         // function
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("c");         // function
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("t");         // function
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("i");         // function
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("o");         // function
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("n");         // function
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("n");         // name
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("a");         // name
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("m");         // name
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("e");         // name
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("(");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(")");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print(" ");         // blank
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.print("{");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        Keyboard.print("}");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        break;
      }
    case 12:  // Array ( int myarray[] = { 1, 2, 3 }; )
      {
        Keyboard.print("i");               // int
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print("n");               // int
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print("t");               // int
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print(" ");               // blank
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print("m");               // array name
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print("y");               // array name
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print("a");               // array name
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print("r");               // array name
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print("r");               // array name
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print("a");               // array name
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print("y");               // array name
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.write(91);                // [
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.write(93);                // ]
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print(" ");               // blank
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.write(61);                // =
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print(" ");               // blank
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print("{");               // bracket
        delay(DEFAULTWAITVALUE);           // Wait
        Keyboard.print(" ");               // blank
        delay(DEFAULTWAITVALUE);           // Wait
        for (int i = 1; i <= 5; i++) {     // Repeat actions 5 times
          Keyboard.print(i);               // case
          delay(DEFAULTWAITVALUE);         // Wait
          if (i != 5) Keyboard.write(44);  // ,
          delay(DEFAULTWAITVALUE);         // Wait
          Keyboard.print(" ");             // blank
          delay(DEFAULTWAITVALUE);         // Wait
        }
        Keyboard.print("}");         // bracket
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.write(59);          // ;
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.press(KEY_RETURN);  // enter
        delay(DEFAULTWAITVALUE);     // Wait
        Keyboard.releaseAll();       // Release all keys
        break;
      }

    case 13:  // Start the Windows Explorer:
      {
        Keyboard.press(KEY_LEFT_GUI);  // Press and hold the Windows key
        Keyboard.press('e');           // Press and hold the 'r' key
        delay(DEFAULTWAITVALUE);       // Wait
        Keyboard.releaseAll();         // Release both of the above keys
        break;
      }
    case 14:  // Show the Windows Desktop:
      {
        Keyboard.press(KEY_LEFT_GUI);  // Press and hold the Windows key
        Keyboard.press('d');           // Press and hold the 'd' key
        delay(DEFAULTWAITVALUE);       // Wait
        Keyboard.releaseAll();         // Release both of the above keys
        break;
      }
    case 15:  // Start the Windows Terminal as Administrator:
      {
        Keyboard.press(KEY_LEFT_GUI);    // Press and hold the Windows key
        Keyboard.press('r');             // Press and hold the 'r' key
        delay(DEFAULTWAITVALUE);         // Wait
        Keyboard.releaseAll();           // Release both of the above keys
        delay(500);                      // Wait for the Windows Run Dialog to open
        Keyboard.print("powershell");    // Type "powershell"
        Keyboard.press(KEY_LEFT_CTRL);   // Press the LEFT CTRL key
        Keyboard.press(KEY_LEFT_SHIFT);  // Press the LEFT SHIFT key
        Keyboard.press(KEY_RETURN);      // Press the Enter key
        Keyboard.releaseAll();           // Release the Enter key
        delay(1000);
        Keyboard.press(KEY_LEFT_ARROW);  // Press the LEFT Arrow key
        Keyboard.releaseAll();           // Release the Enter key
        delay(500);
        Keyboard.press(KEY_RETURN);  // Press the Enter key
        Keyboard.releaseAll();       // Release the Enter key
        break;
      }
    case 16:  // Start the GitHub Desktop application: (Note: You need to set CTRL+ALT+F5 in the keyboard shortcut of the GitHub Desktop application desktop icon)
      {
        Keyboard.press(KEY_LEFT_CTRL);  // Press and hold the CTRL key
        Keyboard.press(KEY_LEFT_ALT);   // Press and hold the ALT key
        Keyboard.press(KEY_F5);         // Press and hold the 'F5' key
        delay(DEFAULTWAITVALUE);        // Wait
        Keyboard.releaseAll();          // Release the Enter key

        // Alternative way to use it with the Windows Run command:
        // Keyboard.press(KEY_LEFT_GUI);  // Press and hold the Windows key
        // Keyboard.press('r');           // Press and hold the 'r' key
        // delay(DEFAULTWAITVALUE);       // Wait
        // Keyboard.releaseAll();         // Release both of the above keys
        // delay(500);                    // Wait for the Windows Run Dialog to open
        // Keyboard.print("github");      // Type "github"
        // Keyboard.press(KEY_RETURN);    // Press the Enter key
        // delay(DEFAULTWAITVALUE);       // Wait
        // Keyboard.releaseAll();         // Release the Enter key
        // delay(3000);
        // Keyboard.press(KEY_ESC);       // Press the Escape key to close a popup
        // delay(DEFAULTWAITVALUE);       // Wait
        // Keyboard.releaseAll();         // Release the Enter key
        break;
      }
  }
}
// ###########################################################################################################################################