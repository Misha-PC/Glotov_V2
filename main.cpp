#include <iostream>
#include <string>
#include "bookkeeping.h"

int main(){
  std::cout << __cplusplus << '\n';

  Bookkeeping* arr = new Bookkeeping[4]; // выделяем память на 4 объекта(0, 1, 2, 3)

  arr[0].setName("Nadejda");  //
  arr[0].setAge(41);          //  заполняем поля нулевого объекта
  arr[0].setMoney(50000);     //

  // arr[1].setMeta("Den", 45, 100000); // заполняем все поля первого объекта
  std::cin >> arr[1]; //заполняем поля первого объекта перегруженным оператором


  // arr[2].readFile("/home/misha/cpp/Glotov4/Nikita.txt"); // заполняем поля второго объекта из файла
  arr[2].readFile("object.txt"); // заполняем поля второго объекта из файла

  std::cout<<    arr[0].getName()   <<
       "\n"<<    arr[0].getAge()    <<
       "\n"<<    arr[0].getMoney()  <<"\n";   // выводим на экран нулевой объект по полям


  arr[1].print();
  arr[2].print(); //выводм перый и второй объекты


  arr[3] = arr[2]; // перегруженны бинарный оператор
                   // присваеваем третьему объекту значение полей второго

  ++arr[3]; // перегруженны унарный оператор
            // инкриментируем значение 3го элемента (возраст)

  std::cout << arr[3] << '\n';// выводим в поток значения 3го объекта
  arr[1].objectToFile("object.txt");

  // arr[3].writeFile("Test\n25\n90000", "123.txt");



  // system("pause");

  return 0;
}
