#pragma once
#ifndef BOOKVALIDATOR_H
#define BOOKVALIDATOR_H

#include <unordered_map>
#include <memory>
#include <string>
#include "Book.h"

using namespace std;

class CBookValidator {
public:
    bool isValidId(int id) const;
    bool isValidQuantity(int quantity) const;
    bool isValidString(const string& str) const;
    bool bookExists(const unordered_map<int, shared_ptr<CBook>>& books, int id) const;
};

#endif
