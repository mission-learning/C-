#include <SFML/Graphics.hpp>
#include <time.h>
#include "grid.h"
#include <math.h>

using namespace sf;

RenderWindow app(VideoMode(850,850),"NONOGRAM - get the whole picture by clicking right squares, block false squares by choosing X!");

void circle_draw(Sprite circle)
{
    circle.setTextureRect(IntRect(0,0,120,120));
    circle.setPosition(280,705);
    app.draw(circle);
}

void cross_draw(Sprite cross)
{
    cross.setTextureRect(IntRect(0,0,120,120));
    cross.setPosition(483,705);
    app.draw(cross);
}


void draw_num(int life, Sprite back)
{
    back.setTextureRect(IntRect(0,0,45,52));
    back.setPosition(722,340);
    app.draw(back);
    Texture num;
    int lifes = (int)life/2;
    if (lifes != 0)
    {

        switch( lifes )
        {
            case 5:
                num.loadFromFile("5.png");
                break;
            case 4:
                num.loadFromFile("4.png");
                break;
            case 3:
                num.loadFromFile("3.png");
                break;
            case 2:
                num.loadFromFile("2.png");
                break;
            case 1:
                num.loadFromFile("1.png");
                break;
            default:
                //std::cout << lifes << std::endl;
                break;
        }
        Sprite number(num);
        number.setTextureRect(IntRect(0,0,50,50));
        number.setPosition(720,340);
        app.draw(number);
    }
    else
    {

    }
}

int main()
{
    srand(time(0));

    int w = 30;
    int lifes = 10;

    Grid grid;
    Grid sgrid;

    int flag;
    Texture background;
    background.loadFromFile("Play.png");
    Sprite back(background);

    Texture gameOver;
    gameOver.loadFromFile("game_over.png");
    Sprite GameOver(gameOver);

    Texture end;
    end.loadFromFile("final.png");
    Sprite GameWon(end);

    Texture around;
    around.loadFromFile("ramka.png");
    Sprite ramka(around);

    Texture t;
    t.loadFromFile("tiles.png");
    Sprite s(t);

    Texture circle_ON;
    circle_ON.loadFromFile("koło ON.png");
    Sprite circleON(circle_ON);

    Texture cross_ON;
    cross_ON.loadFromFile("krzyżyk ON.png");
    Sprite crossON(cross_ON);

    Texture circle_OFF;
    circle_OFF.loadFromFile("koło OFF.png");
    Sprite circleOFF(circle_OFF);

    Texture cross_OFF;
    cross_OFF.loadFromFile("krzyżyk OFF.png");
    Sprite crossOFF(cross_OFF);

    Texture button;
    button.loadFromFile("start_again.png");
    Sprite startAgain(button);


    Texture underNum;
    underNum.loadFromFile("back.png");
    Sprite under(underNum);

    int circleSX = 340;
    int circleSY = 765;

    int crossSX = 543;
    int crossSY = 765;

    int radius = 60;

    int finish = 115;

    //gridMaker
    grid.setRow(0,5,7,3);

    grid.setRow(1,4,5,3);
    grid.setRow(1,7,8,3);

    grid.setRow(2,4,4,4);
    grid.setRow(2,5,9,3);

    grid.setRow(3,3,5,4);
    grid.setRow(3,6,7,3);
    grid.setRow(3,9,9,3);
    grid.setRow(3,11,13,7);
    grid.setRow(3,14,14,6);

    grid.setRow(4,0,0,4);
    grid.setRow(4,2,2,4);
    grid.setRow(4,4,6,4);
    grid.setRow(4,7,9,3);
    grid.setRow(4,11,12,7);

    grid.setRow(5,0,7,4);
    grid.setRow(5,8,8,3);
    grid.setRow(5,10,10,7);
    grid.setRow(5,12,12,7);

    grid.setRow(6,9,13,7);
    grid.setRow(6,14,14,6);
    grid.setRow(6,1,7,4);

    grid.setRow(7,0,0,3);
    grid.setRow(7,1,4,4);
    grid.setRow(7,6,7,4);
    grid.setRow(7,9,12,7);

    grid.setRow(8,0,0,3);
    grid.setRow(8,2,6,4);
    grid.setRow(8,8,12,7);

    grid.setRow(9,3,5,4);
    grid.setRow(9,8,11,7);
    grid.setRow(9,13,13,7);
    grid.setRow(9,14,14,6);

    grid.setRow(10,3,3,3);
    grid.setRow(10,5,6,4);
    grid.setRow(10,9,12,7);

    grid.setRow(11,2,3,3);
    grid.setRow(11,5,6,4);
    grid.setRow(11,9,9,7);
    grid.setRow(11,11,12,7);

    grid.setRow(12,10,14,7);
    grid.setRow(12,14,14,6);

    grid.setRow(13,6,7,5);
    grid.setRow(13,11,11,7);

    grid.setRow(14,5,7,5);
    grid.setRow(14,8,10,7);
    int stop = 0;

    int gameLost = 0;
    int gameFinished = 0;

    while(app.isOpen())
    {
        Vector2i pos = Mouse::getPosition(app);
        int x = pos.x;
        int y = pos.y;

        int posx = (int)(x-230)/w;
        int posy = (int)(y-240)/w;

        Event e;
        while(app.pollEvent(e))
        {
            if(e.type == Event::Closed)
            {
                app.close();
            }
            if(e.type = Event::MouseButtonPressed)
            {
                if((enum sf::Mouse::Button)e.key.code == Mouse::Left)
                {
                    if (pow((x-circleSX),2) + pow(y-circleSY,2) <= pow(radius,2))
                    {
                        flag = 1;
                    }
                    else if(pow((x-crossSX),2) + pow(y-crossSY,2) <= pow(radius,2))
                    {
                        flag = 0;
                    }
                    else if (pow((x-(5+60)),2) + pow(y-(720+60),2) <= pow(radius,2))
                    {
                        sgrid.clearBoard();
                        lifes = 10;
                        gameLost = 0;
                        gameFinished = 0;
                        finish = 115;
                    }
                    else if(posx >= 0 && posx <= 14 && posy >= 0 and posy <= 14)
                    {
                        if(flag)
                        {
                            if(grid[posx][posy]>2 && sgrid[posx][posy]==0)
                            {
                                sgrid[posx][posy] = grid[posx][posy];
                                sgrid.checkRow(posx, grid);
                                sgrid.checkColumn(posy,grid);
                                finish-=1;
                                if(finish == 0)
                                {
                                    gameFinished = 1;
                                }
                            }
                            else{
                                if(sgrid[posx][posy]==0)
                                {
                                    lifes-=2;
                                    sgrid[posx][posy] = 1;
                                    if(lifes == 0)
                                    {
                                        gameLost = 1;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if(stop == 0)
                            {
                                if (sgrid[posx][posy] == 2)
                                {
                                    sgrid[posx][posy] = 0;
                                }
                                else if (sgrid[posx][posy] == 0)
                                {
                                    sgrid[posx][posy] = 2;
                                }
                                stop=1;
                            }
                            else
                            {
                                stop = 0;
                            }
                        }

                    }
                }
            }
        }
        if(gameLost == 0 && gameFinished == 0)
        {

            const Color color = Color(31,13,84);
            app.clear(color);

            back.setTextureRect(IntRect(0,0,850,850));
            back.setPosition(0,0);
            app.draw(back);

            for (int i = 0; i < 15; i++)
            {
                for(int j = 0; j < 15; j++)
                {
                    s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
                    s.setPosition(i*w+230,j*w+240);
                    app.draw(s);
                }
            }

            if (flag)
            {
                circle_draw(circleON);
                cross_draw(crossOFF);
            }
            else
            {
                circle_draw(circleOFF);
                cross_draw(crossON);
            }

            ramka.setTextureRect(IntRect(0,0,452,452));
            ramka.setPosition(230,240);
            app.draw(ramka);
            draw_num(lifes, back);
        }
        else if(gameLost == 1)
        {
            GameOver.setTextureRect(IntRect(0,0,850,850));
            GameOver.setPosition(0,0);
            app.draw(GameOver);
        }
        else
        {
            //gameFinished
            GameWon.setTextureRect(IntRect(0,0,850,850));
            GameWon.setPosition(0,0);
            app.draw(GameWon);

        }

        startAgain.setTextureRect(IntRect(0,0,120,120));
        startAgain.setPosition(5,720);
        app.draw(startAgain);

        app.display();
    }
    return 0;
}