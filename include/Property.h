#ifndef PROPERTY_H
#define PROPERTY_H

using namespace std;

#include <string>
#include <SFML/Graphics.hpp>
#include "Model.h"

class Property
{
    public:
        static int pairs[8][4];
        string name;
        string color;
        string cardTextString[8];
        int price;
        int housePrice;
        int rent;
        int rent1House,rent2House,rent3House,rent4House;
        int rentHotel;
        int owner;
        int type;
        int nrHouses;
        sf::Text cardText[9];
        sf::Sprite card;
        sf::Texture cardTexture;
        Property();
};

#endif // PROPERTY_H
