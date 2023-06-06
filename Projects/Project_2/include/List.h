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
   	 //check types of nodes
    	template <typename T> bool isType()const;
    	/**
     	* @brief 
     	* store the information of type of TNode-derived class
     	* @tparam Type 
     	*/
    	template <typename Type>void notice();
	//function get next node in the list
    	Node *next()const;
	//virtual desctructor
    	virtual ~Node(){};
    	Node *next_n;
	private:
    	std::string type;
};
template <typename T> bool Node::isType()const
    {
        return typeid(T).name()==type;
    }
    template <typename Type>void Node::notice()
    {
        type=typeid(Type).name();
    }
 
//template function -store data in TNode,element of the list   
template <typename T> class TNode:public Node
{
    public:
  
    /**
     * @brief Construct a new TNode object
     * 
     * @param value 
     */
    TNode(T value):_value{value}{}
    //return data from TNode
    T get()const
    {
        return _value;
    }
    ~TNode(){}
    private:
    T _value;
   
    
    

};
//slownik dedukcji typow CTAD
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
     * return data store in parameter of function
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
    Node *new_node=new TNode<T>(value);
    //notice which type it is
    new_node->notice<T>();
    //add to list
    new_node->next_n=head_d;
    head_d=new_node;
}

#endif
