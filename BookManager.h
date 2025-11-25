#pragma once
#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <unordered_map>
#include <vector>
#include <memory>
#include <string>
#include "Book.h"
#include "BookValidator.h"
#include "FileHandler.h"

using namespace std;

class CBookManager {
private:
    unordered_map<int, shared_ptr<CBook>>& m_bookMap;
    CBookValidator m_objValidator;
    CFileHandler& m_objFileHandler;

public:
    CBookManager(unordered_map<int, shared_ptr<CBook>>& b, CFileHandler& fh);
    bool addBook(int id, const string& title, const string& author, int quantity, string& errorMsg);
    bool updateQuantity(int id, int newQuantity, string& errorMsg);
    bool deleteBook(int id, string& errorMsg);
    vector<shared_ptr<CBook>> getAllBooks() const;
};

#endif
