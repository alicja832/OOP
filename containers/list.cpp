#include <list>
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <algorithm>
#include <array>
template<typename T,template<typename U=T,typename Allocator=std::allocator<U>>
class Two>
class Contener
{
    public:
    //constructor with parameters
    Contener(const std::string s):_name{s}{}
    //function which adds items to container
    void add(T thing)
    {
        contener.push_back(thing);
    }
    using type=T;
    using cont_type=Two<T>;

    cont_type operator*()const
    {
        return contener;
    }

    type& operator[](unsigned i)
    {
        unsigned count=0;
        for(auto& j:contener)
        {
            if(count==i)
                return j;
            count++;
        }
        return *(contener.begin());
    }

    std::string& operator()()
    {
        return _name;
    }

    private:
    Two<T> contener;
    std::string _name;
};

int main()
{
    Contener<int,std::list> X("List");
    X.add(1);
    auto element=*X;
    std::cout<<X()<<std::endl;
    std::cout<<X[0]<<std::endl;

    Contener<double,std::vector> Y("Vector");
    Y.add(2.3);
    auto element_two=*Y;
    std::cout<<Y()<<std::endl;
    std::cout<<Y[0]<<std::endl;
    //przyklad funkcji
    std::list<int> x;
    x.push_back(2);
    x.push_back(3);
    for_each(x.begin(),x.end(),[](int& x){std::cout<<x<<std::endl;});
}
/* 
List
1
Vector
2.3
 */