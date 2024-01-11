#include <utility>
#include <iostream>

template<typename T=float>
struct Type_t
{
    /// można było bez niczego xxd 
    explicit Type_t(T x):_v(x){}
    //tego nie dałam!! BŁĄD
    Type_t()=default;
    T _v;

};
template<typename U>
struct ptr
{
    using value_type=U;
  
    explicit ptr(U *ptr):p{ptr}{}
    
    ptr(){p=nullptr;}
  
    ptr(ptr<U>&& other):ptr(std::move(other.p)){}
  
    ptr<U>& operator=(ptr<U>&& other)
    {
        //tutaj nie zwróciłam *this-tragedia
        p=std::move(other.p);
        return *this;
    }
    //to bylo dobrze
    U& operator*()const
    {
        return *p;
    }
    //to też było źle
    U* operator->()const
    {
        return p;
    }
    private:
    U* p;
};
using Float_t=Type_t<>;
template<typename T>
std::ostream& operator <<(std::ostream& o,const Type_t<T>& el)
{
    o<<el._v;
    return o;
}

/* Uzupelnij 1 */

// Type_t to opakowywacz

int main()
{
    using Float_t = Type_t<>;
    using Test_t = ptr<std::pair<Float_t, Float_t>>;

    Test_t t1{new Test_t::value_type{}};
    // Test_t t2 = t1;                            // BLAD KOMPILACJI
    // Test_t t3; t3 = t1;                        // BLAD KOMPILACJI
    // Test_t t4 = new Test_t::value_type();    // BLAD KOMPILACJI

    (*t1).first = Test_t::value_type::first_type{1};
    t1->second = Test_t::value_type::second_type{3.141};

    Test_t t2;
    t2 = std::move(t1);
    std::cout << (*t2).first << ", " << t2->second._v << "\n";

    const Test_t t3 = std::move(t2);
    // (*t3).first = 13;       //  BLAD KOMPILACJI
    // t3->second = 13;        //  BLAD KOMPILACJI

    std::cout << (*t3).first._v << ", " << t3->second << "\n";
}
/* output:
1, 3.141
1, 3.141
*/
