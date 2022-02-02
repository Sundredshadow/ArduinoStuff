const int buttonPinOne = 2;  // the number of the pushbutton pin
const int ledPinOne =  5;    // the number of the LED pin
int buttonStateOne = 0;      // variable for reading the pushbutton 

const int buttonPinTwo = 17;  // the number of the pushbutton pin
const int ledPinTwo =  19;    // the number of the LED pin
int buttonStateTwo = 0; 

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinOne, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinOne, INPUT);

  // initialize the LED pin as an output:
  pinMode(ledPinTwo, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinTwo, INPUT);
}
void loop() {
  // read the state of the pushbutton value:
  buttonStateOne = digitalRead(buttonPinOne);
  buttonStateTwo = digitalRead(buttonPinTwo);
  if (buttonStateOne == HIGH && buttonStateTwo==HIGH) {
    // turn green LED on:
    digitalWrite(ledPinTwo, LOW);
    digitalWrite(ledPinOne, HIGH);       
  } else {
    // turn red LED on:
    digitalWrite(ledPinOne, LOW);
    digitalWrite(ledPinTwo, HIGH);
  }
}
