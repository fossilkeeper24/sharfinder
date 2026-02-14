int BUT1 = D3;
int BUT2 = D4;
int BUT3 = D5;

int LED1 = D0; // can't quite use these because i messed up somewhere in maybe the soldering
int LED2 = D1;
int LED3 = D2;

long but1time; // i want to use these elsewhere for minigameee. give 1-20 ms buffer
long but2time;
long but3time;

int pattern[] = {1, 2, 3};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);

//  pinMode(LED1, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT); //desperately testing

  //digitalWrite(LED1, LOW); //desperately testing
  //delay(100);
  //digitalWrite(LED1, HIGH);
  //delay(100);

  long startTime = millis();


}

void loop() { // input array

 //  secret();
  


}

// func to check if pattern is same as inputs, pass pattern and inputs as parameters
// for i in range 0, len(pattern)-1 check index is same
// return true of false then reset input array

void test(){
  but2time = 0;
  but3time = 50; // reset
  int status1 = digitalRead(BUT1);
  if (status1 == 0){ but1time = millis();}
  int status2 = digitalRead(BUT2);
  if (status2 == 0){ but2time = millis();}
  int status3 = digitalRead(BUT3);
  if (status3 == 0){ but3time = millis();}
  // 1 means not pressed, 0 means pressed

  Serial.println("button1:");
  Serial.println(status1);
  Serial.println("button2:");
  Serial.println(status2);
  Serial.println("button3:");
  Serial.println(status3);
  delay(400);

  //Serial.println(but3time - but2time);
  //Serial.println(but2time - but1time);
  //Serial.println();

  if (abs(but3time - but2time) <= 20){
    if (abs(but2time - but1time) <= 20){
      Serial.println("All three pressed simultaneously!");
      //initialiseGame();

    }
  }

}

void secret() {
  if (but1time >10000) {
    for (int runs = 0; runs <= 3; runs +=1){
      digitalWrite(LED1, HIGH);
      delay(500);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(500);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(500);
      digitalWrite(LED3, LOW);

    }

  }

}

// memory gameee whackamole style - in the foreseeable future

void initialiseGame() {
      for (int runs = 0; runs <= 3; runs+=1){
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        delay(1000);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
      }

    }

void testing() {
  digitalWrite(LED1, LOW);
  delay(1000);
  digitalWrite(LED1, HIGH);
  delay(1000);

  digitalWrite(LED2, LOW); //desperately testing
  delay(1000);
  digitalWrite(LED2, HIGH);
  delay(1000);

  digitalWrite(LED3, LOW); //desperately testing
  delay(1000);
  digitalWrite(LED3, HIGH);
  delay(1000);


}

void flash_userled() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second

}

void real() {
  if (digitalRead(BUT1) == LOW) {
    but1time = millis();
    digitalWrite(LED1, HIGH);
    Serial.println("But1 pressed");
  } else {
    digitalWrite(LED1, LOW);
  }

  if (digitalRead(BUT2) == LOW) {
    but2time = millis();
    digitalWrite(LED2, HIGH);
    Serial.println("But2 pressed");
  } else {
    digitalWrite(LED2, LOW);
  }

  if (digitalRead(BUT3) == LOW) {
    digitalWrite(LED3, HIGH);
    Serial.println("But3 pressed");
    but3time = millis();
  } else {
    digitalWrite(LED3, LOW);
    but3time = 0;
  }


}

