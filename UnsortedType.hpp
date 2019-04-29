#ifndef UnsortedType_hpp
#define UnsortedType_hpp

#include <stdio.h>
#include <iostream>
#include "Student.hpp"
typedef Student ItemType;

enum ERROR_CODE {SUCCESS, OVER_FLOW, UNDER_FLOW};

struct NodeType{
    ItemType info;
    NodeType* next = NULL;
};

class  UnsortedType{
    
public:
    // constructor
    UnsortedType();
    // assignment operator =
    UnsortedType operator = (const UnsortedType&);
    // destructor
    ~UnsortedType();
    // Copy Constructor
    UnsortedType(const UnsortedType&);   // WAS NEEDED FOR TESTING. NOT WRITTEN BY US. TAKEN FROM STACK E.
    void   MakeEmpty();
    bool   IsFull()  const;
    int    Length()  const;
    void   RetrieveItem(ItemType& item, bool& found);
    ERROR_CODE InsertItem(ItemType  item);
    ERROR_CODE   DeleteItem(ItemType  item);
    void   ResetList();
    ERROR_CODE GetNextItem(ItemType&  item, bool&);
    bool isEmpty(); // checks if list is already empty
    
private :
    NodeType*  listData;
    int length;
    NodeType*  currentPos;
    // deletes all elements in the list
    void deleteList();
    // Checks if an item exists in list, int stores the index
    bool itemExists(const ItemType&, int&);
    
} ;

#endif /* UnsortedType_hpp */
