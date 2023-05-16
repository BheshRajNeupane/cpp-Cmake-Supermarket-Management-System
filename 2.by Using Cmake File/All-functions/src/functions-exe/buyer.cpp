#include "./shopping.hpp"
using namespace std;
using namespace superMarket ;

void shopping::buyer()
{
m:
  int choice;
  cout << "\n\n\n\n";
  cout << "\t\t"
       << "|___  Buyer____|\n";
  cout << "                                    \n";
  cout << "\t\t"
       << "______________________________\n";
  cout << "                                       \n";
  cout << "\t\t"
       << " |___1)  Buy product____|\n";
  cout << "                                     \n";
  cout << "\t\t"
       << " |___2)  Go back____ _____|\n";
  cout << "\t\t"
       << "                          ";
  cout << "\t\t"
       << " Enter your choice:   \n                ";
  cin >> choice;

  switch (choice)
  {
  case 1:
    receipt();
    break;

  case 2:
    menu();
    break;

  default:

    cout << "Invalid choice.";
  }
  goto m;
}
