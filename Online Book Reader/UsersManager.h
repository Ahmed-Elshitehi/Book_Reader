#ifndef BOOK_READER_USERSMANAGER_H
#define BOOK_READER_USERSMANAGER_H
#include <string>
#include <map>
#include "user.h"
class UsersManager {
private:
    User* current_user {nullptr};
    map<string, User *> users_list;
    void FreeData();
public:
    void AccessSystem();
    void Login();
    void SignUp();
};


#endif
