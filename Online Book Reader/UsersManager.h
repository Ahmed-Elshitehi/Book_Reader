#ifndef BOOK_READER_USERSMANAGER_H
#define BOOK_READER_USERSMANAGER_H
#include <string>
#include <map>
#include "user.h"
class UsersManager {
    User* current_user {nullptr};
    map<string, User *> userame_userobject_map;
};


#endif
