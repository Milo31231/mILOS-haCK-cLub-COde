// SDVX CODE
// U1 - Seeeduino XIAO

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

void setup()
{
    Serial.begin(115200);

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
    // Buttons
    if (digitalRead(D0) == LOW)
        Serial.println("1");

    if (digitalRead(D1) == LOW)
        Serial.println("2");

    if (digitalRead(D2) == LOW)
        Serial.println("3");

    if (digitalRead(D3) == LOW)
        Serial.println("4");

    if (digitalRead(D4) == LOW)
        Serial.println("5");
 
    if (digitalRead(D5) == LOW)
        Serial.println("6");

    if (digitalRead(D6) == LOW)
        Serial.println("7");

 
    // right Encoder (D7/D8)

    currentA = digitalRead(ENC1_A);

    if (currentA != lastA)
    {
        currentB = digitalRead(ENC1_B);

        if (currentB != currentA)
        {
            Serial.println("Left Encoder Left");
        }
        else
        {
            Serial.println("Left Encoder Right");
        }

        lastA = currentA;
    }

    
    // left Encoder (D9/D10)
   
    current2A = digitalRead(ENC2_A);

    if (current2A != last2A)
    {
        current2B = digitalRead(ENC2_B);

        if (current2B != current2A)
        {
            Serial.println("Right Encoder Left");
        }
        else
        {
            Serial.println("Right Encoder Right");
        }

        last2A = current2A;
    }
}