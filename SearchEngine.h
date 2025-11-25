
#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <vector>
#include <unordered_map>
#include <memory>
#include <string>
#include "Book.h"

using namespace std;

class CSearchEngine {
private:
    string toLower(const string& str) const;

public:
    shared_ptr<CBook> searchById(const unordered_map<int, shared_ptr<CBook>>& books, int id) const;
    vector<shared_ptr<CBook>> searchByTitle(const unordered_map<int, shared_ptr<CBook>>& books, const string& title) const;
    vector<shared_ptr<CBook>> searchByAuthor(const unordered_map<int, shared_ptr<CBook>>& books, const string& author) const;
};

#endif