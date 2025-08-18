#define moveUp 7
#define moveDown 6
#define sprayCommand 5

void setup(){
    pinMode(moveUp, INPUT);
    pinMode(moveDown, INPUT);
    pinMode(sprayCommand, INPUT);

    Serial.begin(9600);
}

void loop(){
    if(digitalRead(moveUp) == HIGH){
        Serial.println("Moving Up");
    }
    if(digitalRead(moveDown) == HIGH){
        Serial.println("Moving Down");
    }
    if(digitalRead(sprayCommand) == HIGH){
        Serial.println("Spay Command Activated");
    }

    delay(100);
}