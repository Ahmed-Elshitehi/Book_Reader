//
// Created by Ahmed Salah on 9/15/2023.
//

#ifndef ONLINE_BOOK_READER_USER_H
#define ONLINE_BOOK_READER_USER_H

#include <string>
#include <set>
#include <iostream>
#include <iomanip>
#include <map>
#include "book.h"
using namespace std;
class user {
private:
    string first_name;
    string last_name;
    string user_name;
    string password;
    map<string, int> books; // previse page // book name
    pair<string, int> last;
public:
    user(string &, string &, string &, string &);
    user();
    ~user();
    bool new_book(const string &);
    bool remove_book(string &);
    bool print_library(map<string, book> &data_base);
    void welcome(map<string, book> &data_base);
    void read(string &, int &, map<string, book> &);
    int& get_page_for_book(string &);
    string get_first_name() const;
    string get_last_name() const;
    string get_user_name() const;
    string get_password() const;
};


#endif //ONLINE_BOOK_READER_USER_H
