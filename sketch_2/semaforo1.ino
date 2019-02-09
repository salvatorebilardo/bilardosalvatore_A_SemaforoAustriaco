int rosso = 10;
int giallo = 11;
int verde = 12;
int rosso1 = 4;
int giallo1 = 6;
int verde1 = 7;
int tempo = 100;
int ripetizioni=4;
int delaygiallo = 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  pinMode(rosso, OUTPUT);
  pinMode(giallo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(rosso1, OUTPUT);
  pinMode(giallo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  if (delaygiallo == 0){
    inputgiallo();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite (rosso1, LOW);
  digitalWrite (giallo1, LOW);
  digitalWrite (giallo, LOW);
  digitalWrite (rosso, HIGH);
  digitalWrite (verde1, HIGH);
  delay(4600);

  digitalWrite (giallo, HIGH);
  lampeggia(verde1, tempo, ripetizioni);
  digitalWrite (giallo1, HIGH);
  delay(1000);

  digitalWrite (rosso, LOW);
  digitalWrite (giallo, LOW);
  digitalWrite (verde, HIGH);
  digitalWrite (giallo1, LOW);
  digitalWrite (rosso1, HIGH);
  delay(4600);
  
  lampeggia(verde, tempo, ripetizioni);
  digitalWrite (giallo, HIGH);
  delay(1000);
  
}
void lampeggia(int led, int tempo, int ripetizioni) {
  for (int i = 0;i <= ripetizioni;i++)
  {
  digitalWrite (led,LOW);
  delay(tempo);
  digitalWrite (led,HIGH);
  delay(tempo);
  digitalWrite (led,LOW);
  }
  
}
void inputgiallo() {
  Serial.print("quanto vuoi fare durare il giallo?");
  while ( Serial.available() == 0 ){ };
  delaygiallo =  Serial.readString().toInt();
  
}
void inputlampeggiverde() {
  Serial.print("quanto lampeggi il giallo?");
  while ( Serial.available() == 0 ){ };
  delaygiallo =  Serial.readString().toInt();
}
