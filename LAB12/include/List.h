#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
#include <string>
#include <typeinfo>
/**
 * @brief 
 * class base for node list-for every type
 */
class Node
{
    public:
    Node(){}
    //check types but it has to be template function
    template <typename T> bool isType()const;
    /**
     * @brief 
     * store the information of type of TNode-derived class
     * @tparam Type 
     */
    template <typename Type>void notice();

    Node *next()const;
    virtual ~Node(){};
    Node *next_n;
    std::string type;
    int _value;
};
template <typename T> bool Node::isType()const
    {
        return typeid(T).name()==type;
    }
template <typename Type>void Node::notice()
    {
        type=typeid(Type).name();
    }
 
   
template <typename T> class TNode:public Node
{
    public:
  
    /**
     * @brief Construct a new TNode object
     * 
     * @param value 
     */
    TNode(T value):_value{value}{}
    
    T get()const
    {
        return _value;
    }
    ~TNode(){}
    const std::type_info &typ=typeid(T);
    private:
    T _value;
   
    
    

};
template <typename T> TNode(T t)->TNode<T>;
class List
{
    
    public:
    /**
     * @brief Construct a new List object
     * default constructor
     */
    List()
    {
        head_d=nullptr;
    }
    /**
     * @brief 
     * add new node
     * @tparam T 
     * @param value 
     */
    template<typename T>void add(T value);
    /**
     * @brief 
     * returns head of list
     * @return Node* 
     */
    Node *head()const
    {
        return head_d;
    }
    /**
     * @brief 
     * I don't know what this function has to do (XD)
     * @tparam T 
     * @param elem 
     * @return T 
     */
     
    template<typename T=double>static T get(Node *elem);
   
    ~List();
    private:
    Node *head_d;
};

template<typename T>T List::get(Node *elem)
{
    TNode<T> *tmp=dynamic_cast<TNode<T>*>(elem);
    return tmp->get();
}


template<typename T>void List::add(T value)
{
    //the head is the base of TNode<T>
    Node *new_node=new TNode(value);
    //notice which type it is
    new_node->notice<T>();
    //add to list
    new_node->next_n=head_d;
    head_d=new_node;
}

#endif