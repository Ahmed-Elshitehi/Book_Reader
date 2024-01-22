#ifndef BOOK_READER_BOOKSMANAGER_H
#define BOOK_READER_BOOKSMANAGER_H

#include <string>
#include <map>
#include "book.h"
class BooksManager {
private:
    map<string, Book*> isbn_to_book_map;

};


#endif
