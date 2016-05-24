#ifndef USER_H
#define USER_H

#include <string>
#include "UserManager.h"
#include "MyCart.h"
#include "MasinaManager.h"

using namespace std;

class UserManager;

class User
{
    public:
        User();
        User(string,string,string);

        string GetUsername();
        string GetName();
        string GetPassword();

        void LogIn();
        void LogOut();
        bool IsLoggedIn();
        bool CheckPassword(string);

        void addCarToCart(Masina*);

        MasinaManager* getCarList();

    protected:

    private:
        int _id;
        string _name;
        string _username;
        string _password;
        bool _loggedIn;

        static int noUsers;
        MasinaManager myCart;
};

#endif // USER_H
