#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include "Student.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "UnsortedType.hpp"

enum STATUS {EMPTY, FULL};

struct StudentH{
    Student student;
    STATUS status = EMPTY;
};

class  HashTable    // declares a class data type
{
public :
    HashTable ( );
    void    RetrieveItem(Student&  item, bool&  found);
    ERROR_CODE InsertItem (Student  item);
    ERROR_CODE DeleteItem (Student  item);
    void print();//print all students
    
    // additional
    bool isFull();
    bool isEmpty();
    void populateTable();
    
private:                //  3 private data members
    StudentH    info[MAX_ITEMS];
    int length;
};

#endif /* HashTable_hpp */
