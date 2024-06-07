#define A0_MID 498
#define A1_MID 533
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  double state0=analogRead(0);
  double state1=analogRead(1);
  state0-=A0_MID;
  state1-=A1_MID;
  // Serial.print(state0);
  // Serial.print(' ');
  // Serial.print(state1);
  // Serial.print(' ');
  double ind=0.287;
  double deg0=(state0)*ind;
  double deg1=(state1)*ind;
  Serial.print(deg0);
  Serial.print(' ');
  Serial.print(deg1);
  Serial.print('\n');
}
