#include "../Headers/PerceptronData.h"

PerceptronData::PerceptronData():
        _weight(0.0),
        _value(0.0),
        _name("")
{

}

PerceptronData::PerceptronData(std::string name):
        _weight(0.0),
        _value(0.0),
        _name(name)
{

}

PerceptronData::~PerceptronData()
{

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

std::string PerceptronData::getName (void) const
{
    return _name;
}

void PerceptronData::setName (std::string name)
{
    _name = name;
}

float PerceptronData::getXnWnResult (void) const
{
    return _weight*_value;
}

