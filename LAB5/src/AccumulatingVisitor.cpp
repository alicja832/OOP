#include "AccumulatingVisitor.h"
#include "Data.h"
float AccumulatingVisitor::sum=0;
void AccumulatingVisitor::visit(const FloatData* d)const
    {
        sum+=d->getValue();    
    }
    void AccumulatingVisitor::visit(const IntData* d)const
    {
        
        sum+=static_cast<float>(d->get());
    }
    float AccumulatingVisitor::getTotalSum()
    {
        return sum;
    }