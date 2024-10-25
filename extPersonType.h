#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H

#include "personType.h"

class extPersonType : public personType {
public:
    extPersonType();  // Default constructor
    extPersonType(const std::string& first, const std::string& last, const dateType& bDate, const std::string& phone, const addressType& address, const std::string& relationship);

    void print() const override;
    std::string getRelationship() const { return relationship; }

    // Overloaded operators for ordered comparison
    bool operator==(const extPersonType& other) const;
    bool operator!=(const extPersonType& other) const;
    bool operator>=(const extPersonType& other) const;

private:
    std::string relationship;
};

#endif // EXTPERSONTYPE_H
