#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <vector>
#include <memory>
#include <string>
#include "Book.h"

using namespace std;

class CDisplayManager {
public:
    void displayHeader() const;
    void displayBook(const shared_ptr<CBook>& book) const;
    void displayBooks(const vector<shared_ptr<CBook>>& books) const;
    void displayMenu() const;
    void displaySuccess(const string& message) const;
    void displayError(const string& message) const;
};

#endif