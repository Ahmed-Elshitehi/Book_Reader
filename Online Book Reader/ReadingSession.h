#ifndef BOOK_READER_READINGSESSION_H
#define BOOK_READER_READINGSESSION_H

#include "book.h"

class ReadingSession {
private:
    Book *book;
    int currentPage;
public:
    ReadingSession();
    ReadingSession(Book *book);
    void NextPage();
    void PreviousPage();

};

#endif
