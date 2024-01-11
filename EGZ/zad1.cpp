#include <algorithm>
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> v={1,2,3,4,5,6};
    std::for_each(v.begin(),v.end(),[](int& i){std::cout<<i<<" ";});
    std::cout<<"\n";
    std::for_each(v.begin(),v.end(),[](int& i){
        if(!(i%2))
            std::cout<<i<<" ";});
    std::cout<<"\n";
    std::sort(v.begin(),v.end(),[](int &a,int &b){return a>b;});
    std::for_each(v.begin(),v.end(),[](int& i){std::cout<<"["<<i<<"]";});
    std::cout<<"\n";
    int x=5;
    //tak powinno być
    auto g=[x](int& i){i+=x;};
    std::for_each(v.begin(),v.end(),g);
    std::for_each(v.begin(),v.end(),[](int& i){std::cout<<i<<" ";});
    std::cout<<"\n";
    //nie trzeba mutable, ponieważ przechwytujemy element x przez referencję, nie przez wartość
    auto f=[&x](int i){x+=i; return x; };
    std::cout<<f(6)<<std::endl;
    std::cout<<x<<std::endl;
}