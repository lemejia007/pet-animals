
// DateOfBirth.cpp
// Class DateOfBirth implementation file.

#include "Exception.h"
#include "DateOfBirth.h"
#include <ctime>

using namespace std;

  // Class DateOfBirth default constructor
  DateOfBirth::DateOfBirth() {
    this->month = 1;
    this->day   = 1;
    this->year  = 2022;
  }
  
  // Class DateOfBirth copy constructor
  DateOfBirth::DateOfBirth(const DateOfBirth &dateOfBirth) {
      this->setYear(dateOfBirth.getYear());
      this->setMonth(dateOfBirth.getMonth());
      this->setDay(dateOfBirth.getDay());
  }

  // Class DateOfBirth constructor
  DateOfBirth::DateOfBirth(int month, int day, int year) {
      this->setYear(year);   // Validates year first 
      this->setMonth(month); // Validates month second
      this->setDay(day);     // Validates day third
  }
  
  // Member function getMonth() returns month
  int DateOfBirth::getMonth() const {
    return this->month;
  }
  
  // Member function getDay() returns day
  int DateOfBirth::getDay() const {
    return this->day;
  }
  
  // Member function getYear() returns year
  int DateOfBirth::getYear() const {
    return this->year;    
  }
  
  // Member function setMonth() validates the month passed as an argument before 
  // setting it to this DateOfBirth object's month member variable
  void DateOfBirth::setMonth(int month) {
    // Validate month
    if (month < 1 || month > 12) 
      throw Exception("Invalid Month", "Month must be between 1 and 12", __LINE__);
    else {
      this->month = month;
    }
  }
  
  // Member function setDay() validates the day passed as an argument before 
  // setting it to this DateOfBirth object's day member variable
  void DateOfBirth::setDay(int day) {
    // Validate day
    if (this->month == 1 || this->month == 3 || this->month == 5  || 
        this->month == 7 || this->month == 8 || this->month == 10 || 
        this->month == 12 && (day < 1 || day > 31))
      throw Exception("Invalid Day", "Day must be between 1 and 31", __LINE__);
    else if (this->month == 4 || this->month == 6 || this->month == 9 || 
            this->month == 11 && (day < 1 || day > 30))
      throw Exception("Invalid Day", "Day must be between 1 and 30", __LINE__);
    else if (this->month == 2 && ((this->year % 100 == 0 && this->year % 400 == 0) 
             || (this->year % 4 == 0)) && (day < 1 || day > 29))
      throw Exception("Invalid Day", "Day must be between 1 and 29", __LINE__);
    else if (this->month == 2 && (day < 1 || day > 28))
      throw Exception("Invalid Day", "Day must be between 1 and 28", __LINE__);
    else {
      this->day = day;
    }
  }
  
  // Member function setYear() validates the day passed as an argument before 
  // setting it to this DateOfBirth object's year member variable
  void DateOfBirth::setYear(int year) {
    // Validate year
    if (year < 0)
      throw Exception("Invalid Year", "Year must be between 0 and the current year", __LINE__);
    else {
      this->year = year;
    }
  }
  
  // Overloaded insertion operator 
  ostream& operator<<(ostream& outStream, const DateOfBirth& dateOfBirth) {
      outStream << dateOfBirth.getMonth() << dateOfBirth.getDay() << dateOfBirth.getYear();
      return outStream;
  }
  
  // Overloaded extraction operator
  istream& operator>>(istream& inStream, DateOfBirth& dateOfBirth) {
      
      int month,
          day,
          year;
      
    inStream >> month >> day >> year;
    
    // Validate year first
    if (year < 0) {
      inStream.setstate(ios_base::failbit);
      dateOfBirth.setYear(2020);
    } 
    else {
      dateOfBirth.setYear(year);
    }
    
    // Validate month second
    if (month < 1 || month > 12) {
      inStream.setstate(ios_base::failbit);
      dateOfBirth.setMonth(1);
    } 
    else {
      dateOfBirth.setMonth(month);
    }
    
    // Validate day third
    if (month == 1 || month == 3 || month == 5  || 
        month == 7 || month == 8 || month == 10 || 
        month == 12 && (day < 1  || day > 31)) {
      inStream.setstate(ios_base::failbit);
      dateOfBirth.setDay(1);
    } 
    else if (month == 4 || month == 6 || month == 9 || 
             month == 11 && (day < 1 || day > 30)) {
      inStream.setstate(ios_base::failbit);
      dateOfBirth.setDay(1);
    }
    else if (month == 2 && ((year % 100 == 0 && year % 400 == 0) 
             || (year % 4 == 0)) && (day < 1 || day > 29)) {
      inStream.setstate(ios_base::failbit);
      dateOfBirth.setDay(1);
    }
    else if (month == 2 && (day < 1 || day > 28)) {
      inStream.setstate(ios_base::failbit);
      dateOfBirth.setDay(1);
    } 
    else {
      dateOfBirth.setDay(day);
    }
    
    return inStream;
  }
  