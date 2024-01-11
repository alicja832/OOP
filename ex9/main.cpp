#include <iostream>
//tu sprawdzamy kolejność wywoływania się konstruktorów
struct BB
{
    BB()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};
template<typename T>struct AA
{
    AA()
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
    AA(T x):x{x}
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
    using type_A=T;
    T x;
};
/*Virtual będzie pierwsze!!*/
struct A: private AA<int>,virtual BB
{
    using AA<int>::type_A;
    A(int value):AA{4},_value{value}
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
    A operator++(int)
    {
        A tmp=A(_value);//copy elision
        _value+=type_A(1.0);
        return tmp;
    }
    A operator--(int)
    {
        A tmp=A(_value);//copy elision
        _value--;
        return tmp;
    }
    static void* operator new(std::size_t t)
    {
        void *x=malloc(t);
        std::cout<<"op_new"<<std::endl;
        return x;
    }
    int _value;
};
int main()
{
    using value_type=A*;
    value_type x=new A{2};
    A a{2};

    std::cout<<a++._value<<std::endl;
    std::cout<<a--._value<<std::endl;

    int s=0;
    std::cout<<s++<<std::endl;
    s=5;
    std::cout<<s--<<std::endl;
    delete x;

    //jest to możliwe, ponieważ klasę AA dziedziczymy publicznie,
    // gdyby było dziedziczone private to nie skompilowałoby się
    A::type_A k=2;
    

}