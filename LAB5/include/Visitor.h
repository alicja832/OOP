#pragma once
class FloatData;
class IntData;
class Visitor
{
    public:
    virtual void visit(const FloatData *d)const=0;
    virtual void visit(const IntData* d)const=0;
    virtual ~Visitor(){}
};