#ifndef _PUNKT_H_
#define _PUNKT_H_

#include <string>
#include <iostream>

class Punkt
{
    public:
        Punkt(const std::string& i,int x, int y):_i{i},_x{x},_y{y}
        {}
        //friend void swap(Punkt& a,Punkt& b);
        friend std::ostream& operator<<(std::ostream& o,Punkt& other);
        template<int T>int wsp()
        {
            return T==0 ? _x : _y;
        }
        bool operator<(Punkt& rhs)
        {
            return _x == rhs._x ? _y < rhs._y : _x < rhs._x;
        }
        // Dwa obiekty kl. Punkt mozna porównywać <. Najpierw porównywane są 
        // wsp. x a wsp. y tylko gdy x-owe sa rowne:
        // return x == rhs.x ? y < rhs.y : x < rhs.x
        template<typename T>static T min(T a,T b)
        {
            return a<b ? a : b;
        }
        Punkt& operator=(Punkt& other)
        {
            if(this==&other)
                return *this;
            _x=other._x;
            _y=other._y;
            return *this;
        }
    private:
        std::string _i;
        int _x;
        int _y;     
};
std::ostream& operator<<(std::ostream& o,Punkt& other)
{
    o<<other._i<<"("<<other._x<<","<<other._y<<")";
    return o;
}
template<typename T>void swap(T& a, T& b)
{
    T aptr=a;
    a=b;
    b=aptr;

}
template<typename T>void swap(Punkt& a, Punkt& b)
{
    std::cout<<"ta f";
    T aptr=a;
    a=b;
    b=aptr;

}

#endif