#include "SearchEngine.h"
#include <algorithm>
using namespace std;

string CSearchEngine::toLower(const string& str) const {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

shared_ptr<CBook> CSearchEngine::searchById(const unordered_map<int, shared_ptr<CBook>>& books, int id) const {
    auto it = books.find(id);
    if (it != books.end()) {
        return it->second;
    }
    return nullptr;
}

vector<shared_ptr<CBook>> CSearchEngine::searchByTitle(const unordered_map<int, shared_ptr<CBook>>& books, const string& searchTitle) const {
    string lowerSearch = toLower(searchTitle);
    vector<shared_ptr<CBook>> results;

    for (const auto& pair : books) {
        string bookTitle = toLower(pair.second->getTitle());
        if (bookTitle.find(lowerSearch) != string::npos) {
            results.push_back(pair.second);
        }
    }
    return results;
}

vector<shared_ptr<CBook>> CSearchEngine::searchByAuthor(const unordered_map<int, shared_ptr<CBook>>& books, const string& authorName) const {
    string lowerSearch = toLower(authorName);
    vector<shared_ptr<CBook>> results;

    for (const auto& pair : books) {
        string bookAuthor = toLower(pair.second->getAuthor());
        if (bookAuthor.find(lowerSearch) != string::npos) {
            results.push_back(pair.second);
        }
    }
    return results;
}