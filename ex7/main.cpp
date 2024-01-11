#include <iostream>
#include <string>
struct is_printable
{
   virtual void get_item(std::ostream& o)const=0;
};
struct A:is_printable
{
  std::string _a;
  A(std::string s):_a{s}{}
  void get_item(std::ostream& o)const
  {
    o<<_a;
  }
};
struct B:is_printable
{
  int _b;
  B(int b):_b{b}{}
  void get_item(std::ostream& o)const
  {
    o<<_b;
  }
};
std::ostream& operator<<(std::ostream& o,const is_printable& other)
{ 
  other.get_item(o);
  return o;
}
int main() {
    A a{"Tekst"};
    B b{123};

    std::cout << "a=" << a << ";\tb=" << b << ";\n";
    is_printable& a_r = a;
  is_printable& b_r = b; 
    std::cout << "a_r=" << a_r << ";\tb_r=" << b_r << ";\n";

  return 0;
}

// a: Tekst; b: 123
// a_r: Tekst b_r: 123