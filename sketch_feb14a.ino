int ledPins[]  =  {5,6,7}; 

int outputLEDs[] ={8,9,10,11,19,18,17,16};
int switchPins[] = {21,20,2};
int switchStates[]={0,0,0};
int decimalValue=0;

void readButtonStates(int* states){
  for(int a =0; a<sizeof(switchPins) / sizeof(int); a++) 
  {
    int pin=switchPins[a];
    states[a] = digitalRead(pin);
    //Serial.println(states[a]);
  }
}

void loadPins( int* pins,int quantity, bool mode){
    for(int a =0; a<quantity; a++) 
    {
      int pin=pins[a];
      if(mode){
        pinMode(pin, INPUT);
      }else{
        pinMode(pin, OUTPUT);
      }
    }
}

void changeLedState(int index,bool state){
    int pin=ledPins[index];
    if(state){
      digitalWrite(pin, HIGH);
    }else{
      digitalWrite(pin, LOW);  
    }
}

void changeLedStateOutput(int index,bool state){
    int pin=outputLEDs[index];
    if(state){
      digitalWrite(pin, HIGH);
    }else{
      digitalWrite(pin, LOW);  
    }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  loadPins(ledPins,3,0);
  loadPins(switchPins,3,1);
  loadPins(outputLEDs,8,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  readButtonStates(switchStates);
  decimalValue=0;
  int power = 0;

  for(int a =0; a<sizeof(switchPins)/ sizeof(int); a++){
    //Serial.println(switchPins[a]);
     if(switchStates[a]==HIGH){
        changeLedState(a,1);
        decimalValue = decimalValue + pow(2,power);
      }else{
        changeLedState(a,0);
      }
     power++;
  }
  for(int a=0; a<sizeof(outputLEDs)/ sizeof(int);a++){
    if(a<decimalValue){
      
      changeLedStateOutput(a,1);
    }else{
      changeLedStateOutput(a,0);  
    }
  }
  Serial.println(decimalValue);
  
}
