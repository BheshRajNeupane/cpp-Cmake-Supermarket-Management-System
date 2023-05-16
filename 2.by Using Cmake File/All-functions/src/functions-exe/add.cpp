 #include "./shopping.hpp"



using namespace std;
using namespace superMarket ;

void shopping::add()
{
m:
  int c;
  int token = 0;
  float p;
  float d;
  string n;
  fstream data;

  cout << "\n\n \t\t"
       << "Add new product ";
  cout << "\n\n\t\t"
       << "Product code of the product ";
  cin >> pcode;
  cout << "\n\n\t\t"
       << "Name of the product ";
  cin >> pname;
  cout << "\n\n \t\t"
       << "Price of the product ";
  cin >> price;
  cout << "\n\n\t\t"
       << "Discount of the product ";
  cin >> dis;

  data.open("databse.txt", ios::in); // read

  if (!data)
  { // write
    data.open("database.txt", ios::app | ios::out);

    data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
    data.close();
  }
  else
  {
    data >> c >> n >> p >> d;

    while (!data.eof())
    {
      if (c == pcode)
      {
        token++;
      }
      data >> c >> n >> p >> d;
    }

    data.close();

    if (token == 1)
    {
      goto m; // if same pcode or add code is already exist
    }
    else
    {
      data.open("databasee.txt", ios::app | ios::out);
      data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
      data.close();
    }
  }
  cout << "Record inserted!";
}