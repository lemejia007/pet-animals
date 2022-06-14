
// Pet.h
// Class Pet is used as a base class for pet animals.

#ifndef PET_H
#define PET_H

#include "DateOfBirth.h"
#include <string>

using namespace std;

class Pet {

// Private class members
private:
  string name;
  char   sex;
  DateOfBirth dateOfBirth;

// Public class members
public:
  // Constructors/ Destructor
  Pet();
  Pet(const Pet &pet);
  Pet(string name, char sex, DateOfBirth dateOfBirth);
  virtual ~Pet() {};
  
  // Binary I/O functions 
  virtual void writeData(fstream &outFile) = 0;
  virtual void readData (fstream &inFile)  = 0;
  
  // Overloaded operators (I/O)
  friend ostream& operator<<(ostream& outStream, const Pet& pet);
  friend istream& operator>>(istream& inStream, Pet& pet);
  
  // Getters/ Accessor member functions
  string getName()       const;
  char   getSex()        const;
  int    getBirthMonth() const;
  int    getBirthDay()   const;
  int    getBirthYear()  const;
  
  // Setters/ Mutator member functions
  void setName(string name);
  void setSex(char sex);
  void setBirthMonth(int month);
  void setBirthDay(int day);
  void setBirthYear(int year);
};

#endif /* PET_H */

