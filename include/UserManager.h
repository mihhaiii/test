#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include <bits/stdc++.h>

using namespace std;

class User;
class UserManager
{
    public:
        UserManager();
        virtual ~UserManager();

        void AddUser(User*);
        void DeleteUser(string);
        bool ExistsUser(string);

        bool CheckLogInfo(string,string);
        void WriteData(const char*);

        User* LoggedInUser();
        User* UserToLogIn(string username);

    protected:

    private:
        vector<User*> _usersList;
};

#endif // USERMANAGER_H
