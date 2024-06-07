#define A0_MID 500
#define A1_MID 533
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
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
  // digitalWrite(10,1);
  int value=(int)((deg0/45)*500+1500);
  if(value>2000){value=2000;}
  if(value<1000){value=1000;}

  digitalWrite(11, HIGH);
  delayMicroseconds(value); 			// 输出PWM，占空比为100/1000=10%
  digitalWrite(11, LOW);
  delayMicroseconds(20000-value); 	// 修改这里的1000可以调整频率，总周期为1000us,所以频率为1000Hz.

  Serial.print(deg0);
  Serial.print(' ');
  Serial.print(deg1);
  Serial.print('\n');
}
