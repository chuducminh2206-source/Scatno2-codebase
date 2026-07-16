/* Button vars -- changed buttonA to bwd and fwd to fwd to be consistent with schematic */
int bwd;
int bwdPrev;
int fwd;
int fwdPrev;
/* Rotation var */
#define enc_dt 2
#define enc_clk 3
#define button 4
volatile int encoderValue = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial communications started");

  bwd = digitalRead(4);
  fwd = digitalRead(5);
  bwdPrev = bwd;
  fwdPrev = fwd;
  pinMode(enc_dt, INPUT_PULLUP);
  pinMode(enc_clk, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(enc_clk), encoder, FALLING);
}

void loop() {
  
  /* Rotation control */
  Serial.println(encoderValue);
  delay(100);
  
  /* Red button controls */
  bwd = digitalRead(4);
  fwd = digitalRead(5);
  
  if(bwdPrev == 0 && bwd == 1) {
    Serial.println("Button bwd pressed");
  }
  
  if(bwdPrev == 1 && bwd == 0) {
    Serial.println("Button bwd released");
  }
  
  /* Blue button controls */
  if(fwdPrev == 0 && fwd == 1) {
    Serial.println("Button B pressed");
  }
  
  if(fwdPrev == 1 && fwd == 0) {
    Serial.println("Button B released");
  }


  bwdPrev = bwd;
  fwdPrev = fwd;
}

void encoder() {
 if (digitalRead(enc_clk) == digitalRead(enc_dt)) {
 encoderValue++;
 }
 else {
 encoderValue--;
 }
}
