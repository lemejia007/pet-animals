
// DobermanPinscher.cpp
// Class DobermanPinscher specification file.
// Class DobermanPinscher is derived from base class Dog.

#include "DateOfBirth.h"
#include "Dog.h"
#include <fstream>
#include <string>

using namespace std;


#ifndef DOBERMANPINSCHER_H
#define DOBERMANPINSCHER_H

class DobermanPinscher : public Dog {
  
  // Private class members
  private:
    string coatColor;
    char   region;
    bool   workingDog,
           declawed;
    
  // Public class members
  public:
    // Constructors/ Destructor
    DobermanPinscher();
    DobermanPinscher(const DobermanPinscher &dobermanPinscher);
    DobermanPinscher(string name, char sex, DateOfBirth dateOfBirth, string furType, char size, 
      bool earsCropped, bool tailDocked, string coatColor, char region, bool workingDog, bool declawed);
    virtual ~DobermanPinscher() {};
    
    // Binary I/O functions
    virtual void writeData(fstream &outFile) override final;
    virtual void readData (fstream &inFile)  override final;
    
    // Overloaded operators (I/O)
    friend ostream &operator<<(ostream &outStream, const DobermanPinscher& dobermanPinscher);
    friend istream &operator>>(istream &inStream, DobermanPinscher& dobermanPinscher);
    
    // Getters/ accessor member functions
    string getCoatColor()  const;
    char   getRegion()     const;
    bool   getWorkingDog() const;
    bool   getDeclawed()   const;
    
    // Setters/ mutator member functions
    void setCoatColor(string coatColor);
    void setRegion(char region);
    void setWorkingDog(bool workingDog);
    void setDeclawed(bool declawed);
};

#endif /* DOBERMANPINSCHER_H */

