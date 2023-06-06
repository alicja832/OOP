#pragma once
#include <iostream>
#include <vector>
#include "Visitor.h"
class AccumulatingVisitor:public Visitor
{
    public:
    void visit(const FloatData* d)const override;
    void visit(const IntData* d)const override;
    float getTotalSum();
    private:
    static float sum;

};
