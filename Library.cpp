#include "Library.h"
#include <iostream>
using namespace std;

CLibrary::CLibrary() : m_objFileHandler("library_data.txt"), m_objBookManager(m_bookMap, m_objFileHandler) {
    m_objFileHandler.loadBooks(m_bookMap);
}

CLibrary::~CLibrary() {
    m_objFileHandler.saveBooks(m_bookMap);
}

void CLibrary::addBook(int id, const string& title, const string& author, int quantity) {
    string errorMsg = "";
    if (m_objBookManager.addBook(id, title, author, quantity, errorMsg)) 
    {
        m_objDisplayManager.displaySuccess("Book added successfully!");
    }
    else
    {
        m_objDisplayManager.displayError("Error adding book: " + errorMsg);
    }
}

void CLibrary::searchById(int id) 
{
    auto book = m_objSearchEngine.searchById(m_bookMap, id);
    if (book) {
        cout << "\n--- Book Found ---\n";
        m_objDisplayManager.displayHeader();
        m_objDisplayManager.displayBook(book);
    }
    else
    {
        m_objDisplayManager.displayError("Book with ID " + to_string(id) + " not found.");
    }
}

void CLibrary::searchByTitle(const string& title) 
{
    auto results = m_objSearchEngine.searchByTitle(m_bookMap, title);
    if (results.empty()) {
        m_objDisplayManager.displayError("No books found with title containing: " + title);
    }
    else {
        cout << "\n--- Search Results (" << results.size() << " found) ---\n";
        m_objDisplayManager.displayBooks(results);
    }
}

void CLibrary::searchByAuthor(const string& author) {
    auto results = m_objSearchEngine.searchByAuthor(m_bookMap, author);
    if (results.empty()) {
        m_objDisplayManager.displayError("No books found by author: " + author);
    }
    else {
        cout << "\n--- Search Results (" << results.size() << " found) ---\n";
        m_objDisplayManager.displayBooks(results);
    }
}

void CLibrary::displayAllBooks() {
    auto allBooks = m_objBookManager.getAllBooks();
    if (allBooks.empty()) {
        m_objDisplayManager.displayError("Library is empty. No books to display.");
    }
    else {
        cout << "\n--- All Books in Library (" << allBooks.size() << " total) ---\n";
        m_objDisplayManager.displayBooks(allBooks);
    }
}

void CLibrary::updateQuantity(int id, int newQuantity) {
    string errorMsg;
    if (m_objBookManager.updateQuantity(id, newQuantity, errorMsg)) {
        m_objDisplayManager.displaySuccess("Quantity updated successfully!");
    }
    else {
        m_objDisplayManager.displayError("Error updating quantity: " + errorMsg);
    }
}

void CLibrary::deleteBook(int id) {
    string errorMsg;
    if (m_objBookManager.deleteBook(id, errorMsg)) {
        m_objDisplayManager.displaySuccess("Book deleted successfully!");
    }
    else {
        m_objDisplayManager.displayError(errorMsg);
    }
}

void CLibrary::showMenu() {
    m_objDisplayManager.displayMenu();
}

