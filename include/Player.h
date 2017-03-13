#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

#include <string>
#include "Model.h"

class Player
{
    public:
        int pos,money;
        float x,z,y;
        string name;
        Model pion,banner;
        Player(string n,const char* str,const char *str2,float p1,float p2);
};

#endif // PLAYER_H
