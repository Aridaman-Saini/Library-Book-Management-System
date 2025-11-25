#include "DisplayManager.h"
#include <iostream>
#include <iomanip>
using namespace std;

void CDisplayManager::displayHeader() const {
    cout << string(80, '-') << endl;
    cout << left << setw(10) << "Book ID"
        << setw(30) << "Title"
        << setw(25) << "Author"
        << setw(10) << "Quantity" << endl;
    cout << string(80, '-') << endl;
}

void CDisplayManager::displayBook(const shared_ptr<CBook>& book) const {
    book->display();
}

void CDisplayManager::displayBooks(const vector<shared_ptr<CBook>>& books) const {
    if (books.empty()) {
        cout << "\n No books to display.\n";
        return;
    }

    displayHeader();
    for (const auto& book : books) {
        book->display();
    }
}

void CDisplayManager::displayMenu() const {
    cout << "\n";
    cout << " ________________________________________ \n";
    cout << "|   LIBRARY BOOK MANAGEMENT SYSTEM       |\n";
    cout << "|________________________________________|\n";
    cout << "  1. Add New Book\n";
    cout << "  2. Search Book by ID\n";
    cout << "  3. Search Book by Title\n";
    cout << "  4. Search Book by Author\n";
    cout << "  5. Display All Books\n";
    cout << "  6. Update Book Quantity\n";
    cout << "  7. Delete Book\n";
    cout << "  8. Exit\n";
    cout << "────────────────────────────────────────\n";
    cout << "  Enter your choice: ";
}

void CDisplayManager::displaySuccess(const string& message) const {
    cout << "\n" << message << endl;
}

void CDisplayManager::displayError(const string& message) const {
    cout << "\n" << message << endl;
}