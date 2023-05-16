#include "./shopping.hpp"

using namespace std;
using namespace superMarket ;

 void shopping::menu(){


m: // for goto
  int choice;
  string email;
  string password;

  cout << "\t\t"
       << "_____________________________________________\n";
  cout << "\t\t"
       << "                                \n";
  cout << "\t\t"
       << "     SuperMarket Main Menu       \n";
  cout << "\t\t"
       << "                                \n";
  cout << "\t\t"
       << "_____________________________________________\n";
  cout << "\t\t"
       << "                                \n";
  cout << "\t\t"
       << "|   1)Administor            |\n";
  cout << "\t\t"
       << "|                           |     \n";
  cout << "\t\t"
       << "|   2)Buyer                 |\n";
  cout << "\t\t"
       << "|                           |     \n";
  cout << "\t\t"
       << "|   3)Exit                  |\n";
  cout << "\t\t"
       << "                                \n";
  cout << "\t\t"
       << " PLease Select!                               \n";
  cin >> choice;

  switch (choice)
  {
  case 1:
    cout << "\t\t"
         << "Please Login \n";
    cout << "\t\t"
         << "Enter Email \n";
    cin >> email;
    cout << "\t\t"
         << "Enter Password \n";
    cin >> password;

    if (email == "shop1@gmail.com" && password == "12345")
    {
      administor();
    }
    else
    {
      cout << "Invalid email or password ";
    }
    break;

  case 2:
  {
    buyer();
  }
  case 3:
  {
    exit(0);
  }

  default:
  {
    cout << "Please select from the given options.";
  }
  }

  goto m;
}