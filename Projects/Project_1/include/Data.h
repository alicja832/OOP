#pragma once
#include <string>
#include <iostream>
/**
 * @brief 
 * an abstract class, base for  InData and StringData
 Node for the linked list
 */
 

class Data{
    public:
    /**
     * @brief 
     * procedure which create stream to print
     * @param a 
     */
    virtual void out(std::ostream& a)const=0;
    friend std::ostream& operator<<(std::ostream& o,const Data& k)
    {
        k.out(o);
        return o;
    } 
    /**
     * @brief 
     * function witch create new Data pointer
     * @return Data* 
     */
    virtual Data* mkdir()const=0;
    
    /**
     * @brief Destroy the Data object
     * 
     */
    virtual ~Data(){}
    virtual bool isSame( const Data& x) const = 0;
    //pointer to next node
   // Data *next;
};

class IntData:public Data
{
    public:
    /**
     * @brief Construct a new Int Data object
     * 
     * @param a 
     */
    IntData(int a):_a{a}{}
    /**
     * @brief Construct a new Int Data object
     * copy constructor
     * @param other 
     */
    bool isSame( const Data& x) const
    {
        if(_a==dynamic_cast<const IntData&>(x).get_int())
        {
            return true;
        }
        return false;
    }
    IntData(const IntData& other):IntData(other._a){}
    /**
     * @brief 
     * create new InData pointer
     * @return IntData* 
     */
    IntData* mkdir()const;
    /**
     * @brief 
     * operator to take reference to this
     * @param a 
     * @return IntData& 
     */
    IntData& operator()(int a);
    /**
     * @brief 
     * a is a stream to print InData
     * @param a 
     */
    void out(std::ostream& a)const override;
    /**
     * @brief Destroy the Int Data object
     * 
     */

    ~IntData();
    int get_int()const
    {
        return _a;
    }
    private:
    int _a;
};

class StringData:public Data{
    public:
    /**
     * @brief Construct a new String Data object
     * 
     * @param s 
     */
    StringData(std::string s):_str{s}{}
    /**
     * @brief Construct a new String Data object
     * copy constructor
     * @param other 
     */
    StringData(const StringData& other):StringData(other._str){}
    /**
     * @brief 
     * 
     * @param t 
     * @return const StringData& 
     */
    const StringData& operator()(const char *t);
    /**
     * @brief 
     * create new StringData object
     * @return StringData* 
     */
    StringData* mkdir()const;
    /**
     * @brief 
     * put a sring do stream
     * @param a 
     */
    void out(std::ostream& a)const override;
    /**
     * @brief Destroy the String Data object
     * 
     */
    ~StringData();
    bool isSame( const Data& x) const
    {
      if(_str==dynamic_cast<const StringData&>(x).get_string())
      {
          return true;
      }
      return false;
    }
    std::string get_string()const
    {
        return _str;
    }
    private:
    std::string _str;
  

};
 class FloatData:public Data
{
    public:
    /**
     * @brief Construct a new Int Data object
     * 
     * @param a 
     */
    FloatData(float a):_a{a}{}
    /**
     * @brief Construct a new Int Data object
     * copy constructor
     * @param other 
     */
    FloatData(const FloatData& other):FloatData(other._a){}
    /**
     * @brief 
     * create new InData pointer
     * @return IntData* 
     */
    FloatData* mkdir()const;
    /**
     * @brief 
     * operator to take reference to this
     * @param a 
     * @return IntData& 
     */
    FloatData& operator()(float a);
    /**
     * @brief 
     * a is a stream to print InData
     * @param a 
     */
    void out(std::ostream& a)const override;
    /**
     * @brief Destroy the Int Data object
     * 
     */
     bool isSame( const Data& x) const
{
  if(_a==dynamic_cast<const FloatData&>(x).get_float())
  {
      return true;
  }
  return false;
}
float get_float()const
{
    return _a;
}
    ~FloatData();
    private:
    float _a;
};
//Boolean(false)
class Boolean:public Data
{
    public:
    /**
     * @brief Construct a new Int Data object
     * 
     * @param a 
     */
    Boolean(bool a):_a{a}{}
    /**
     * @brief Construct a new Int Data object
     * copy constructor
     * @param other 
     */
    Boolean(const Boolean& other):Boolean(other._a){}
    /**
     * @brief 
     * create new InData pointer
     * @return IntData* 
     */
    Boolean* mkdir()const;
    /**
     * @brief 
     * operator to take reference to this
     * @param a 
     * @return IntData& 
     */
    Boolean& operator()(bool a);
    /**
     * @brief 
     * a is a stream to print InData
     * @param a 
     */
    void out(std::ostream& a)const override;
    /**
     * @brief Destroy the Int Data object
     * 
     */
     bool isSame( const Data& x) const
{
  if(_a==dynamic_cast<const Boolean&>(x).get_bool())
  {
      return true;
  }
  return false;
}
float get_bool()const
{
    return _a;
}
    ~Boolean();
    private:
    bool _a;
};
class Node
 {
    public:
    Node()
    {}
    Node& operator=(const Node& other)
    {   
        if(&other==this)
            return *this;
        next=other.next;
        return *this;
    }
    Data *wsk;
    Node *next;
 };