/*
 * TaskM1.T2P
 */
 
int ledPin = 13;                // Inbuilt led pin
int inputPin = 2;               // Input pin
int val = 0;					// input pin value 

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(inputPin, INPUT);     
 
  attachInterrupt(digitalPinToInterrupt(inputPin), toggle, HIGH); //setup interrupt on PIR pin to run toggle function
  
  Serial.begin(9600);
}
 
void loop(){
  	delay(5000); //placeholder to simulate a task that is interrupted
}

void toggle() {
  	val = digitalRead(inputPin);  // read input value
    if (val == LOW) {            // check if the input is LOW
      digitalWrite(ledPin, LOW); // turn LED OFF
      Serial.println("Motion LOW"); // print motion low
    }
  	else {							//otherwise motion must be HIGH
      digitalWrite(ledPin, HIGH);  // turn LED ON
      Serial.println("Motion HIGH"); // print motion HIGH
  	}
}  
