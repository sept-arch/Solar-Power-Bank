int RED = 9;
int YELLOW = 8;
int DT = 12;
int CLK = 13;
int SW = 10;
int lastStateCLK;
int currentStateCLK;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(CLK, INPUT); //CLK
  pinMode(DT, INPUT); // DT
  pinMode(SW, INPUT);
  //for debugging
  Serial.begin(9600);
  // for comparison
  lastStateCLK = digitalRead(13);
}

void menuFunction() {
    // currently, LEDs represent directions.
  currentStateCLK = digitalRead(CLK);
  Serial.print(currentStateCLK);
  Serial.print(digitalRead(DT));
  //if any change is detected
  if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {
    //counter clockwise
    if (digitalRead(DT) != currentStateCLK) {
      digitalWrite(YELLOW, HIGH);
      delay(10);
      digitalWrite(YELLOW, LOW);
    }
    //clockwise
    else {
      digitalWrite(RED, HIGH);
      delay(10);
      digitalWrite(RED, LOW);
    }
  }
    lastStateCLK = currentStateCLK;
    delay(1);
    int swState = digitalRead(SW);
    //button press; not hold
    if (swState == LOW) {
      digitalWrite(RED, HIGH);
      digitalWrite(YELLOW, HIGH);
      delay(100);
      while (swState == LOW) {
        digitalWrite(RED, LOW);
        digitalWrite(YELLOW, LOW);
        swState = digitalRead(SW);
      }
    }
}


void loop() {
  menuFunction();
  }

