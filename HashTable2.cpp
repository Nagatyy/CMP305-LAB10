#include "HashTable2.hpp"

HashTable2::HashTable2(){
    length = 0;
    for(int i = 0; i < MAX_ITEMS; i++)
        info[i] = new UnsortedType;
    populateTable();
}

HashTable2::~HashTable2(){
    makeEmpty();
}
HashTable2::HashTable2(const HashTable2& other){
    length = other.length;
    
    for(int i = 0; i < MAX_ITEMS; i++)
        info[i] = other.info[i];     // assuming the = operator for UnsortedType works

}
HashTable2 HashTable2::operator = (const HashTable2& other){
    
    if(this == &other) // check for self assignment
        return *this;
    makeEmpty();
    length = other.length;
    for(int i = 0; i < MAX_ITEMS; i++){
        info[i] = new UnsortedType;
        info[i] = other.info[i];
    }
        return *this;
}

void HashTable2::RetrieveItem(Student&  item, bool&  found){
    found = false;
    int loc = item.Hash();
    
    info[loc]->RetrieveItem(item, found);
    
    if(found){
        // then item is already = targetItem, so no need to set it
        // and found has updated
    }
}
ERROR_CODE HashTable2::InsertItem (Student  item){
    int loc = item.Hash();
    
    if(info[loc] -> InsertItem(item) == SUCCESS)
        return SUCCESS;
    else
        return OVER_FLOW; // overflow returned when insertion failed
}
ERROR_CODE HashTable2::DeleteItem (Student  item){
    int loc = item.Hash();
    
    if(info[loc] -> DeleteItem(item) == SUCCESS){
        length--;
        return SUCCESS;
    }
    else
        return UNDER_FLOW; // underflow returned when deletion failed
    
}
void HashTable2::print(){
    
    Student tempStudent;
    bool finished = false;
    
    for(int i = 0; i < MAX_ITEMS; i++){
        info[i] -> ResetList();
        info[i]->GetNextItem(tempStudent, finished);
        while(!finished){
            std::cout << tempStudent.getId() << std::setw(15) << tempStudent.getFirstName() << std::setw(15) << tempStudent.getLastName() << std::setw(15);
            std::cout << '\n';
            info[i]->GetNextItem(tempStudent, finished);
        }
    }
    
}

// additional
bool HashTable2::isFull(){
    return length == MAX_ITEMS;
}
bool HashTable2::isEmpty(){
    return length == 0;
}
void HashTable2::makeEmpty(){
    length = 0;
    for(int i = 0; i < MAX_ITEMS; i++)
        info[i] -> MakeEmpty();
}

void HashTable2::populateTable(){
    std::ifstream iFile;
    int idHolder;
    std::string fNameHolder;
    std::string lNameHolder;
    Student tempStudent;
    
    iFile.open("student.txt");
    if(iFile.fail()){
        std::cout << "Failed to open file...\n";
        exit(1);
    }
    
    while (iFile >> idHolder >> fNameHolder >> lNameHolder){
        tempStudent.setId(idHolder);
        tempStudent.setFirstName(fNameHolder);
        tempStudent.setLastName(lNameHolder);
        
        if(InsertItem(tempStudent) != SUCCESS){
            std::cout << "Insertion failed... \n";
        }
        else
            length++;
    }
    iFile.close();
}

