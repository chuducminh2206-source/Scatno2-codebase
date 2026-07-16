int buttonA;
int buttonAPrev;
int buttonB;
int buttonBPrev;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial communications started");

  buttonA = digitalRead(4);
  buttonB = digitalRead(5);
  buttonAPrev = buttonA;
  buttonBPrev = buttonB;
}

void loop() {
  buttonA = digitalRead(4);
  buttonB = digitalRead(5);

  /* Red button controls */
  if(buttonAPrev == 0 && buttonA == 1) {
    Serial.println("Button A pressed");
  }
  
  if(buttonAPrev == 1 && buttonA == 0) {
    Serial.println("Button A released");
  }
  
  /* Blue button controls */
  if(buttonBPrev == 0 && buttonB == 1) {
    Serial.println("Button B pressed");
  }
  
  if(buttonBPrev == 1 && buttonB == 0) {
    Serial.println("Button B released");
  }


  buttonAPrev = buttonA;
  buttonBPrev = buttonB;
}
