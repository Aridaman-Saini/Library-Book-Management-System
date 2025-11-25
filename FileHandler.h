#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <unordered_map>
#include <memory>
#include "Book.h"

using namespace std;

class CFileHandler {
private:
    string m_strFilename;

public:
    CFileHandler(const string& fname);
    void saveBooks(const unordered_map<int, shared_ptr<CBook>>& books) const;
    void loadBooks(unordered_map<int, shared_ptr<CBook>>& books) const;
};

#endif
