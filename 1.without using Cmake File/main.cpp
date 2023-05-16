#include <iostream>
#include<fstream>
#include<string>

 using namespace std;

class shopping
{
private:
  int pcode;
  float price;
  float dis;
  string pname;

public:
  void menu();
  void administor();
  void buyer();
  void edit();
  void add();
  void rem();
  void list();
  void receipt();
};


void shopping:: menu(){

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


void  shopping::administor()
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
       << " Pleasee enter your choice:";
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

void shopping::list()
{
  fstream data;
  data.open("database.txt", ios::in);
  cout<<" \t List of itmes:";
  cout << "\n\n";
  cout << "\tP.Code \t Name \t\t Price \n";
  cout << "__________________________________________\n";
  data >> pcode >> pname >> price >> dis;
  while (!data.eof())
  {
    cout << "\t" << pcode << "\t" << pname << "\t\t " << price << "\n";
     data >> pcode >> pname >> price >> dis;
  }
  data.close();
}


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


void shopping ::receipt()
{
  fstream data;
  data.open("database.txt", ios::in);
  cout << "\n\n";

  int prod_code[100];
  int prod_qty[100];
  char choice;
  int c = 0;
  float amount = 0;
  float dis = 0;
  float total = 0;

  
  // data.open("database.txt", ios::in);
  // data.seekg(0);
  if (!data)
  {

    cout << "\n\n\t Empty database ";
    // return;
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

       c=c+1;

      cout << "\n\n Do you want to buy another product? if yes then press y else no:  ";
      cin >> choice;

    }
     while (choice == 'y' ||choice == 'Y' );

    cout << "\n\n\t_______________RECEIPT______________\n";
    cout << "                                          \n";
    cout << "\nP.Code  ProductName  Quantity  Price  discount \n";

    
    for (int i = 0; i < c; i++)
    {
      data.open("database.txt", ios::in);
      data >> pcode >> pname >> price >> dis;
       int d=0;
       cout<<"d="<<d;
       d++;

      while (!data.eof())
      
      {
         cout<<"d=in"<<d;
       d++;

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
  
  cout << "Total amount :         " << total << endl;
}

int main()

  {
shopping s;
   s.menu();
  
  return 0;
}

