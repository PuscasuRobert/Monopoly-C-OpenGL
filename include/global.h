#ifndef GLOBAL_H
#define GLOBAL_H

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "Player.h"
#include "Property.h"

using namespace std;

#include <windows.h>
#include <fstream>
#include <iostream>

using namespace std;

extern float camX,camY,camZ,camRX,camRY,camRZ;
extern const char* pionColors[4];
extern int frames,nrPlayers,nr1,nr2,dicePressed,currentPlayer,movePion,manageSource,tradeWith,cardsOwner[40],offerCards1[40],offerCards2[40];
extern bool ok1,ok2,ok3,ok4,ok5;

struct Button
{
    int x,y,w,h;
    sf::Texture texture;
    sf::Sprite image;
};
struct TextBox
{
    Button button;
    sf::Text text;
    string textString;
};

extern sf::RenderWindow window;
extern sf::Clock ceas;
extern sf::Time FPS;
extern sf::Font font1;
extern sf::Texture nameTexture[4],moneyTexture,optionBarTexture[4],buyBarTexture,ManageMenuTexture,plusTexture,minusTexture,payBarTexture[4],TradeMenuTexture1,TradeMenuTexture2;
extern sf::Sprite nameTextBox[4],moneyTextBox[4],optionBar[4],buyBar,ManageMenu,payBar[4],TradeMenu1,TradeMenu2;
extern sf::Text nameText[4],moneyText[4],optionBarText[3],endTurnText,payBarText,TradeWithText,tradePlayerNameText[4],tradeBankNameText;
extern Property property[40];
extern Button newGame,loadGame,exitGame,backgroundMenu,addPlayer,cancelMenu,startGame,Manage,RollDice,Trade,Buy,DontBuy,Done,managePlus[40],manageMinus[40],tradePlayerName[4],TradeBank,cards1[40],cards2[40],cancelTrade;
extern TextBox textbox[4];

extern Model room,dice1,dice2,house,hotel;
extern vector<Player>player;

string intToString(int a);

void loadButtons();
void loadTextFontsAndSettings();
bool isButtonPressed(Button a);
void setButtonCoordinates(Button &button,int x,int y,int w,int h);
void setTextBoxCoordinates(TextBox &textbox,int x,int y,int w,int h);
void init();

void drawWorld(int &screen);
void drawDice();
void drawPioni();
void drawStats();
void drawBanners();
void drawBuildings();
#endif // GLOBAL_H
