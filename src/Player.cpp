#include "Player.h"

Player::Player(string n,const char* str,const char*str2,float p1,float p2)
{
    y=4.225;
    x=p1;
    z=p2;
    pos=40;
    money=1500;
    name=n;
    pion.loadModel(str);
    banner.loadModel(str2);
}
