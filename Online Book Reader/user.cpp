#include "user.h"


void User::ReadInfo(string &user_name) {

    SetUser_name(user_name);
    string str;

    cout << "Enter password (no spaces): ";
    cin >> str;
    SetPassword(str);

    cout << "Enter first name (no spaces): ";
    cin >> str;
    SetFirst_name(str);

    cout << "Enter last name (no spaces): ";
    cin >> str;
    SetLast_name(str);

    cout << "Do you want to be admin? (Y/N): ";
    char c;
    cin >> c;
    if (toupper(c) == 'Y') {
        cout << "Enter admins code (no spaces): ";
        cin >> str;
        if (str == "m3rof")
            Set_admin(true);
        else
            Set_admin(false);
    }
}

void User::SetUser_name(string user_name) {
    this->user_name = user_name;
}

void User::SetFirst_name(string first_name) {
    this->first_name = first_name;
}

void User::SetLast_name(string last_name) {
    this->last_name = last_name;
}

void User::SetPassword(string password) {
    this->password = password;
}

void User::Set_admin(bool admin) {
    this->admin = true;
}

void User::PrintInfo() {
    cout << "Name: " << first_name << " " << last_name;
    if (admin)
        cout << " | Admin";
    cout << '\n';
    cout << "User name: " << user_name << '\n';
}

const string &User::GetUserName() const {
    return user_name;
}

const string &User::GetPassword() const {
    return password;
}

bool User::Is_admin() const {
    return admin;
}

void User::ListReadingHistory() {
    int idx = 0;
    for (auto& session : reading_sessions) {
        cout << ++idx << ": ";
        session->PrintInfo();
    }

    if (idx == 0)
        cout << "\nNo history. List books and start having fun\n";
    else {
        cout << "\nWhich session to open?: ";
        cout << "\nEnter number in range " << "1 - " << idx << ": ";
        int choice;
        cin >> choice;
        DisplaySession(reading_sessions[choice - 1]);
    }
}

void User::DisplaySession(ReadingSession *session) {
    while (true) {
        cout << "Current Page: " << session->GetCurrentPage() + 1 << "\n";
        cout << session->GetCurrentPageContent() << "\n";
        cout << "\t1: Next Page\n";
        cout << "\t2: Previous Page\n";
        cout << "\t3: Stop Reading\n";
        cout << "\nEnter number in range " << "1 - 3: ";
        int choice;
        cin >> choice;
        if (choice == 1)
            session->NextPage();
        else if (choice == 2)
            session->PreviousPage();
        else
            break;
    }
}

void User::AdminView(BooksManager *bookManager) {
    cout << "\n\nHello " << Get_name() << " | Admin View\n";
    while (true) {
        int choice;
        cout << "\t1: View Profile\n";
        cout << "\t2: Add Book\n";
        cout << "\t3: Logout\n";
        cout << "\nEnter number in range " << "1 - 3: ";
        cin >> choice;
        if (choice == 1) {
            PrintInfo();
        } else if (choice == 2) {
            Book *book = new Book();
            book->ReadInfo();
            bookManager->AddBook(book);
        } else {
            break;
        }
    }
}

void User::UserView(BooksManager *booksManager) {
    cout << "\n\nHello " << Get_name() << " | User View\n";
    while (true) {
        int choice;
        cout << "\t1: View Profile\n";
        cout << "\t2: List & Select from My Reading History\n";
        cout << "\t3: List & Select from Available Books\n";
        cout << "\t4: Logout\n";
        cin >> choice;
        if (choice == 1) {
            PrintInfo();
        } else if (choice == 2) {
            ListReadingHistory();
        } else if (choice == 3) {
            cout << "\nOur current book collection:\n";
            int idx = 0;
            for (const auto &pair : booksManager->GetLibrary()) {
                cout << "\t" << ++idx << " " << pair.second->GetTitle() << "\n";
            }

            cout << "\nWhich book to read?: ";
            cout << "\nEnter number in range " << "1 - " << idx << ": ";
            int ch;
            cin >> ch;
            idx = 0;
            for (const auto &pair : booksManager->GetLibrary()) {
                if (++idx == choice) {
                    ReadingSession *session = new ReadingSession(pair.second);
                    reading_sessions.push_back(session);
                    DisplaySession(session);
                    break;
                }
            }
        } else {
            break;
        }
    }
}

string User::Get_name() {
    string name;
    name += first_name;
    name += " ";
    name += last_name;
    return name;
}


