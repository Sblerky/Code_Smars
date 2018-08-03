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
  while(lineNumber<800) {
    digitalWrite(rmotorpin1,HIGH);
    digitalWrite(rmotorpin2,LOW);
    digitalWrite(lmotorpin1,HIGH);
    digitalWrite(lmotorpin2,LOW);
    lineNumber= analogRead(A4);  //On lit la valeur du capteur branché sur A4
    Serial.println(lineNumber);
   };
   
  //Cette partie fait reculer le robot pendant 1 seconde et le fait tourner à gauche pendant 1 seconde
  digitalWrite(lmotorpin1,LOW);
  digitalWrite(lmotorpin2,HIGH);
  digitalWrite(rmotorpin1,LOW);
  digitalWrite(rmotorpin2,HIGH);
  delay(1000);  
  //Tourne à gauche
  digitalWrite(lmotorpin1,LOW);
  digitalWrite(lmotorpin2,HIGH);
  digitalWrite(rmotorpin1,HIGH);
  digitalWrite(rmotorpin2,LOW);
  delay(1000);
  Serial.println(lineNumber);

}
