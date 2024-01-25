#ifndef BOOK_READER_READINGSESSION_H
#define BOOK_READER_READINGSESSION_H

#include "book.h"

class ReadingSession {
private:
    Book *book;
    int currentPage;
public:
    ReadingSession(Book *book);
    ReadingSession();
    void NextPage();
    void PreviousPage();
    void PrintInfo();
    const int &GetCurrentPage() const;

    string GetCurrentPageContent();
};

#endif
