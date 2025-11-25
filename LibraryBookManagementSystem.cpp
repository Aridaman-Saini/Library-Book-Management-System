// LibraryBookManagementSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Library.h"
#include "InputHandler.h"

using namespace std;

int main() {
    CLibrary objLibrary;
    CInputHandler objInputHandler;
    int iInput;

    cout << "\n*** Welcome to Library Book Management System ***\n";

    while (true) {
        objLibrary.showMenu();

        if (!objInputHandler.getInteger(iInput))
        {
            cout << "\n Invalid input! Please enter a number.\n";
            objInputHandler.pauseScreen();
            continue;
        }

       
        switch (iInput) {
        case 1: 
        {
            int id;
            int quantity;
            string title;
            string author;

            cout << "\n--- Add New Book ---\n";
            cout << "Enter Book ID: ";
            if (!objInputHandler.getInteger(id)) {
                cout << "Invalid ID!\n";
                break;
            }

            cout << "Enter Title: ";
            title = objInputHandler.getString();

            cout << "Enter Author: ";
            author = objInputHandler.getString();

            cout << "Enter Quantity: ";
            if (!objInputHandler.getInteger(quantity)) {
                cout << "Invalid quantity!\n";
                break;
            }

            objLibrary.addBook(id, title, author, quantity);
            break;
        }
        case 2: {
            int id;
            cout << "\n--- Search by ID ---\n";
            cout << "Enter Book ID: ";
            if (objInputHandler.getInteger(id)) {
                objLibrary.searchById(id);
            }
            else {
                cout << "Invalid ID!\n";
            }
            break;
        }
        case 3: {
            string title;
            cout << "\n--- Search by Title ---\n";
            cout << "Enter Title (or partial): ";
            title = objInputHandler.getString();
            objLibrary.searchByTitle(title);
            break;
        }
        case 4: {
            string author;
            cout << "\n--- Search by Author ---\n";
            cout << "Enter Author Name (or partial): ";
            author = objInputHandler.getString();
            objLibrary.searchByAuthor(author);
            break;
        }
        case 5: {
            objLibrary.displayAllBooks();
            break;
        }
        case 6: {
            int id, quantity;
            cout << "\n--- Update Quantity ---\n";
            cout << "Enter Book ID: ";
            if (!objInputHandler.getInteger(id)) {
                cout << "Invalid ID!\n";
                break;
            }
            cout << "Enter New Quantity: ";
            if (!objInputHandler.getInteger(quantity)) {
                cout << "Invalid quantity!\n";
                break;
            }
            objLibrary.updateQuantity(id, quantity);
            break;
        }
        case 7: {
            int id;
            cout << "\n--- Delete Book ---\n";
            cout << "Enter Book ID: ";
            if (!objInputHandler.getInteger(id)) {
                cout << "Invalid ID!\n";
                break;
            }

            if (objInputHandler.getConfirmation("Are you sure?")) {
                objLibrary.deleteBook(id);
            }
            else {
                cout << "\n Deletion cancelled.\n";
            }
            break;
        }
        case 8: {
            cout << "\n*** Thank you for using Library Management System! ***\n";
            return 0;
        }
        default: {
            cout << "\n Invalid choice! Please enter 1-8.\n";
        }
        }
       

        objInputHandler.pauseScreen();
    }

    return 0;
}