#include <iostream>
#include <deque>
#include <stack>

int main()
{
    std::stack<int> s;
    s.push(10);
    s.push(14);

        std::cout<<s.top()<<std::endl;
        s.pop();
        std::cout<<s.top()<<std::endl;
}