#include <iostream>  // Include the standard input/output stream library, which is needed for input and output operations.

class Menu  // Define a C++ class named 'Menu'.
{
 public:
  virtual void displayMenu() = 0;
  // Declare a pure virtual function named 'displayMenu' in the 'Menu' class.
  // This function has no implementation in this class, as denoted by the '= 0'
  // at the end.
};
