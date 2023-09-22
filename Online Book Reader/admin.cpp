//

#include "admin.h"

admin::admin(string &user_name, string &password, string &first_name, string &last_name) :
        user_name(user_name), password(password), first_name(first_name), last_name(last_name) {
}
//
// Created by Ahmed Salah on 9/14/2023.
admin::admin() {
    user_name = password = first_name = last_name = "";
}

bool admin::add_book(map<string, book> &data_base, map<string, bool> &book_av) {
    int number_of_pages;
    string title;
    string author;
    cout << "inter book title : ";
    cin >> title;
    cout << "inter book author : ";
    cin >> author;
    cout << "inter number of pages : ";
    cin >> number_of_pages;
    check:
    cout << "check\n";
    book Book(title, number_of_pages, author);
    if (book_av[title]) {
        cout << "We have book with the same tittle \n "
             << "Do you want to inter new tittle ? (Y/N) : ";
        char ch;
        cin >> ch;
        if (toupper(ch) == 'Y') {
            cin >> title;
            goto check;
        } else {
            return false;
        }
    } else {
        data_base[title] = Book;
        book_av[title] = true;
        cout << "added successfully\n\n";
        return true;
    }
}

bool admin::remove_book(map<string, book> &data_base, map<string, bool> &book_av) {
    cout << "what is the book you want to remove ? ";
    string title;
    cin >> title;
    if (data_base[title].get_title().empty()) {
        cout << "\tthis book is not in Data Base\n";
        return false;
    } else {
        data_base.erase(title);
        book_av.erase(title);
        cout << "\tremoved successfully\n\n";
        return true;
    }
}
string admin::get_first_name() const {
    return first_name;
}
string admin::get_last_name() const {
    return last_name;
}
string admin::get_user_name() const {
    return user_name;
}

string admin::get_password() const {
    return password;
}

admin::~admin() = default;
