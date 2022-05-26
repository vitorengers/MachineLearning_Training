#include "../Headers/PerceptronData.h"

#include <chrono>
#include <random>

PerceptronData::PerceptronData():
        _name(""),
        _value(0.0f),
        _normalizedValue(0.0f),
        _sum(0.0f),
        _smallDelta(0.0f),
        _expected(0),
        _error(0.0f)
{

}

PerceptronData::PerceptronData(std::string name):
        _name(name),
        _value(0.0f),
        _normalizedValue(0.0f),
        _sum(0.0f),
        _smallDelta(0.0f),
        _expected(0),
        _error(0.0f)
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

float PerceptronData::getNormalizedValue(void) const
{
    return _normalizedValue;
}

void PerceptronData::setNormalizedValue (float normalizedValue)
{
    _normalizedValue = normalizedValue;
}

float PerceptronData::getSum(void) const
{
    return _sum;
}

void PerceptronData::setSum (float sum)
{
    _sum = sum;
}


float PerceptronData::getSmallDelta(void) const
{
    return _smallDelta;
}

void PerceptronData::setSmallDelta(float smallDelta)
{
    _smallDelta = smallDelta;
}


float PerceptronData::getExpected (void) const
{
    return _expected;
}

void PerceptronData::setExpected (float expected)
{
    _expected = expected;
}

float PerceptronData::getError (void) const
{
    return _error;
}

void PerceptronData::setError (float error)
{
    _error = error;
}

// float PerceptronData::getXnWnResult (void) const
// {
//     return _weight*_value;
// }

void PerceptronData::addNewWeight(void)
{
    std::uniform_real_distribution<double> distribution(-0.5,0.5);
    _weight.push_back(distribution(_generator));
    // _weight.push_back(1.0f);

}


float PerceptronData::getXnWnResult (unsigned int index) const
{
    return _weight.at(index)*_value;
}



