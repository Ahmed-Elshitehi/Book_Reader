#ifndef BOOK_READER_BOOKSMANAGER_H
#define BOOK_READER_BOOKSMANAGER_H

#include <string>
#include <map>
#include "book.h"
class BooksManager {
private:
    map<string, Book*> library;
public:
    BooksManager();
    void AddBook(Book *);
    void DeleteBook(string isbn);
    void ListAvailableBooks();
};
#endif
