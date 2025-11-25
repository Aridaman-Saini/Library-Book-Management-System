#include "BookManager.h"
#include <algorithm>
using namespace std;

CBookManager::CBookManager(unordered_map<int, shared_ptr<CBook>>& b, CFileHandler& fh)
    : m_bookMap(b), m_objFileHandler(fh) {}

bool CBookManager::addBook(int id, const string& title, const string& author, int quantity, string& errorMsg) {
    try {
        if (!m_objValidator.isValidId(id)) {
            errorMsg = "Invalid Book ID. Must be positive.";
            return false;
        }

        if (m_objValidator.bookExists(m_bookMap, id)) {
            errorMsg = "Book ID already exists";
            return false;
        }

        if (!m_objValidator.isValidString(title)) {
            errorMsg = "Title cannot be empty";
            return false;
        }

        if (!m_objValidator.isValidString(author)) {
            errorMsg = "Author name cannot be empty";
            return false;
        }

        if (!m_objValidator.isValidQuantity(quantity)) {
            errorMsg = "Quantity must be non-negative";
            return false;
        }

        auto book = make_shared<CBook>(id, title, author, quantity);
        m_bookMap[id] = book;
        m_objFileHandler.saveBooks(m_bookMap);
        return true;
    }
    catch (const exception& e) {
        errorMsg = e.what();
        return false;
    }
}

bool CBookManager::updateQuantity(int id, int newQuantity, string& errorMsg) {
    try {
        if (!m_objValidator.bookExists(m_bookMap, id)) {
            errorMsg = "Book ID not found";
            return false;
        }

        if (!m_objValidator.isValidQuantity(newQuantity)) {
            errorMsg = "Quantity must be non-negative";
            return false;
        }

        m_bookMap[id]->setQuantity(newQuantity);
        m_objFileHandler.saveBooks(m_bookMap);
        return true;
    }
    catch (const exception& e) {
        errorMsg = e.what();
        return false;
    }
}

bool CBookManager::deleteBook(int id, string& errorMsg) {
    if (!m_objValidator.bookExists(m_bookMap, id)) {
        errorMsg = "Book ID not found";
        return false;
    }

    m_bookMap.erase(id);
    m_objFileHandler.saveBooks(m_bookMap);
    return true;
}

vector<shared_ptr<CBook>> CBookManager::getAllBooks() const {
    vector<shared_ptr<CBook>> allBooks;
    vector<int> ids;

    for (const auto& pair : m_bookMap) {
        ids.push_back(pair.first);
    }
    sort(ids.begin(), ids.end());

    for (int id : ids) {
        allBooks.push_back(m_bookMap.at(id));
    }
    return allBooks;
}