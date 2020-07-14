/*
 * TaskM1.T1P
 */
 
int ledPin = 13;                // Inbuilt led pin
int inputPin = 2;               // Input pin
int pirState = LOW;             // start pir as LOW
int val = 0;					// input pin value 

int ButPin = 3;
int ButState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(inputPin, INPUT);     
  pinMode(ButPin, INPUT); 
  
  attachInterrupt(digitalPinToInterrupt(inputPin), toggle, HIGH);
  attachInterrupt(digitalPinToInterrupt(ButPin), toggleButton, HIGH);
  
  Serial.begin(9600);
}
 
void loop(){
  
	delay(5000);
  
}

void toggle() {
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion HIGH");
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion LOW");
      pirState = LOW;
    }
  }
}

void toggleButton(){
  	ButState = digitalRead(ButPin);
  
  if (ButState == HIGH){
   digitalWrite(ledPin, HIGH); // turn LED ON 
  }
  else{
   digitalWrite(ledPin, LOW); // turn LED OFF
  }

  
}