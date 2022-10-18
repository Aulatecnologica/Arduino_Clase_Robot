#include "Arduino.h" 
#ifndef Robot_h
#define Robot_h

class Robot{
	       public: 
		          Robot(int pm1,int pm2, int pm3, int pm4, int lr, int lg,int lb,int an, int sp );  
				  Robot();
	              void adelante(int t);
                  void atras(int t);   
		          void izquierda(int t);
				  void derecha(int t);
		          void detener( );
				  void Inicio();
				  int dist();
				  void distancia();
				  int spA();
				  int spB();
				  void cerebro();
				  void dir(int t);/* 
				                     ROBOT TIPO CARRO DE PANCHO O TANQUE  
				                     0   
				                     1
									 2
									 3
									 4
									 ROBOT TIPO CARRO DE PANCHO O TANQUE LOGICA INVERTIDA
									 5
									 6
									 7
									 8
									 9
									 ROBOT TIPO AUTO
									 10
									 11
									 12
									 13
									 14
									 15
									 ROBOT TIPO AUTO LOGICA INVERTIDA
									 16
									 17
									 18
									 19
									 20
				  */
				  void SBit(int p,int v);// p = puerto 0..13 v=valor 0..1 
				  void SBitN(int p,int v);// p = puerto 0..13 v=valor 0..1 
				  void led(int v);//led(rgb)0..8
				  
	       private:
		    int _pm1;
			int _pm2;
			int _pm3;
            int _pm4;
            int _lr;
			int _lg;
			int _lb;
			int _sp;
			int _an; 
};
#endif




  