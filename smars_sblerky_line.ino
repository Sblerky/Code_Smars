int lmotorpin1=3; //Broches pour moteurs
int lmotorpin2=5;
int rmotorpin1=6;
int rmotorpin2=9;
int lineNumber;  //Variable pour stocker la valeur du capteur

void setup() {
  Serial.begin(9600);
  pinMode(lmotorpin1,OUTPUT);
  pinMode(lmotorpin2,OUTPUT);
  pinMode(rmotorpin1,OUTPUT);
  pinMode(rmotorpin2,OUTPUT);

}

void loop() {
  lineNumber= analogRead(A4); //On lit la valeur du capteur branché sur A4
  
  //La partie suivante se répète jusqu'à ce que le capteur trouve une zone sombre (scotch)
  while(lineNumber>800) {
    digitalWrite(rmotorpin1,HIGH);
    digitalWrite(rmotorpin2,LOW);
    digitalWrite(lmotorpin1,HIGH);
    digitalWrite(lmotorpin2,LOW);
    lineNumber= analogRead(A4);  //On lit la valeur du capteur branché sur A4
   };
  if(lineNumber<800) {
    digitalWrite(rmotorpin1,LOW);
    digitalWrite(rmotorpin2,HIGH);
    digitalWrite(lmotorpin1,HIGH);
    digitalWrite(lmotorpin2,LOW);

   }
  else{
    digitalWrite(rmotorpin1,HIGH);
    digitalWrite(rmotorpin2,LOW);
    digitalWrite(lmotorpin1,LOW);
    digitalWrite(lmotorpin2,HIGH);
  };
  Serial.println(lineNumber);
}
