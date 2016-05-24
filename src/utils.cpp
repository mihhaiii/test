#include <string>
#include "utils.h"


const string CarFiles[] = {
    "images/car1.png",
    "images/car2.png",
    "images/car3.png",
    "images/car4.png",
    "images/car5.png",
    "images/car6.png",
    "images/car7.png",
    "images/car8.png",
    "images/car9.png",
    "images/car10.png",
    "images/curse1.png",
    "images/curse2.png",
    "images/curse3.png",
    "images/curse4.png",
    "images/curse5.png",
    "images/curse6.png",
    "images/curse7.png",
    "images/lim1.png",
    "images/lim2.png",
    "images/lim3.png",
    "images/lim4.png",
    "images/sport1.png",
    "images/sport2.png",
    "images/sport3.png",
    "images/sport4.png",
    "images/sport5.png",
    "images/sport6.png",
    "images/sport7.png",
    "images/suv1.png",
    "images/suv2.png",
    "images/suv3.png",
    "images/suv4.png",
    "images/suv5.png",
    "images/suv6.png",
    "images/suv7.png"
};

const char* Brands2Str[] =
{
    "FIAT",
    "BMW",
    "FORD",
    "DACIA",
    "AUDI",
    "TOYOTA",
    "FERARRI",
    "VOLKSWAGEN",
    "MERCEDES",
    "OPEL"
};

const char* Models2Str[] =
{
    "a32",
    "f5",
    "h1100",
    "j3r3",
    "lk90",
    "xb44",
    "hu35",
    "ui100",
    "xb330",
    "hwt4500"
};


string int2str(int x){
    string s("");
    while (x) {
        s = char(x%10+'0')+s;
        x/=10;
    }
    return s;
}

const string CarState2Str[] = {
    "În vînzare",
    "Stoc epuizat"
};



void showText(string str, sf::RenderWindow& window, int x, int y)
{
    if (str.size()==1&&str[0]>='0'&&str[0]<='9')
    str += ".";
        sf::Font font;
        font.loadFromFile("arial.ttf");
        sf::Text text;
        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(20);
        text.setColor(sf::Color::Black);
        text.setStyle(sf::Text::Italic);

        text.setPosition(x,y);
        window.draw(text);
}
