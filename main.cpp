#include <iostream>
#include <string>
#include "bookkeeping.h"

int main(){
  Bookkeeping* arr = new Bookkeeping[3];
  arr[0].setName("Nadejda");
  arr[0].setAge(41);
  arr[0].setMoney(50000);

  arr[1].setMeta("Den", 45, 100000);
  arr[2].readFile("/home/misha/cpp/Glotov4/Nikita.txt");
  // arr[2].setMeta("Nikita", 18, 5000);

  std::cout<<    arr[0].getName()   <<
       "\n"<<    arr[0].getAge()    <<
       "\n"<<    arr[0].getMoney()  <<"\n";

  arr[1].print();
  arr[2].print();


/*  //uncoment if code not work
  char end_;
  std::cin >> end_;
*/

  return 0;
}
