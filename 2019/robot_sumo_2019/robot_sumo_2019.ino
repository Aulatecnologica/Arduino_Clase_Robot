
#define mot1 2 
#define mot2 3
#define mot3 4
#define mot4 5
#define lR 6
#define lG 7
#define lB 8
int sp1=0;
int sp2=1;
int sp3=2;
int disparo=9;
int eco=10;



void setup() {
 
  pinMode(mot1,OUTPUT); 
  pinMode(mot2,OUTPUT); 
  pinMode(mot3,OUTPUT); 
  pinMode(mot4,OUTPUT);
  pinMode(lR,OUTPUT); 
  pinMode(lG,OUTPUT); 
  pinMode(lB,OUTPUT); 
  pinMode(disparo,OUTPUT);
  pinMode(eco,INPUT);
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
int distancia(){
  int dis;
  int tiempo;
  digitalWrite(disparo,LOW);
  delayMicroseconds(5);
  digitalWrite(disparo,HIGH);
  delayMicroseconds(10);
  tiempo=pulseIn(eco,HIGH);
  dis=int(0.017*tiempo);
  return dis;
  }

void loop() {
 int y;
 dir(0);rgb(1);
 delay(3000);

 while(1){
          y=distancia();
          Serial.println(y);
          if(y<10){rgb(2);
                   dir(0);rgb(2);delay(1000);        
                   dir(2);rgb(3);delay(1000);
                        
            }  
         else{ dir(4);rgb(4);(500);
         }   
  }
  
 }

