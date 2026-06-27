#define BUTTON_PIN 2      // Push button (active-low, internal pull-up)
#define SEG_A 3           // 7-Segment Display Pins (common-cathode)
#define SEG_B 4
#define SEG_C 5
#define SEG_D 6
#define SEG_E 7
#define SEG_F 8
#define SEG_G 9

int diceNumbers[6][7] = {  // 7-segment patterns for 1-6 (1 = segment on, common-cathode)
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1}   // 6
};

// Debounced, edge-detected button (active-low) so one press = one roll.
const unsigned long DEBOUNCE_MS = 50;
int lastReading = HIGH;
int stableState = HIGH;
unsigned long lastChange = 0;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);  // Button input with pull-up resistor

    // Set all segment pins as OUTPUT
    pinMode(SEG_A, OUTPUT);
    pinMode(SEG_B, OUTPUT);
    pinMode(SEG_C, OUTPUT);
    pinMode(SEG_D, OUTPUT);
    pinMode(SEG_E, OUTPUT);
    pinMode(SEG_F, OUTPUT);
    pinMode(SEG_G, OUTPUT);

    randomSeed(analogRead(A0));  // Seed the RNG from a floating analog pin
}

void loop() {
    int reading = digitalRead(BUTTON_PIN);

    // Restart the debounce timer whenever the raw level changes.
    if (reading != lastReading) {
        lastChange = millis();
        lastReading = reading;
    }

    // Roll exactly once on a debounced press edge, instead of repeatedly while held.
    if ((millis() - lastChange) > DEBOUNCE_MS && reading != stableState) {
        stableState = reading;
        if (stableState == LOW) {
            displayNumber(random(1, 7));  // random number 1-6
        }
    }
}

void displayNumber(int num) {
    int *segments = diceNumbers[num - 1];  // Get segment pattern for number
    digitalWrite(SEG_A, segments[0]);
    digitalWrite(SEG_B, segments[1]);
    digitalWrite(SEG_C, segments[2]);
    digitalWrite(SEG_D, segments[3]);
    digitalWrite(SEG_E, segments[4]);
    digitalWrite(SEG_F, segments[5]);
    digitalWrite(SEG_G, segments[6]);
}
