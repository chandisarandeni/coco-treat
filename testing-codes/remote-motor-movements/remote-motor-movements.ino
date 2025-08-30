// ----------- Command Pins (Buttons) -----------
#define moveUp 7
#define moveDown 6
#define sprayCommand 5
#define sprayer 4

// ----------- Motor Driver Pins -----------
#define enb 13
#define in4 12
#define in3 11
#define in2 10
#define in1 9
#define ena 8

void setup() {
  // Button pins (with internal pullups)
  pinMode(moveUp, INPUT_PULLUP);
  pinMode(moveDown, INPUT_PULLUP);
  pinMode(sprayCommand, INPUT_PULLUP);
  pinMode(sprayer, OUTPUT);

  // Motor pins
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Enable motors (full speed)
  digitalWrite(ena, HIGH);
  digitalWrite(enb, HIGH);

  Serial.begin(9600);
}

// ----------- METHODS -----------
void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("Move Up");
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("Move Down");
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("Stopped");
}

// ----------- MAIN LOOP -----------
void loop() {
  int upState = digitalRead(moveUp);
  int downState = digitalRead(moveDown);
  int sprayState = digitalRead(sprayCommand);

  if (upState == LOW) {
    moveForward();
  } else if (downState == LOW) {
    moveBackward();
  } else {
    stopMotors();  // stop if nothing pressed
  }

  if (sprayState == LOW) {
    digitalWrite(sprayer, HIGH);
    Serial.println("Spray Command");
  } else {
    digitalWrite(sprayer, LOW);
  }

  delay(200);  // debounce
}
