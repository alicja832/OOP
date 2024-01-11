#include <deque>
#include <iostream>

int main()
{
    using type=std::deque<double>;
    using it=type::iterator;

    type a;
    a.push_back(4);
    a.push_front(8);

    it i=a.begin();
    std::cout<<*i<<std::endl;
}