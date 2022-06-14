
// Dog.cpp
// Class Dog implementation file.

#include "Dog.h"
#include "DateOfBirth.h"
#include "Exception.h"
#include <string>

using namespace std;

// Class Dog default constructor
Dog::Dog() : Pet() {
  this->setName("N/A");
  this->setSex(0);
  this->setBirthYear(2020);
  this->setBirthMonth(5);
  this->setBirthDay(20);
  this->setFurType("Shaggy");
  this->setSize(2);
  this->setEarsCropped(false);
  this->setTailDocked(false);
}

// Class Dog copy constructor
Dog::Dog(const Dog &dog) : Pet(dog) {
  this->setName(dog.getName());
  this->setSex(dog.getSex());
  this->setBirthYear(dog.getBirthYear());
  this->setBirthMonth(dog.getBirthMonth());
  this->setBirthDay(dog.getBirthDay());
  this->setFurType(dog.getFurType());
  this->setSize(dog.getSize());
  this->setEarsCropped(dog.getEarsCropped());
  this->setTailDocked(dog.getTailDocked());
}

// Class Dog constructor 
Dog::Dog(string name, char sex, DateOfBirth dateOfBirth, string furType, char size, 
  bool earsCropped, bool tailDocked) : Pet(name, sex, dateOfBirth) {
  this->setName(name);
  this->setSex(sex);
  this->setBirthYear(dateOfBirth.getYear());
  this->setBirthMonth(dateOfBirth.getMonth());
  this->setBirthDay(dateOfBirth.getDay());
  this->setFurType(furType);
  this->setSize(size);
  this->setEarsCropped(earsCropped);
  this->setTailDocked(tailDocked);
}

// Member function writeData writes a Dog object to a binary file
void Dog::writeData(fstream &outFile) {
    
  string   name        = this->getName();
    char   sex         = this->getSex();
    int    month       = this->getBirthMonth();
    int    day         = this->getBirthDay();
    int    year        = this->getBirthYear();
    string furType     = this->getFurType();
    char   size        = this->getSize();
    bool   earsCropped = this->getEarsCropped();
    bool   tailDocked  = this->getTailDocked();
    
  outFile.write( (char *)&name,        sizeof(name) );
  outFile.write( (char *)&sex,         sizeof(sex) );
  outFile.write( (char *)&month,       sizeof(month) );
  outFile.write( (char *)&day,         sizeof(day) );
  outFile.write( (char *)&year,        sizeof(year) );
  outFile.write( (char *)&furType,     sizeof(furType) );
  outFile.write( (char *)&size,        sizeof(size) );
  outFile.write( (char *)&earsCropped, sizeof(earsCropped) );
  outFile.write( (char *)&tailDocked,  sizeof(tailDocked) );
}

// Member function readData reads from Dog object from a binary file
void Dog::readData (fstream &inFile) {
    
  string name;
  char   sex;
  int    month,
         day,
         year;
  string furType;
  char   size;
  bool   earsCropped,
         tailDocked;
  
  inFile.read( (char *)&name,       sizeof(name) );
  inFile.read( (char *)&sex,        sizeof(sex) );
  inFile.read( (char *)&month,      sizeof(month) );
  inFile.read( (char *)&day,        sizeof(day) );
  inFile.read( (char *)&year,       sizeof(year) );
  inFile.read( (char *)&furType,    sizeof(furType) );
  inFile.read( (char *)&size,       sizeof(size) );
  inFile.read( (char *)&earsCropped,sizeof(earsCropped) );
  inFile.read( (char *)&tailDocked, sizeof(tailDocked) );
  
  this->setName(name);
  this->setSex(sex);
  this->setBirthYear(year);
  this->setBirthMonth(month);
  this->setBirthDay(day);
  this->setFurType(furType);
  this->setSize(size);
  this->setEarsCropped(earsCropped);
  this->setTailDocked(tailDocked);
}

// Overloaded insertion operator 
ostream& operator<<(ostream& outStream, const Dog& dog) {
  outStream << dog.getName()      << dog.getSex()     << dog.getBirthMonth() << dog.getBirthDay() 
            << dog.getBirthYear() << dog.getFurType() << dog.getSize()       << dog.getEarsCropped() 
            << dog.getTailDocked();
  return outStream;
}
  
// Overloaded extraction operator
istream& operator>>(istream& inStream, Dog& dog) {
    
    string name;
    char   sex;
    int    month,
           day,
           year;
    string furType;
    char   size;
    bool   earsCropped,
           tailDocked;
    
  inStream >> name >> sex >> month >> day >> year >> furType >> size >> earsCropped
           >> tailDocked;
  
  dog.setName(name);
  dog.setFurType(furType);
  dog.setEarsCropped(earsCropped);
  dog.setTailDocked(tailDocked);
  
  if (sex < 0 || sex > 1) {
    inStream.setstate(ios_base::failbit);
    dog.setSex(1);
  }
  
  if (year < 0) {                                   // Validate birth year
    inStream.setstate(ios_base::failbit);
    dog.setBirthYear(2020);
  } 
  
  if (month < 1 || month > 12) {                    // Validate birth month
    inStream.setstate(ios_base::failbit);
    dog.setBirthMonth(1);
  } 
  
  if (month == 1 || month == 3 || month == 5  || 
      month == 7 || month == 8 || month == 10 || 
      month == 12 && (day < 1 || day > 31)) {       // Validate birth day
    inStream.setstate(ios_base::failbit);
    dog.setBirthDay(1);
  }
  else if (month == 4 || month == 6 || month == 9 || 
           month == 11 && (day < 1 || day > 30)) {
    inStream.setstate(ios_base::failbit);
    dog.setBirthDay(1);
  }
  else if (month == 2 && ((year % 100 == 0 && year % 400 == 0) 
             || (year % 4 == 0)) && (day < 1 || day > 29)) {
    inStream.setstate(ios_base::failbit);
    dog.setBirthDay(1);
  }
  else if (month == 2 && (day < 1 || day > 28)) {
    inStream.setstate(ios_base::failbit);
    dog.setBirthDay(1);
  }
  
  if (size < 1 || size > 3) {
    inStream.setstate(ios_base::failbit);
    dog.setSize(2);
  }
  
  return inStream;
}

// Member function getFurType() returns this Dog object's furType.
string Dog::getFurType() const {
  return this->furType; 
}
  
// Member function getSize() returns this Dog object's size.
char Dog::getSize() const {
  return this->size;
}
    
// Member function getEarsCropped() returns true or false (ears cropped/ not cropped).
bool Dog::getEarsCropped() const {
  return this->earsCropped;
}
    
// Member function getTailDocked() returns true or false (tail docked/ not docked).
bool Dog::getTailDocked() const {
  return this->tailDocked;
}
    
// Member function setFurType() sets this Dog object's furType.
void Dog::setFurType(string furType) {
  this->furType = furType;
}

// Member function setSize() sets this Dog object's size.
void Dog::setSize(char size) {
  if (size < 1 || size > 3)
    throw Exception("Invalid Size", "1 = small, 2 = medium, 3 = large", __LINE__);
  else {
    this->size = size;   
  }
}

// Member function setEarsCropped() sets this Dog object's earsCropped.
void Dog::setEarsCropped(bool earsCropped) {
  this->earsCropped = earsCropped;
}

// Member function setTailDocked() sets this Dog object's tailDocked
void Dog::setTailDocked(bool tailDocked) {
  this->tailDocked = tailDocked;
}
