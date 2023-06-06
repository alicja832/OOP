#pragma once
#include "Mebel.h"
#include "Sofa.h"
#include "Lozko.h"

class Kanapa:public Lozko,public Sofa
{
    public:
        Kanapa(int a,int b,int c,int d,int e):Sofa{a,b,c,d},Lozko{a,b,c,e},Mebel(a,b,c)
        {}
        void out(std::ostream& o)const
        {
            o<<"jako Mebel ";
            Mebel::out(o);
            o<<std::endl;
            o<<" jako Sofa: ";
            Sofa::out(o);
            o<<std::endl;
            o<<"jako Lozko";
            Lozko::out(o);
        }
        ~Kanapa()
        {
            std::cout<<__FUNCTION__<<std::endl;
        }

    private:
       int szer_spania;

};