#include "Student.hpp"

Student::Student(){
    id = -1;
    firstName = "";
    lastName = "";
}
Student::Student(int id, std::string firstName, std::string lastName){
    this -> id = id;
    this -> firstName = firstName;
    this -> lastName = lastName;
}
// 2 students are equal if they have the same ID
bool Student::operator ==( const Student & other){
    return id == other.id;
}
void Student::setId(int value){
    id = value;
}
int Student::getId(){
    return id;
}
void Student::setFirstName(std::string firstName){
    this -> firstName = firstName;
}
std::string Student::getFirstName (){
    return firstName;
}
void  Student::setLastName(std::string lastName){
    this -> lastName = lastName;
}
std::string Student::getLastName (){
    return lastName;
}

int Student::Hash(){
    return id%MAX_ITEMS;
}
Student& Student::operator = (const Student& other){
    if (this == &other)
        return *this;
    id = other.id;
    firstName = other.firstName;
    lastName = other.lastName;
    
    return *this;
}


