#include "system.h"

System::System() :
        books_manager(new BooksManager()), users_manager(new UsersManager()) {
}

void System::LoadDatabase() {
    users_manager->LoadDatabase();
    books_manager->LoadDatabase();
}

void System::Run() {
    LoadDatabase();
    while (true) {
        users_manager->AccessSystem();

        if (users_manager->Get_user()->Is_admin()) {
            users_manager->Get_user()->AdminView(books_manager);
        } else {
            users_manager->Get_user()->UserView(books_manager);
        }

    }
}

System::~System() {
    delete users_manager;
    delete books_manager;
}

