//
// Created by Ahmed Salah on 9/14/2023.
//

#ifndef ONLINE_BOOK_READER_ADMIN_H
#define ONLINE_BOOK_READER_ADMIN_H

#include <string>
#include <map>
#include "book.h"
using namespace std;
class admin {
private:
    string first_name;
    string last_name;
    string user_name;
    string password;
public:
    admin();
    ~admin();
    admin(string &, string &, string &, string &);
    bool add_book(map<string, book> &data_base, map<string, bool> &book_av);
    bool remove_book(map<string, book> &data_base, map<string, bool> &book_av);
    string get_first_name() const;
    string get_last_name() const;
    string get_user_name() const;
    string get_password() const;
};


#endif //ONLINE_BOOK_READER_ADMIN_H
