
#include "BooksManager.h"

BooksManager::BooksManager() {
}

void BooksManager::AddBook(Book *book) {
    library[book->GetIsbn()] = book;
}

void BooksManager::DeleteBook(string isbn) {
    delete library[isbn];
    library.erase(isbn);
    // Bad implementation because I'm lazy
}

void BooksManager::ListAvailableBooks() {
    int idx = 0;
    for (auto [isbn, book]: library) {
        cout << '\t' << ++idx << ' ' << book->GetTitle() << '\n';
    }
}


