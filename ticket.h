#include <cmath>
#include <iostream>

using namespace std;

// Base class representing a generic ticket
class Ticket {
protected:
  int ticketNumber;
  double price;

public:
  // Constructor for the Ticket class
  Ticket(int);

  // Pure virtual function for getting the price of the ticket
  virtual double getPrice() const = 0;

  // Overloading << operator to print Ticket details
  friend ostream &operator<<(ostream &, const Ticket &);
};

// Derived class for Walkup Tickets
class WalkupTicket : public Ticket {
public:
  // Constructor for WalkupTicket class
  WalkupTicket(int);

  // Implementation of the virtual function to get the price of Walkup Tickets
  double getPrice() const;
};

// Derived class for Advance Tickets
class AdvanceTicket : public Ticket {
protected:
  int daysInAdvance;

public:
  // Constructor for AdvanceTicket class
  AdvanceTicket(int, int);

  // Implementation of the virtual function to get the price of Advance Tickets
  double getPrice() const;
};

// Derived class for Student Advance Tickets
class StudentAdvanceTicket : public AdvanceTicket {
public:
  // Constructor for StudentAdvanceTicket class
  StudentAdvanceTicket(int, int);

  // Implementation of the virtual function to get the price of Student Advance
  // Tickets
  double getPrice() const;
};

// Function prototype for the menu
void menu();
