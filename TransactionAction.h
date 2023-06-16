#ifndef _TRANSACTIONACTION_H_
#define _TRANSACTIONACTION_H_
#include <cstddef>
#include <iostream>

namespace Transaction
{
/**
 * @brief 
 * an abstract type, base for other actions during Transaction
 */
class UndoAction{

    public:

        virtual void Init()=0;
        virtual void Ok()=0;
        virtual void Fail()=0;
        virtual void Set_oryginal(){};
};

template<typename T> class KeepValue:public UndoAction
{
    public:
        /**
         * @brief Construct a new Keep Value object
         * place is a pointer to orginal value
         * @param value 
         */
        KeepValue(T& value):_value{value},place{&value}
        {}
        /**
         * @brief 
         * if the transaction is broken we change the value of place to oryginal value
         */
        void Set_oryginal()override;
        void Init(){}
        void Ok(){}
        void Fail(){}
    private:
        T _value;
        T *place;

};
template<typename T> void KeepValue<T>::Set_oryginal()
{
    *place=_value;
}

/**
 * @brief 
 * CAD Dictionary,helps that KeepValue may be for different types
 * @tparam T 
 */
 
template<typename T>KeepValue(T)->KeepValue<T>;
/**
 * @brief 
 * special class for Int values
 */
class KeepInt:public KeepValue<int>
{
    public:
        KeepInt(int& a):KeepValue(a){}
        void Init(){}
        void Ok(){}
        void Fail(){}
};
class AccountState{
    public:
        /**
        * @brief Construct a new Account State object
        * takes 
        * @param m 
        */
        AccountState(UndoAction *undo);
        /**
         * @brief Destroy the Account State object
         * 
         */
        ~AccountState();
        /**
         * @brief 
         * In this function set the transaction is ok,not broken
         */
        static void AllOk();
    private:
        //the base of information about account
        UndoAction *_msg;
        //information that transaction was ok or not
        static bool ok;
};
};

#endif