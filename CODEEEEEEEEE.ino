#include <Keyboard.h>
#include <Mouse.h>

// SDVX CODE
// U1 - Seeed XIAO RP2040

// Buttons
// Sw1 -> D0
// Sw2 -> D1
// Sw3 -> D2
// Sw4 -> D3
// Sw5 -> D4
// Sw6 -> D5
// Sw7 -> D6

// Left Encoder
// A -> D7
// B -> D8

// Right Encoder
// A -> D9
// B -> D10

// Encoder pin definitions
const int ENC1_A = D7;
const int ENC1_B = D8;

const int ENC2_A = D9;
const int ENC2_B = D10;

// Encoder state variables
int currentA = 0;
int currentB = 0;
int lastA = 0;

int current2A = 0;
int current2B = 0;
int last2A = 0;

bool btn1Down = false;
bool btn2Down = false;
bool btn3Down = false;
bool btn4Down = false;
bool btn5Down = false;
bool btn6Down = false;
bool btn7Down = false;

void handleButton(int pin, char key, bool &wasDown)
{
    bool pressed = (digitalRead(pin) == LOW);

    if (pressed && !wasDown)
        Keyboard.press(key);

    if (!pressed && wasDown)
        Keyboard.release(key);

    wasDown = pressed;
}


void setup()
{
    Keyboard.begin();
    Mouse.begin();

    // Buttons
    pinMode(D0, INPUT_PULLUP);
    pinMode(D1, INPUT_PULLUP);
    pinMode(D2, INPUT_PULLUP);
    pinMode(D3, INPUT_PULLUP);
    pinMode(D4, INPUT_PULLUP);
    pinMode(D5, INPUT_PULLUP);
    pinMode(D6, INPUT_PULLUP);

    // Encoders
    pinMode(ENC1_A, INPUT_PULLUP);
    pinMode(ENC1_B, INPUT_PULLUP);

    pinMode(ENC2_A, INPUT_PULLUP);
    pinMode(ENC2_B, INPUT_PULLUP);

    // Initialize encoder state
    lastA = digitalRead(ENC1_A);
    last2A = digitalRead(ENC2_A);
}

void loop()
{
    handleButton(D0, 'd', btn1Down);
    handleButton(D1, 'f', btn2Down);
    handleButton(D2, 'j', btn3Down);
    handleButton(D3, 'k', btn4Down);
    handleButton(D4, 'c', btn5Down);
    handleButton(D5, 'm', btn6Down);
    handleButton(D6, '1', btn7Down);
 
    // Left Encoder (D7/D8)

    currentA = digitalRead(ENC1_A);

    if (currentA != lastA)
    {
        currentB = digitalRead(ENC1_B);

        if (currentB != currentA)
        {
             Mouse.move(-4, 0, 0);
        }
        else
        {
            Mouse.move(4, 0, 0);
        }

        lastA = currentA;
    }

    
    // Right Encoder (D9/D10)
   
    current2A = digitalRead(ENC2_A);

    if (current2A != last2A)
    {
        current2B = digitalRead(ENC2_B);

        if (current2B != current2A)
        {
            Mouse.move(0, -4, 0);
        }
        else
        {
            Mouse.move(0, 4, 0);
        }

        last2A = current2A;
    }
}