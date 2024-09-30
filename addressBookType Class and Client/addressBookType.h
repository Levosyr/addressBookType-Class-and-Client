#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "extPersonType.h"

class addressBookType {
public:
    void loadData(const std::string& filename);
    void displayAllEntries() const;
    void displayEntryByName(const std::string& name) const;
    void displayEntriesByMonth(int month) const;
    void displayEntriesByRelationship(const std::string& relationship) const;

private:
    std::vector<extPersonType> entries;
};

#endif // ADDRESSBOOKTYPE_H
