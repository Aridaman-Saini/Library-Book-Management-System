#pragma once
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
using namespace std;

class CInputHandler {
public:
    void clearInput();
    void pauseScreen();
    bool getInteger(int& value);
    string getString();
    bool getConfirmation(const string& message);
};

#endif

