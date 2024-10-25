#ifndef H_orderedListType
#define H_orderedListType

#include "linkedList.h"

using namespace std;

template <class Type>
class orderedLinkedList : public linkedListType<Type>
{
public:
    void insert(const Type& newItem);
    void deleteNode(const Type& deleteItem);
};

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type>* current;
    nodeType<Type>* trailCurrent = nullptr;
    nodeType<Type>* newNode;

    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = nullptr;

    if (this->first == nullptr)
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        bool found = false;

        while (current != nullptr && !found)
        {
            if (current->info >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }

        if (current == this->first)
        {
            newNode->link = this->first;
            this->first = newNode;
        }
        else
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == nullptr)
                this->last = newNode;
        }
        this->count++;
    }
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type>* current;
    nodeType<Type>* trailCurrent = nullptr;
    bool found;

    if (this->first == nullptr)
    {
        cout << "Cannot delete from an empty list." << endl;
    }
    else
    {
        current = this->first;
        found = false;

        while (current != nullptr && !found)
        {
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }

        if (current == nullptr)
        {
            cout << "The item to be deleted is not in the list." << endl;
        }
        else if (current->info == deleteItem)
        {
            if (this->first == current)
            {
                this->first = this->first->link;
                if (this->first == nullptr)
                    this->last = nullptr;
                delete current;
            }
            else
            {
                trailCurrent->link = current->link;
                if (current == this->last)
                    this->last = trailCurrent;
                delete current;
            }
            this->count--;
        }
        else
        {
            cout << "The item to be deleted is not in the list." << endl;
        }
    }
}

#endif
