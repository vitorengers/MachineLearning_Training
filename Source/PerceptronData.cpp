#include "../Headers/PerceptronData.h"

PerceptronData::PerceptronData():
        _name(""),
        _weight(0.0),
        _value(0.0),
        _expected(0)
{

}

PerceptronData::PerceptronData(std::string name):
        _name(name),
        _weight(0.0),
        _value(0.0),
        _expected(0)
{

}

PerceptronData::~PerceptronData()
{

}

std::string PerceptronData::getName (void) const
{
    return _name;
}

void PerceptronData::setName (std::string name)
{
    _name = name;
}

float PerceptronData::getWeight (void) const
{
    return _weight;
}

void PerceptronData::setWeight (float weigth)
{
    _weight = weigth;
}

float PerceptronData::getValue (void) const
{
    return _value;
}

void PerceptronData::setValue (float value)
{
    _value = value;
}

float PerceptronData::getExpected (void) const
{
    return _expected;
}

void PerceptronData::setExpected (float expected)
{
    _expected = expected;
}

float PerceptronData::getXnWnResult (void) const
{
    return _weight*_value;
}

