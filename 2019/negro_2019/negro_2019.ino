
#define mot1 2 
#define mot2 3
#define mot3 4
#define mot4 5
#define lR 6
#define lG 7
#define lB 8
#define sp1 0
#define sp2 1
#define sp3 2
#define sp4 3
#define sp  4




void setup() {
 
  pinMode(mot1,OUTPUT); 
  pinMode(mot2,OUTPUT); 
  pinMode(mot3,OUTPUT); 
  pinMode(mot4,OUTPUT);
  pinMode(lR,OUTPUT); 
  pinMode(lG,OUTPUT); 
  pinMode(lB,OUTPUT); 
   Serial.begin(9600);

}
void dBit(int puerto, int valor){
  if(valor==1){digitalWrite(puerto,HIGH);}
  else{  digitalWrite(puerto,LOW);
         }
  }
  
void dir(int valor){
  switch(valor){
                 case 0: dBit(mot1,0);dBit(mot2,0);dBit(mot3,0);dBit(mot4,0);break;
                 case 1: dBit(mot1,1);dBit(mot2,0);dBit(mot3,1);dBit(mot4,0);break;//atras
                 case 2: dBit(mot1,0);dBit(mot2,1);dBit(mot3,0);dBit(mot4,1);break;//ade
                 case 3: dBit(mot1,1);dBit(mot2,0);dBit(mot3,0);dBit(mot4,1);break;//der
                 case 4: dBit(mot1,0);dBit(mot2,1);dBit(mot3,1);dBit(mot4,0);break;//izq  
                 
    
    }
  
  
  }
void rgb(int valor){
  
  switch(valor){
                 case 0: dBit(lR,0);dBit(lG,0);dBit(lB,0);break;
                 case 1: dBit(lR,0);dBit(lG,0);dBit(lB,1);break;
                 case 2: dBit(lR,0);dBit(lG,1);dBit(lB,0);break; 
                 case 3: dBit(lR,0);dBit(lG,1);dBit(lB,1);break; 
                 case 4: dBit(lR,1);dBit(lG,0);dBit(lB,0);break; 
                 case 5: dBit(lR,1);dBit(lG,0);dBit(lB,1);break;  
                 case 6: dBit(lR,1);dBit(lG,1);dBit(lB,0);break;
                 case 7: dBit(lR,1);dBit(lG,1);dBit(lB,1);break;   
    }
  
  
  }
void Sensores(){
 /* Serial.print(" Sensor A :");
  Serial.println(analogRead(sp1));
  delay(500);
  Serial.print(" Sensor B :");
  Serial.println(analogRead(sp2));
  delay(500);
  Serial.print(" Sensor C :");
  Serial.println(analogRead(sp3));
  delay(500);
  Serial.print(" Sensor D :");
  Serial.println(analogRead(sp4));
  delay(500);*/
  Serial.print(" Sensor E :");
  Serial.println(analogRead(sp));
  delay(500);
   
  
  }   
void loop() {
 while(1){ 
  Sensores();
  }
 
 }
