// constants won't change. They're used here to
// set pin numbers:

const int ledPin =  7;      // the number of the LED pin
const int ledPin1 =  10;
const int ledPin2=  9;
const int ledPin4 =  8;
const int buton= 2;
const int buton1= 3;
const int buton2= 4;
const int buton3= 5;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
 int randomnumber;
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
    pinMode(ledPin1, OUTPUT);
      pinMode(ledPin2, OUTPUT);
        pinMode(ledPin4, OUTPUT);
  pinMode(buton, INPUT);
  pinMode(buton1, INPUT);
  pinMode(buton2, INPUT);
  pinMode(buton3, INPUT);
  digitalWrite(buton, LOW);
  digitalWrite(buton1, LOW);
  digitalWrite(buton2, LOW);
  digitalWrite(buton3, LOW);
        
  // initialize the pushbutton pin as an input:
//  pinMode(buttonPin, INPUT);

     
}
void wrong()
{
  int timesDo = 3;
  while (timesDo > 0)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin4, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin4, LOW);
    delay(500);
    timesDo--;
  }
}

boolean isNotPressed(int button)
{
  return(digitalRead(button) == LOW);
}

boolean anyButtonPressed()
{
  return !(isNotPressed(buton) && isNotPressed(buton1) && isNotPressed(buton2) && isNotPressed(buton3));
}

void loop() {
  
  randomnumber=random(7,14);
  digitalWrite(randomnumber, HIGH);
  digitalWrite(buton, LOW);
  digitalWrite(buton1, LOW);
  digitalWrite(buton2, LOW);
  digitalWrite(buton3, LOW);
  delay(1000);
  if(randomnumber==8 && (isNotPressed(buton) && anyButtonPressed()) || isNotPressed(buton))
  {
   wrong();
  } 

  if(randomnumber==9 && (isNotPressed(buton1) && anyButtonPressed()) || isNotPressed(buton1))
  {
   wrong();
  } 

  if(randomnumber==10 && (isNotPressed(buton2) && anyButtonPressed()) || isNotPressed(buton2))
  {
   wrong();
  } 

  if(randomnumber==11 && (isNotPressed(buton3) && anyButtonPressed()) || isNotPressed(buton3))
  {
   wrong();
  }
  
  if(randomnumber > 11 && anyButtonPressed())
  {
    wrong();
  }
  
  

  digitalWrite(randomnumber, LOW);
  
  /*// read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }*/
}
