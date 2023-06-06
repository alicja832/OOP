#ifndef _RATIONAL_H_
#define _RATIONAL_H_
#include <iostream>

/**
 * @brief 
 template class-
 * an aggregate contains two numeric values
 * @tparam T 
 * @tparam U 
 */
template<typename T,typename U>class Pair
{
    public:
    T first;
    U second;
    /**
     * @brief 
     * opeartor <<
     to print values
     * @param o 
     * @param pair 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& o,const Pair& pair)
    {
        o<<pair.first<<","<<pair.second;
        return o;
    }

};
/**
 * @brief 
 * CTAD dictionary
 * @tparam T 
 * @tparam U 
 */
template<typename T,typename U>
Pair(T t,U u)->Pair<T,U>;

/**
 * @brief 
 * template class-an aggregate derived from Pair
 * @tparam T1 
 */
template<typename T1>class Rational
:public Pair<T1,T1>
{
    public:
    /**
     * @brief 
     * operator << to print values
     * @param o 
     * @param rational 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& o,const Rational& rational)
    {
        o<<rational.first<<"/"<<rational.second;
        return o;
    }
    /**
     * @brief 
     * conversion operator
     * @return double 
     */
    explicit operator double()const
    {
        return static_cast<double>(this->first)/static_cast<double>(this->second);
    }
    /**
     * @brief 
     * returns new object with change values-first=second,second=first
     * @return Rational<T1> 
     */
    Rational<T1> Inverse()
    {
        Rational tmp{this->second,this->first};
        return tmp;
    }
    

};
/**
 * @brief 
 * CTAD dictionary
 * @tparam T 
 * @tparam U 
 */
template<typename T,typename U>
Rational(T t,U u)->Rational<T>;

#endif