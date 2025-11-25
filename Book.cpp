#include "Book.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

CBook::CBook(int iBookId, const string& strTitle, const string& strAuthor, int iQuantity)
    : m_iBookId(iBookId), m_strTitle(strTitle), m_strAuthor(strAuthor)
{
    setQuantity(iQuantity); 
}

CBook::~CBook() {}

int CBook::getBookId() const 
{
    return m_iBookId;
}

string CBook::getTitle() const 
{
    return m_strTitle;
}

string CBook::getAuthor() const 
{
    return m_strAuthor;
}

int CBook::getQuantity() const 
{
    return m_iQuantity;
}

void CBook::setQuantity(int q) 
{
    if (q < 0) 
    {
        throw invalid_argument("Quantity cannot be negative");
    }
    m_iQuantity = q;
}

void CBook::setTitle(const string& t) 
{
    m_strTitle = t;
}

void CBook::setAuthor(const string& a)
{
    m_strAuthor = a;
}

void CBook::display() const 
{
    cout << left << setw(10) << m_iBookId
        << setw(30) << m_strTitle
        << setw(25) << m_strAuthor
        << setw(10) << m_iQuantity << endl;
}

string CBook::serialize() const 
{
    return to_string(m_iBookId) + "|" + m_strTitle + "|" + m_strAuthor + "|" + to_string(m_iQuantity);
}

