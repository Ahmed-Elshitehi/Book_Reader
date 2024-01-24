#ifndef ONLINE_BOOK_READER_USER_H
#define ONLINE_BOOK_READER_USER_H

#include <string>
#include <set>
#include <iostream>
#include <iomanip>
#include <map>
#include "Book.h"
using namespace std;
class User {
private:
    string first_name;
    string last_name;
    string user_name;
    string password;
    bool admin;
public:
    void ReadInfo(string &user_name);
    void PrintInfo();
    void SetUser_name(string &user_name);
    void SetFirst_name(string &basicString);
    void SetLast_name(string &basicString);
    void SetPassword(string &basicString);
    void Set_admin(bool admin);
    const string &GetUserName() const;
    const string &GetPassword() const;
};


#endif
