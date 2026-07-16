int buttonA;
int buttonAPrev;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial communications started");

  buttonA = digitalRead(4);
  buttonAPrev = buttonA;
}

void loop() {
  buttonA = digitalRead(4);

  if(buttonAPrev == 0 && buttonA == 1) {
    Serial.println("Button A pressed");
  }
  
  if(buttonAPrev == 1 && buttonA == 0) {
    Serial.println("Button A released");
  }

  buttonAPrev = buttonA;
}
