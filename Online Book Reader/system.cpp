//
// Created by Ahmed Salah on 9/18/2023.
//

#include "system.h"

system::system() {
    cout << "\t\t\tWELCOME\n";
    cout << "\tThis is you Online Book Reader\n";
    cout << "\tThis is your first time to use this app so you have to sign up as admin first \n";
    sign_up(1);
}

bool system::sign_up(int type) {
    if (!type) {
        cout << "\tsign up as \n"
             << "1- admin\n"
             << "2- user\n";
        cin >> type;
    }
    string first_name;
    string last_name;
    string user_name;
    string password;
    cout << "Inter First name : ";
    cin >> first_name;
    cout << "Inter Last name : ";
    cin >> last_name;
    cout << "Inter User name : ";
    cin >> user_name;
    cout << "Inter Password : ";
    cin >> password;
    if (type == 1) {
        admin temp(user_name, password, first_name, last_name);
        if (!admins[user_name].get_user_name().empty()) {
            cout << "this user_name is already taken for another admin\n";
            return false;
        } else {
            admins[user_name] = temp;
        }
    } else {
        user temp(user_name, password, first_name, last_name);
        if (!users[user_name].get_user_name().empty()) {
            cout << "this user_name is already taken for another user \n";
            return false;
        } else {
            users[user_name] = temp;
        }
    }
    return true;
}

bool system::log_in(int type) {
    if (!type) {
        cout << "\tlog in as \n"
             << "1- admin\n"
             << "2- user\n";
        cin >> type;
    }
    string user_name;
    string password;
    cout << "Inter User name : ";
    cin >> user_name;
    cout << "Inter Password : ";
    cin >> password;
    if (type == 1) {
        if (admins[user_name].get_password() != password) {
            return false;
        }
        admin_menu(admins[user_name]);
    } else {
        if (users[user_name].get_password() != password) {
            return false;
        }
        users[user_name].welcome(data_base);
        user_menu(users[user_name]);
    }
    return true;
}

void system::user_menu(user &User) {
    int chose = 1;
    while (chose) {
        cout << "\t 1- Add new Book \n";
        cout << "\t 2- remove Book \n";
        cout << "\t 3- reading \n";
        cout << "\t 4- See your library \n";
        cout << "\t 5- sign out \n";
        cout << "Chose Number From 1 - 5\n";
        cin >> chose;
        if (chose == 1) {
            cout << "\t\t All Available Books\n";
            for (auto item: data_base) {
                cout << '\t' << item.first << '\n';
            }
            string title;
            cout << "inter your chose Book (NO spaces) \n";
            cin >> title;
            User.new_book(title);
        } else if (chose == 2) {
            if (User.print_library(data_base)) {
                cout << '\n';
                string title;
                cout << "inter your chose Book (NO spaces) \n";
                cin >> title;
                User.remove_book(title);
            }
        } else if (chose == 3) {
            reading(User);
        } else if (chose == 4) {
            User.print_library(data_base);
        } else {
            chose = 0;
        }
    }
}
void system::reading(user &User) {
    string tittle;
    cout << "\twhat is the book you want to read ?";
    cin >> tittle;
    User.read(tittle, User.get_page_for_book(tittle), data_base);
}

void system::admin_menu(admin &Admin) {
    int chose = 1;

    while (chose) {
        cout << "\t 1- Add new Book to System\n";
        cout << "\t 2- remove Book from System\n";
        cout << "\t 3- sign out \n";
        cout << "Chose Number From 1 - 3\n";
        cin >> chose;
        if (chose == 1) {
            Admin.add_book(data_base, book_av);
        } else if (chose == 2) {
            Admin.remove_book(data_base, book_av);
        } else {
            chose = 0;
        }
    }
}

void system::run() {
    int chose = 1;
    while (chose) {
        cout << "1- log in \n";
        cout << "2- sign up \n";
        cout << "3- Exit \n";
        cin >> chose;
        if (chose == 1) {
            log_in(0);
        } else if (chose == 2) {
            sign_up(0);
        } else {
            chose = 0;
        }
    }
}

system::~system() = default;
