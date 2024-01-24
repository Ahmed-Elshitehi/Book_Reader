#include "UsersManager.h"

void UsersManager::FreeData() {
    for (auto pair: users_list) {
        delete pair.second;
    }
    users_list.clear();
    current_user = nullptr;
}

void UsersManager::AccessSystem() {
    cout << "\n";
    cout << "\t1: ";
         cout << "\nEnter number in range " << "1 - 2"  ": ";
    int choice;
    cin >> choice;
    if (choice == 1)
        Login();
    else
        SignUp();
}

void UsersManager::Login() {
    while (true) {
        string user_name, pass;
        cout << "Enter user name (no spaces): ";
        cin >> user_name;
        cout << "Enter password (no spaces): ";
        cin >> pass;

        if (!users_list.count(user_name)) {
            cout << "\nInvalid user user_name or password. Try again\n\n";
            continue;
        }
        User* user_exist = users_list.find(user_name)->second;

        if (pass != user_exist->GetPassword()) {
            cout << "\nInvalid user user_name or password. Try again\n\n";
            continue;
        }
        current_user = user_exist;
        break;
    }
}

void UsersManager::SignUp() {
    string user_name;
    while (true) {
        cout << "Enter user name (No spaces): ";
        cin >> user_name;

        if (users_list.count(user_name))
            cout << "This user name already used. Try again\n";
        else
            break;
    }
    current_user = new User();
    current_user->ReadInfo(user_name);
    string t = current_user->GetUserName();
    users_list[current_user->GetUserName()] = current_user;
}

