#include "Arduino.h" 
#include "Robot.h"

/**************************************************************************************************************************/
/* Configuracion de planta robot
 *  
                        _____________________________
                 P     | 0             A           A5| 
                 C     | 1             R           A4| sdi  
                 MOT+A | 2             D           A3| sp4  
                 MOT-A | 3             U           A2| sp3
                 MOT+B | 4             I           A1| sp2
                 MOT-B | 5             N           A0| sp1 
                 lr    | 6             O             |
                 lg    | 7                           | 
                 lb    | 8                           |
                       | 9                           |  
                       | 10                          | 
                       | 11                          |
                       | 12                          | 
                       | 13                          | 
                       |_____________________________| 
                        
                         
 */

/***********************************************MOTORES*********************************************************************/

Robot :: Robot ( int pm1,int pm2, int pm3, int pm4, int lr, int lg,int lb,int an, int sp ) 
{ 
   pinMode ( pm1 , OUTPUT ) ; // pin de configuracion del motor  MA+
   pinMode ( pm2 , OUTPUT ) ; // pin de configuracion del motor  MA-
   pinMode ( pm3 , OUTPUT ) ; // pin de configuracion del motor  MB+
   pinMode ( pm4 , OUTPUT ) ; // pin de configuracion del motor  MB- 
   pinMode ( lr  , OUTPUT ) ; // led rojo
   pinMode ( lg  , OUTPUT ) ; // led verde
   pinMode ( lb  , OUTPUT ) ; // led azul
   pinMode ( sp  , INPUT  );  // Sensor piso 
   
   _pm1 = pm1;
   _pm2 = pm2;
   _pm3 = pm3;
   _pm4 = pm4;
   _lr = lr;
   _lg = lg;
   _lb = lb;
   _sp = sp;
   _an = an;
   
   
   Serial.begin(9600);
   
} 
/* CONSTRUCTOR PARA ROBOT SEGUIDOR DE LINEA */ 
Robot :: Robot (  ) 
{ 
   pinMode (2, OUTPUT ) ; // pin de configuracion del motor  MA+
   pinMode (3 , OUTPUT ) ; // pin de configuracion del motor  MA-
   pinMode (4, OUTPUT ) ; // pin de configuracion del motor  MB+
   pinMode (5 , OUTPUT ) ; // pin de configuracion del motor  MB- 
   pinMode (6, OUTPUT ) ; // led rojo
   pinMode (7, OUTPUT ) ; // led verde
   pinMode (8  , OUTPUT ) ; // led azul
   pinMode (9  ,OUTPUT);// Disparo
   pinMode (10, INPUT  );  // ECO 
   
   _pm1 = 2;
   _pm2 = 3;
   _pm3 = 4;
   _pm4 = 5;
   _lr = 6;
   _lg = 7;
   _lb = 8;
   _sp = 10;
   _an = 9;
   
   
} 


void Robot::SBit(int p,int v){ if(v==1){ digitalWrite(p, HIGH);} else{ digitalWrite(p, LOW); }  }
void Robot::SBitN(int p,int v){ if(v==1){ digitalWrite(p, LOW);} else{ digitalWrite(p, HIGH); }  }
void Robot::adelante(int t){ SBit(_pm1,1); SBit(_pm2,0); SBit(_pm3,0); SBit(_pm4,1); Serial.println("Adelante...");}
void Robot::atras(int t){ SBit(_pm1,0); SBit(_pm2,1); SBit(_pm3,1); SBit(_pm4,0); Serial.println("Atras..."); }
void Robot::derecha(int t){ SBit(_pm1,1); SBit(_pm2,0); SBit(_pm3,1); SBit(_pm4,0); Serial.println("Derecha..."); }
void Robot::izquierda(int t){ SBit(_pm1,0); SBit(_pm2,1); SBit(_pm3,0); SBit(_pm4,1);Serial.println("Izquierda..."); }
void Robot::detener(){ SBit(_pm1,0); SBit(_pm2,0); SBit(_pm3,0); SBit(_pm4,0); Serial.println("Detener...");}
int  Robot::dist(){
	            long dis;
				long tiempo;  
	            SBit(_an ,0);
				delayMicroseconds(2);
				SBit(_an ,1);
				delayMicroseconds(10);
				SBit(_an ,0);
				tiempo=pulseIn(_sp,HIGH);
                dis=int(tiempo*0.017) ; 	
                return dis; 				
}
void Robot::distancia(){
	             Serial.print("Distancia :");
				 Serial.println(dist());
	 
}
int Robot::spA(){  // menor a 350 blanco , mayor  negro
                             // Blanco 1
                             // Negro 0							 
                    int puerto;
                    puerto=	analogRead(A0);				
                    Serial.print("Sensor A :");
                    Serial.println(puerto);  
                     if( puerto<=350){ return 1;}else{ return 0;}                    
					
}      
int Robot::spB(){  // menor a 350 blanco , mayor  negro
                             // Blanco 1
                             // Negro 0							 
                    int puerto;
                    puerto=	analogRead(A1);				
                    Serial.print("Sensor B :");
                    Serial.println(puerto);  
                     if( puerto<=350){ return 1;}else{ return 0;}                    
					
}     
void Robot::Inicio(){
	Serial.begin(9600);	
}
void Robot::dir(int valor){
	switch(valor){  
	                //ROBOT TIPO CARRO DE PANCHO O TANQUE
	                case 0: SBit(_pm1,0); SBit(_pm2,0); SBit(_pm3,0); SBit(_pm4,0); Serial.println("Detener...");   break; 	
		            case 1: SBit(_pm1,1); SBit(_pm2,0); SBit(_pm3,0); SBit(_pm4,1); Serial.println("Adelante...");  break;
		            case 2: SBit(_pm1,0); SBit(_pm2,1); SBit(_pm3,1); SBit(_pm4,0); Serial.println("Atras...");     break;
					case 3: SBit(_pm1,0); SBit(_pm2,1); SBit(_pm3,0); SBit(_pm4,1); Serial.println("Izquierda..."); break;
					case 4: SBit(_pm1,1); SBit(_pm2,0); SBit(_pm3,1); SBit(_pm4,0); Serial.println("Derecha...");   break;
					// LOGICA INVERTIDA
					case 5: SBitN(_pm1,0); SBitN(_pm2,0); SBitN(_pm3,0); SBitN(_pm4,0); Serial.println("Detener...");   break; 	
		            case 6: SBitN(_pm1,1); SBitN(_pm2,0); SBitN(_pm3,0); SBitN(_pm4,1); Serial.println("Adelante...");  break;
		            case 7: SBitN(_pm1,0); SBitN(_pm2,1); SBitN(_pm3,1); SBitN(_pm4,0); Serial.println("Atras...");     break;
					case 8: SBitN(_pm1,0); SBitN(_pm2,1); SBitN(_pm3,0); SBitN(_pm4,1); Serial.println("Izquierda..."); break;
					case 9: SBitN(_pm1,1); SBitN(_pm2,0); SBitN(_pm3,1); SBitN(_pm4,0); Serial.println("Derecha...");   break; 
					// ROBOT TIPO AUTO
					case 10: SBit(_pm3,1); SBit(_pm4,0); Serial.println("Derecha...");   break; 
					case 11: SBit(_pm1,1); SBit(_pm2,0);  Serial.println("Adelante..."); break;
					case 12: SBit(_pm1,0); SBit(_pm2,1);     Serial.println("Atras..."); break;
					case 13: SBit(_pm3,0); SBit(_pm4,1); Serial.println("Izquierda..."); break;
					case 14: SBit(_pm3,1); SBit(_pm4,0); Serial.println("Derecha...");   break;
					case 15: SBit(_pm1,0); SBit(_pm2,0); SBit(_pm3,0); SBit(_pm4,0); Serial.println("Detener..."); break;
					// LOGICA INVERTIDA
					case 16: SBit(_pm3,1); SBit(_pm4,0); Serial.println("Derecha...");   break; 
					case 17: SBit(_pm1,1); SBit(_pm2,0);  Serial.println("Adelante..."); break;
					case 18: SBit(_pm1,0); SBit(_pm2,1);     Serial.println("Atras..."); break;
					case 19: SBit(_pm3,0); SBit(_pm4,1); Serial.println("Izquierda..."); break;
					case 20: SBit(_pm3,1); SBit(_pm4,0); Serial.println("Derecha...");   break;
					case 21: SBit(_pm1,0); SBit(_pm2,0); SBit(_pm3,0); SBit(_pm4,0); Serial.println("Detener..."); break;
					
		
	}
	
}


void Robot::led(int v){
	                   switch(v){
						         case 0: SBit(_lr,0);SBit(_lg,0);SBit(_lb,0);break;   
						         case 1: SBit(_lr,0);SBit(_lg,0);SBit(_lb,1);break; 
						         case 2: SBit(_lr,0);SBit(_lg,1);SBit(_lb,0);break; 
								 case 3: SBit(_lr,0);SBit(_lg,1);SBit(_lb,1);break;
								 case 4: SBit(_lr,1);SBit(_lg,0);SBit(_lb,0);break;
								 case 5: SBit(_lr,1);SBit(_lg,0);SBit(_lb,1);break;
								 case 6: SBit(_lr,1);SBit(_lg,1);SBit(_lb,0);break;
                                 case 7: SBit(_lr,1);SBit(_lg,1);SBit(_lb,1);break;  								 
								 
					   }
	
	
}
void Robot::cerebro(){
	int dato;
	         if (Serial.available() > 0) {
			    dato=Serial.read();
				switch(dato){
				             case 65: //A
                                     led(1);break;  
                             case 66: //B
                                     led(2);break;    
                             case 67://C
                                     led(3);break; 
                             case 68://D
                                     led(4);break;   
							 case 69://E
                                     led(5);break; 
							 case 70://F
                                     led(6);break; 
							 case 71://G
                                     led(7);break; 
							 case 72: //H	 programacion 
                                      break;   	
                             case 73: //I
                                     dir(0);;break;  
                             case 74: //J
                                     dir(1);break;    
                             case 75://K
                                     dir(2);break; 
                             case 76://L
                                     dir(3);break;   
							 case 77://M
                                     dir(4);break; 
							 case 78://N
                                     dir(10);break;
							case 79://O
                                     dir(11);break;		 
							case 80://P
                                     dir(12);break;		 
							case 81://Q
                                     dir(13);break;
                            case 82://R
                                     dir(14);break;   									 
									 
									 
									 
									 
									 
									 





									 



									  
									 
				}        	 
				 
				 
				 
			 }   
	
	
}

