#include <iostream>
#include <string>
#include "bookkeeping.h"

int main(){
  Bookkeeping* arr = new Bookkeeping[4]; // выделяем память на 4 объекта(0, 1, 2, 3)

  arr[0].setName("Nadejda");  //
  arr[0].setAge(41);          //  заполняем поля нулевого объекта
  arr[0].setMoney(50000);     //

  // arr[1].setMeta("Den", 45, 100000); // заполняем поля первого объекта
  std::cin >> arr[1];             // заполняем поля первого объекта перегруженным оператором

  arr[2].readFile("object.txt"); // заполняем поля второго объекта из файла

  std::cout<<    "\nObject #1:\n";
  std::cout<<    arr[0].getName()   <<
       "\n"<<    arr[0].getAge()    <<
       "\n"<<    arr[0].getMoney();

  std::cout<<    "\n\nObject #2:\n";
  arr[1].print();

  std::cout<<   "\nObject #3:\n";
  std::cout<<   arr[2]   << '\n';   // выводим в поток значения 2го объекта

  arr[3] = arr[2]; // перегруженный бинарный оператор
  ++arr[3]; // перегруженный унарный оператор
  std::string name3;
  std::cout << "New name: ";
  std::cin >> name3;
  arr[3].setName(name3);
  std::cout << "\nObject #4:\n" << arr[3] << '\n';// выводим в поток значения 3го объекта


  arr[1].objectToFile("object.txt");

  // system("pause");

  return 0;
}
