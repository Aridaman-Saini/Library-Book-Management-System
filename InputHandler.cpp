#include "InputHandler.h"
#include <iostream>
#include <limits>
using namespace std;

void CInputHandler::clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void CInputHandler::pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

bool CInputHandler::getInteger(int& value) {
    if (cin >> value) {
        clearInput();
        return true;
    }
    clearInput();
    return false;
}

string CInputHandler::getString() {
    string input;
    getline(cin, input);
    return input;
}

bool CInputHandler::getConfirmation(const string& message) {
    char response;
    cout << message << " (y/n): ";
    cin >> response;
    clearInput();
    return (response == 'y' || response == 'Y');
}