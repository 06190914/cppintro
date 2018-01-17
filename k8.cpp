#include <iostream>
using namespace std;

void func(int &x,int &y){
  int tmp;
  tmp = x;
  x   = y;
  y   = tmp;
}

int main(){
  int main_x = 1;
  int main_y = 9;

  cout << "変更前:" << "main_x = " << main_x << " main_y = " << main_y <<"\n";
  func(main_x,main_y);
  cout << "変更後:" << "main_x = " << main_x << " main_y = " << main_y <<"\n";


}
