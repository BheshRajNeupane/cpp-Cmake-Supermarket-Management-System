
#include "./shopping.hpp"

using namespace std;
using namespace superMarket ;

void shopping::list()
{
  fstream data;
  data.open("database.txt", ios::in);
  cout << "\n\n";
  cout << "\tProNo \t Name \t\t Price \n";
  cout << "__________________________________________\n";
  data >> pcode >> pname >> price >> dis;
  while (!data.eof())
  {
    cout << "\t" << pcode << "\t\t" << pname << "\t\t" << price << "\n";
    data >> pcode >> pname >> price >> dis;
  }
  data.close();
}