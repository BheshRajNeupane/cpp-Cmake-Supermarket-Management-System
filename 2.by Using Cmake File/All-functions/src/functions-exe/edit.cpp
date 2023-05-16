#include "./shopping.hpp"

using namespace std;
using namespace superMarket ;

void shopping ::edit()
{
  fstream data, data1;
  int pkey;
  int token = 0;
  int c;
  float p;
  float d;
  string n;

  cout << "\n\n\t\t"
       << "|_____MOdify the record_____|";
  cout << " \n\n\t\t"
       << "  Enter Prodcut code:";
  cin >> pkey;

  data.open("database.txt", ios::in);
  if (!data)
  {
    cout << "File doesnot exist:";
  }
  else
  {
    data1.open("database1.txt", ios::app | ios::out);

    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
      if (pkey == pcode)
      { // allow to edit matched pcode details
        cout << "\n\t\t Product new code:";
        cin >> c;
        cout << "\n\t\t Name of the prodcut:";
        // getline(data1, n);
        cin >> n;
        cout << "\n\t\t Price:";
        cin >> p;
        cout << "\n\t\t Discount:";
        cin >> d;
        data1 << " " << c << " " << n << " " << p << " " << d << "\n";
        cout << "\n\n\t\t Record editied\n";
        token++;
      }
      else
      {
        data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
      }

      data >> pcode >> pname >> price >> dis; 
    }
    data.close();
    data1.close();

    // build in function
    remove("database.txt"); // delete
    rename("database1.txt", "database.txt");
    // database1.txt is  converted to databse.txt
  }
  if (token == 0)
  {
    cout << "\n\n Record not found ";
  }
}