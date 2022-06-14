
// DateOfBirth.h
// Class DateOfBirth specification file.
// Class DateOfBirth is used to demonstrate composition. Every Pet object will 
// have, as a member, aDateOfBirth object.

#ifndef DATEOFBIRTH_H
#define DATEOFBIRTH_H

#include <fstream>
#include <iostream>

using namespace std;

class DateOfBirth {
  
  // Private class members
  private:
    int month,
        day,
        year;    
  
  // Public class members
  public:
    // Constructors/ Destructor
    DateOfBirth(); 
    DateOfBirth(const DateOfBirth &dateOfBirth); 
    DateOfBirth(int month, int day, int year);
    virtual ~DateOfBirth(){};
   
    // Getter/ Accessor member functions
    int getMonth() const;
    int getDay()   const;
    int getYear()  const;
    
    // Setter/ Mutator member functions
    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);
    
    // Overloaded operators (I/O)
    friend ostream& operator<<(ostream &outStream, const DateOfBirth &dateOfBirth);
    friend istream& operator>>(istream &inStream, DateOfBirth &dateOfBirth);
};

#endif /* DATEOFBIRTH_H */
