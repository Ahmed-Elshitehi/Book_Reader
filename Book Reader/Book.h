#ifndef ONLINE_BOOK_READER_BOOK_H
#define ONLINE_BOOK_READER_BOOK_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Book {
private:
    string isbn;
    string title;
    string author;
    vector<string> pages;
public:
    const string &GetAuthor() const;
    void SetAuthor(const string &author);
    const string &GetIsbn() const;
    void SetIsbn(const string &isbn);
    const vector<string> &GetPages() const;
    void SetPages(const vector<string> &pages);
    const string &GetTitle() const;
    void SetTitle(const string &title);
    void ReadInfo();
};

#endif
