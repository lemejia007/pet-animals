
// Exception.h
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

using namespace std;

class Exception {
  
  private:
    string exception_name;
    string exception_message;
    int exception_line_number;
    
  public:
    Exception(string name, string message, int line);
    string getException() const;
    string getExceptionName() const;
    string getExceptionMessage() const;
    int getExceptionLineNumber() const;
};

#endif /* EXCEPTION_H */
