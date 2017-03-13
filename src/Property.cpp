#include "Property.h"


int Property::pairs[8][4]={
                    {2,1,3,0},
                    {3,6,8,9},
                    {3,11,13,14},
                    {3,16,18,19},
                    {3,21,23,24},
                    {3,26,27,29},
                    {3,31,32,34},
                    {2,37,39,0}
                };

Property::Property()
{
    int i,j;
    owner=-1;
    nrHouses=0;
}


