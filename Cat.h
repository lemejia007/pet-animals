
// Cat.h
// Class Cat specification file.
// Class Cat is a derived class of base class Pet.

#ifndef CAT_H
#define CAT_H

#include "DateOfBirth.h"
#include "Pet.h"
#include <fstream>
#include <string>
using namespace std;

class Cat : public Pet {

  // Private class members
  private:
    string eyeColor;
    char   hairType;
    bool   likesWater,
           isSassy;
    
  // Public class members
  public:
    // Constructors/ Destructor
    Cat();
    Cat(const Cat &cat);
    Cat(string name, char sex, DateOfBirth dateOfBirth, string eyeColor, char hairType, 
        bool likesWater, bool isSassy);
    virtual ~Cat() {};
    
    // Binary I/O functions
    virtual void writeData(fstream &outFile) override;
    virtual void readData (fstream &inFile)  override;
    
    // Overloaded operators (I/O)
    friend ostream &operator<<(ostream &outStream, const Cat &cat);
    friend istream &operator>>(istream &inStream, Cat &cat);
    
    // Getters/ Accessor member functions
    string getEyeColor()   const;
    char   getHairType()   const;
    bool   getLikesWater() const;
    bool   getIsSassy()    const;
    
    // Setters/ Mutator member functions
    void setEyeColor(string eyeColor);
    void setHairType(char hairType);
    void setLikesWater(bool likesWater);
    void setIsSassy(bool isSassy);
};

#endif /* CAT_H */

