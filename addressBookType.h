#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

#include "extPersonType.h"
#include "include/orderedLinkedList.h"  

class addressBookType : public orderedLinkedList<extPersonType> {
public:
    addressBookType();
    void initEntry(const std::string& filename);
    void findPerson(const std::string& firstName, const std::string& lastName) const;
    void findBirthdays(int month) const;
    void findRelations(const std::string& relationship) const;
    void print() const;
};

#endif // ADDRESSBOOKTYPE_H
