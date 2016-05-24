#include "UserManager.h"

UserManager::UserManager()
{
    //ctor
}

UserManager::~UserManager()
{
    //dtor
}

void UserManager::AddUser(User* u)
{
    _usersList.push_back(u);
}
void UserManager::DeleteUser(string username)
{

}

bool UserManager::ExistsUser(string username)
{
    for (auto user:_usersList)
        if (user->GetUsername() == username) return true;
    return false;
}

User* UserManager::UserToLogIn(string username)
{
    for (auto user:_usersList)
        if (user->GetUsername() == username) return user;
}

bool UserManager::CheckLogInfo(string username, string password)
{
    for(auto user : _usersList) {
        if (user->GetUsername() == username)
            return user->CheckPassword(password);
    }
}

void UserManager::WriteData(const char* filename) {
    freopen(filename,"w",stdout);
    for(auto user : _usersList) {
        cout << user->GetName() << "\n" << user->GetUsername() << "\n" << user->GetPassword() << "\n\n";
    }
}

User* UserManager::LoggedInUser()
{
    for (auto user: _usersList)
        if (user->IsLoggedIn())
            return user;
}
