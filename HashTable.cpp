#include "HashTable.hpp"


HashTable::HashTable ( ){
    length = 0;
    populateTable();
}
void HashTable::RetrieveItem(Student&  item, bool&  found) {
    // make sure not empty
    if(isEmpty())
        return;
    
    int loc = item.Hash();
    found = false;
    int counter = 0;
    
    while(!found && counter != MAX_ITEMS){
        counter++;
        if(info[loc].student == item && info[loc].status == FULL){
            found = true;
            item = info[loc].student;
        }
        else
            loc = (loc+1)%MAX_ITEMS;
    }
    
}
ERROR_CODE HashTable::InsertItem (Student  item){
    
    if(isFull())
        return OVER_FLOW;
    // check that the item doesnt already exist
    bool found;
    RetrieveItem(item, found);
    
    if(!found){ // only insert if not found
    
        int loc = item.Hash();
        
        while(info[loc].status != EMPTY)
            loc = (loc+1)%MAX_ITEMS;
        
        info[loc].student = item;
        info[loc].status = FULL;
        length++;
        
        return SUCCESS;
    }
    else {
        std::cout << "Student Already Exists... \n";
        return OVER_FLOW; // overflow returned if item already exists
    }
    
}
ERROR_CODE HashTable::DeleteItem (Student  item){
    
    if(isEmpty())
        return UNDER_FLOW;
    
    bool found = false;
    int counter = 0; // so we dont keep searching after we've looked at every element
    int loc = item.Hash();
    
    while(!found && counter != MAX_ITEMS){ // while we still have more to search and item isnt found
        counter++;
        if(info[loc].student == item){
            found = true;
            info[loc].status = EMPTY; // Delete by marking as empty
            length--;
            return SUCCESS;
        }
        else
            loc = (loc+1)%MAX_ITEMS;

    }
    
    return UNDER_FLOW; // underflow retruned if deletion failed
    
}
void HashTable::print(){
    
    for(int i = 0; i < MAX_ITEMS; i++){
        if(info[i].status == FULL)
            std::cout << info[i].student.getId() << std::setw(10) << info[i].student.getFirstName() << std::setw(10) << info[i].student.getLastName() << '\n';
    }
        
    
}
bool HashTable::isFull(){
    return length == MAX_ITEMS;
}
bool HashTable::isEmpty(){
    return length == 0;
}

void HashTable::populateTable(){
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
        
        if(InsertItem(tempStudent) == OVER_FLOW){
            std::cout << "Insertion failed... \n";
        }
        else
            length++;
    }
        iFile.close();
}

