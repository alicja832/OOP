#pragma once
#include <iostream>
#include "Visitor.h"
class PrintingVisitor:public Visitor
{
    public:
    void visit(const FloatData* d)const override
    {
        std::cout<<d->getValue()<<" ";    
    }
    void visit(const IntData* d)const override
    {
        std::cout<<d->get()<<" ";
    }

};
