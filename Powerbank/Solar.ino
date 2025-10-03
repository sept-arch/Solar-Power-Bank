int RED = 9;
int YELLOW = 8;
int DT = 12;
int CLK = 13;
int lastStateCLK;
int currentStateCLK;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(CLK, INPUT); //CLK
  pinMode(DT, INPUT); // DT

  //for debugging
  Serial.begin(9600);
  // for comparison
  lastStateCLK = digitalRead(13);
}



void loop() {
  // put your main code here, to run repeatedly:
  currentStateCLK = digitalRead(CLK);
  Serial.print(currentStateCLK);
  Serial.print(digitalRead(DT));

}
