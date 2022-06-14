
// DobermanPinscher.cpp
// Class DobermanPinscher implementation file.

#include "Exception.h"
#include "DateOfBirth.h"
#include "DobermanPinscher.h"
#include <string>

using namespace std;

// Class DobermanPinscher default constructor 
DobermanPinscher::DobermanPinscher() : Dog() {
  this->setName("N/A");
  this->setSex(1);
  this->setBirthYear(2020);
  this->setBirthMonth(5);
  this->setBirthDay(20);
  this->setFurType("Short");
  this->setSize(3);
  this->setEarsCropped(true);
  this->setTailDocked(true);
  this->setCoatColor("Black/Rust");
  this->setRegion(1);
  this->setWorkingDog(true);
  this->setDeclawed(false);
}
// Class DobermanPinscher copy constructor 
DobermanPinscher::DobermanPinscher(const DobermanPinscher &dobermanPinscher)
  : Dog(dobermanPinscher) {
    this->setName(dobermanPinscher.getName());
    this->setSex(dobermanPinscher.getSex());
    this->setBirthYear(dobermanPinscher.getBirthYear());
    this->setBirthMonth(dobermanPinscher.getBirthMonth());
    this->setBirthDay(dobermanPinscher.getBirthDay());
    this->setFurType(dobermanPinscher.getFurType());
    this->setSize(dobermanPinscher.getSize());
    this->setEarsCropped(dobermanPinscher.getEarsCropped());
    this->setTailDocked(dobermanPinscher.getTailDocked());
    this->setCoatColor(dobermanPinscher.getCoatColor());
    this->setRegion(dobermanPinscher.getRegion());
    this->setWorkingDog(dobermanPinscher.getWorkingDog());
    this->setDeclawed(dobermanPinscher.getDeclawed());
}
// Class DobermanPinscher constructor
DobermanPinscher::DobermanPinscher(string name, char sex, DateOfBirth dateOfBirth, string furType, char size, 
  bool earsCropped, bool tailDocked, string coatColor, char region, bool workingDog, bool declawed) 
  : Dog(name, sex, dateOfBirth, furType, size, earsCropped, tailDocked) {
    this->setName(name);
    this->setSex(sex);
    this->setBirthYear(dateOfBirth.getYear());
    this->setBirthMonth(dateOfBirth.getMonth());
    this->setBirthDay(dateOfBirth.getDay());
    this->setFurType(furType);
    this->setSize(size);
    this->setEarsCropped(earsCropped);
    this->setTailDocked(tailDocked);
    this->setCoatColor(coatColor);
    this->setRegion(region);
    this->setWorkingDog(workingDog);
    this->setDeclawed(declawed);
}
    
// Member function writeData writes a DobermanPinscher object to a binary file.
void DobermanPinscher::writeData(fstream &outFile)  {
    
  string name        = this->getName();
  char   sex         = this->getSex();
  int    month       = this->getBirthMonth();
  int    day         = this->getBirthDay();
  int    year        = this->getBirthYear();
  string furType     = this->getFurType();
  char   size        = this->getSize();
  bool   earsCropped = this->getEarsCropped();
  bool   tailDocked  = this->getTailDocked();
  string coatColor   = this->getCoatColor();
  char   region      = this->getRegion();
  bool   workingDog  = this->getWorkingDog();
  bool   declawed    = this->getDeclawed();
    
  outFile.write( (char *)&name,        sizeof(name) );
  outFile.write( (char *)&sex,         sizeof(sex) );
  outFile.write( (char *)&month,       sizeof(month) );
  outFile.write( (char *)&day,         sizeof(day) );
  outFile.write( (char *)&year,        sizeof(year) );
  outFile.write( (char *)&furType,     sizeof(furType) );
  outFile.write( (char *)&size,        sizeof(size) );
  outFile.write( (char *)&earsCropped, sizeof(earsCropped) );
  outFile.write( (char *)&tailDocked,  sizeof(tailDocked) );
  outFile.write( (char *)&coatColor,   sizeof(coatColor) );
  outFile.write( (char *)&region,      sizeof(region) );
  outFile.write( (char *)&workingDog,  sizeof(workingDog) );
  outFile.write( (char *)&declawed,    sizeof(declawed) );
}

// Member function writeRead reads a DobermanPinscher object from a binary file.
void DobermanPinscher::readData (fstream &inFile) {
    
  string name;
  char   sex;
  int    month,
         day,
         year;
  string furType;
  char   size;
  bool   earsCropped,
         tailDocked;
  string coatColor;
  char   region;
  bool   workingDog,
         declawed;
  
  inFile.read( (char *)&name,        sizeof(name) );
  inFile.read( (char *)&sex,         sizeof(sex) );
  inFile.read( (char *)&month,       sizeof(month) );
  inFile.read( (char *)&day,         sizeof(day) );
  inFile.read( (char *)&year,        sizeof(year) );
  inFile.read( (char *)&furType,     sizeof(furType) );
  inFile.read( (char *)&size,        sizeof(size) );
  inFile.read( (char *)&earsCropped, sizeof(earsCropped) );
  inFile.read( (char *)&tailDocked,  sizeof(tailDocked) );
  inFile.read( (char *)&coatColor,   sizeof(coatColor) );
  inFile.read( (char *)&region,      sizeof(region) );
  inFile.read( (char *)&workingDog,  sizeof(workingDog) );
  inFile.read( (char *)&declawed,    sizeof(declawed) );
  
  this->setName(name);
  this->setSex(sex);
  this->setBirthYear(year);
  this->setBirthMonth(month);
  this->setBirthDay(day);
  this->setFurType(furType);
  this->setSize(size);
  this->setEarsCropped(earsCropped);
  this->setTailDocked(tailDocked);
  this->setCoatColor(coatColor);
  this->setRegion(region);
  this->setWorkingDog(workingDog);
  this->setDeclawed(declawed);
}
    
// Overloaded insertion operator
ostream& operator<<(ostream& outStream, const DobermanPinscher& dobermanPinscher) {
  outStream << dobermanPinscher.getName()       << dobermanPinscher.getSex()       << dobermanPinscher.getBirthMonth() << dobermanPinscher.getBirthDay() 
            << dobermanPinscher.getBirthYear()  << dobermanPinscher.getFurType()   << dobermanPinscher.getSize()       << dobermanPinscher.getEarsCropped() 
            << dobermanPinscher.getTailDocked() << dobermanPinscher.getCoatColor() << dobermanPinscher.getRegion()     << dobermanPinscher.getWorkingDog() 
            << dobermanPinscher.getDeclawed();
  return outStream;
}

// Overloaded extraction operator
istream& operator>>(istream& inStream, DobermanPinscher& dobermanPinscher) {
    
  string name;
  char   sex;
  int    month,
         day,
         year;
  string furType;
  char   size;
  bool   earsCropped,
         tailDocked;
  string coatColor;
  char   region;
  bool   workingDog,
         declawed;
    
  inStream >> name >> sex >> month >> day >> year >> furType >> size >> earsCropped
           >> tailDocked;
  
  dobermanPinscher.setName(name);
  dobermanPinscher.setFurType(furType);
  dobermanPinscher.setEarsCropped(earsCropped);
  dobermanPinscher.setTailDocked(tailDocked);
  dobermanPinscher.setCoatColor(coatColor);
  dobermanPinscher.setWorkingDog(workingDog);
  dobermanPinscher.setDeclawed(declawed);
  
   if (sex < 0 || sex > 1) {
    inStream.setstate(ios_base::failbit);
    dobermanPinscher.setSex(1);
  }
  
  if (year < 0) {                                   // Validate birth year
    inStream.setstate(ios_base::failbit);
    dobermanPinscher.setBirthYear(2020);
  } 
  
  if (month < 1 || month > 12) {                    // Validate birth month
    inStream.setstate(ios_base::failbit);
    dobermanPinscher.setBirthMonth(1);
  } 
  
  if (month == 1 || month == 3 || month == 5  || 
      month == 7 || month == 8 || month == 10 || 
      month == 12 && (day < 1 || day > 31)) {       // Validate birth day
    inStream.setstate(ios_base::failbit);
    dobermanPinscher.setBirthDay(1);
  }
  else if (month == 4 || month == 6 || month == 9 || 
           month == 11 && (day < 1 || day > 30)) {
    inStream.setstate(ios_base::failbit);
    dobermanPinscher.setBirthDay(1);
  }
  else if (month == 2 && ((year % 100 == 0 && year % 400 == 0) 
             || (year % 4 == 0)) && (day < 1 || day > 29)) {
    inStream.setstate(ios_base::failbit);
    dobermanPinscher.setBirthDay(1);
  }
  else if (month == 2 && (day < 1 || day > 28)) {
    inStream.setstate(ios_base::failbit);
    dobermanPinscher.setBirthDay(1);
  }
  
  if (size < 1 || size > 3) {
    inStream.setstate(ios_base::failbit);
    dobermanPinscher.setSize(2);
  }
  
  if (region < 0 || region > 1) {
    inStream.setstate(ios_base::failbit);
    dobermanPinscher.setRegion(region);
  }
  
  return inStream;
}
    
// Class member function getCoatColor() returns this DobermanPinscher's coatColor.
string DobermanPinscher::getCoatColor() const {
  return this->coatColor;
}

// Class member function getRegion() returns this DobermanPinscher's region.
char   DobermanPinscher::getRegion() const {
  return this->region;
}

// Class member function getWorkingDog() returns true or false (workingNot/ not a working dog).
bool   DobermanPinscher::getWorkingDog() const {
  return this->workingDog;
}

// Class member function getDeclawed() returns true or false (declawed/ no declawed).
bool   DobermanPinscher::getDeclawed() const {
  return this->declawed;
}
    
// Class member function setCoatColor() sets this DobermanPinscher's coatColor.
void DobermanPinscher::setCoatColor(string coatColor) {
  this->coatColor = coatColor;
}

// Class member function setRegion() sets this DobermanPinscher's region.
void DobermanPinscher::setRegion(char region) {
  if (region < 0 || region > 1)
    throw Exception("Invalid Region", "0 = American Doberman, 1 = European Doberman", __LINE__);
  else {
    this->region = region;
  }
}

// Class member function setWorkingDog() sets this DobermanPinscher's workingDog.
void DobermanPinscher::setWorkingDog(bool workingDog) {
  this->workingDog = workingDog;
}

// Class member function setDeclawed() sets this DobermanPinscher's declawed.
void DobermanPinscher::setDeclawed(bool declawed) {
  this->declawed = declawed;
}