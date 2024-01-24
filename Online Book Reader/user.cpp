#include "user.h"


void User::ReadInfo(string &user_name) {

    SetUser_name(user_name);
    string str;

    cout << "Enter password (no spaces): ";
    cin >> str;
    SetPassword(str);

    cout << "Enter first name (no spaces): ";
    cin >> str;
    SetFirst_name(str);

    cout << "Enter last name (no spaces): ";
    cin >> str;
    SetLast_name(str);

    cout << "Do you want to be admin? (Y/N): ";
    char c;
    cin >> c;
    if (toupper(c) == 'Y') {
        cout << "Enter admins code (no spaces): ";
        cin >> str;
        if (str == "m3rof")
            Set_admin(true);
        else
            Set_admin(false);
    }
}

void User::SetUser_name(string &user_name) {
    this->user_name = user_name;
}

void User::SetFirst_name(string &first_name) {
    this->first_name = first_name;
}

void User::SetLast_name(string &last_name) {
    this->last_name = last_name;
}

void User::SetPassword(string &password) {
    this->password = password;
}

void User::Set_admin(bool admin) {
    this->admin = true;
}

void User::PrintInfo() {
    cout << "Name: " << first_name << " " << last_name;
    if (admin)
        cout << " | Admin";
    cout << '\n';
    cout << "User name: " << user_name << '\n';
}

const string &User::GetUserName() const {
    return user_name;
}

const string &User::GetPassword() const {
    return password;
}


