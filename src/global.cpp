#include "global.h"

float x0=0;

void loadTable()
{
    int i,j;
    ifstream fin("data/table.in");
    ifstream pin;
    char c[100],d[100];
    for(i=0;i<40;i++)
    {
        fin.getline(c,256);
        property[i].name=c;
        fin>>property[i].type;
        fin.get();
        if(property[i].type==1)
        {
            vector<string>line;
            pin.open(("data/properties/"+property[i].name+".in").c_str());
            for(j=0;j<9;j++)
            {
                pin.getline(d,256);
                line.push_back(d);
            }
            sscanf(line[0].c_str(),"price %d",&property[i].price);
            sscanf(line[1].c_str(),"house price %d",&property[i].housePrice);
            sscanf(line[2].c_str(),"rent %d",&property[i].rent);
            sscanf(line[3].c_str(),"rent 1 house %d",&property[i].rent1House);
            sscanf(line[4].c_str(),"rent 2 house %d",&property[i].rent2House);
            sscanf(line[5].c_str(),"rent 3 house %d",&property[i].rent3House);
            sscanf(line[6].c_str(),"rent 4 house %d",&property[i].rent4House);
            sscanf(line[7].c_str(),"rent hotel %d",&property[i].rentHotel);
            sscanf(line[8].c_str(),"%s",&c);
            property[i].color=c;
            property[i].cardTexture.loadFromFile(("images/property cards/"+property[i].color).c_str());
            property[i].card.setTexture(property[i].cardTexture);
            property[i].card.setPosition(262,75);

            for(j=0;j<8;j++)
            {
                property[i].cardText[j].setCharacterSize(24);
                property[i].cardText[j].setFont(font1);
                property[i].cardText[j].setColor(sf::Color(0,0,0));
            }
            property[i].cardText[8].setCharacterSize(35);
            property[i].cardText[8].setFont(font1);
            property[i].cardText[8].setColor(sf::Color(0,0,0));

            property[i].cardTextString[0]=intToString(property[i].price);
            property[i].cardTextString[1]=intToString(property[i].rent);
            property[i].cardTextString[2]=intToString(property[i].rent1House);
            property[i].cardTextString[3]=intToString(property[i].rent2House);
            property[i].cardTextString[4]=intToString(property[i].rent3House);
            property[i].cardTextString[5]=intToString(property[i].rent4House);
            property[i].cardTextString[6]=intToString(property[i].rentHotel);
            property[i].cardTextString[7]=intToString(property[i].housePrice);

            for(j=0;j<2;j++)
                property[i].cardText[j].setPosition(600,217+j*27);
            for(j=2;j<7;j++)
                property[i].cardText[j].setPosition(600,271+j*27);
            property[i].cardText[7].setPosition(600,290+7*27);
            pin.close();
        }
    }
}

string intToString(int a)
{
    string x;
    int i,lg;
    int c[200];
    for(i=0;a>0;i++)
    {
        c[i]=a%10+'0';
        a=a/10;
    }
    lg=i;
    for(i=lg-1;i>=0;i--)
        x+=c[i];
    return x+'$';
}

void loadButtons()
{
    int i,j;
    newGame.texture.loadFromFile("images/newGameButton.bmp");
    newGame.image.setTexture(newGame.texture);
    newGame.image.setPosition(1024/2-150,150);
    setButtonCoordinates(newGame,1024/2-150,150,300,75);
    loadGame.texture.loadFromFile("images/loadGameButton.bmp");
    loadGame.image.setTexture(loadGame.texture);
    loadGame.image.setPosition(1024/2-150,275);
    setButtonCoordinates(loadGame,1024/2-150,275,300,75);
    exitGame.texture.loadFromFile("images/exitButton.bmp");
    exitGame.image.setTexture(exitGame.texture);
    exitGame.image.setPosition(1024/2-150,400);
    setButtonCoordinates(exitGame,1024/2-150,400,300,75);
    backgroundMenu.texture.loadFromFile("images/backgroundMenu.bmp");
    backgroundMenu.image.setTexture(backgroundMenu.texture);
    backgroundMenu.image.setPosition(1024/2-325,75);
    addPlayer.texture.loadFromFile("images/addPlayer.bmp");
    addPlayer.image.setTexture(addPlayer.texture);
    addPlayer.image.setPosition(1024/2-250,525);
    setButtonCoordinates(addPlayer,1024/2-250,525,200,50);
    cancelMenu.texture.loadFromFile("images/cancelMenu.bmp");
    cancelMenu.image.setTexture(cancelMenu.texture);
    cancelMenu.image.setPosition(1024/2+50,525);
    setButtonCoordinates(cancelMenu,1024/2+50,525,200,50);
    startGame.texture.loadFromFile("images/startGame.bmp");
    startGame.image.setTexture(startGame.texture);
    startGame.image.setPosition(1024/2-100,600);
    setButtonCoordinates(startGame,1024/2-100,600,200,50);
    nameTexture[0].loadFromFile("images/nameTexture1.bmp");
    moneyTexture.loadFromFile("images/moneyTexture.bmp");
    nameTextBox[0].setTexture(nameTexture[0]);
    moneyTextBox[0].setTexture(moneyTexture);
    nameTexture[1].loadFromFile("images/nameTexture2.bmp");
    moneyTexture.loadFromFile("images/moneyTexture.bmp");
    nameTextBox[1].setTexture(nameTexture[1]);
    moneyTextBox[1].setTexture(moneyTexture);
    nameTexture[2].loadFromFile("images/nameTexture3.bmp");
    moneyTexture.loadFromFile("images/moneyTexture.bmp");
    nameTextBox[2].setTexture(nameTexture[2]);
    moneyTextBox[2].setTexture(moneyTexture);
    nameTexture[3].loadFromFile("images/nameTexture4.bmp");
    moneyTexture.loadFromFile("images/moneyTexture.bmp");
    nameTextBox[3].setTexture(nameTexture[3]);
    moneyTextBox[3].setTexture(moneyTexture);
    nameTextBox[0].setPosition(25,25);
    nameText[0].setPosition(25+10,25+5);
    moneyTextBox[0].setPosition(25,25+40);
    moneyText[0].setPosition(25+10,25+35+10);
    nameTextBox[1].setPosition(1024-170-25,25);
    nameText[1].setPosition(1024-170-25+10,25+5);
    moneyTextBox[1].setPosition(1024-170+45,65);
    moneyText[1].setPosition(1024-170+45+10,60+10);
    nameTextBox[2].setPosition(25,680);
    nameText[2].setPosition(25+10,680+5);
    moneyTextBox[2].setPosition(25,680+40);
    moneyText[2].setPosition(25+10,680+35+10);
    nameTextBox[3].setPosition(1024-170-25,680);
    nameText[3].setPosition(1024-170-25+10,680+5);
    moneyTextBox[3].setPosition(1024-170+45,680+40);
    moneyText[3].setPosition(1024-170+45+10,680+35+10);
    optionBarTexture[0].loadFromFile("images/optionBar.bmp");
    optionBar[0].setTexture(optionBarTexture[0]);
    optionBar[0].setPosition(222,650);
    optionBarTexture[1].loadFromFile("images/optionBar1.bmp");
    optionBar[1].setTexture(optionBarTexture[1]);
    optionBar[1].setPosition(222,650);
    optionBarTexture[2].loadFromFile("images/optionBar2.bmp");
    optionBar[2].setTexture(optionBarTexture[2]);
    optionBar[2].setPosition(222,650);
    optionBarTexture[3].loadFromFile("images/optionBar3.bmp");
    optionBar[3].setTexture(optionBarTexture[3]);
    optionBar[3].setPosition(222,650);
    setButtonCoordinates(Manage,  222+ 50,650,100,100);
    setButtonCoordinates(RollDice,220+250,650,100,100);
    setButtonCoordinates(Trade,   220+450,650,100,100);
    buyBarTexture.loadFromFile("images/buyBar.bmp");
    buyBar.setTexture(buyBarTexture);
    buyBar.setPosition(222,650);
    setButtonCoordinates(Buy,372,675,100,100);
    setButtonCoordinates(DontBuy,612,675,100,100);

    ManageMenuTexture.loadFromFile("images/ManageMenu.bmp");
    ManageMenu.setTexture(ManageMenuTexture);
    ManageMenu.setPosition((1024-750)/2,75);
    plusTexture.loadFromFile("images/plus.bmp");
    minusTexture.loadFromFile("images/minus.bmp");
    Done.texture.loadFromFile("images/Done.bmp");
    Done.image.setTexture(Done.texture);
    Done.image.setPosition((1024-300)/2+150,675);
    setButtonCoordinates(Done,(1024-300)/2+150,675,200,50);

    TradeMenuTexture1.loadFromFile("images/TradeMenu1.bmp");
    TradeMenu1.setTexture(TradeMenuTexture1);
    TradeMenu1.setPosition((1024-750)/2,75);

    TradeMenuTexture2.loadFromFile("images/TradeMenu2.bmp");
    TradeMenu2.setTexture(TradeMenuTexture2);
    TradeMenu2.setPosition((1024-750)/2,75);

    payBarTexture[0].loadFromFile("images/payBar.bmp");
    payBarTexture[1].loadFromFile("images/payBar1.bmp");
    payBarTexture[2].loadFromFile("images/payBar2.bmp");
    payBarTexture[3].loadFromFile("images/payBar3.bmp");
    for(i=0;i<4;i++)
    {
        payBar[i].setTexture(payBarTexture[i]);
        payBar[i].setPosition(222,650);
    }
    for(i=0;i<4;i++)
    {
        for(j=1;j<=property[0].pairs[i][0];j++)
        {
            managePlus[property[0].pairs[i][j]].image.setTexture(plusTexture);
            managePlus[property[0].pairs[i][j]].image.setPosition(120+110*j,175+130*i);
            setButtonCoordinates(managePlus[property[0].pairs[i][j]],120+110*j,175+130*i,20,20);

            manageMinus[property[0].pairs[i][j]].image.setTexture(minusTexture);
            manageMinus[property[0].pairs[i][j]].image.setPosition(120+110*j,205+130*i);
            setButtonCoordinates(manageMinus[property[0].pairs[i][j]],120+110*j,205+130*i,20,20);
        }
    }
    for(i=4;i<8;i++)
    {
        for(j=1;j<=property[0].pairs[i][0];j++)
        {
            managePlus[property[0].pairs[i][j]].image.setTexture(plusTexture);
            managePlus[property[0].pairs[i][j]].image.setPosition(500+110*j,175+130*(i-4));
            setButtonCoordinates(managePlus[property[0].pairs[i][j]],500+110*j,175+130*(i-4),20,20);

            manageMinus[property[0].pairs[i][j]].image.setTexture(minusTexture);
            manageMinus[property[0].pairs[i][j]].image.setPosition(500+110*j,205+130*(i-4));
            setButtonCoordinates(manageMinus[property[0].pairs[i][j]],500+110*j,205+130*(i-4),20,20);
        }
    }
    for(i=0;i<4;i++)
    {
        tradePlayerName[i].texture.loadFromFile("images/TradePlayer.bmp");
        tradePlayerName[i].image.setTexture(tradePlayerName[i].texture);
    }
    for(i=0;i<2;i++)
    {
        tradePlayerName[i].image.setPosition(   (1024-750)/2+116+i*316,275);
        setButtonCoordinates(tradePlayerName[i],(1024-750)/2+116+i*316,275,200,50);
    }
    for(i=2;i<4;i++)
    {
        tradePlayerName[i].image.setPosition(   (1024-750)/2+116+(i-2)*316,400);
        setButtonCoordinates(tradePlayerName[i],(1024-750)/2+116+(i-2)*316,400,200,50);
    }
    TradeBank.texture.loadFromFile("images/TradeBank.bmp");
    TradeBank.image.setTexture(TradeBank.texture);
    TradeBank.image.setPosition((1024-200)/2,500);
    for(i=0;i<8;i++)
        for(j=1;j<=property[0].pairs[i][0];j++)
        {
            setButtonCoordinates(cards1[property[0].pairs[i][j]],160+50*(j-1),165+47*i,30,40);
            setButtonCoordinates(cards2[property[0].pairs[i][j]],735+50*(j-1),165+47*i,30,40);
        }
}

void loadTextFontsAndSettings()
{
    int i;
    font1.loadFromFile("fonts/justadream_solid.ttf");
    for(i=0;i<4;i++)
    {
        textbox[i].button.texture.loadFromFile("images/textbox.bmp");
        textbox[i].button.image.setTexture(textbox[i].button.texture);
        textbox[i].button.image.setPosition(1024/2-125,225+i*75);
        setTextBoxCoordinates(textbox[i],1024/2-125,225+i*75,250,40);
    }
    for(i=0;i<4;i++)
    {
        textbox[i].text.setPosition(1024/2-100,225+i*75);
        setTextBoxCoordinates(textbox[i],1024/2-100,225+i*75,250,40);
        textbox[i].text.setFont(font1);
        textbox[i].text.setCharacterSize(25);
        textbox[i].text.setColor(sf::Color(100, 0, 0));
    }
    for(i=0;i<3;i++)
    {
        optionBarText[i].setPosition(222+65+i*200,740);
        optionBarText[i].setCharacterSize(18);
        optionBarText[i].setFont(font1);
        optionBarText[i].setColor(sf::Color(255,255,255));
    }
    endTurnText.setCharacterSize(18);
    endTurnText.setFont(font1);
    endTurnText.setColor(sf::Color(255,255,255));
    endTurnText.setPosition(222+65+200,740);
    payBarText.setPosition(500,740);
    payBarText.setCharacterSize(18);
    payBarText.setFont(font1);
    payBarText.setColor(sf::Color(255,255,255));
    optionBarText[0].setString("Manage");
    optionBarText[1].setString("Roll Dice");
    optionBarText[2].setString("Trade");
    endTurnText.setString("End turn");
    payBarText.setString("Pay");
    for(i=0;i<4;i++)
    {
        nameText[i].setCharacterSize(24);
        nameText[i].setFont(font1);
        nameText[i].setColor(sf::Color(0,0,0));
        moneyText[i].setCharacterSize(24);
        moneyText[i].setFont(font1);
        moneyText[i].setColor(sf::Color(0,0,0));
    }
    TradeWithText.setString("Trade with:");
    TradeWithText.setColor(sf::Color(0,0,0));
    TradeWithText.setPosition((1024-750)/2+40,75+100);
    TradeWithText.setCharacterSize(50);
    TradeWithText.setFont(font1);

    for(i=0;i<4;i++)
    {
        tradePlayerNameText[i].setFont(font1);
        tradePlayerNameText[i].setCharacterSize(30);
        tradePlayerNameText[i].setColor(sf::Color(255,255,255));
    }
    for(i=0;i<2;i++)
        tradePlayerNameText[i].setPosition((1024-750)/2+125+i*316,283);
    for(i=2;i<4;i++)
        tradePlayerNameText[i].setPosition((1024-750)/2+125+(i-2)*316,408);
    tradeBankNameText.setFont(font1);
    tradeBankNameText.setCharacterSize(30);
    tradeBankNameText.setColor(sf::Color(255,255,255));
    tradeBankNameText.setPosition((1024-200)/2+40,500);
    tradeBankNameText.setString("Bank");

    cancelTrade.texture.loadFromFile("images/cancelTrade.bmp");
    cancelTrade.image.setTexture(cancelTrade.texture);
    cancelTrade.image.setPosition((1024-300)/2-50,675);
    setButtonCoordinates(cancelTrade,(1024-300)/2-50,675,200,50);
}

void setButtonCoordinates(Button &button,int x,int y,int w,int h)
{
    button.x=x;
    button.y=y;
    button.w=w;
    button.h=h;
}

void setTextBoxCoordinates(TextBox &textbox,int x,int y,int w,int h)
{
    textbox.button.x=x;
    textbox.button.y=y;
    textbox.button.w=w;
    textbox.button.h=h;
}

bool isButtonPressed(Button a)
{
    sf::Vector2i m;
    m=sf::Mouse::getPosition(window);
    return (m.x>=a.x && m.x<=a.x+a.w && m.y>=a.y && m.y<=a.y+a.h);
}

void drawWorld(int &screen)
{
    int i,j,k;
    if(screen==0)///First menu
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        room.draw();
        glRotatef(0.6,0,1,0);
        camRY+=0.6;
        window.pushGLStates();
            window.draw(newGame.image);
            window.draw(loadGame.image);
            window.draw(exitGame.image);
        window.popGLStates();


        window.display();
    }
    else if(screen==1)///New game setings
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        room.draw();
        glRotatef(0.6,0,1,0);
        camRY+=0.6;
        window.pushGLStates();
            window.draw(backgroundMenu.image);
            window.draw(addPlayer.image);
            window.draw(cancelMenu.image);

            for(i=0;i<nrPlayers;i++)
            {
                window.draw(textbox[i].button.image);
                window.draw(textbox[i].text);
            }
            window.draw(startGame.image);
        window.popGLStates();
        window.display();
    }
    else if(screen==3)///Tabla de sus
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        room.draw();
        drawPioni();drawBuildings();drawBanners();drawStats();
        window.pushGLStates();
            if(isButtonPressed(Manage)==1)
                window.draw(optionBar[1]);
            else if(isButtonPressed(RollDice)==1)
                window.draw(optionBar[2]);
            else if(isButtonPressed(Trade)==1)
                window.draw(optionBar[3]);
            else window.draw(optionBar[0]);
            for(i=0;i<3;i++)
                window.draw(optionBarText[i]);
        window.popGLStates();
        window.display();
    }
    else if(screen==4)
    {
        float a,b;
        a=-12;b=4.8;
        for(j=0;j<15;j++)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glTranslatef(0,(-10.7-camY)/15,(-11.5-camZ)/15);
            room.draw();
            drawDice();drawPioni();drawBuildings();drawBanners();
            drawStats();
            window.display();
        }
        camY=-10.7;camZ=-11.5;
        for(k=0;k<nr1+nr2;k++)
        {
            if(ok1==true)
                if(player[currentPlayer].pos>=0||player[currentPlayer].pos==40)
                {
                    ok1=false;
                    for(j=0;j<15;j++)
                    {
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        glRotatef((50-camRX)/15,1,0,0);
                        room.draw();
                        drawDice();drawPioni();drawBuildings();drawBanners();
                        drawStats();
                        window.display();
                    }
                    camRX=50;
                }
            if(ok2==true)
                if(player[currentPlayer].pos>=10&&player[currentPlayer].pos!=40)
                {
                    ok2=false;
                    for(j=0;j<15;j++)
                    {
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        glRotatef((90-camRY)/15,0,1,0);
                        room.draw();
                        drawDice();drawPioni();drawBuildings();drawBanners();drawStats();
                        window.display();
                    }
                    camRY=90;
                }
            if(ok3==true)
                if(player[currentPlayer].pos>=20&&player[currentPlayer].pos!=40)
                {
                    ok3=false;
                    for(j=0;j<15;j++)
                    {
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        glRotatef((180-camRY)/15,0,1,0);
                        room.draw();
                        drawDice();drawPioni();drawBuildings();drawBanners();drawStats();
                        window.display();
                    }
                    camRY=180;
                }
            if(ok4==true)
            {
                if(player[currentPlayer].pos>=30&&player[currentPlayer].pos!=40)
                {
                    ok4=false;
                    for(j=0;j<15;j++)
                    {
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        glRotatef((270-camRY)/15,0,1,0);
                        room.draw();
                        drawDice();drawPioni();drawBuildings();drawBanners();drawStats();
                        window.display();
                    }
                    camRY=270;
                }
            }
            if(ok4==false)
            {
                if(player[currentPlayer].pos==0)
                {
                    ok5=false;
                    for(j=0;j<15;j++)
                    {
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        glRotatef((-camRY)/15,0,1,0);
                        room.draw();
                        drawDice();drawPioni();drawBuildings();drawBanners();drawStats();
                        window.display();
                    }
                    camRY=0;
                }
            }
            x0=0.4/15;
            if(player[currentPlayer].pos==10)
            {
                player[currentPlayer].x+=-0.2;
                player[currentPlayer].z+=-0.2;
            }
            if(player[currentPlayer].pos==20)
            {
                player[currentPlayer].x+= 0.2;
                player[currentPlayer].z+=-0.1;
            }
            if(player[currentPlayer].pos==30)
            {
                player[currentPlayer].x+= 0.2;
                player[currentPlayer].z+= 0.1;
            }
            if(player[currentPlayer].pos==40||player[currentPlayer].pos==0)
            {
                player[currentPlayer].x+=-0.2;
                player[currentPlayer].z+= 0.1;
            }
            for(j=0;j<15;j++)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                room.draw();
                if((player[currentPlayer].pos>=0&&player[currentPlayer].pos<10)||player[currentPlayer].pos==40)
                {
                    player[currentPlayer].x-=0.4/15;
                    player[currentPlayer].y=4.225+(x0*x0*a +x0*b);
                }
                if(player[currentPlayer].pos>=10&&player[currentPlayer].pos<20)
                {
                    player[currentPlayer].z-=0.4/15;
                    player[currentPlayer].y=4.225+(x0*x0*a +x0*b);
                }
                if(player[currentPlayer].pos>=20&&player[currentPlayer].pos<30)
                {
                    player[currentPlayer].x+=0.4/15;
                    player[currentPlayer].y=4.225+(x0*x0*a +x0*b);
                }
                if(player[currentPlayer].pos>=30&&player[currentPlayer].pos<40)
                {
                    player[currentPlayer].z+=0.4/15;
                    player[currentPlayer].y=4.225+(x0*x0*a +x0*b);
                }
                drawDice();drawPioni();drawBuildings();drawBanners();drawStats();
                x0+=0.4/15;
                window.display();
            }
            player[currentPlayer].pos=(player[currentPlayer].pos+1)%40;
        }
        if(property[player[currentPlayer].pos].type==1&&property[player[currentPlayer].pos].owner==-1)
            screen=5;
        else if(property[player[currentPlayer].pos].type==1&&property[player[currentPlayer].pos].owner!=currentPlayer)
            {screen=9;}
        else screen=6;
}
    else if(screen==5)
    {
        int pos=player[currentPlayer].pos;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        room.draw();
        drawPioni();drawBuildings();drawBanners();drawStats();
        window.pushGLStates();
            window.draw(property[pos].card);
            for(i=0;i<8;i++)
            {
                property[pos].cardText[i].setString(property[pos].cardTextString[i]);
                window.draw(property[pos].cardText[i]);
            }
            property[pos].cardText[8].setString(property[pos].name);
            float width=property[pos].cardText[8].getLocalBounds().width;
            property[pos].cardText[8].setPosition((1024-width)/2,120);
            window.draw(property[pos].cardText[8]);
            window.draw(buyBar);
        window.popGLStates();
        window.display();
    }
    else if(screen==6)
    {
        if(player[currentPlayer].pos>30&&ok5==true)
        {
            for(j=0;j<15;j++)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glRotatef((-camRY)/15,0,1,0);
                room.draw();
                drawDice();drawPioni();drawBuildings();drawBanners();drawStats();
                window.display();
            }
            camRY=0;
        }
        if(player[currentPlayer].pos>20&&ok5==true)
        {
            for(j=0;j<15;j++)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glRotatef((-camRY)/15,0,1,0);
                room.draw();
                drawDice();drawPioni();drawBuildings();drawBanners();drawStats();
                window.display();
            }
            camRY=0;
        }
        if(player[currentPlayer].pos>10&&ok5==true)
        {
            for(j=0;j<15;j++)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glRotatef((-camRY)/15,0,1,0);
                room.draw();
                drawDice();drawPioni();drawBuildings();drawBanners();drawStats();
                window.display();
            }
            camRY=0;
        }
        if(player[currentPlayer].pos>0)
        {
            for(j=0;j<15;j++)
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glRotatef((90-camRX)/15,1,0,0);
                room.draw();
                drawPioni();drawBuildings();drawBanners();drawStats();
                window.display();
            }
            camRX=90;
        }
        for(j=0;j<15;j++)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glTranslatef(0,(-12-camY)/15,(-13.8-camZ)/15);
            room.draw();
            drawPioni();drawBuildings();drawBanners();drawStats();
            window.display();
        }
        ok1=ok2=ok3=ok4=ok5=true;
        camX=0;camY=-12;camZ=-13.8;
        screen=7;
    }
    else if(screen==7)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        room.draw();
        drawPioni();drawBuildings();drawBanners();drawStats();
        window.pushGLStates();
            if(isButtonPressed(Manage)==1)
                window.draw(optionBar[1]);
            else if(isButtonPressed(RollDice)==1)
                window.draw(optionBar[2]);
            else if(isButtonPressed(Trade)==1)
                window.draw(optionBar[3]);
            else window.draw(optionBar[0]);
            window.draw(optionBarText[0]);
            window.draw(optionBarText[2]);
            window.draw(endTurnText);
        window.popGLStates();
        window.display();
    }
    else if(screen==8)
    {
        int i,j;
        int ok=1;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        room.draw();
        drawPioni();drawBuildings();drawBanners();drawStats();
        window.pushGLStates();
            window.draw(ManageMenu);
            window.draw(Done.image);
            for(i=0;i<4;i++)
            {
                ok=1;
                for(j=1;j<property[0].pairs[i][0];j++)
                    if(!(property[property[0].pairs[i][j]].owner == property[property[0].pairs[i][j+1]].owner&& property[property[0].pairs[i][j+1]].owner == currentPlayer))
                        {ok=0;break;}
                for(j=1;j<=property[0].pairs[i][0];j++)
                {
                    if(property[property[0].pairs[i][j]].owner != currentPlayer)
                        property[property[0].pairs[i][j]].card.setColor(sf::Color(255, 255, 255, 64));
                    property[property[0].pairs[i][j]].card.setScale(0.09,0.12);
                    property[property[0].pairs[i][j]].card.setPosition(70+110*j,170+130*i);
                    window.draw(property[property[0].pairs[i][j]].card);
                    property[property[0].pairs[i][j]].card.setPosition(262,75);
                    property[property[0].pairs[i][j]].card.setScale(1,1);
                    property[property[0].pairs[i][j]].card.setColor(sf::Color(255, 255, 255));
                    if(ok==1)
                    {
                        if(property[property[0].pairs[i][j]].nrHouses!=5)
                            window.draw(managePlus[property[0].pairs[i][j]].image);
                        if(property[property[0].pairs[i][j]].nrHouses!=0)
                            window.draw(manageMinus[property[0].pairs[i][j]].image);
                    }
                }
            }
            for(i=4;i<8;i++)
            {
                ok=1;
                for(j=1;j<property[0].pairs[i][0];j++)
                    if(!(property[property[0].pairs[i][j]].owner == property[property[0].pairs[i][j+1]].owner&& property[property[0].pairs[i][j+1]].owner == currentPlayer))
                        {ok=0;break;}
                for(j=1;j<=property[0].pairs[i][0];j++)
                {
                    if(property[property[0].pairs[i][j]].owner != currentPlayer)
                        property[property[0].pairs[i][j]].card.setColor(sf::Color(255, 255, 255, 64));
                    property[property[0].pairs[i][j]].card.setScale(0.09,0.12);
                    property[property[0].pairs[i][j]].card.setPosition(450+110*j,170+130*(i-4));
                    window.draw(property[property[0].pairs[i][j]].card);
                    property[property[0].pairs[i][j]].card.setPosition(262,75);
                    property[property[0].pairs[i][j]].card.setScale(1,1);
                    property[property[0].pairs[i][j]].card.setColor(sf::Color(255, 255, 255));
                    if(ok==1)
                    {
                        if(property[property[0].pairs[i][j]].nrHouses!=5)
                            window.draw(managePlus[property[0].pairs[i][j]].image);
                        if(property[property[0].pairs[i][j]].nrHouses!=0)
                            window.draw(manageMinus[property[0].pairs[i][j]].image);
                    }
                }
            }
        window.popGLStates();
        window.display();
    }
    if(screen==9)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        room.draw();
        drawPioni();drawBuildings();drawBanners();drawStats();
        window.pushGLStates();
            if(isButtonPressed(Manage)==1)
                window.draw(payBar[1]);
            else if(isButtonPressed(RollDice)==1)
                window.draw(payBar[2]);
            else if(isButtonPressed(Trade)==1)
                window.draw(payBar[3]);
            else window.draw(payBar[0]);
            window.draw(optionBarText[0]);
            window.draw(optionBarText[2]);
            window.draw(payBarText);
        window.popGLStates();
        window.display();
    }
    if(screen==10)
    {
        setButtonCoordinates(Done,(1024-200)/2,675,200,50);
        Done.image.setPosition((1024-200)/2,675);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        room.draw();
        drawPioni();drawBuildings();drawBanners();drawStats();
        window.pushGLStates();
            window.draw(TradeMenu1);
            window.draw(TradeWithText);
            for(i=0;i<nrPlayers;i++)
            {
                tradePlayerNameText[i].setString(player[i].name);
                if(i==currentPlayer)
                {
                    tradePlayerName[i].image.setColor(sf::Color(255,255,255,30));
                    tradePlayerNameText[i].setColor(sf::Color(255,255,255,64));
                }
                else
                {
                    tradePlayerName[i].image.setColor(sf::Color(255,255,255,255));
                    tradePlayerNameText[i].setColor(sf::Color(255,255,255,255));
                }
                window.draw(tradePlayerName[i].image);
                window.draw(tradePlayerNameText[i]);
                window.draw(TradeBank.image);
            }
            window.draw(Done.image);
        window.popGLStates();
        window.display();
    }
    if(screen==11)
    {
        setButtonCoordinates(Done,(1024-200)/2,675,200,50);
        Done.image.setPosition((1024-300)/2+150,675);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        room.draw();
        drawPioni();drawBuildings();drawBanners();drawStats();
        window.pushGLStates();
            window.draw(TradeMenu2);
            window.draw(Done.image);
            window.draw(cancelTrade.image);
            for(i=0;i<8;i++)
                for(j=1;j<=property[0].pairs[i][0];j++)
                {
                    if(property[property[0].pairs[i][j]].owner==currentPlayer)
                        property[property[0].pairs[i][j]].card.setColor(sf::Color(255,255,255,255));
                    else
                        property[property[0].pairs[i][j]].card.setColor(sf::Color(255,255,255,64));
                    property[property[0].pairs[i][j]].card.setScale(0.06,0.08);
                    property[property[0].pairs[i][j]].card.setPosition(160+50*(j-1),165+47*i);
                    window.draw(property[property[0].pairs[i][j]].card);
                    property[property[0].pairs[i][j]].card.setPosition(262,75);
                    property[property[0].pairs[i][j]].card.setScale(1,1);
                }

            for(i=0;i<8;i++)
                for(j=1;j<=property[0].pairs[i][0];j++)
                {
                    if(property[property[0].pairs[i][j]].owner==tradeWith)
                        property[property[0].pairs[i][j]].card.setColor(sf::Color(255,255,255,255));
                    else
                        property[property[0].pairs[i][j]].card.setColor(sf::Color(255,255,255,64));
                    property[property[0].pairs[i][j]].card.setScale(0.06,0.08);
                    property[property[0].pairs[i][j]].card.setPosition(735+50*(j-1),165+47*i);
                    window.draw(property[property[0].pairs[i][j]].card);
                    property[property[0].pairs[i][j]].card.setPosition(262,75);
                    property[property[0].pairs[i][j]].card.setScale(1,1);
                }
            k=-1;
            for(i=0;i<40;i++)
                if(offerCards1[i]==1)
                {
                    k++;
                    property[i].card.setScale(0.06,0.08);
                    property[i].card.setPosition(325+50*(k%8),165+47*(k/8));
                    property[i].card.setColor(sf::Color(255,255,255,255));
                    window.draw(property[i].card);
                    property[i].card.setScale(1,1);
                    property[i].card.setColor(sf::Color(255,255,255,64));
                }
            k=-1;
            for(i=0;i<40;i++)
                if(offerCards2[i]==1)
                {
                    k++;
                    property[i].card.setScale(0.06,0.08);
                    property[i].card.setPosition(325+50*(k%8),445+47*(k/8));
                    property[i].card.setColor(sf::Color(255,255,255,255));
                    window.draw(property[i].card);
                    property[i].card.setScale(1,1);
                    property[i].card.setColor(sf::Color(255,255,255,64));
                }
        window.popGLStates();
        window.display();
    }
}

void drawDice()
{
     glPushMatrix();
        if(nr1==1)
        {
            glTranslatef(-0.3,4.3,0);glRotatef(90,0,0,1);
            dice2.draw();
        }
        else if(nr1==2)
        {
            glTranslatef(-0.3,4.3,0);
            dice2.draw();
        }
        else if(nr1==3)
        {
            glTranslatef(-0.3,4.3,0);glRotatef(-90,0,0,1);
            dice2.draw();
        }
        else if(nr1==4)
        {
            glTranslatef(-0.3,4.3,0);glRotatef(180,1,0,0);
            dice2.draw();
        }
        else if(nr1==5)
        {
            glTranslatef(-0.3,4.3,0);glRotatef(90,1,0,0);
            dice2.draw();
        }
        else if(nr1==6)
        {
            glTranslatef(-0.3,4.3,0);glRotatef(-90,1,0,0);
            dice2.draw();
        }
    glPopMatrix();
    glPushMatrix();
        if(nr2==1)
        {
            glTranslatef(0.3,4.3,0);glRotatef(90,0,0,1);
            dice2.draw();
        }
        else if(nr2==2)
        {
            glTranslatef(0.3,4.3,0);
            dice2.draw();
        }
        else if(nr2==3)
        {
            glTranslatef(0.3,4.3,0);glRotatef(-90,0,0,1);
            dice2.draw();
        }
        else if(nr2==4)
        {
            glTranslatef(0.3,4.3,0);glRotatef(180,1,0,0);
            dice2.draw();
        }
        else if(nr2==5)
        {
            glTranslatef(0.3,4.3,0);glRotatef(90,1,0,0);
            dice2.draw();
        }
        else if(nr2==6)
        {
            glTranslatef(0.3,4.3,0);glRotatef(-90,1,0,0);
            dice2.draw();
        }
    glPopMatrix();
}
void drawStats()
{
    int i;
    window.pushGLStates();
        for(i=0;i<player.size();i++)
        {
            string x;
            char c[100];
            itoa(player[i].money,c,10);x=c;x+='$';
            nameText[i].setString(player[i].name);
            moneyText[i].setString(x);
            if(i!=currentPlayer)
            {
                nameTextBox[i].setColor(sf::Color(255,255,255,64));
                nameText[i].setColor(sf::Color(0,0,0,64));
                moneyTextBox[i].setColor(sf::Color(255,255,255,64));
                moneyText[i].setColor(sf::Color(0,0,0,64));
            }
            else
            {
                nameTextBox[i].setColor(sf::Color(255,255,255,255));
                nameText[i].setColor(sf::Color(0,0,0,255));
                moneyTextBox[i].setColor(sf::Color(255,255,255));
                moneyText[i].setColor(sf::Color(0,0,0,255));
            }
            window.draw(nameTextBox[i]);
            window.draw(nameText[i]);
            window.draw(moneyTextBox[i]);
            window.draw(moneyText[i]);
        }
    window.popGLStates();
}

void drawPioni()
{
    int i;
    for(i=0;i<player.size();i++)
    {
        glPushMatrix();
            glTranslatef(player[i].x,player[i].y,player[i].z);
            player[i].pion.draw();
        glPopMatrix();
    }
}

void drawBanners()
{
    int i;
    for(i=0;i<40;i++)
    {
        if(property[i].owner>=0)
        {
            glPushMatrix();
                if(i>=0&&i<10)
                {
                    glTranslatef(0.4*(5-i),4.1,2.5);
                    glRotatef(90,0,1,0);
                }
                if(i>=10&&i<20)
                    glTranslatef(-2.5,4.1,0.4*(15-i));
                if(i>=20&&i<30)
                {
                    glTranslatef(-0.4*(25-i),4.1,-2.5);
                    glRotatef(90,0,1,0);
                }
                if(i>=30&&i<40)
                    glTranslatef(2.5,4.1,-0.4*(35-i));
                player[property[i].owner].banner.draw();
            glPopMatrix();
        }
    }
}

void drawBuildings()
{
    int i,j;
    for(i=0;i<40;i++)
        if(property[i].type==1&&property[i].owner!=-1)
            if(property[i].nrHouses!=0)
            {
                for(j=0;j<property[i].nrHouses;j++)
                {
                    glPushMatrix();
                        if(i>=0&&i<10)
                        {
                            if(property[i].nrHouses==5)
                            {
                                glTranslatef(0.4*(5-i),4.12,1.85);
                                hotel.draw();
                            }
                            else
                            {
                                glTranslatef(0.4*(5-i)+0.1*j-0.15,4.12,1.85);
                                house.draw();
                            }
                        }
                        if(i>=10&&i<20)
                        {
                            if(property[i].nrHouses==5)
                            {
                                glTranslatef(-1.85,4.12,0.4*(15-i));
                                glRotatef(90,0,1,0);
                                hotel.draw();
                            }
                            else
                            {
                                glTranslatef(-1.85,4.12,0.4*(15-i)+0.1*j-0.15);
                                glRotatef(90,0,1,0);
                                house.draw();
                            }
                        }
                        if(i>=20&&i<30)
                        {
                            if(property[i].nrHouses==5)
                            {
                                glTranslatef(-0.4*(25-i),4.12,-1.85);
                                hotel.draw();
                            }
                            else
                            {
                                glTranslatef(-0.4*(25-i)+0.1*j-0.15,4.12,-1.85);
                                house.draw();
                            }
                        }
                        if(i>=30&&i<40)
                        {
                            if(property[i].nrHouses==5)
                            {
                                glTranslatef(1.85,4.12,-0.4*(35-i));
                                glRotatef(90,0,1,0);
                                hotel.draw();
                            }
                            else
                            {
                                glTranslatef(1.85,4.12,-0.4*(35-i)-0.1*j+0.15);
                                glRotatef(90,0,1,0);
                                house.draw();
                            }
                        }
                    glPopMatrix();
                }
            }
}

void init()
{
    glClearColor(0,0,0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,1,200);
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,1024,1024);
    GLfloat amb[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat pos[] = {0.0, 5.5, 0.0, 1.0};
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT0, GL_POSITION, pos);

    loadButtons();
    loadTable();
    loadTextFontsAndSettings();

    room.loadModel("models/room.obj");
    dice1.loadModel("models/dice.obj");
    dice2.loadModel("models/dice.obj");
    house.loadModel("models/house.obj");
    hotel.loadModel("models/hotel.obj");
    window.setFramerateLimit(30);

    glTranslatef(0,-8.4,-6);
    camX=0;camY=-8.4;camZ=-6;
    camRX=0;camRY=0;camRZ=0;
}
