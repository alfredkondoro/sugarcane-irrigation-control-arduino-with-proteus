//Sugarcane Irrigation Control
//*****************************

int SenOne = A0;
int SenTwo = A1;

void setup() {
  pinMode(SenOne, INPUT);
  pinMode(SenTwo, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);

  Serial.begin(9600);
}

//Functions for Motor One
void motorOneOn(){
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
}
void motorOneOff(){
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
}

//Functions for Motor Two
void motorTwoOn(){
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
}
void motorTwoOff(){
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
}

void loop() {

//Most Tolerated Value--------------
  float humVal = 750.01;
  
//Least Tolerated Value-------------
  float dryVal = 615.20;

  int SenValOne = analogRead(SenOne);   
  float SenVOne = analogRead(SenOne)*0.0048828125;   
  
  int SenValTwo = analogRead(SenTwo);   
  float SenVTwo = analogRead(SenTwo)*0.0048828125;

  if(SenValOne<=dryVal && SenValTwo>=humVal){
    motorOneOn();
    motorTwoOff();
    Serial.write(1);
  }
  else if(SenValOne>=humVal && SenValTwo<=dryVal){
    motorOneOff();
    motorTwoOn();
    Serial.write(2);
  }
  else if(SenValOne<=dryVal && SenValTwo<=dryVal){
    motorOneOn();
    motorTwoOn();
    Serial.write(3);
  }
  else if(SenValOne>=humVal && SenValTwo>=humVal){
    motorOneOff();
    motorTwoOff();
    Serial.write(4);
  }
}
