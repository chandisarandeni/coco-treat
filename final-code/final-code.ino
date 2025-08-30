// --- SIGNAL INPUTs
#define btn_moveUp 7
#define btn_moveDown 6
#define btn_sprayCommand 5

// -- SIGNAL INDICATORS
#define movementIndicator 3
#define pumpIndicator 2

int lastUpState = HIGH;
int lastDownState = HIGH;
int lastSprayState = HIGH;
bool sprayOn = false;

void setup() {
  // INPUT pin IO STATE
  pinMode(btn_moveUp, INPUT_PULLUP);
  pinMode(btn_moveDown, INPUT_PULLUP);
  pinMode(btn_sprayCommand, INPUT_PULLUP);

  // SIGNAL INDICATORS IO STATE
  pinMode(movementIndicator, OUTPUT);
  pinMode(pumpIndicator, OUTPUT);

  allIndicatorsOff();

  // -- SERIAL PRINT
  Serial.begin(9600);
}

void loop() {
  int upState = digitalRead(btn_moveUp);
  int downState = digitalRead(btn_moveDown);
  int sprayState = digitalRead(btn_sprayCommand);

  // --- Movement buttons
  if (upState == LOW && lastUpState == HIGH) {
    moveUpIndicator();
  } else if (downState == LOW && lastDownState == HIGH) {
    moveDownIndicator();
  } else if (upState == HIGH && downState == HIGH && (lastUpState == LOW || lastDownState == LOW)) {
    allIndicatorsOff();
  }

  // --- Spray button toggle
  if (sprayState == LOW && lastSprayState == HIGH) {
    sprayOn = !sprayOn;
    if (sprayOn) {
      pumpIndicatorOn();
    } else {
      digitalWrite(pumpIndicator, LOW);
    }
  }

  // remember last states
  lastUpState = upState;
  lastDownState = downState;
  lastSprayState = sprayState;
}

// ------------------ Functions ------------------
void moveUpIndicator() {
  digitalWrite(movementIndicator, HIGH);
}

void moveDownIndicator() {
  digitalWrite(movementIndicator, HIGH);
}

void pumpIndicatorOn() {
  digitalWrite(pumpIndicator, HIGH);
}

void allIndicatorsOff() {
  digitalWrite(movementIndicator, LOW);
  digitalWrite(pumpIndicator, LOW);
}
