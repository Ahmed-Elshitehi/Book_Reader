//
// Created by Ahmed Salah on 9/18/2023.
//

#ifndef ONLINE_BOOK_READER_SYSTEM_H
#define ONLINE_BOOK_READER_SYSTEM_H

#include <string>
#include <map>
#include <vector>
#include "book.h"
#include "user.h"
#include "admin.h"
class system {
public:
    map<string, book> data_base;
    map<string, bool> book_av;
    map<string, user> users;
    map<string, admin> admins;
public:
    system();
    ~system();
    void run();
    bool sign_up(int type);
    bool log_in(int type);
    void user_menu(user &User);
    void admin_menu(admin &Admin);
    void reading(user &User);
};


#endif //ONLINE_BOOK_READER_SYSTEM_H
