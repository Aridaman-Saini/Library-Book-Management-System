#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H

#include <unordered_map>
#include <memory>
#include <string>
#include "Book.h"
#include "FileHandler.h"
#include "SearchEngine.h"
#include "DisplayManager.h"
#include "BookManager.h"
using namespace std;

class CLibrary {
private:
    unordered_map<int, shared_ptr<CBook>> m_bookMap;
    CFileHandler m_objFileHandler;
    CSearchEngine m_objSearchEngine;
    CDisplayManager m_objDisplayManager;
    CBookManager m_objBookManager;

public:
    CLibrary();
    ~CLibrary();
    void addBook(int id, const string& title, const string& author, int quantity);
    void searchById(int id);
    void searchByTitle(const string& title);
    void searchByAuthor(const string& author);
    void displayAllBooks();
    void updateQuantity(int id, int newQuantity);
    void deleteBook(int id);
    void showMenu();

};

#endif
