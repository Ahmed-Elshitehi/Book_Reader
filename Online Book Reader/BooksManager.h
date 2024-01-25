#ifndef BOOK_READER_BOOKSMANAGER_H
#define BOOK_READER_BOOKSMANAGER_H

#include <string>
#include <map>
#include "book.h"
class BooksManager {
private:
    map<string, Book*> library;
    void FreeLoad();
public:
    BooksManager();
    void AddBook(Book *);
    void DeleteBook(string isbn);
    void ListAvailableBooks();
    void LoadDatabase();
    map<string, Book *> &GetLibrary();
    ~BooksManager();
};
#endif
