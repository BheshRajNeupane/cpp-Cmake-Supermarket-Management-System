
#include "./shopping.hpp"

using namespace std;
using namespace superMarket ;

void shopping ::administor()
{
m:
  int choice;
  cout << "\n\n\n\n";
  cout << "\t\t"
       << "   Administrator Menu  \n";
  cout << "\t\t"
       << "|___1)  Add the product____|\n";
  cout << "                                     \n";
  cout << "\t\t"
       << "|___2)  Modify the product____|\n";
  cout << "                                     \n";
  cout << "\t\t"
       << "|___3)  Delete the product____|\n";
  cout << "                                     \n";
  cout << "\t\t"
       << "|___4)  Back to main mainu____|\n";
  cout << "                                          \n";

  cout << "\n\n";
  cout << "\t\t"
       << " Please enter your choice:";
  cin >> choice;

  switch (choice)
  {
  case 1:
    add();
    break;

  case 2:
    edit();
    break;

  case 3:
    rem();
    break;

  case 4:
    menu();
    break;

  default:

    cout << "Invalid choice.";
  }
  goto m;
}
