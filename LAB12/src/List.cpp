#include "List.h"
List::~List()
{
    Node *tmp=head_d;
    while(head_d)
    {
        tmp=head_d->next_n;
        delete head_d;
        head_d=tmp;
    }
}
Node* Node::next()const
{
    return next_n;
}