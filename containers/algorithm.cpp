#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

struct D
{
    D(const std::string& element )
    {
        _name=element;
    }
    std::string _name; 
};
int main()
{
    std::vector<D> d;
    d.push_back(std::string("Ala"));//,"Basia","Kasia"};
    d.push_back(std::string("Basia"));
    d.push_back(std::string("Kasia"));
    //działa
    auto i=std::find_if(d.begin(),d.end(),[](D x){return x._name==std::string("Basia");});
    std::cout<<i->_name<<std::endl;
}