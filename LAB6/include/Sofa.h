#pragma once
#include "Mebel.h"

class Sofa:public virtual Mebel
{
    public:
        Sofa(int a,int b,int c,int d):Mebel(a,b,c),szer_siedziska{d}
        {}
        void out(std::ostream& o)const
        {
            Mebel::out(o);
            o<<" siedzisko "<<szer_siedziska;
        }
        ~Sofa()
        {
            std::cout<<__FUNCTION__<<std::endl;
        }

    private:
       int szer_siedziska;

};