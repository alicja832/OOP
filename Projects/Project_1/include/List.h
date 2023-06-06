#pragma once
#include "Data.h"
#include <iostream>
#include <vector>

class List{
public:
/**
 * @brief Construct a new List object
 * 
 */
    List()
    {
        head=nullptr;
    }
    /**
     * @brief Construct a new List object
     * copy constructor
     * @param other 
     */
    List(const List& other);
    /**
     * @brief 
     * if it is in list it return pointer to data
     * @param tmp 
     * @return * Data 
     */
    Data* clone_if_exists(const Data& tmp)const;
    /**
     * @brief 
     * function return this elements which are numeric
     * @return List& 
     */
    List numeric()const;
    List non_numeric()const;
    /**
     * @brief 
     * insert Data to linked list
     * @param d 
     * @param w 
     * @return List& 
     */
    List& insert(const Data& d,int where=0);
    //znajdowanie elementu
    bool find(const Data& d)const;
   
    List& operator<<(List& l);
    void exchange()
    {
        head=nullptr;
    }
    /**
 * @brief 
 * prints List 
 */
    void print()const;
    /**
     * @brief Destroy the List object
     * 
     */
    ~List(); 
enum where{Begin=1,End=0};
private:
    //procedure to reverse list
    void reverse();
    //dodawanie listy
     void add_list(List& l);
    //head of the linked list
    Node *head;
    
};