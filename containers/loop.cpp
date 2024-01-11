#include <list>
#include <iostream>

class A
{
    public:
        using T=std::list<int>;
        T& items()
        {
            container.push_back(2);
            container.push_back(3);
            container.push_back(10);
            return container;
        }
        T container;
};

int main()
{
    A thing=A();
    for(auto& i:thing.items())
        std::cout<<i<<std::endl;

    typedef decltype(thing.container)::value_type n_type;
    n_type n=3;
}