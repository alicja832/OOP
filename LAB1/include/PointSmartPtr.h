#pragma once
#include <string>
#include <iostream>
#include <vector>
//i jest potrzebne aby nie usuwać dwa razy pointera ktory bedzie
//wskazywac na tego samego point'a
 
class Named
{   
    public:
        Named(std::string n = "None"):name{n}
        {

        }
        const std::string& Name()const
        {
            return name;
        }
        friend void operator>>(std::string n,Named& Name)
        {
            Name.name = n;
        }

    private:
        std::string name;
};

class Point:public Named
{
    public:
    Point(double x=0.0,double y=0.0,std::string n = "None"):_x{x},_y{y},Named(n)
    {}
    friend std::ostream& operator<<(std::ostream& o, const Point& K)
    {
        o<<K.Name()<<" ["<<K._x<<","<<K._y<<"]";
        return o;
    }
    Point operator++(int)
    {
        Point tmp = *this;
        _x=_x+1.0;
        _y=_y+1.0;
        return tmp;
    }
    private:
        double _x,_y;
};

class PointSmartPtr
{
    public:
        PointSmartPtr()
        {
        }
        PointSmartPtr(Point* p):ptr(new Point)
        {
          (*i)++;
          ptr = p;
          vec.push_back(ptr);
        }
        const PointSmartPtr& operator=(PointSmartPtr& K)
        {   
            if(&K == this)
                return *this;
            //ptr = new Point;
            ptr = K.ptr;
            vec.push_back(ptr);
            *ptr = *(K.ptr);
             (*i)=*(K.i);
            return *this;

        }
        Point& operator*()const
        {
            return *ptr;
        }
        void realise()
        {
            if((*i)>=0 && vec[*i])
            {
                delete vec[*i];
                vec[*i] = nullptr;
            }
            else if((*i) < 0 && i)
            {
                delete i;
                i = nullptr;
            }
            (*i)--;
        }
        ~ PointSmartPtr()
        {
            realise();
        }
    private:
        Point *ptr;
        std::vector<Point*> vec;
        static int *i;

};
int* PointSmartPtr::i = new int;
