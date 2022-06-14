
// Cat.cpp
// Class Cat implementation file.

#include "Exception.h"
#include "Pet.h"
#include "Cat.h"
#include "DateOfBirth.h"
#include <string>

using namespace std;

// Class Cat default constructor 
Cat::Cat() : Pet() {
  this->setName("N/A");
  this->setSex(0);
  this->setBirthYear(2020);
  this->setBirthMonth(5);
  this->setBirthDay(20);
  this->setEyeColor("Lime Green");
  this->setHairType(1);
  this->setLikesWater(false);
  this->setIsSassy(false);
}

// Class Cat copy constructor
Cat::Cat(const Cat &cat) {
  this->setName(cat.getName());
  this->setSex(cat.getSex());
  this->setBirthYear(cat.getBirthYear());
  this->setBirthMonth(cat.getBirthMonth());
  this->setBirthDay(cat.getBirthDay());
  this->setEyeColor(cat.getEyeColor());
  this->setHairType(cat.getHairType());
  this->setLikesWater(cat.getLikesWater());
  this->setIsSassy(cat.getIsSassy());
}


// Class Cat constructor
Cat::Cat(string name, char sex, DateOfBirth dateOfBirth, string eyeColor, char hairType, 
        bool likesWater, bool isSassy) : Pet(name, sex, dateOfBirth) {
  this->setName(name);
  this->setSex(sex);
  this->setBirthYear(dateOfBirth.getYear());
  this->setBirthMonth(dateOfBirth.getMonth());
  this->setBirthDay(dateOfBirth.getDay());
  this->setEyeColor(eyeColor);
  this->setHairType(hairType);
  this->setLikesWater(likesWater);
  this->setIsSassy(isSassy);
}

// Member class function writeData() writes a Cat object to a binary file
void Cat::writeData(fstream &outFile) {
    
  string name       = this->getName();
  char   sex        = this->getSex();
  int    month      = this->getBirthMonth();
  int    day        = this->getBirthDay();
  int    year       = this->getBirthYear();
  string eyeColor   = this->getEyeColor();
  char   hairType   = this->getHairType();
  bool   likesWater = this->getLikesWater();
  bool   isSassy    = this->getIsSassy();
    
  outFile.write( (char *)&name,      sizeof(name) );
  outFile.write( (char *)&sex,       sizeof(sex) );
  outFile.write( (char *)&month,     sizeof(month) );
  outFile.write( (char *)&day,       sizeof(day) );
  outFile.write( (char *)&year,      sizeof(year) );
  outFile.write( (char *)&eyeColor,  sizeof(eyeColor) );
  outFile.write( (char *)&hairType,  sizeof(hairType) );
  outFile.write( (char *)&likesWater,sizeof(likesWater) );
  outFile.write( (char *)&isSassy,   sizeof(isSassy) );
}

// Member function readData reads a Cat object from a binary file
void Cat::readData(fstream &inFile) {
    
  string name;
  char   sex;
  int    month,
         day,
         year;
  string eyeColor;
  char   hairType;
  bool   likesWater,
         isSassy;
  
  inFile.read( (char *)&name,       sizeof(name) );
  inFile.read( (char *)&sex,        sizeof(sex) );
  inFile.read( (char *)&month,      sizeof(month) );
  inFile.read( (char *)&day,        sizeof(day) );
  inFile.read( (char *)&year,       sizeof(year) );
  inFile.read( (char *)&eyeColor,   sizeof(eyeColor) );
  inFile.read( (char *)&hairType,   sizeof(hairType) );
  inFile.read( (char *)&likesWater, sizeof(likesWater) );
  inFile.read( (char *)&isSassy,    sizeof(isSassy) );
  
  this->setName(name);
  this->setSex(sex);
  this->setBirthYear(year);
  this->setBirthMonth(month);
  this->setBirthDay(day);
  this->setEyeColor(eyeColor);
  this->setHairType(hairType);
  this->setLikesWater(likesWater);
  this->setIsSassy(isSassy);
}

// Overloaded insertion operator 
ostream& operator<<(ostream &outStream, const Cat &cat) {
  outStream << cat.getName()      << cat.getSex()      << cat.getBirthMonth() << cat.getBirthDay() 
            << cat.getBirthYear() << cat.getEyeColor() << cat.getHairType()   << cat.getLikesWater() 
            << cat.getIsSassy();
  return outStream;
}
  
// Overloaded extraction operator
istream& operator>>(istream &inStream, Cat &cat) {
    
    string name;
    char   sex;
    int    month,
           day,
           year;
    string eyeColor;
    char   hairType;
    bool   likesWater,
           isSassy;
    
  inStream >> name >> sex >> month >> day >> year >> eyeColor >> hairType >> likesWater
           >> isSassy;
  
  cat.setName(name);
  cat.setEyeColor(eyeColor);
  cat.setLikesWater(likesWater);
  cat.setIsSassy(isSassy);
  
  if (sex < 0 || sex > 1) {
    inStream.setstate(ios_base::failbit);
    cat.setSex(1);
  }
  
  if (year < 0) {                                   // Validate birth year
    inStream.setstate(ios_base::failbit);
    cat.setBirthYear(2020);
  } 
  
  if (month < 1 || month > 12) {                    // Validate birth month
    inStream.setstate(ios_base::failbit);
    cat.setBirthMonth(1);
  } 
  
  if (month == 1 || month == 3 || month == 5  || 
      month == 7 || month == 8 || month == 10 || 
      month == 12 && (day < 1 || day > 31)) {       // Validate birth day
    inStream.setstate(ios_base::failbit);
    cat.setBirthDay(1);
  }
  else if (month == 4 || month == 6 || month == 9 || 
           month == 11 && (day < 1 || day > 30)) {
    inStream.setstate(ios_base::failbit);
    cat.setBirthDay(1);
  }
  else if (month == 2 && ((year % 100 == 0 && year % 400 == 0) 
             || (year % 4 == 0)) && (day < 1 || day > 29)) {
    inStream.setstate(ios_base::failbit);
    cat.setBirthDay(1);
  }
  else if (month == 2 && (day < 1 || day > 28)) {
    inStream.setstate(ios_base::failbit);
    cat.setBirthDay(1);
  }
  
  if (hairType < 0 || hairType > 1) {
    inStream.setstate(ios_base::failbit);
    cat.setHairType(1);
  }
  
  return inStream;
}

// Class member function getEyeColor() returns this Cat object's eyeColor.
string Cat::getEyeColor() const {
  return this->eyeColor;
}

// Class member function getHairType() returns this Cat object's hairType.
char Cat::getHairType() const {
  return this->hairType;
}

// Class member function getLikesWater() returns true/ false (likesWater/ does not like water)
bool Cat::getLikesWater() const {
  return this->likesWater;
}

// Class member function getIsSassy() returns true/ false (isSassy/ is not sassy)
bool Cat::getIsSassy() const {
  return this->isSassy;
}

// Class member function setEyeColor() sets this Cat object's eyeColor.
void Cat::setEyeColor(string eyeColor) {
  this->eyeColor = eyeColor;
}

// Class member function setHairType() sets this Cat object's hairType.
void Cat:: setHairType(char hairType) {
  if (hairType < 0 || hairType > 1)
      throw Exception("Invalid Hair Type", "1 == short, 2 == long", __LINE__);
  else {
   this->hairType = hairType;   
  }
}

// Class member function setLikesWater() sets this Cat object's likesWater member.
void Cat::setLikesWater(bool likesWater) {
  this->likesWater = likesWater;
}

// Class member function setIsSassy() sets this Cat object's isSassy member.
void Cat::setIsSassy(bool isSassy) {
  this->isSassy = isSassy;
}
