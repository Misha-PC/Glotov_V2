#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "bookkeeping.h"

Bookkeeping::Bookkeeping()
{
	std::cout << m_name << "\tinitialized. \n";
}

Bookkeeping::~Bookkeeping()
{
	std::cout << m_name << "\tdestroyed\n";
}


void Bookkeeping::print()
{
	std::cout << "Name: " << m_name <<
		"\nAge: " << m_age <<
		"\nMoney: $" << m_money << '\n';
}


std::string Bookkeeping::getName() { return(m_name); }
double      Bookkeeping::getMoney() { return(m_money); }
int         Bookkeeping::getAge() { return(m_age); }

void Bookkeeping::setName(std::string name) { m_name = name; }
void Bookkeeping::setAge(int age) { m_age = age; }
void Bookkeeping::setMoney(int money) { m_money = money; }


void Bookkeeping::writeFile(std::string context, std::string fileName)
{
	std::ofstream file(fileName);

	if (file.is_open())
	{
		file << context << std::endl;
	}
	file.close();
}

void Bookkeeping::readFile(std::string fileName)
{
	std::string line;
	std::string outLine[3];

	std::ifstream file;
	file.open(fileName);


	if (!file.is_open())
	{
		std::cout << "ERROR!" << std::endl;
	}
	else
	{
		std::cout << "Open" << std::endl;

		int i = 0;
		while (!file.eof() and i < 3) {
			line = "";
			getline(file, line);
			std::cout << "test:" << line << std::endl;
			outLine[i++] = line;
		}
	}

	file.close();

	int intAge, intMoney;
	std::istringstream iss (outLine[1]);
	iss >> intAge;

	std::istringstream iss1(outLine[2]);
	iss1 >> intMoney;


	Bookkeeping::setMeta(outLine[0], intAge, intMoney);
}

void Bookkeeping::setMeta(std::string name, int age, double money)
{
	Bookkeeping::setName(name);
	Bookkeeping::setAge(age);
	Bookkeeping::setMoney(money);
}

Bookkeeping & Bookkeeping::operator=(const Bookkeeping & right)
{
	if (this != &right)
	{
		m_name = right.m_name;
		m_age = right.m_age;
		m_money = right.m_money;
	}
	return *this;
}

Bookkeeping & Bookkeeping::operator++()
{
	m_age++;
	return *this;
}

std::ostream & operator<< (std::ostream & out, Bookkeeping & p)
{
	// out << p.print();
	out << "Name: " << p.getName() <<
		"\nAge: " << p.getAge() <<
		"\nMoney: $" << p.getMoney() << '\n';
	return out;
}

std::istream & operator>> (std::istream & in, Bookkeeping & p)
{
	std::string temp;
	int n;
	std::cout << "Name: ";
	std::getline(std::cin, temp);
	p.setName(temp);

	std::cout << "Age: ";
	std::cin >> n;
	p.setAge(n);
	std::cin.ignore();

	std::cout << "money: ";
	std::cin >> n;
	p.setMoney(n);
	std::cin.ignore();

	return in;
}
