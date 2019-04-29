//
//  HashTable2.hpp
//  CMP305-LAB10
//
//  Created by Mohamed Nagaty on 4/29/19.
//  Copyright © 2019 Mohamed Nagaty. All rights reserved.
//

#ifndef HashTable2_hpp
#define HashTable2_hpp

#include <stdio.h>
#include "Student.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "UnsortedType.hpp"

class  HashTable2    // declares a class data type
{
public :
    HashTable2();
    ~HashTable2();
    HashTable2(const HashTable2&);
    HashTable2 operator = (const HashTable2&);
    
    void RetrieveItem(Student&  item, bool&  found);
    ERROR_CODE InsertItem (Student  item);
    ERROR_CODE DeleteItem (Student  item);
    void print();//print all students
    
    // additional
    bool isFull();
    bool isEmpty();
    void makeEmpty();
    void populateTable();
    
private:                //  3 private data members
    UnsortedType *info[MAX_ITEMS];
    int length;
};


#endif /* HashTable2_hpp */
