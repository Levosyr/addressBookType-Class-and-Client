#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

#include "orderedLinkedList.h"
#include "extPersonType.h"
#include <fstream>
#include <iostream>

class addressBookType : public orderedLinkedList<extPersonType>
{
public:
    void loadData(const std::string& filename) {
        std::ifstream inputFile(filename);
        if (!inputFile) {
            std::cerr << "Unable to open file: " << filename << std::endl;
            return;
        }

        extPersonType person;
        while (person.read(inputFile)) {
            insert(person);
        }
        inputFile.close();
    }

    void displayAllEntries() const {
        nodeType<extPersonType>* current = this->first;
        while (current != nullptr) {
            current->info.print();
            current = current->link;
        }
    }

    void displayEntryByName(const std::string& name) const {
        nodeType<extPersonType>* current = this->first;
        while (current != nullptr) {
            if (current->info.getName() == name) {
                current->info.print();
                return;
            }
            current = current->link;
        }
        std::cout << "No entry found for name: " << name << std::endl;
    }

    void displayEntriesByMonth(int month) const {
        nodeType<extPersonType>* current = this->first;
        bool found = false;
        while (current != nullptr) {
            if (current->info.getBirthDate().getMonth() == month) {
                current->info.print();
                found = true;
            }
            current = current->link;
        }
        if (!found) {
            std::cout << "No entries found for month: " << month << std::endl;
        }
    }

    void displayEntriesByRelationship(const std::string& relationship) const {
        nodeType<extPersonType>* current = this->first;
        bool found = false;
        while (current != nullptr) {
            if (current->info.getRelationship() == relationship) {
                current->info.print();
                found = true;
            }
            current = current->link;
        }
        if (!found) {
            std::cout << "No entries found for relationship: " << relationship << std::endl;
        }
    }

    void addEntry() {
        extPersonType newEntry;
        std::string firstName, lastName, street, city, state, zip, phone, relationship;
        int birthMonth, birthDay, birthYear;

        std::cout << "Enter first name: ";
        std::getline(std::cin, firstName);
        std::cout << "Enter last name: ";
        std::getline(std::cin, lastName);
        newEntry.setName(firstName, lastName);

        std::cout << "Enter birth date (month day year): ";
        std::cin >> birthMonth >> birthDay >> birthYear;
        std::cin.ignore();
        newEntry.setBirthDate(birthMonth, birthDay, birthYear);

        std::cout << "Enter street address: ";
        std::getline(std::cin, street);
        std::cout << "Enter city: ";
        std::getline(std::cin, city);
        std::cout << "Enter state: ";
        std::getline(std::cin, state);
        std::cout << "Enter zip code: ";
        std::getline(std::cin, zip);
        newEntry.setAddress(street, city, state, zip);

        std::cout << "Enter phone number: ";
        std::getline(std::cin, phone);
        newEntry.setPhone(phone);

        std::cout << "Enter relationship (Friend, Family, Business): ";
        std::getline(std::cin, relationship);
        newEntry.setRelationship(relationship);

        insert(newEntry);
    }

    void deleteEntryByName(const std::string& firstName, const std::string& lastName) {
        std::string nameKey = lastName + " " + firstName;
        nodeType<extPersonType>* current = this->first;
        while (current != nullptr) {
            if (current->info.getName() == nameKey) {
                deleteNode(current->info);
                return;
            }
            current = current->link;
        }
        std::cout << "No entry found for name: " << nameKey << std::endl;
    }

    void saveData(const std::string& filename) const {
        std::ofstream outputFile(filename);
        if (!outputFile) {
            std::cerr << "Unable to open file: " << filename << std::endl;
            return;
        }

        nodeType<extPersonType>* current = this->first;
        while (current != nullptr) {
            outputFile << current->info.getName() << "\n"
                << current->info.getBirthDate().getMonth() << " "
                << current->info.getBirthDate().getDay() << " "
                << current->info.getBirthDate().getYear() << "\n"
                << current->info.getAddress().getStreet() << "\n"
                << current->info.getAddress().getCity() << "\n"
                << current->info.getAddress().getState() << "\n"
                << current->info.getAddress().getZipCode() << "\n"
                << current->info.getPhone() << "\n"
                << current->info.getRelationship() << "\n";
            current = current->link;
        }
        outputFile.close();
    }
};

#endif