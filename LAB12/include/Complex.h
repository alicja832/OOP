#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

template<typename T,typename U>
class Pair
{
    public:
    T first;
    U second;
    friend std::ostream& operator<<(std::ostream& o,
    const Pair<T,U> pair)
    {
        o<<pair.first<<","<<pair.second;
        return o;
    }
};
template<typename T,typename U>
Pair(T t,U u)->Pair<T,U>;

//class derived
template<typename T,typename U>
class Complex:public Pair<T,U>
{
    public:
    friend std::ostream& operator<<(std::ostream& o,
    const Complex<T,U> complex)
    {
        o<<complex.first;
        complex.second<0. ? o<<"" : o<<"+";
        o<<complex.second<<"i";
        return o;
    }
    Complex<T,U> Conjugate()
    {
        Complex<T,U> tmp{Pair<T,U>::first,-(Pair<T,U>::second)};
        return tmp;
    }

};
template<typename T,typename U>
Complex(T t,U u)->Complex<T,U>;
#endif