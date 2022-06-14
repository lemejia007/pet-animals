
// Dog.h
// Class Dog specification file.
// Class Dog is a sub class of base class Pet.

#ifndef DOG_H
#define DOG_H

#include "DateOfBirth.h"
#include "Pet.h"
#include <fstream>
#include <string>

using namespace std;

class Dog : public Pet {
  
  // Private class members
  private:
    string furType;
    char   size;
    bool   earsCropped,
           tailDocked;
    
  // Public class members
  public:
    // Constructors/ Destructor
    Dog();
    Dog(const Dog &dog);
    Dog(string name, char sex, DateOfBirth dateOfBirth, string furType, char size, 
        bool earsCropped, bool tailDocked);
    virtual ~Dog() {};
    
    // Binary I/O functions
    virtual void writeData(fstream &outFile) override;
    virtual void readData (fstream &inFile)  override;
    
    // Overloaded operators (I/O)
    friend ostream& operator<<(ostream& outStream, const Dog& dog);
    friend istream& operator>>(istream& inStream, Dog& dog);
    
    // Getters/ Accessor member functions
    string getFurType()     const;
    char   getSize()        const;
    bool   getEarsCropped() const;
    bool   getTailDocked()  const;
    
    // Setters/ Mutator member functions
    void setFurType(string furType);
    void setSize(char size);
    void setEarsCropped(bool earsCropped);
    void setTailDocked(bool tailDocked);
};

#endif /* DOG_H */

