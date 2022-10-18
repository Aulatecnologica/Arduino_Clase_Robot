int sp1=0;
int sp2=1;
int sp3=2;
int disparo=9;
int eco=10;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(disparo,OUTPUT);
  pinMode(eco,INPUT);
}
void distancia(){
  int dis;
  int tiempo;
  digitalWrite(disparo,LOW);
  delayMicroseconds(5);
  digitalWrite(disparo,HIGH);
  delayMicroseconds(10);
  tiempo=pulseIn(eco,HIGH);
  dis=int(0.017*tiempo);
  Serial.print("Distancia en CM: ");
  Serial.println(dis);
  delay(200);
  }

void loop() {
  int t;
  int a,b,c;
  a=0;b=0;c=0;
  // put your main code here, to run repeatedly:
  while(1){distancia();}
 t=analogRead(sp1);
 if(t<600){Serial.println("Limite 1");}
 t=analogRead(sp2);
 if(t<600){Serial.println("Limite 2");} 
 t=analogRead(sp3);
 if(t<600){Serial.println("Limite 3");} 
}
