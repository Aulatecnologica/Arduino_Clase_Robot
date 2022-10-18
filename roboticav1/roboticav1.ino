#include <ROBOT.h>

Robot bot(2,3,4,5,6,7,8,9,0);
void setup(){
bot.Inicio();
}
void loop(){
            bot.cerebro();
            bot.spA();
            bot.spB();
            bot.distancia();
            delay(100); 

}


