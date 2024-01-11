#include <set>
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::set<int> s;
    s.insert(2);
    s.insert(1);
    s.insert(10);
    for(auto& i:s)
        std::cout<<i<<"\n";//in ascending order
    auto fun=[]<typename T>(T x){std::cout<<x<<"\n";};
    for(auto& i:s)
        fun(i);//in ascending order
    //auto glambda = []<class T>(T a, auto&& b) { return a < b; };
    //później jeszcze map
    std::map<int,std::string> m={{1,"Pierwszy"}};
    m.insert({3,"Nowy"});
    m.insert({4,"Stary"});
    m.insert({10,"Dziesiąty"});
    //m.insert({3,"Nowynn"});
    for (auto& [key,value]:m)//nie wypisuje pierwszego xxd
        std::cout<<key<<":"<<value<<"\n";
    auto finder=m.find(10);
    std::cout<<finder->first<<std::endl;
    std::cout<<finder->second<<std::endl;
        
}