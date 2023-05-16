#include "./shopping.hpp"
//  database --> "../../../build/Win64/main-exe/Release/database.txt"
using namespace std;
using namespace superMarket ;

void shopping ::receipt()
{
  fstream data;
  data.open("../../../build/Win64/main-exe/Release/database.txt", ios::in);
  cout << "\ndddddddfds\n";

  int prod_code[100];
  int prod_qty[100];
  char choice;
  int c = 0;
  float amount = 0;
  float dis = 0;
  float total = 0;

  cout << "\n\n\t\t Receipt ";
  // data.open("../../../build/Win64/main-exe/Release/database.txt", ios::in);
  // data.seekg(0);
  if (!data)
  {

    cout << "\n\n\t Empty database ";
     //return;
  }

  else
  {
    data.close();

    list();

    cout << "\n_____________________________________________\n";
    cout << "                                               \n";
    cout << "         Please place the order                \n";
    cout << "                                               \n";
    cout << "\n_____________________________________________\n";

    do
    {
    m:
      cout << "\n\n Enter Product code: ";
      cin >> prod_code[c];
      cout << "\n\n Enter the product quantity:";
      cin >> prod_qty[c];

      for (int i = 0; i < c; i++)
      {
        if (prod_code[c] == prod_code[i])
        {
          cout << "\n\n Dublicate product code.Please try again!";
          goto m;
        }
      }
      c++;//-----------------paxi thakeko

    cout <<c++;//-----------------------------------------------------------
      cout << "\n\n Do you want to buy another product? if yes then press y else no:  ";
      cin >> choice;

    } while (choice == 'y' ||choice == 'Y' );

    cout << "\n\n\t_______________RECEIPT______________\n";
    cout << "                                          \n";
    cout << "\nProduct No \t        ProductName \t        Quantity \t          Price  \t        discount \n";

 cout <<c++;
    for (int i = 0; i < c; i++)
    {
      cout<<pcode <<" "<<prod_code[i]<<endl; ///paxii thapeko hatayaa huncaa-==========================
      data.open("../../../build/Win64/main-exe/Release/database.txt", ios::in);
      data >> pcode >> pname >> price >> dis;


      while (!data.eof())
      //  1st all pcode of file copare with  prod_code[0] then with  prod_code[i+1] ....
      {
    cout<<pcode <<" "<<prod_code[i]<<endl; ///paxii thapeko hatayaa huncaa-====================================================
        if (pcode == prod_code[i])
        { // index of prod_code[] = index of prod_qty[]
          amount = price * prod_qty[i];
          dis = (amount * dis / 100);
          total += amount - dis;

          cout << "\n\n " << pcode << "\t\t     " << pname << " \t      " << prod_qty[i] << "\t\t     " << amount << "\t           " << dis << endl;
        }
        data >> pcode >> pname >> price >> dis;
      }
    }
    data.close();
  }




  cout << "\n\n____________________________________________";
  // cout<<" Amount :"<< "              " <<amount<<endl;
  //   cout<<"Total discount:             "<<dis<<endl;
  cout << "Total amount :         " << total << endl;
}