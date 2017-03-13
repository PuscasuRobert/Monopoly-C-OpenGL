#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "Model.h"
#include "global.h"
#include "Player.h"

bool running = true,ok1,ok2,ok3,ok4,ok5;
int screen,textboxPos,nrPlayers,dicePressed=-1,currentPlayer=0,movePion=-1,nr1,nr2,manageSource,tradeSource,deletePlayer=-1,tradeWith,cardsOwner[40],offerCards1[40],offerCards2[40];
float px=1.825,py=4.2,pz=1.8;
float camX,camY,camZ,camRX,camRY,camRZ;
const char *pionColors[4]={"models/pion1.obj","models/pion2.obj","models/pion3.obj","models/pion4.obj"};
const char *bannerColors[4]={"models/bannerRed.obj","models/bannerBlue.obj","models/bannerYellow.obj","models/bannerGreen.obj"};

//sf::RenderWindow window(sf::VideoMode(1024,768), "Monopoly", sf::Style::Fullscreen, sf::ContextSettings(32));
sf::RenderWindow window(sf::VideoMode(1024,768), "Monopoly", sf::Style::Default, sf::ContextSettings(32));
sf::Event Event;
sf::Font font1;
sf::Texture nameTexture[4],moneyTexture,optionBarTexture[4],buyBarTexture,ManageMenuTexture,plusTexture,minusTexture,payBarTexture[4],TradeMenuTexture1,TradeMenuTexture2;
sf::Sprite nameTextBox[4],moneyTextBox[4],optionBar[4],buyBar,ManageMenu,payBar[4],TradeMenu1,TradeMenu2;
sf::Text nameText[4],moneyText[4],optionBarText[3],dontBuyText,buyText,endTurnText,payBarText,TradeWithText,tradePlayerNameText[4],tradeBankNameText;

TextBox textbox[4];
Model room,dice1,dice2,house,hotel;;
Button newGame,loadGame,exitGame,backgroundMenu,addPlayer,cancelMenu,startGame,Manage,RollDice,Trade,Buy,DontBuy,Done,managePlus[40],manageMinus[40],tradePlayerName[4],TradeBank,cards1[40],cards2[40],cancelTrade;
Property property[40];

vector<Player>player;

int main()
{
    ok1=ok2=ok3=ok4=ok5=true;
    int i,j;
    init();
    for(i=0;i<8;i++)
    {
        property[property[0].pairs[i][1]].owner=1;
        property[property[0].pairs[i][1]].nrHouses=0;
        for(j=2;j<=property[i].pairs[i][0];j++)
        {
            property[property[0].pairs[i][j]].owner=0;
            property[property[0].pairs[i][j]].nrHouses=0;
        }
    }
    while(running)
    {
        while (window.pollEvent(Event))
        {
            if(Event.type==sf::Event::Closed)
                running=false;

            if(Event.type==sf::Event::TextEntered)
            {
                if(screen>=3)
                    if(Event.text.unicode=='q')
                        running=false;
                if(screen==1)
                {
                    if(Event.text.unicode>='a'&&Event.text.unicode<='z')
                    {
                        textbox[textboxPos].textString+=(char)Event.text.unicode-32;
                        textbox[textboxPos].text.setString(textbox[textboxPos].textString);
                    }
                    if(Event.text.unicode==8)
                        if(textbox[textboxPos].textString.size()!=0)
                        {
                            textbox[textboxPos].textString.erase(textbox[textboxPos].textString.size()-1,textbox[textboxPos].textString.size());
                            textbox[textboxPos].text.setString(textbox[textboxPos].textString);
                        }
                }
            }
            if(Event.type==sf::Event::MouseButtonPressed)
                if(Event.mouseButton.button==sf::Mouse::Left)
                {
                    if(screen==0)///Menu
                    {
                        if(isButtonPressed(newGame)==1)
                            {screen=1;nrPlayers=2;}
                        if(isButtonPressed(loadGame)==1)
                            screen=2;
                        if(isButtonPressed(exitGame)==1)
                            running=false;
                    }
                    if(screen==1)///NewGame
                    {
                        for(i=0;i<nrPlayers;i++)
                            if(isButtonPressed(textbox[i].button)==1)
                                textboxPos=i;
                        if(isButtonPressed(addPlayer)==1)
                            if(nrPlayers!=4)
                                nrPlayers++;
                        if(isButtonPressed(cancelMenu)==1)
                        {
                            screen=0;
                            for(i=0;i<4;i++)
                            {
                                textbox[i].textString.clear();
                                textbox[i].text.setString(textbox[i].textString);
                            }
                            player.clear();
                        }
                        if(isButtonPressed(startGame)==1)
                        {
                            glRotatef(-camRY,0,1,0);
                            glRotatef(90,1,0,0);
                            glTranslatef(0,-12-camY,-13.8-camZ);
                            camRX=90;camRY=0;camRZ=0;
                            camX=0;camY=-12;camZ=-13.8;
                            screen=3;
                            if(nrPlayers>=2)
                            {
                                Player p1(textbox[0].textString,pionColors[0],bannerColors[0], 2.1, 2.2);
                                Player p2(textbox[1].textString,pionColors[1],bannerColors[1], 2.3, 2.2);
                                player.push_back(p1);
                                player.push_back(p2);
                            }
                            if(nrPlayers>=3)
                            {
                                Player p3(textbox[2].textString,pionColors[2],bannerColors[2], 2.1, 2.0);
                                player.push_back(p3);
                            }
                            if(nrPlayers==4)
                            {
                                Player p4(textbox[3].textString,pionColors[3],bannerColors[3], 2.3, 2.0);
                                player.push_back(p4);
                            }
                        }
                    }
                    if(screen==3)
                    {
                        if(isButtonPressed(RollDice)==1)
                        {
                            srand(static_cast<unsigned int>(time(0)));
                            nr1=rand()%6+1;
                            nr2=rand()%6+1;
                            screen=4;
                        }
                        if(isButtonPressed(Manage)==1)
                        {
                            screen=8;
                            manageSource=3;
                        }
                        if(isButtonPressed(Trade)==1)
                        {
                            tradeSource=3;
                            screen=10;
                        }
                    }
                    if(screen==5)
                    {
                        if(isButtonPressed(Buy)==1)
                        {
                            if(player[currentPlayer].money>=property[player[currentPlayer].pos].price)
                            {
                                screen=6;
                                property[player[currentPlayer].pos].owner=currentPlayer;
                                player[currentPlayer].money-=property[player[currentPlayer].pos].price;
                            }
                        }
                        if(isButtonPressed(DontBuy)==1)
                            screen=6;
                    }
                    if(screen==7)
                    {
                        if(isButtonPressed(RollDice)==1)
                        {
                            screen=3;
                            if(deletePlayer!=-1)
                            {
                                player.erase(player.begin()+currentPlayer);
                                deletePlayer=-1;
                                for(i=0;i<40;i++)
                                    if(property[i].type==1)
                                        if(property[i].owner>currentPlayer)
                                            property[i].owner--;
                                if(currentPlayer==player.size()+1)
                                    currentPlayer=0;
                                if(player.size()==1)
                                    {running=false;break;}
                            }
                            else
                            {
                                currentPlayer++;
                                currentPlayer%=player.size();
                            }
                        }
                        if(isButtonPressed(Manage)==1)
                        {
                            screen=8;
                            manageSource=7;
                        }
                        if(isButtonPressed(Trade)==1)
                        {
                            tradeSource=7;
                            screen=10;
                        }
                    }
                    if(screen==8)
                    {
                        if(isButtonPressed(Done)==1)
                            screen=manageSource;
                        for(i=1;i<40;i++)
                        {
                            if(property[i].owner==currentPlayer)
                                if(isButtonPressed(managePlus[i])==true)
                                    if(property[i].nrHouses<=4)
                                        if(player[currentPlayer].money>=property[i].housePrice)
                                        {property[i].nrHouses++;player[currentPlayer].money-=property[i].housePrice;}
                            if(property[i].owner==currentPlayer)
                                if(isButtonPressed(manageMinus[i])==true)
                                    if(property[i].nrHouses>=1)
                                        {property[i].nrHouses--;player[currentPlayer].money+=property[i].housePrice;}
                        }
                    }
                    if(screen==9)
                    {
                        if(isButtonPressed(RollDice)==1)
                        {
                            bool ok=false;
                            screen=6;
                            if(property[player[currentPlayer].pos].nrHouses==0)
                            {
                                if(player[currentPlayer].money>=property[player[currentPlayer].pos].rent)
                                {
                                    player[currentPlayer].money-=property[player[currentPlayer].pos].rent;
                                    player[property[i].owner].money+=property[player[currentPlayer].pos].rent;
                                    ok=true;
                                }
                            }
                            else if(property[player[currentPlayer].pos].nrHouses==1)
                            {
                                if(player[currentPlayer].money>=property[player[currentPlayer].pos].rent1House)
                                {
                                    player[currentPlayer].money-=property[player[currentPlayer].pos].rent1House;
                                    player[property[i].owner].money+=property[player[currentPlayer].pos].rent1House;
                                    ok=true;
                                }
                            }
                            else if(property[player[currentPlayer].pos].nrHouses==2)
                            {
                                if(player[currentPlayer].money>=property[player[currentPlayer].pos].rent2House)
                                {
                                    player[currentPlayer].money-=property[player[currentPlayer].pos].rent2House;
                                    player[property[i].owner].money+=property[player[currentPlayer].pos].rent2House;
                                    ok=true;
                                }
                            }
                            else if(property[player[currentPlayer].pos].nrHouses==3)
                            {
                                if(player[currentPlayer].money>=property[player[currentPlayer].pos].rent3House)
                                {
                                    player[currentPlayer].money-=property[player[currentPlayer].pos].rent3House;
                                    player[property[i].owner].money+=property[player[currentPlayer].pos].rent3House;
                                    ok=true;
                                }
                            }
                            else if(property[player[currentPlayer].pos].nrHouses==4)
                            {
                                if(player[currentPlayer].money>=property[player[currentPlayer].pos].rent4House)
                                {
                                    player[currentPlayer].money-=property[player[currentPlayer].pos].rent4House;
                                    player[property[i].owner].money+=property[player[currentPlayer].pos].rent4House;
                                    ok=true;
                                }
                            }
                            else if(property[player[currentPlayer].pos].nrHouses==5)
                            {
                                if(player[currentPlayer].money>=property[player[currentPlayer].pos].rentHotel)
                                {
                                    player[currentPlayer].money-=property[player[currentPlayer].pos].rentHotel;
                                    player[property[i].owner].money+=property[player[currentPlayer].pos].rentHotel;
                                    ok=true;
                                }
                            }
                            if(ok==false)
                            {
                                for(i=0;i<40;i++)
                                    if(property[i].type==1&&property[i].owner==currentPlayer)
                                        {ok=true;break;}
                                if(ok==false)
                                {
                                    player[property[i].owner].money+=player[currentPlayer].money;
                                    player[currentPlayer].money=0;
                                    deletePlayer=currentPlayer;
                                }
                            }
                        }
                        if(isButtonPressed(Manage)==1)
                        {
                            screen=8;
                            manageSource=9;
                        }
                        if(isButtonPressed(Trade)==1)
                        {
                            tradeSource=9;
                            screen=10;
                        }
                    }
                    if(screen==10)
                    {
                        if(isButtonPressed(Done))
                            screen=tradeSource;
                        for(i=0;i<4;i++)
                            if(isButtonPressed(tradePlayerName[i])==1)
                                if(i!=currentPlayer)
                                {
                                    tradeWith=i;
                                    screen=11;
                                    for(j=0;j<40;j++)
                                        cardsOwner[j]=property[j].owner;
                                }
                        if(isButtonPressed(TradeBank)==1)
                            screen=11;
                    }
                    if(screen==11)
                    {
                       for(i=0;i<40;i++)
                            if(property[i].owner==currentPlayer)
                                if(isButtonPressed(cards1[i])==1)
                                    {offerCards1[i]=1;break;}
                        for(i=0;i<40;i++)
                            if(property[i].owner==tradeWith)
                                if(isButtonPressed(cards2[i])==1)
                                    {offerCards2[i]=1;break;}
                        if(isButtonPressed(cancelTrade)==1)
                            screen=10;
                        if(isButtonPressed(Done)==1)
                        {
                            for(i=0;i<40;i++)
                            {
                                if(offerCards1[i]==1)
                                    property[i].owner=tradeWith;
                                if(offerCards2[i]==1)
                                    property[i].owner=currentPlayer;
                            }
                            for(i=0;i<40;i++)
                                offerCards1[i]=offerCards2[i]=0;
                            screen=tradeSource;
                        }

                    }
                }

            /*float speed=0.1;
            if(Event.type==sf::Event::KeyPressed)
            {
                if(Event.key.code==sf::Keyboard::Up)
                    {glTranslatef(0,0, speed);camZ+=speed;}
                if(Event.key.code==sf::Keyboard::Down)
                    {glTranslatef(0,0,-speed);camZ-=speed;}
                if(Event.key.code==sf::Keyboard::Left)
                    {glTranslatef( speed,0,0);camX-=speed;}
                if(Event.key.code==sf::Keyboard::Right)
                    {glTranslatef(-speed,0,0);camX+=speed;}
                if(Event.key.code==sf::Keyboard::I)
                    {glTranslatef(0, speed,0);camY+=speed;}
                if(Event.key.code==sf::Keyboard::K)
                    {glTranslatef(0,-speed,0);camY-=speed;}
                if(Event.key.code==sf::Keyboard::W)
                    {glRotatef( speed*10,1,0,0);camRX+=speed*10;}
                if(Event.key.code==sf::Keyboard::S)
                    {glRotatef(-speed*10,1,0,0);camRX-=speed*10;}
                if(Event.key.code==sf::Keyboard::A)
                    {glRotatef( speed*10,0,0,1);camRZ+=speed*10;}
                if(Event.key.code==sf::Keyboard::D)
                    {glRotatef(-speed*10,0,0,1);camRZ-=speed*10;}
                if(Event.key.code==sf::Keyboard::Y)
                    {glRotatef( speed*10,0,1,0);camRY+=speed*10;}
                if(Event.key.code==sf::Keyboard::H)
                    {glRotatef(-speed*10,0,1,0);camRY-=speed*10;}
                cout<<camX<<' '<<camY<<' '<<camZ<<' '<<camRX<<' '<<camRY<<' '<<camRZ<<endl;
            }*/
        }
        drawWorld(screen);
    }
    return 0;
}
