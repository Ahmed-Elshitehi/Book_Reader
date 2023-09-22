//
// Created by Ahmed Salah on 9/13/2023.
//
#ifndef ONLINE_BOOK_READER_BOOK_H
#define ONLINE_BOOK_READER_BOOK_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class book {
private:
    int number_of_pages;
    string title;
    string author;
    vector<vector<string>> pages;
public:
    book();
    book(const book &book1);
    book(string &, int, string &);
    ~book();
    void print_page(int);
    void reading(int&);
    int get_number_of_pages() const;
    const string &get_title()const;
    const string &get_author()const;
};

#endif
