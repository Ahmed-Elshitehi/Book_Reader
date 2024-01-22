#include "book.h"

const string &Book::GetAuthor() const {
    return author;
}

void Book::SetAuthor(const string &author) {
    this->author = author;
}

const string &Book::GetIsbn() const {
    return isbn;
}

void Book::SetIsbn(const string &isbn) {
    this->isbn = isbn;
}

const vector<string> &Book::GetPages() const {
    return pages;
}

void Book::SetPages(const vector<string> &pages) {
    this->pages = pages;
}

const string &Book::GetTitle() const {
    return title;
}

void Book::SetTitle(const string &title) {
    this->title = title;
}

void Book::ReadInfo() {
    string string;

    cout << "Enter ISBN: ";
    cin >> string;
    SetIsbn(string);

    cout << "Enter Title: ";
    cin >> string;
    SetTitle(string);

    cout << "Enter Author Name: ";
    cin >> string;
    SetAuthor(string);

    cout << "Enter How many pages: ";
    int numOfPages;
    cin >> numOfPages;

    for (int page = 0; page < numOfPages; ++page) {
        string = "page # ";
        string += char('0' + page);
        pages.push_back(string);
    }
}

