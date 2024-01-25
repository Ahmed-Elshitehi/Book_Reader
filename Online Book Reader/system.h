#ifndef ONLINE_BOOK_READER_SYSTEM_H
#define ONLINE_BOOK_READER_SYSTEM_H
#include "BooksManager.h"
#include "UsersManager.h"
class System {
private:
    BooksManager *books_manager;
    UsersManager *users_manager;
    void LoadDatabase();
public:
    System();
    void Run();
    ~System();
};


#endif
