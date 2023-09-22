//
// Created by Ahmed Salah on 9/15/2023.
//

#include "user.h"

user::user(string &user_name, string &password, string &first_name, string &last_name) :
        user_name(user_name), password(password), first_name(first_name), last_name(last_name) {
    last = {"", 0};
}
user::user() {
    user_name = password = first_name = last_name = "";
    last = {"", 0};
}

user::~user() = default;
bool user::new_book(const string &title) {
    if (books[title]) {
        std::cout << "\tThis Book is already in your library\n";
        return false;
    }
    books[title] = 1;
    cout << "\tBook added successfully to your library \n";
    return true;
}

bool user::remove_book(string &title) {
    if (books[title] == 0) {
        std::cout << "\tThis Book is not in your library\n";
        books.erase(title);
        return false;
    }
    books.erase(title);
    cout << "\tBook removed successfully to your library \n";
    return true;
}

bool user::print_library(map<string, book> &data_base) {
    if (books.empty()) {
        cout << "\tYour library is empty \n";
        return false;
    } else {
        cout << setfill(' ') << left << setw(10) << "Title";
        cout << "progress\n";
        for (const auto& book: books) {
            cout << setfill(' ') << left << setw(10) << book.first;
            cout << (double) book.second / data_base[book.first].get_number_of_pages() * 100 << "%\n";
        }
    }
    return true;
}
void user::welcome(map<string, book> &data_base) {
    cout << "\t Welcome " << first_name << ' ' << last_name << '\n';
    cout << "\t Your current session is" << last.first << ' ' << last.second << '\n';
    print_library(data_base);
}
void user::read(string &tittle, int &page,map<string, book> &data_base) {
    if (!books[tittle]) {
        std::cout << "\tThis Book is not in your library\n";
        books.erase(tittle);
    } else {
        if (books[tittle] == data_base[tittle].get_number_of_pages()) {
            cout << "Do you want to re-read this Book ? (Y/N)";
            char c;
            cin >> c;
            if (toupper(c) == 'Y') {
                books[tittle] = 1;
            } else {
                return;
            }
        }
        data_base[tittle].reading(books[tittle]);
        last = {tittle, books[tittle]};
    }
}
string user::get_first_name() const {
    return first_name;
}
string user::get_last_name() const {
    return last_name;
}
string user::get_user_name() const {
    return user_name;
}
string user::get_password() const {
    return password;
}

int& user::get_page_for_book(string &tittle) {
    return books[tittle];
}


