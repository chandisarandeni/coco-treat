// Command pins
#define moveUp 7
#define moveDown 6
#define sprayCommand 5

void setup() {
  // Set input pins with pull-ups (recommended for buttons)
  pinMode(moveUp, INPUT_PULLUP);
  pinMode(moveDown, INPUT_PULLUP);
  pinMode(sprayCommand, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // Read states (LOW = pressed, HIGH = not pressed when using INPUT_PULLUP)
  int upState = digitalRead(moveUp);
  int downState = digitalRead(moveDown);
  int sprayState = digitalRead(sprayCommand);

  if (upState == LOW) {
    Serial.println("Move Up");
  }

  if (downState == LOW) {
    Serial.println("Move Down");
  }

  if (sprayState == LOW) {
    Serial.println("Spray Command");
  }

  delay(200); // debounce delay (avoid multiple prints)
}
