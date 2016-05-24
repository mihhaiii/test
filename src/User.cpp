#include "User.h"

User::User() {
    //ctor
    noUsers++;
    _id = noUsers;
}

User::User(string a, string b, string c) :
    _name(a), _username(b), _password(c) {
    noUsers++;
    _id = noUsers;
}

MasinaManager* User::getCarList() {
    return &myCart;
}

string User::GetName(){
    return _name;
}
string User::GetUsername(){
    return _username;
}
string User::GetPassword(){
    return _password;
}
bool User::CheckPassword(string password){
    return this->_password == password;
}


int User::noUsers = 0; //?? TODO

void User::addCarToCart(Masina* m){
    myCart.AddCar(m);
}








void User::LogIn()
{
    _loggedIn = true;
}

void User::LogOut()
{
    _loggedIn = false;
}

bool User::IsLoggedIn()
{
    return _loggedIn;
}
