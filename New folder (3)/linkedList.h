#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>

using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type>* link;
};

template <class Type>
class linkedListIterator
{
public:
    linkedListIterator();
    linkedListIterator(nodeType<Type>* ptr);
    Type operator*();
    linkedListIterator<Type> operator++();
    bool operator==(const linkedListIterator<Type>& right) const;
    bool operator!=(const linkedListIterator<Type>& right) const;
private:
    nodeType<Type>* current;
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = nullptr;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type>* ptr)
{
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}

template <class Type>
class linkedListType
{
public:
    linkedListType();
    void initializeList();
    bool isEmptyList() const;
    void print() const;
    void destroyList();
    linkedListIterator<Type> begin();
    linkedListIterator<Type> end();
    int length() const;
protected:
    int count;
    nodeType<Type>* first;
    nodeType<Type>* last;
};

template <class Type>
linkedListType<Type>::linkedListType()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

#endif
