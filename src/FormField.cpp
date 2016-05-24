#include "FormField.h"

FormField::FormField()
{
    shape.setSize(sf::Vector2f(200, 20));
    textLabelObj.SetCharacterSize(12);
    textLabelObj.SetStyle("normal");
    encryptedLabel.SetCharacterSize(12);
    encryptedLabel.SetStyle("normal");

    cursor.SetText("|");
    cursor.SetStyle("normal");
    _active = false;
    _passwordType = false;
}

FormField::~FormField()
{
    //dtor
}

void FormField::UpdateCursor() {
    if (_passwordType) {
         cursor.SetPosition((int)encryptedLabel.getPosition().x + encryptedLabel.GetWidth(),shape.getPosition().y+4);
    } else {
         cursor.SetPosition((int)textLabelObj.getPosition().x + textLabelObj.GetWidth(),shape.getPosition().y+4);
    }
}

void FormField::SetPosition(int x, int y) {
    shape.setPosition(sf::Vector2f(x, y));
    textLabelObj.SetPosition(x+5, y+4);
    encryptedLabel.SetPosition(x+5,y+4);
    UpdateCursor();
}

void FormField::AddLetter(char c) {
    if (_passwordType) {
        if (encryptedLabel.GetWidth() + 15 > shape.getSize().x )
            return;
    } else {
        if (textLabelObj.GetWidth() + 15 > shape.getSize().x )
            return;
    }

    textLabelObj.AddLetter(c);
    encryptedLabel.AddLetter('*');

    UpdateCursor();
}
void FormField::PopLetter() {
        textLabelObj.PopLetter();
        encryptedLabel.PopLetter();

        UpdateCursor();
}

void FormField::Show(sf::RenderWindow& window) {
    window.draw(shape);
    if (_passwordType) {
        encryptedLabel.Show(window);
    } else {
        textLabelObj.Show(window);
    }


    if (_active) {
        sf::Time time = clock.getElapsedTime();
        if ((int)time.asSeconds() % 2 == 1) {
            cursor.SetText("|");
        }
        else {
            cursor.SetText("");
        }
        cursor.Show(window);
    }

}

string FormField::GetText() {
    return textLabelObj.GetText();
}

bool FormField::IsButtonPressedAt(int x, int y) {
    sf::Rect<float> rect =  shape.getGlobalBounds();
    return x >= rect.left && x <= rect.left + rect.width && y >= rect.top && y <= rect.top + rect.height;
}

void FormField::SetActive(bool f) {
    _active = f;
}


bool FormField::IsActive(){
    return _active;
}

void FormField::SetPasswordType(bool f) {
    _passwordType = f;
}

