#include <iostream>
#include "addressBookType.h"

int main()
{
    addressBookType addressBook;
    addressBook.loadData("data.txt");

    int option;
    std::string name, firstName, lastName;
    int month;
    std::string relationship;

    do
    {
        std::cout << "On-line Address Book\nSelect an option:\n"
            << "1 - Display all entries in the address book.\n"
            << "2 - Display an entry by a person’s name.\n"
            << "3 - Display all entries with a given birth month.\n"
            << "4 - Display all entries with a given relationship tag (Business, Friend, Family).\n"
            << "5 - Add a new entry to the address book.\n"
            << "6 - Delete an entry by name.\n"
            << "7 - Quit\n";
        std::cin >> option;
        std::cin.ignore();

        switch (option)
        {
        case 1:
            addressBook.displayAllEntries();
            break;
        case 2:
            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            name = lastName + " " + firstName;
            addressBook.displayEntryByName(name);
            break;
        case 3:
            std::cout << "Enter birth month (1-12): ";
            std::cin >> month;
            addressBook.displayEntriesByMonth(month);
            break;
        case 4:
            std::cout << "Enter relationship: ";
            std::getline(std::cin, relationship);
            addressBook.displayEntriesByRelationship(relationship);
            break;
        case 5:
            addressBook.addEntry();
            break;
        case 6:
            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            addressBook.deleteEntryByName(firstName, lastName);
            break;
        case 7:
            std::cout << "Quitting...\n";
            addressBook.saveData("data.txt");
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    } while (option != 7);

    return 0;
}