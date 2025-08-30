// -- remove inputs
#define moveUpBtn 7
#define moveDownBtn 6
#define sprayBtn 5

// -- signal indicators
#define movementIndicator 3
#define pumpIndicator 2

int lastUpState = HIGH;
int lastDownState = HIGH;
int lastSprayState = HIGH;

void setup() {
  pinMode(moveUpBtn, INPUT_PULLUP);
  pinMode(moveDownBtn, INPUT_PULLUP);
  pinMode(sprayBtn, INPUT_PULLUP);

  pinMode(movementIndicator, OUTPUT);
  pinMode(pumpIndicator, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int upState = digitalRead(moveUpBtn);
  int downState = digitalRead(moveDownBtn);
  int sprayState = digitalRead(sprayBtn);

  if (upState == LOW && lastUpState == HIGH) {
    doMoveUp();
  } else if (downState == LOW && lastDownState == HIGH) {
    doMoveDown();
  } else if (upState == HIGH && downState == HIGH && (lastUpState == LOW || lastDownState == LOW)) {
    stopMovement();
  }

  if (sprayState == LOW && lastSprayState == HIGH) {
    pumpOn();
  } else if (sprayState == HIGH && lastSprayState == LOW) {
    pumpOff();
  }

  lastUpState = upState;
  lastDownState = downState;
  lastSprayState = sprayState;
}

void doMoveUp() {
  digitalWrite(movementIndicator, HIGH);
  Serial.println("Motor Moving UP");
}

void doMoveDown() {
  digitalWrite(movementIndicator, HIGH);
  Serial.println("Motor Moving DOWN");
}

void stopMovement() {
  digitalWrite(movementIndicator, LOW);
  Serial.println("Motor Stopped");
}

void pumpOn() {
  digitalWrite(pumpIndicator, HIGH);
  Serial.println("Pump ON");
}

void pumpOff() {
  digitalWrite(pumpIndicator, LOW);
  Serial.println("Pump OFF");
}
