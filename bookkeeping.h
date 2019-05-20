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

  // Bookkeeping::Bookkeeping(const Bookkeeping &bookkeeping) : m_name(bookkeeping.m_name), m_age(bookkeeping.m_age);
  Bookkeeping(const Bookkeeping &);
  Bookkeeping();
 ~Bookkeeping();

  void print();

  std::string getName();
  int         getAge();
  double      getMoney();

  void setName(std::string name);
  void setAge(int age);
  void setMoney(int money);

  void writeFile(std::string context, std::string fileName);
  void objectToFile(std::string fileName);
  void readFile(std::string fileName);

  Bookkeeping & operator= (const Bookkeeping & right);
  Bookkeeping & operator++();
  // std::string readFile(std::string fileName);

  void setMeta(std::string, int, double);
};

std::ostream& operator<< (std::ostream& out, Bookkeeping& p);
std::istream& operator>> (std::istream& in, Bookkeeping& p);

#endif
