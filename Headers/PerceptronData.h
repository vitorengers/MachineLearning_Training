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

    float getWeight(void) const;
    void setWeight (float weigth);

    float getValue(void) const;
    void setValue (float value);

    std::string getName(void) const;
    void setName (std::string name);

    float getXnWnResult(void) const;

    friend std::ostream& operator<<( std::ostream& os, const PerceptronData& data)
    {
        os << "*--------PERCEPTRON DATA--------*" << std::endl;
        os << "Identifier: " << data.getName() << std::endl;
        os << "Weight: " << data.getWeight() << std::endl;
        os << "Value: " << data.getValue() << std::endl;
        os << "*-------------------------------*" << std::endl;
        return os;
    }
    


private:
    float _weight;
    float _value;
    std::string _name;
};

#endif