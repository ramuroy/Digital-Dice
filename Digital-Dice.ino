#define BUTTON_PIN 2      // Push button connected to digital pin 2
#define SEG_A 3           // 7-Segment Display Pins
#define SEG_B 4
#define SEG_C 5
#define SEG_D 6
#define SEG_E 7
#define SEG_F 8
#define SEG_G 9

int diceNumbers[6][7] = {  // 7-segment representation for numbers 1-6
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1}   // 6
};

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

    randomSeed(analogRead(0));  // Seed for random function
}

void loop() {
    if (digitalRead(BUTTON_PIN) == LOW) {  // If button is pressed
        int number = random(1, 7);  // Generate a random number between 1-6
        displayNumber(number);  // Show the number on 7-segment display
        delay(500);  // Debounce delay
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