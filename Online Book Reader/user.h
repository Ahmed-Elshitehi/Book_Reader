#ifndef ONLINE_BOOK_READER_USER_H
#define ONLINE_BOOK_READER_USER_H

#include <string>
#include <set>
#include <iostream>
#include <iomanip>
#include <map>
#include "Book.h"
#include "BooksManager.h"
#include "vector"
#include "ReadingSession.h"
using namespace std;
class User {
private:
    string first_name;
    string last_name;
    string user_name;
    string password;
    bool admin;
    vector<ReadingSession *> reading_sessions;
public:
    void ReadInfo(string &user_name);
    void PrintInfo();
    void SetUser_name(string user_name);
    void SetFirst_name(string basicString);
    void SetLast_name(string basicString);
    void SetPassword(string basicString);
    void Set_admin(bool admin);
    bool Is_admin() const;
    const string &GetUserName() const;
    const string &GetPassword() const;
    string Get_name();
    void ListReadingHistory();
    void DisplaySession(ReadingSession *);
    void AdminView(BooksManager *pManager);
    void UserView(BooksManager *pManager);
};


#endif
