#include <iostream>
#include "addressBookType.h"

void showMenu() {
    std::cout << "On-line Address Book\nSelect an option:\n"
        << "1 - Display all entries in the address book.\n"
        << "2 - Display an entry by a person’s name.\n"
        << "3 - Display all entries with a given birth month.\n"
        << "4 - Display all entries with a given relationship tag (Business, Friend, Family).\n"
        << "5 - Quit\n";
}

int main() {
    addressBookType addressBook;
    addressBook.initEntry("AddressBookData.txt");

    int option;
    do {
        showMenu();
        std::cout << "Enter choice: ";
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
        case 1:
            addressBook.print();
            break;
        case 2: {
            std::string firstName, lastName;
            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            addressBook.findPerson(firstName, lastName);
            break;
        }
        case 3: {
            int month;
            std::cout << "Enter birth month (1-12): ";
            std::cin >> month;
            while (month < 1 || month > 12) {
                std::cout << "Invalid month. Please enter a value between 1 and 12: ";
                std::cin >> month;
            }
            addressBook.findBirthdays(month);
            break;
        }
        case 4: {
            std::string relationship;
            std::cin.ignore();
            std::getline(std::cin, relationship);
            addressBook.findRelations(relationship);
            break;
        }
              case
