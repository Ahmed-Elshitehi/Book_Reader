//
// Created by Ahmed Salah on 9/13/2023.
//
#include "book.h"
using namespace std;
const int number_of_lines = 10;// every page has 10 line

book::book() : title(""), number_of_pages(0), author("") {
}

book::book(const book &book1) {
    title = book1.title;
    author = book1.author;
    number_of_pages = book1.number_of_pages;
    pages = book1.pages;
}

book::book(string &name, int num, string &author) : title(name), number_of_pages(num), author(author) {
//    pages == new vector<vector<string>>(number_of_pages, vector<string>(number_of_lines, "page content\n"));
    pages.resize(number_of_pages, vector<string>(number_of_lines, "page content\n"));
    for (int i = 0; i < number_of_pages; ++i) {
        pages[i][number_of_lines - 1] = "################ " + to_string(i + 1) + "\n";
    }
}
void book::print_page(int page) {
    for (int j = 0; j < 10; ++j) {
        cout << pages[page][j];
    }
}
void book::reading(int &page) {
    int current_page = page - 1;
    bool exit = false;
    while (current_page < number_of_pages && current_page >= 0 && !exit) {
        print_page(current_page);
        int ch;
        cout << "\tinter number in range 1 - 3\n";
        cout << "\t1 - Next Page\n";
        cout << "\t2 - Previous Page\n";
        cout << "\t3 - Exit\n";
        cin >> ch;
        if (ch == 3) {
            exit = true;
        } else {
            current_page += (ch == 1);
            current_page -= (ch == 2);
        }
    }
    if (current_page == number_of_pages) {
        cout << "\t*************************\n";
        cout << "\t*                       *\n";
        cout << "\t* You finished the Book *\n";
        cout << "\t*                       *\n";
        cout << "\t*************************\n";
    }
    page = current_page + 1;
}
int book::get_number_of_pages() const {
    return number_of_pages;
}

const string &book::get_title()const{
    return title;
}

const string &book::get_author()const{
    return author;
}

book::~book() {
    delete &pages;
    delete &title;
    delete &author;
}
