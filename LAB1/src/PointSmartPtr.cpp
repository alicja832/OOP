#include "PointSmartPtr.h"
#include <string>
#include <iostream>

using namespace std;

string& Named::Name()
    {
        return name;
    }
void operator>>(std::string n,Named& Name)
    {
        Name.name = n;
    }