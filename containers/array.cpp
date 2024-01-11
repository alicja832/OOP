#include <array>
#include <cstdlib>
#include <algorithm>
#include <iostream>

int main()
{
    std::array<int,3> a;

    auto fun=[](int& t){t=rand()%10;};
    std::for_each(a.begin(),a.end(),fun);    
    
    //check if autput is great
    for(auto& i:a)
        std::cout<<i<<";";
    int& x=a[0];
    int& y=a[1];
    std::swap(x,y);
    for(auto& i:a)
        std::cout<<i<<";";
}