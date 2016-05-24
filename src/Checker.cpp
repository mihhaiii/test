#include "Checker.h"

Checker::Checker()
{
    //ctor
}

Checker::~Checker()
{
    //dtor
}

bool Checker::CheckLogIn(string username, string password, UserManager* userManager)
{
    if (username.size() < 5) return false;
    if (password.size() < 5) return false;

    if (userManager->ExistsUser(username))  {
        if (userManager->CheckLogInfo(username, password))
            return true;
    }
    return false;
}
bool Checker::CheckRegister(string nume, string username, string password, string email, UserManager* userManager)
{
    if (nume.size()<3) return false;
    if (username.size()<3) return false;
    if (password.size()<5) return false;
    if (email.size()<5) return false;

    bool atChar = false;
    bool pointChar = false;

    for(auto ch : email) {
        if (ch =='@') atChar = true;
        if (ch =='.' && atChar) pointChar=true;
    }
    if (!atChar || !pointChar) return false;
    else if (userManager->ExistsUser(username))
        return false;
    return true;
}
