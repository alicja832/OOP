#pragma once
#include <iostream>

class Mebel
{
    public:
        Mebel(int width,int hight, int length):_width{width},
        _hight{hight},_length{length}
        {}
        virtual ~Mebel()
        {
            std::cout<<__FUNCTION__<<std::endl;
        }
        friend std::ostream& operator<<(std::ostream& o, const Mebel& m)
        {
            m.out(o);
            return o;
        } 
        virtual void out(std::ostream& o)const
        {
            o<<"szer: "<<_width<<" wys: "<<_hight<<" dl: "<<_length;
        }

    private:
        int _width,_hight,_length;

};
