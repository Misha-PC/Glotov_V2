#include <iostream>
#include <string>
#include <fstream>

#include "bookkeeping.h"

Bookkeeping::Bookkeeping()
{
  std::cout << m_name << "\tinitialized. \n";
}
Bookkeeping::~Bookkeeping()
{
  std::cout << m_name <<"\tdestroyed\n";
}


void Bookkeeping::print()
{
  std::cout << "Name: " <<    m_name   <<
              "\nAge: " <<    m_age    <<
           "\nMoney: $" <<    m_money  << '\n';
}


std::string Bookkeeping::getName()            { return(m_name);   }
double Bookkeeping::getMoney()                { return(m_money);  }
int Bookkeeping::getAge()                     { return(m_age);    }

void Bookkeeping::setName(std::string name)   {  m_name  = name;  }
void Bookkeeping::setAge(int age)             {  m_age   = age;   }
void Bookkeeping::setMoney(int money)         {  m_money = money; }


void Bookkeeping::writeFile(std::string context, std::string fileName)
{
  std::ofstream file(fileName);

  if (file.is_open())
    {
        file << context << std::endl;
    }
  file.close();
}

/*
std::string Bookkeeping::readFile(std::string fileName)
{
  std::fstream file(fileName);

  std::string line, outLine;

  while (getline(file, line))
  {
    outLine += line + "\n";
  }
  return(outLine);
}
*/

void Bookkeeping::readFile(std::string fileName)
{
  std::fstream file(fileName);
  std::string line;
  std::string outLine[3];

  int i=0;
  while(getline(file, line)){
    outLine[i++] = line;
  }

  Bookkeeping::setName(outLine[0]);
  Bookkeeping::setAge(stoi(outLine[1]));
  Bookkeeping::setMoney(stod(outLine[2]));
}


void Bookkeeping::setMeta(std::string name, int age, double money)
{
  Bookkeeping::setName(name);
  Bookkeeping::setAge(age);
  Bookkeeping::setMoney(money);
}
