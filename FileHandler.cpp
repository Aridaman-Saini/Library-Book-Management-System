#include "FileHandler.h"
#include <fstream>
#include <iostream>
using namespace std;

CFileHandler::CFileHandler(const string& fname) : m_strFilename(fname) {}

void CFileHandler::saveBooks(const unordered_map<int, shared_ptr<CBook>>& books) const {
    try {
        ofstream file(m_strFilename);
        if (!file) {
            throw runtime_error("Unable to open file for writing");
        }

        for (const auto& pair : books) {
            file << pair.second->serialize() << endl;
        }
        file.close();
    }
    catch (const exception& e) {
        cout << "✗ Error saving to file: " << e.what() << endl;
    }
}

void CFileHandler::loadBooks(unordered_map<int, shared_ptr<CBook>>& books) const {
    ifstream file(m_strFilename);
    if (!file) {
        return; // File doesn't exist yet
    }

    string line;
    while (getline(file, line)) {
        try {
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);
            size_t pos3 = line.find('|', pos2 + 1);

            if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
                continue;
            }

            int id = stoi(line.substr(0, pos1));
            string title = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string author = line.substr(pos2 + 1, pos3 - pos2 - 1);
            int quantity = stoi(line.substr(pos3 + 1));

            auto book = make_shared<CBook>(id, title, author, quantity);
            books[id] = book;
        }
        catch (const exception& e) {
            continue; // Skip invalid lines
        }
    }
    file.close();
}