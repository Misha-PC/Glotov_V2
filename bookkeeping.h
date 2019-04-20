#include <string>
#include <iostream>
#include <fstream>


#ifndef BOOKKEEPING_H
#define BOOKKEEPING_H

class Bookkeeping
{
private:
  std::string m_name;
  int m_age;
  double m_money;
public:

  Bookkeeping();
  ~Bookkeeping();

  void print();

  std::string getName();
  int getAge();
  double getMoney();

  void setName(std::string name);
  void setAge(int age);
  void setMoney(int money);

  void writeFile(std::string context, std::string fileName);
  void readFile(std::string fileName);
  // std::string readFile(std::string fileName);

  void setMeta(std::string, int, double);
};
#endif
