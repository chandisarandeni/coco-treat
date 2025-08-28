#define enb 13
#define in4 12
#define in3 11
#define in2 10
#define in1 9
#define ena 8

void setup() {
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Enable motors (full speed)
  digitalWrite(ena, HIGH);
  digitalWrite(enb, HIGH);
}

// ---------- METHODS ----------
void moveForward(int timeMs) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(timeMs);
}

void moveBackward(int timeMs) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(timeMs);
}

void stopMotors(int timeMs) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(timeMs);
}

// ---------- MAIN LOOP ----------
void loop() {
  moveForward(2000);   // Forward for 2 sec
  stopMotors(1000);    // Stop for 1 sec
  moveBackward(2000);  // Backward for 2 sec
  stopMotors(1000);    // Stop for 1 sec
}
