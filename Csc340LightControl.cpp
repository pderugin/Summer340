/**
 * \mainpage
 *   <h1>
 *     <b>In Class Exercise 1</b>
 *   </h1>
 *   <h3>
 *     CSC 340 Summer 2015 <br>
 *     Team Members: Paul Derugin, Junteng Tan <br>
 *   </h3>
 *   <p>
 *     This program simulates a home lighting system that operates using an
 *     embedded controller. The lights are controlled by a single byte
 *     that is (simulated) sent to a control function.  The control function
 *     is simulated by printing the settings that are passed to it.
 *
 *     A menu system allows the user to toggle each light.  The system defaults
 *     to all lights on.
 *
 *     The control word is laid out in the following manner:
 *
 *     <center>
 *      |bit|  description  |
 *      |---|---------------|
 *      | 0 |Garage         |
 *      | 1 |Entry          |
 *      | 2 |Living         |
 *      | 3 |Kitchen        |
 *      | 4 |Bed            |
 *      | 5 |N/A (must be 0)|
 *      | 6 |N/A (must be 0)|
 *      | 7 |N/A (must be 0)|
 *     </center>
 *
 *     When a bit is 1 the lights in the specified area are turned on; when a bit
 *     is 0 the lights are turned off. Bits 5 through 7 should always be off.
 *   </p>
 */

#include <iostream>
using namespace std;

//function prototype
void control(unsigned char);
int menu(unsigned char);
unsigned char trigger(int, unsigned char);

// Bitmasks for each device which is being controlled

// Bitmask for garage bit
const unsigned char GARAGE_LIGHT = 1;

// Bitmask for entry bit
const unsigned char ENTRY_LIGHT = 2;

// Bitmask for living bit
const unsigned char LIVING_LIGHT = 4;

// Bitmask for kitchen bit
const unsigned char KITCHEN_LIGHT = 8;

// Bitmask for bed bit
const unsigned char BED_LIGHT = 16;

// Bitmask for all lights bits
const unsigned char ALL_LIGHT = 31;

/**
 * The system initialization; main control loop of the program
 */
int main() {
    unsigned char lightStatus = 0;
    int userOption = 0;

    cout << "\n            Home Light Control System"
         << "\n ************************************************** \n";

    //turn all the lights on when program starts
    lightStatus = ALL_LIGHT;

    do {
        control(lightStatus);
        userOption = menu(lightStatus);
        lightStatus = trigger(userOption, lightStatus);
    }
    while (userOption != 0);

    // when exiting the control program, turn all lights on
    lightStatus = ALL_LIGHT;
    control(lightStatus);

    return 0;
}

/**
 * Prints a menu for the lighting control; gets input from user (to be sent to
 * the trigger() function).
 *
 * @param setting unsigned char the current status of the lights to print light
 *        status from menu.
 * @return int containing the menu option user entered.
 */
int menu(unsigned char setting) {
    int userOption = 0;

    cout << "\n            Setting Menu"
    << "\n-----------------------------------------"
    << "\n 0. Exit Programming";

    if (GARAGE_LIGHT & setting)
        cout << "\n 1. Garage: On";
    else
        cout << "\n 1. Garage: off";

    if (ENTRY_LIGHT & setting)
        cout << "\n 2. Entry: On";
    else
        cout << "\n 2. Entry: off";

    if (LIVING_LIGHT & setting)
        cout << "\n 3. Living: On";
    else
        cout << "\n 3. Living: off";

    if (KITCHEN_LIGHT & setting)
        cout << "\n 4. Kitchen: On";
    else
        cout << "\n 4. Kitchen: off";

    if (BED_LIGHT & setting)
        cout << "\n 5. Bed: On";
    else
        cout << "\n 5. Bed: off";

    cout << "\n Choose the light that you want to switch on/off (number only): ";
    cin >> userOption;

    return userOption;
}

/**
 * Toggles a particular light (based on the menu option the user entered) and
 * updates the status.
 *
 * @param userOption int the menu option that the user entered.
 * @param setting unsigned char the current status of the lights.
 * @return unsigned char the status of the lights after they have been modified
 *         by this function.
 */

unsigned char trigger(int userOption, unsigned char setting) {
    unsigned char currentSetting = setting;

    switch (userOption) {
    case 1:
        currentSetting = GARAGE_LIGHT ^ currentSetting;
        break;

    case 2:
        currentSetting = ENTRY_LIGHT ^ currentSetting;
        break;

    case 3:
        currentSetting = LIVING_LIGHT ^ currentSetting;
        break;

    case 4:
        currentSetting = KITCHEN_LIGHT ^ currentSetting;
        break;

    case 5:
        currentSetting = BED_LIGHT ^ currentSetting;
        break;

    default:
        cout << "\n Thank you!!!" << endl;
        break;
    }

    return currentSetting;
}

/**
 * Simulates the actual control settings for the light control system by
 * printing out the settings that are passed to it in a control byte.
 *
 * @param setting unsigned char the byte that is sent to the light control
 */
void control(unsigned char setting) {
    cout << "\n            Light Status Menu"
    << "\n-----------------------------------------";

    if (GARAGE_LIGHT & setting)
        cout << "\n Garage: ON";
    else
        cout << "\n Garage: OFF";

    if (ENTRY_LIGHT & setting)
        cout << "\n Entry: ON";
    else
        cout << "\n Entry: OFF";

    if (LIVING_LIGHT & setting)
        cout << "\n Living: ON";
    else
        cout << "\n Living: OFF";

    if (KITCHEN_LIGHT & setting)
        cout << "\n Kitchen: ON";
    else
        cout << "\n Kitchen: OFF";

    if (BED_LIGHT & setting)
        cout << "\n Bed: ON";
    else
        cout << "\n Bed: OFF";

    cout << endl;
}
