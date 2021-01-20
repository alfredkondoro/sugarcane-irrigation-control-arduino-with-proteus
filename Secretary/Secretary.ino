char pacc = 0;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    pacc = Serial.read();
    if(pacc == 1){
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);
    }
    else if(pacc == 2){
      digitalWrite(5, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(2, HIGH);      
    }
    else if(pacc == 3){
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      digitalWrite(2, HIGH);      
    }
    else if(pacc == 4){
      digitalWrite(5, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);      
    }        
  }
}
