#include "ticket.h"
#include <iomanip>

int main() {
  // set decimal precision for double variables
  cout << fixed << setprecision(2);

  // Find random number seed initialization
  srand(time(0));

  // Call the menu function to start the ticket sale program
  menu();
}
