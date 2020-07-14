/*
 * TaskM1.T1P
 */
 
int ledPin = 13;                // Inbuilt led pin
int inputPin = 2;               // Input pin
int pirState = LOW;             // start pir as LOW
int val = 0;					// input pin value 

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(inputPin, INPUT);     
 
  attachInterrupt(digitalPinToInterrupt(inputPin), toggle, HIGH);
  
  Serial.begin(9600);
}
 
void loop(){
  	delay(5000); //placeholder to simulate a task that is interrupted
}

void toggle() {
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion HIGH");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion LOW");
      pirState = LOW;
    }
  }
}