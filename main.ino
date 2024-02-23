// Motor Driver - Right Side
const int PWMA_right = 5;
const int AI2_right = 1;
const int AI1_right = 2;
const int BI1_right = 4;
const int BI2_right = 3;
const int PWMB_right = 6;

// Motor Driver - Left Side
const int PWMA_left = 10;
const int AI2_left = 8;
const int AI1_left = 9;
const int BI1_left = 12;
const int BI2_left = 13;
const int PWMB_left = 11;

int switchPin = 7;

bool courseDone = false;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);

  // attachInterrupt(digitalPinToInterrupt(switchPin), stop, FALLING);

  pinMode(PWMA_right, OUTPUT);
  pinMode(AI2_right, OUTPUT);
  pinMode(AI1_right, OUTPUT);
  pinMode(BI1_right, OUTPUT);
  pinMode(BI2_right, OUTPUT);
  pinMode(PWMB_right, OUTPUT);

  pinMode(PWMA_left, OUTPUT);
  pinMode(AI2_left, OUTPUT);
  pinMode(AI1_left, OUTPUT);
  pinMode(BI1_left, OUTPUT);
  pinMode(BI2_left, OUTPUT);
  pinMode(PWMB_left, OUTPUT);
}

void loop() {
  // forward(2) -> Moves forward 50cm
  // backward(2) -> Moves backward 50cm
  // right(2.4) -> Moves right 50cm
  // left(2.4) -> Moves left 50cm
  // rotateCW(5) -> 360 degree rotation
  // rotateCW(1.45) -> 90 degree rotation
  if (!courseDone && digitalRead(switchPin) == LOW) {
    forward(2);
    delay(1000);
    backward(2);
    delay(1000);
    right(2.4);
    delay(1000);
    left(2.4);
    courseDone = true; 
  }
}

void forward(float time) {
  analogWrite(PWMA_right, 255);
  digitalWrite(AI2_right, HIGH);
  digitalWrite(AI1_right, LOW);
  digitalWrite(BI1_right, LOW);
  digitalWrite(BI2_right, HIGH);
  analogWrite(PWMB_right, 255);
  
  analogWrite(PWMA_left, 255);
  digitalWrite(AI2_left, HIGH);
  digitalWrite(AI1_left, LOW);
  digitalWrite(BI1_left, LOW);
  digitalWrite(BI2_left, HIGH);
  analogWrite(PWMB_left, 255);

  delay(time * 1000);

  stop();
}

void backward(float time){
  analogWrite(PWMA_right, 255);
  digitalWrite(AI2_right, LOW);
  digitalWrite(AI1_right, HIGH);
  digitalWrite(BI1_right, HIGH);
  digitalWrite(BI2_right, LOW);
  analogWrite(PWMB_right, 255);
  
  analogWrite(PWMA_left, 255);
  digitalWrite(AI2_left, LOW);
  digitalWrite(AI1_left, HIGH);
  digitalWrite(BI1_left, HIGH);
  digitalWrite(BI2_left, LOW);
  analogWrite(PWMB_left, 255);

  delay(time * 1000);

  stop();
}

void right(float time){
  analogWrite(PWMA_right, 255);
  digitalWrite(AI2_right, LOW);
  digitalWrite(AI1_right, HIGH);
  digitalWrite(BI1_right, LOW);
  digitalWrite(BI2_right, HIGH);
  analogWrite(PWMB_right, 255);

  analogWrite(PWMA_left, 255);
  digitalWrite(AI2_left, HIGH);
  digitalWrite(AI1_left, LOW);
  digitalWrite(BI1_left, HIGH);
  digitalWrite(BI2_left, LOW);
  analogWrite(PWMB_left, 255);

  delay(time * 1000);

  stop();
}

void left(float time){
  analogWrite(PWMA_right, 255);
  digitalWrite(AI2_right, HIGH);
  digitalWrite(AI1_right, LOW);
  digitalWrite(BI1_right, HIGH);
  digitalWrite(BI2_right, LOW);
  analogWrite(PWMB_right, 255);

  analogWrite(PWMA_left, 255);
  digitalWrite(AI2_left, LOW);
  digitalWrite(AI1_left, HIGH);
  digitalWrite(BI1_left, LOW);
  digitalWrite(BI2_left, HIGH);
  analogWrite(PWMB_left, 255);

  delay(time * 1000);

  stop();
}

void rotateCW(float time){
  analogWrite(PWMA_right, 255);
  digitalWrite(AI2_right, LOW);
  digitalWrite(AI1_right, HIGH);
  digitalWrite(BI1_right, HIGH);
  digitalWrite(BI2_right, LOW);
  analogWrite(PWMB_right, 255);

  analogWrite(PWMA_left, 255);
  digitalWrite(AI2_left, HIGH);
  digitalWrite(AI1_left, LOW);
  digitalWrite(BI1_left, LOW);
  digitalWrite(BI2_left, HIGH);
  analogWrite(PWMB_left, 255);

  delay(time * 1000);

  stop();
}

void stop() {
  analogWrite(PWMA_right, 0); 
  analogWrite(PWMB_right, 0);
  analogWrite(PWMA_left, 0);
  analogWrite(PWMB_left, 0);
}
