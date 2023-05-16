#ifndef SHOPPING_HPP_INCLUDE
#define SHOPPING_HPP_INCLUDE
#include <iostream>
#include<fstream>
#include<string>

namespace superMarket
{
class shopping
{
private:
  int pcode;
  float price;
  float dis;
   std::string pname;

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


}


#endif