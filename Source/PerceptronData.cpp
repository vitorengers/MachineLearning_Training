#include "../Headers/PerceptronData.h"

PerceptronData::PerceptronData():
        _name(""),
        _value(0.0f),
        _expected(0)
{

}

PerceptronData::PerceptronData(std::string name):
        _name(name),
        _value(0.0f),
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

// float PerceptronData::getWeight (void) const
// {
//     return _weight;
// }

// void PerceptronData::setWeight (float weigth)
// {
//     _weight = weigth;
// }

float PerceptronData::getWeight(unsigned int index) const
{
    float retval = -1;

    if (index < _weight.size())
    {
        retval = _weight.at(index);
    }

    return retval;
}

void PerceptronData::setWeight (float weigth, unsigned int index)
{
    if (index < _weight.size())
    {
        _weight.at(index) = weigth;
    }
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

// float PerceptronData::getXnWnResult (void) const
// {
//     return _weight*_value;
// }

void PerceptronData::addNewWeight(void)
{
    _weight.push_back(1.00f);
}


float PerceptronData::getXnWnResult (unsigned int index) const
{
    return _weight.at(index)*_value;
}



