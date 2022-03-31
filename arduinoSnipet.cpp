String buttonInputList[5];
int listCounter = 0;

int redButtonValue = 0;
int yellowButtonValue = 0;
int greenButtonValue = 0;
int blueButtonValue = 0;

int lastRedButtonState = 0;
int lastYellowButtonState = 0; 
int lastGreenButtonState = 0;
int lastBlueButtonState = 0;

int printCount = 0;

int redButton = 5;
int yellowButton = 4;
int greenButton = 3;
int blueButton = 2;

int redLED = 11;
int yellowLED = 10;
int greenLED = 9;
int blueLED = 8;

int speaker = 12;
int counter = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(redButton, INPUT);
  pinMode(redLED, OUTPUT);
  
  pinMode(yellowButton, INPUT);
  pinMode(yellowLED, OUTPUT);
  
  pinMode(greenButton, INPUT);
  pinMode(greenLED, OUTPUT);
  
  pinMode(blueButton, INPUT);
  pinMode(blueLED, OUTPUT);
  
  pinMode (speaker, OUTPUT);
}

void loop() {
  redButtonValue = digitalRead(redButton);
  yellowButtonValue = digitalRead(yellowButton);
  greenButtonValue = digitalRead(greenButton);
  blueButtonValue = digitalRead(blueButton);
  
  if (redButtonValue != lastRedButtonState) {
  	if(redButtonValue == HIGH) {
      digitalWrite(redLED, HIGH);
      Serial.println("Red Hit");
      if (listCounter < 5) {
        buttonInputList[listCounter] = "RED";
        Serial.println("Red added to the list!");
        listCounter ++;
      }
      else {
        Serial.println("list is full!");
        Serial.println("List Contents: ");
        for (int i = 0; i < 5; i++){
          Serial.print(buttonInputList[i] + " ");
        }
      }
  	}
  	else {
    	digitalWrite(redLED, LOW);
  	}
    delay(50);
  }
  
  if (yellowButtonValue != lastYellowButtonState) {
  	if(yellowButtonValue != 0) {
      digitalWrite(yellowLED, HIGH);
      Serial.println("Yellow Hit");
      if (listCounter < 5) {
        buttonInputList[listCounter] = "YELLOW";
        Serial.println("Yellow added to the list!");
        listCounter ++;
      }
      else {
        Serial.println("list is full!");
        Serial.println("List Contents: ");
        for (int i = 0; i < 5; i++){
          Serial.print(buttonInputList[i] + " ");
        }
      }
  	}
    else {
      digitalWrite(yellowLED, LOW);
    }
  }
  
  if (greenButtonValue != lastGreenButtonState) {
    if(greenButtonValue != 0) {
      digitalWrite(greenLED, HIGH);
      digitalWrite (speaker, HIGH);
      Serial.println("Green Hit");
      if (listCounter < 5) {
        buttonInputList[listCounter] = "GREEN";
        Serial.println("Green added to the list!");
        listCounter ++;
      }
      else {
        Serial.println("list is full!");
        Serial.println("List Contents: ");
        for (int i = 0; i < 5; i++){
          Serial.print(buttonInputList[i] + " ");
        }
      }
    }
    else {
      digitalWrite(greenLED, LOW);
      digitalWrite(speaker, LOW);
    }
  }
  
  if (blueButtonValue != lastBlueButtonState) {
    if(blueButtonValue != 0) {
      digitalWrite(blueLED, HIGH);
      digitalWrite (speaker, HIGH);
      Serial.println("Blue Hit");
      if (listCounter < 5) {
        buttonInputList[listCounter] = "BLUE";
        Serial.println("Blue added to the list!");
        listCounter ++;
      }
      else {
        Serial.println("list is full!");
        Serial.println("List Contents: ");
        for (int i = 0; i < 5; i++){
          Serial.print(buttonInputList[i] + " ");
        }
      }
  	}
  	else {
      digitalWrite(blueLED, LOW);
      digitalWrite(speaker, LOW);
  	}
  }
 
  lastRedButtonState = redButtonValue;
  lastYellowButtonState = yellowButtonValue;
  lastGreenButtonState = greenButtonValue;
  lastBlueButtonState = blueButtonValue;
}
