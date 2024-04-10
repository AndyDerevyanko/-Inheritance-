#include "ticket.h"

// Constructor for the Ticket class
Ticket::Ticket(int ticketNumber) : ticketNumber(ticketNumber) {}

// Overloaded << operator to print Ticket details
ostream &operator<<(ostream &out, const Ticket &ticket) {
  out << endl << "Ticket Number: " << ticket.ticketNumber << endl;
  out << "Price: $" << ticket.getPrice() << endl;
  out << "------------------------------" << endl << endl;
  return out;
}

// Constructor for WalkupTicket class, inheriting from Ticket
WalkupTicket::WalkupTicket(int number) : Ticket(number) {}

// Implementation of getPrice() for WalkupTicket
double WalkupTicket::getPrice() const { return 50.00; }

// Constructor for AdvanceTicket class, inheriting from Ticket
AdvanceTicket::AdvanceTicket(int number, int daysInAdvance)
    : Ticket(number), daysInAdvance(daysInAdvance) {}

// Implementation of getPrice() for AdvanceTicket
double AdvanceTicket::getPrice() const {
  if (daysInAdvance >= 10)
    return 30.00;
  else
    return 40.00;
}

// Constructor for StudentAdvanceTicket class, inheriting from AdvanceTicket
StudentAdvanceTicket::StudentAdvanceTicket(int number, int daysInAdvance)
    : AdvanceTicket(number, daysInAdvance) {}

// Implementation of getPrice() for StudentAdvanceTicket
double StudentAdvanceTicket::getPrice() const {
  // Student tickets are half the price of normal advance tickets
  return AdvanceTicket::getPrice() / 2;
}

// Menu function to interactively test the ticket classes
void menu() {
  while (true) {
    // Displaying the menu options
    cout << "--- Welcome to Ticket Sale Booth ---\n"
         << "1. Walkup Ticket\n"
         << "2. Advance Ticket\n"
         << "3. Student Advance Ticket\n"
         << "4. Quit\n\n";
    cout << "Please enter your selection: ";
    int selection;

    // Input validation for menu selection
    do {
      cin >> selection;
      if (selection < 1 || selection > 4)
        cout << "Invalid selection, please enter a number between 1 and 4: ";
    } while (selection < 1 || selection > 4);

    // Switch statement to handle user's menu choice
    switch (selection) {
    case 1: {
      // Creating and printing a WalkupTicket
      WalkupTicket ticket(1000 + rand() % 9000);
      cout << ticket;
      break;
    }
    case 2: {
      int days;
      cout << "Enter days before event: ";
      // Input validation for days in advance
      do {
        cin >> days;
        if (days < 0)
          cout << "Invalid selection, please enter a day value > 0: ";
      } while (days < 0);

      // Creating and printing an AdvanceTicket
      AdvanceTicket ticket(1000 + rand() % 9000, days);
      cout << ticket;
      break;
    }
    case 3: {
      int days;
      cout << "Enter days before event: ";
      // Input validation for days in advance
      do {
        cin >> days;
        if (days < 0)
          cout << "Invalid selection, please enter a day value > 0: ";
      } while (days < 0);

      // Creating and printing a StudentAdvanceTicket
      StudentAdvanceTicket ticket(1000 + rand() % 9000, days);
      cout << ticket;
      break;
    }
    case 4:
      // Quitting the program
      cout << "Enjoy the event!!!";
      return;
    }

    // Asking the user if they want to purchase another ticket
    cout << "Would you like to purchase another ticket (y/n)? ";
    char choice;

    // Input validation for yes or no choice
    do {
      cin >> choice;
      if (tolower(choice) != 'y' && tolower(choice) != 'n')
        cout << "Invalid selection, please enter y or n: ";
      // loop over if choice is not 'y' or 'n'
    } while (tolower(choice) != 'y' && tolower(choice) != 'n');

    // Exiting the program if the user chooses not to purchase another ticket
    if (tolower(choice) == 'n') {
      cout << "Enjoy the event!!!";
      return;
    }

    // new line for formatting
    cout << endl;
  }
}
