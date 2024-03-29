
#include "ReadingSession.h"

ReadingSession::ReadingSession(Book *book) : book(book), currentPage(0) {
}

ReadingSession::ReadingSession() {
    ReadingSession(nullptr);
}

void ReadingSession::NextPage() {
    if (currentPage < book->GetNumOfPages() - 1) {
        currentPage++;
    }
}

void ReadingSession::PreviousPage() {
    if (currentPage > 0) {
        currentPage--;
    }
}

void ReadingSession::PrintInfo() {
    cout << book->GetTitle() << " Page: " << currentPage + 1 << '\n';
}

const int &ReadingSession::GetCurrentPage() const {
    return currentPage;
}

string ReadingSession::GetCurrentPageContent() {
    return book->GetPageAt(currentPage);
}
