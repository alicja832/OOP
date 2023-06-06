#pragma once
#include "Mebel.h"

class Lozko:public virtual Mebel
{
    public:
        Lozko(int a,int b,int c,int d):Mebel(a,b,c),szer_spania{d}
        {}
        void out(std::ostream& o)const
        {
            Mebel::out(o);
            o<<" sz.spania "<<szer_spania;
        }
        ~Lozko()
        {
            std::cout<<__FUNCTION__<<std::endl;
        }

    private:
       int szer_spania;

};