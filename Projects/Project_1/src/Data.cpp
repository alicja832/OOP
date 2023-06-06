#include "Data.h"
IntData* IntData::mkdir()const
    {
        IntData* data=new IntData(*this);
        return data;

    }
IntData& IntData::operator()(int a)
    {
        _a=a;
        return *this;
    }
void IntData::out(std::ostream& a)const
    {
        a<<_a;
    }
IntData::~IntData()
    {
        //std::cout<<__FUNCTION__<<"()"<<std::endl;
    }
const StringData& StringData::operator()(const char *t)
    {
        _str=t;
        return *this;
    }
StringData* StringData::mkdir()const
    {
        StringData *data=new StringData(*this);
        return data;
    }
void StringData::out(std::ostream& a)const
    {
        a<<"\""<<_str<<"\"";
    }
StringData::~StringData()
    {
        //std::cout<<__FUNCTION__<<"()"<<std::endl;
    }
FloatData* FloatData::mkdir()const
   {
       FloatData* data=new FloatData(*this);
       return data;
   }
FloatData& FloatData::operator()(float a)
   {
       _a=a;
       return *this;
   }
void FloatData::out(std::ostream& a)const
   {
       a<<_a;
   }
FloatData::~FloatData()
   {
       //std::cout<<__FUNCTION__<<"()"<<std::endl;
   }
Boolean* Boolean::mkdir()const
   {
       Boolean* data=new Boolean(*this);
       return data;
   }
Boolean& Boolean::operator()(bool a)
   {
       _a=a;
       return *this;
   }
void Boolean::out(std::ostream& a)const
   {
        std::string l;
       _a? l="true":l="false";
        a<<l;
   }
Boolean::~Boolean()
   {
       //std::cout<<__FUNCTION__<<"()"<<std::endl;
   }



   