#ifndef CHECKER_H
#define CHECKER_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "UserManager.h"
#include "User.h"

using namespace std;

class Checker
{
    public:
        Checker();
        virtual ~Checker();

        static bool CheckLogIn(string ,string,UserManager*);
        static bool CheckRegister(string,string,string,string,UserManager*);

    protected:

    private:
};

#endif // CHECKER_H
