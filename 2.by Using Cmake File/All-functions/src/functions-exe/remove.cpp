#include "./shopping.hpp"


using namespace std;
using namespace superMarket ;


void shopping ::rem()
{

  fstream data, data1;
  int pkey;
  int token = 0;

  cout << "\n\n\t Delete Product ";
  cout << "\n\n\t Product Code ";
  cin >> pkey;
  data.open("database.txt", ios::in);
  if (!data)
  {
    cout << "File doesnot exist";
  }
  else
  {
    data1.open("database1.txt", ios::app | ios::out);

    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
      if (pkey == pcode)
      { // allow to edit matched pcode details
        cout << "\nProduct delete....!\n";
      }
      else
      {
        data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
      }

      data >> pcode >> pname >> price >> dis;
    }
    data.close();
    data1.close();

    remove("database.txt"); // delete
    rename("database1.txt", "database.txt");
  }
  if (token == 0)
  {
    cout << "\n\n Record not found ";
  }
}