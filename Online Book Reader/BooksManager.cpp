
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

void BooksManager::LoadDatabase() {
    cout << "BooksManager: LoadDatabase\n";
    Book* book1 = new Book();
    book1->SetIsbn("00001");
    book1->SetAuthor("Ahmed");
    book1->SetTitle("C++ how to program");
    vector<string> pages1 = { "A C++", "B C++", "C C++", "D C++", "E C++" };
    book1->SetPages(pages1);
    AddBook(book1);

    Book* book2 = new Book();
    book2->SetIsbn("00002");
    book2->SetAuthor("Morad");
    book2->SetTitle("Intro to algo");
    vector<string> pages2 = {"A Algo", "B Algo", "C Algo", "D Algo", "E "};
    book2->SetPages(pages2);
    AddBook(book2);
    Book* book3 = new Book();
    book3->SetIsbn("00003");
    book3->SetAuthor("Morad");
    book3->SetTitle("Data Structures in C++");
    vector<string> pages3 = { "A Data", "B Data", "C Data", "D Data", "E Data" };
    book3->SetPages(pages3);
    AddBook(book3);
}

void BooksManager::FreeLoad() {
    for (auto book: library) {
        delete book.second;
    }
    library.clear();
}

BooksManager::~BooksManager() {
    FreeLoad();
}

map<string, Book *> &BooksManager::GetLibrary() {
    return library;
}


