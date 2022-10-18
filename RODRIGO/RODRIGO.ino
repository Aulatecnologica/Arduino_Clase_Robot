#include <ROBOT.h>

Robot bot();
void setup(){
bot.Inicio();
}
void loop(){
            bot.cerebro(); 
            bot.spA();
            bot.spB();
            bot.distancia();
            delay(200);


}

