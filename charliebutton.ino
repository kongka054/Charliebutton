#define PIN1 2
#define PIN2 3
#define PIN3 4
#define flagmax 888

int buttonState = 0; 
int flag        = 0; 

void keydetection(){
  pinMode(PIN1,INPUT);
  pinMode(PIN2,OUTPUT);
  pinMode(PIN3,OUTPUT);
  digitalWrite(PIN2, HIGH);
  buttonState = digitalRead(PIN1);
  if (buttonState == HIGH) {
    flag++;
    if(flag>flagmax)
    {
      Serial.println("Key1 pressed");
      flag = 0;
      }
  }
  digitalWrite(PIN2, LOW); 
  pinMode(PIN1,OUTPUT);
  digitalWrite(PIN1, LOW);
  pinMode(PIN1,INPUT);
  digitalWrite(PIN3, HIGH);
  buttonState = digitalRead(PIN1);
  if (buttonState == HIGH) {
    flag++;
    if(flag>flagmax)
    {
      Serial.println("Key6 pressed");
      flag = 0;
      }
  } 
  digitalWrite(PIN3, LOW);

  pinMode(PIN1,OUTPUT);
  pinMode(PIN2,INPUT);
  pinMode(PIN3,OUTPUT);
  digitalWrite(PIN1, HIGH);
  buttonState = digitalRead(PIN2);
  if (buttonState == HIGH) {     
    flag++;
    if(flag>flagmax)
    {
      Serial.println("Key2 pressed");
      flag = 0;
      }
  } 
  digitalWrite(PIN1, LOW);
  pinMode(PIN2,OUTPUT);
  digitalWrite(PIN1, LOW);
  pinMode(PIN2,INPUT);
  digitalWrite(PIN3, HIGH);
  buttonState = digitalRead(PIN2);
  if (buttonState == HIGH) {
    flag++;
    if(flag>flagmax)
    {
      Serial.println("Key3 pressed");
      flag = 0;
      }
  } 
  digitalWrite(PIN3, LOW);

  pinMode(PIN1,OUTPUT);
  pinMode(PIN2,OUTPUT);
  pinMode(PIN3,INPUT);
  digitalWrite(PIN1, HIGH);
  buttonState = digitalRead(PIN3);
  if (buttonState == HIGH) {
    flag++;
    if(flag>flagmax)
    {
      Serial.println("Key5 pressed");
      flag = 0;
      }
  } 
  digitalWrite(PIN1, LOW);
  pinMode(PIN3,OUTPUT);
  digitalWrite(PIN1, LOW);
  pinMode(PIN3,INPUT);
  digitalWrite(PIN2, HIGH);
  buttonState = digitalRead(PIN3);
  if (buttonState == HIGH) {
    flag++;
    if(flag>flagmax)
    {
      Serial.println("Key4 pressed");
      flag = 0;
      }
  } 
  digitalWrite(PIN2, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial.println("starting key detection");
  pinMode(PIN1,OUTPUT);
  pinMode(PIN2,OUTPUT);
  pinMode(PIN3,OUTPUT);
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN3, LOW);
}


void loop() {
  // put your main code here, to run repeatedly
  keydetection();
}
