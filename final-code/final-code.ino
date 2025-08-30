// --- SIGNAL INPUTs
#define btn_moveUp 7
#define btn_moveDown 6
#define btn_sprayCommand 5

// -- SIGNAL INDICATORS
#define movementIndicator 3
#define pumpIndicator 2

// -- MOTOR PINs
#define enb 13
#define in4 12
#define in3 11
#define in2 10
#define in1 9
#define ena 8

int lastUpState = HIGH;
int lastDownState = HIGH;
int lastSprayState = HIGH;
bool sprayOn = false;

void setup() {
  // INPUT pin IO STATE
  pinMode(btn_moveUp, INPUT_PULLUP);
  pinMode(btn_moveDown, INPUT_PULLUP);
  pinMode(btn_sprayCommand, INPUT_PULLUP);

  // MOTOR pins IO STATE
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // SIGNAL INDICATORS IO STATE
  pinMode(movementIndicator, OUTPUT);
  pinMode(pumpIndicator, OUTPUT);

  // --- ROBOT init STATE
  allIndicatorsOff();
  stopMotors();

  // -- SERIAL PRINT
  Serial.begin(9600);
}

void loop() {
  int upState = digitalRead(btn_moveUp);
  int downState = digitalRead(btn_moveDown);
  int sprayState = digitalRead(btn_sprayCommand);

  // --- Movement buttons
  if (upState == LOW && lastUpState == HIGH) {
    moveUp();
    moveUpIndicator();
    Serial.println("Moving UP");
  } else if (downState == LOW && lastDownState == HIGH) {
    moveDown();
    moveDownIndicator();
    Serial.println("Moving DOWN");
  } else if (upState == HIGH && downState == HIGH && (lastUpState == LOW || lastDownState == LOW)) {
    stopMotors();
    allIndicatorsOff();
    Serial.println("STOP");
  }

  // --- Spray button toggle
  if (sprayState == LOW && lastSprayState == HIGH) {
    sprayOn = !sprayOn;
    if (sprayOn) {
      pumpIndicatorOn();
      Serial.println("Spray ON");
    } else {
      digitalWrite(pumpIndicator, LOW);
      Serial.println("Spray OFF");
    }
  }

  // remember last states
  lastUpState = upState;
  lastDownState = downState;
  lastSprayState = sprayState;
}

// ------------------ MOVEMENT INDICATOR Functions ------------------
void moveUpIndicator() {
  digitalWrite(movementIndicator, HIGH);
}

void moveDownIndicator() {
  digitalWrite(movementIndicator, HIGH);  // can be changed later if needed
}

void pumpIndicatorOn() {
  digitalWrite(pumpIndicator, HIGH);
}

void allIndicatorsOff() {
  digitalWrite(movementIndicator, LOW);
  digitalWrite(pumpIndicator, LOW);
}

// ------------------ MOTOR MOVEMENT Functions ------------------

void moveUp() {
  digitalWrite(ena, HIGH);  // Enable left motor
  digitalWrite(enb, HIGH);  // Enable right motor

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveDown() {
  digitalWrite(ena, HIGH);
  digitalWrite(enb, HIGH);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMotors() {
  digitalWrite(ena, LOW);
  digitalWrite(enb, LOW);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
