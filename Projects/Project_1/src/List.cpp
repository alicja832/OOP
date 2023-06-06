#include "List.h"

List::List(const List& other)
    {
        head=new Node;
        //Node *tmp=new Node;
        Node *tmp=other.head;
        //creating a pointer with the same data
        head->wsk=other.head->wsk->mkdir();
        //pointer to "walk" in new List
        Node *tmp_two=head;
        tmp=tmp->next;
        while(tmp)
        {
            tmp_two->next=new Node;
            tmp_two->next->wsk=tmp->wsk->mkdir();
            tmp=tmp->next;
            tmp_two=tmp_two->next;

        }
        tmp_two=nullptr;
        
    }
bool List::find(const Data& d)const
{
   /*  try {
   ... dynamic_cast<...>(...)
   return ...
 } catch(std::bad_cast) {
   return false; // w kontekście zadania
 }*/
 Node *tmp=head;
 while(tmp)
 {
    if(typeid(d)==typeid(*(tmp->wsk)))
        if(tmp->wsk->isSame(d))
            return true;
    tmp=tmp->next;
 }
    
    return false;
}
Data* List::clone_if_exists(const Data& d)const
{
    Node *tmp=head;
 while(tmp)
 {
    if(typeid(d)==typeid(*(tmp->wsk)))
        if(tmp->wsk->isSame(d))
            return tmp->wsk->mkdir();
    tmp=tmp->next;
 }
    
    return nullptr;
} 
List List::numeric()const
{
    List t=List();
     Node *tmp=head;
 while(tmp)
 {
    if(typeid(IntData)==typeid(*(tmp->wsk)))
        t.insert(*(tmp->wsk->mkdir()));
    tmp=tmp->next;
 }
 return t;
    
}
List List::non_numeric()const
{
    List t=List();
    Node *tmp=head;
 while(tmp)
 {
    if(!(typeid(IntData)==typeid(*(tmp->wsk))))
        t.insert(*(tmp->wsk->mkdir()));
    tmp=tmp->next;
 }
 return t;
}
List& List::insert(const Data& d,int where)
    {
        //new pointer with the same data
        Node *tmp=new Node;
        tmp->wsk=d.mkdir();
       if (!(head))
        {
            head=tmp;
            (head)->next=nullptr;
            return *this;
        }
        //put to begin
        if(where==1)
        {
            tmp->next=head;
           ( head)=tmp;
        }
        //put to end 
        else{
            

            Node *t=head;
            while(head->next)
            {
                head=head->next;
            }
            head->next=tmp;
            tmp->next=nullptr;
            head=t;
        }
        
        return *this;
    }
void List::print()const
{
    //check if the list is not empty
    if(!head)
        return;
    Node *tmp=head;
    std::cout<<"[";
    while(tmp->next)
        {
            tmp->wsk->out(std::cout);
            std::cout<<",";
            tmp=tmp->next;
        }
        tmp->wsk->out(std::cout);
        std::cout<<"]"<<std::endl;
            
}
//operator << konkatenacja
  List& List::operator<<(List& l)
  {
      if(&l==this)
          return *this;
      this->add_list(l);
      //l.exchange();
      return *this;
  }
  
//reverse list
void List::reverse()
{
    if(!head) return;
    Node *current=head;
    Node *prev=nullptr;
    Node *next2=nullptr;
    while(current)
    {
        next2=current->next;
        current->next=prev;
        prev=current;
        current=next2;

    }
    head=prev;
    
}
void List::add_list(List& l)
{
    Node *tmp=head;
    Node *tmp2=l.head;
    while(tmp->next)
    {
        tmp=tmp->next;
    }
    
    
        tmp->next=tmp2;
        tmp=tmp->next;
        tmp->next=tmp2->next;
        tmp2=tmp2->next;
        tmp->next->next->next->next->next=nullptr;
    //l.head=nullptr;
    //tmp->next->next=nullptr;
    //l.get_head()=nullptr;
    //delete tmp2;
}
List::~List()
{
    //this->reverse();
    Node *tmp;
    while(head)
    {
        tmp=head->next;

        delete head->wsk;
        delete head;
        head=tmp;

    }
        
}