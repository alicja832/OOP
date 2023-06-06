#pragma once
#include <iostream>
#include <cmath>

class Ksztalt{
    public:
    Ksztalt()
    {

    }
    Ksztalt(const Ksztalt& other)
    {
        std::cout<<"kkkk";
    }
    virtual void wypisz(std::ostream& a)const
    {

    }
   /* virtual ~Ksztalt()
    {

    }*/
    virtual double polePow()const
    {
        return 0.0;
    }
    //protected:
    int _a,_b,_c,_r;
    
};
class Kwadrat:public Ksztalt
{
    public:
    Kwadrat(int a):_a{a}
    {}
    void wypisz(std::ostream& a)const override{
        a<<"Kwadrat o boku  "<<_a<<std::endl;
    }
    double polePow()const
    {
        return static_cast<double>(_a*_a);    
    }
    ~Kwadrat()
    {

    }
   
};
class Trojkat:public Ksztalt
{
    public:
    Trojkat(int a, int b, int c):_a{a},_b{b},_c{c}
    {

    }
    void wypisz(std::ostream& a)const override{
        a<<"Trojkat o bokach  "<<_a<<" "<<_b<<" "<<_c<<std::endl;
    }
    double polePow()const
    {
        double pol_obw = static_cast<double>(_a+_b+_c)/2.0;
        return sqrt( pol_obw*(pol_obw-_a)*(pol_obw-_b)*(pol_obw-_c) );
    }
    ~Trojkat()
    {

    }
   

};
class Kolo:public Ksztalt
{
    public:
    Kolo(int r):_r{r}
    {

    }
    void wypisz(std::ostream& a)const override{
        a<<"Kolo o promieniu  "<<_r<<std::endl;
    }
    double polePow()const
    {
        return static_cast<double>(_r*_r*3.1415);
    }
    ~Kolo()
    {

    }
    ;
};

//funkcja globalna przyjmująca obiekty klasy ksztalt

void wypisz(const Ksztalt& a)
{
    a.wypisz(std::cout);
}
