#include <iostream>
#include "HashTable2.hpp"
//#include "HashTable.hpp"

//void printStudent(int, HashTable&);
void printStudent(int, HashTable2&); // overloaded for exc 2

int main() {
    
    HashTable2 table;
    int id;
    
    std::cout << "Initial Table: \n";
    table.print();
    std::cout << '\n';

    std::cout << "Table After Insert: \n";
    Student temp(72312, "Human", "Hue");
    table.InsertItem(temp);
    table.print();
    std::cout << '\n';
    
    std::cout << "Table After Delete: \n";
    table.DeleteItem(temp);
    table.print();
    std::cout << '\n';

    
    std::cout << "Enter a students ID: ";
    std::cin >> id;
    
    printStudent(id, table);
    
    return 0;
}

// non member function taking id and printing details
void printStudent(int id, HashTable2& table){
    Student tempStudent;
    tempStudent.setId(id);
    bool found;
    
    table.RetrieveItem(tempStudent, found);
    
    if(found){
        std::cout << "Found!!! \n-----------------------------\n";
        std::cout << tempStudent.getId() << std::setw(10) << tempStudent.getFirstName() << std::setw(10) << tempStudent.getLastName() << '\n';
        std::cout << "-----------------------------\n";
    }
    else
        std::cout << "Student Not Found...\n";
}

