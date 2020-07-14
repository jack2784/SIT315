/*
 * TaskM1.T1P
 */
 
int ledPin = 13;                // Inbuilt led pin
int inputPin = 4;               // Input pin
int pirState = LOW;             // start pir as LOW
int val = 0;                    // input pin value
 
void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(inputPin, INPUT);     
 
  Serial.begin(9600);
}
 
void loop(){
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