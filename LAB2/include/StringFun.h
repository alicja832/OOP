#pragma once
#include <string>
#include <vector>
class Less
{
    public:
    Less()
    {

    }
    bool operator()(std::string& a, std::string& b)const
    {
        return a<b;
    }
};
class Greater
{
    public:
    Greater()
    {

    }
    bool operator()(std::string& a, std::string& b)const
    {
        return a>b;
    }
};
class Length
{
    public:
    Length()
    {

    }
    bool operator()(std::string& a, std::string& b)const
    {
        return a.size()<b.size();
    }
};

    void PrintNames(std::vector<std::string> &v)
    {

        for(int i=0;i<v.size();i++)
        {
            std::cout << v[i] <<" ";
        }
        std::cout<<std::endl;
        std::cout<<std::endl;
    }
   