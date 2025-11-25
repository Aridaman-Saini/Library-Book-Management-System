#include "BookValidator.h"

bool CBookValidator::isValidId(int id) const {
    return id > 0;
}

bool CBookValidator::isValidQuantity(int quantity) const {
    return quantity >= 0;
}

bool CBookValidator::isValidString(const string& str) const {
    return !str.empty() && str.length() > 0;
}

bool CBookValidator::bookExists(const unordered_map<int, shared_ptr<CBook>>& books, int id) const {
    return books.find(id) != books.end();
}