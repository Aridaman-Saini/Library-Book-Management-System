#pragma once

#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class CBook {
private:
    int m_iBookId;
    string m_strTitle;
    string m_strAuthor;
    int m_iQuantity;

public:
    // Constructor
    CBook(int id, const string& t, const string& a, int q);

    ~CBook();

    int getBookId() const;
    string getTitle() const;
    string getAuthor() const;
    int getQuantity() const;

    void setQuantity(int q);
    void setTitle(const string& t);
    void setAuthor(const string& a);

    void display() const;
    string serialize() const;
};

#endif
