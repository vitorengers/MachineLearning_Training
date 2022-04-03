#ifndef PERCEPTRON_DATA_H
#define PERCEPTRON_DATA_H

#pragma once

#include <iostream>
#include <string>


class PerceptronData
{
public:

    

    PerceptronData(std::string);
    PerceptronData();
    ~PerceptronData();

    std::string getName(void) const;
    void setName (std::string);

    float getWeight(void) const;
    void setWeight (float);

    float getValue(void) const;
    void setValue (float);

    float getExpected (void) const;
    void setExpected (float);

    float getXnWnResult(void) const;

    friend std::ostream& operator<<( std::ostream& os, const PerceptronData& data)
    {
        os << "*--------PERCEPTRON DATA--------*" << std::endl;
        os << "Identifier: " << data.getName() << std::endl;
        os << "Weight: " << data.getWeight() << std::endl;
        os << "Value: " << data.getValue() << std::endl;
        os << "Expected: " << data.getExpected() << std::endl;
        os << "*-------------------------------*" << std::endl;
        return os;
    }
    


private:
    std::string _name;
    float _weight;
    float _value;
    float _expected;
};

#endif