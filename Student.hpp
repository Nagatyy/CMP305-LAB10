#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>

const int MAX_ITEMS = 5;

/* no need for big 3 since no dynamic memory*/
class  Student{
    public :
    Student();
    Student(int, std::string, std::string);
    
    bool operator ==( const Student &);//Equality
    void    setId(int value);
    int   getId();
    void    setFirstName(std::string);
    std::string   getFirstName ();
    void    setLastName(std::string lname);
    std::string   getLastName ();
    Student& operator = (const Student&);
    
    // function for hash table
    int Hash();
    
    private :
    int    id  ;
    std::string firstName;
    std::string lastName;
};


#endif /* Student_hpp */
