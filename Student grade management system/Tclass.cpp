#include "Tclass.h"

Tclass::Tclass(const string & a, const string & b, const int & c):major(a),teach_class(b),year(c)
{
}

Tclass::Tclass(const Tclass & p) :major(p.major),teach_class(p.teach_class),year(p.year)
{
}

Tclass::~Tclass()
{
}
