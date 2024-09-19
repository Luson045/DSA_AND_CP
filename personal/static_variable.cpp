#include <iostream>
using namespace std;

class Teacher{
  private:
  static int id;
  string name;
  string role;
  public:
  static void get_id();
};
void Teacher::get_id(){
    cout<<id<<endl;
}
int Teacher::id = 130;
int main(){
  Teacher t1;
  t1.get_id();
  Teacher::get_id();
  return 0;
}