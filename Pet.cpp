
// Pet.cpp
// Class Pet implementation file.

#include "Pet.h"
#include "Exception.h"
#include "DateOfBirth.h"
#include <string>

using namespace std;

// Class Pet default constructor 
Pet::Pet() {
  this->setName("N/A");
  this->setSex(0);
  this->setBirthYear(2020);
  this->setBirthMonth(5);
  this->setBirthDay(20);
}

// Class Pet copy constructor 
Pet::Pet(const Pet &pet) {
  this->setName(pet.getName());
  this->setSex(pet.getSex());
  this->setBirthYear(pet.getBirthYear());
  this->setBirthMonth(pet.getBirthMonth());
  this->setBirthDay(pet.getBirthDay());
}

// Class Pet constructor
Pet::Pet(string name, char sex, DateOfBirth dateOfBirth) {
    this->setName(name);
    this->setSex(sex);
    this->dateOfBirth.setYear(dateOfBirth.getYear());
    this->dateOfBirth.setMonth(dateOfBirth.getMonth());
    this->dateOfBirth.setDay(dateOfBirth.getDay());
}

// Overloaded insertion operator
ostream& operator<<(ostream& outStream, const Pet& pet) {
    outStream << pet.getName() << pet.getSex()  << pet.dateOfBirth.getMonth() 
              << pet.dateOfBirth.getDay()       << pet.dateOfBirth.getYear(); 
    return outStream;
}
  
// Overloaded extraction operator
istream& operator>>(istream& inStream, Pet& pet) {
  
  string name;
  char   sex;
  int    month,
         day,
         year;
    
  inStream >> name >> sex >> month >> day >> year;
  
  if (year < 0) {                                   // Validate birth year
    inStream.setstate(ios_base::failbit);
    pet.setBirthYear(2020);
  } 
  
  if (month < 1 || month > 12) {                    // Validate birth month
    inStream.setstate(ios_base::failbit);
    pet.setBirthMonth(1);
  } 
  
  if (month == 1 || month == 3 || month == 5  || 
      month == 7 || month == 8 || month == 10 || 
      month == 12 && (day < 1 || day > 31)) {       // Validate birth day
    inStream.setstate(ios_base::failbit);
    pet.setBirthDay(1);
  }
  else if (month == 4 || month == 6 || month == 9 || 
           month == 11 && (day < 1 || day > 30)) {
    inStream.setstate(ios_base::failbit);
    pet.setBirthDay(1);
  }
  else if (month == 2 && ((year % 100 == 0 && year % 400 == 0) 
             || (year % 4 == 0)) && (day < 1 || day > 29)) {
    inStream.setstate(ios_base::failbit);
    pet.setBirthDay(1);
  }
  else if (month == 2 && (day < 1 || day > 28)) {
    inStream.setstate(ios_base::failbit);
    pet.setBirthDay(1);
  }
  
  if (sex < 0 || sex > 1) {  // Validate Pet sex
    inStream.setstate(ios_base::failbit);
    sex = 1;
  }
  return inStream;
}

// Member function getFirstName() returns this Pet object's firstName.
string Pet::getName() const {
  return this->name; 
}

// Member function getLastName() returns this Pet object's lastName.
char Pet::getSex() const {
  return this->sex;
}

// Member function getBirthMonth() returns this Pet object's birth month.
int Pet::getBirthMonth() const {
  return this->dateOfBirth.getMonth(); 
}

// Member function getBirthDay() returns this Pet object's birth day.
int Pet::getBirthDay() const {
  return this->dateOfBirth.getDay();
}

// Member function getBirthYear() returns this Pet object's birth year.
int Pet::getBirthYear() const {
  return this->dateOfBirth.getYear();
}

// Member function setFirstName sets this Pet object's firstName.
void Pet::setName(string name) {
  this->name = name;
}

// Member function setLastName sets this Pet object's lastName.
void Pet::setSex(char sex) {
  if (sex < 0 || sex > 1)
    throw Exception("Invalid Sex", "0 = female, 1 = male", __LINE__);
  else {
    this->sex = sex;   
  }
}

// Member function setBirthMonth() sets this Pet object's birth month.
void Pet::setBirthMonth(int month) {
  this->dateOfBirth.setMonth(month);
}

// Member function setBirthDay() sets this Pet object's birth day.
void Pet::setBirthDay(int day) {
  this->dateOfBirth.setDay(day);
}

// Member function setBirthYear() sets this Pet object's birth year.
void Pet::setBirthYear(int year) {
  this->dateOfBirth.setYear(year);
}
