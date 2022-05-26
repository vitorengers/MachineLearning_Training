#ifndef PERCEPTRON_DATA_H
#define PERCEPTRON_DATA_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>

class PerceptronData
{
public:
    PerceptronData(std::string);
    PerceptronData();
    ~PerceptronData();

    std::string getName(void) const;
    void setName (std::string);

    // float getWeight(void) const;
    // void setWeight (float);

    float getWeight(unsigned int) const;
    void setWeight(float, unsigned int);

    float getValue(void) const;
    void setValue(float);

    float getNormalizedValue(void) const;
    void setNormalizedValue(float);

    float getSum(void) const;
    void setSum(float);

    float getSmallDelta(void) const;
    void setSmallDelta(float);


    float getExpected(void) const;
    void setExpected(float);

    float getError(void) const;
    void setError(float);

    // float getXnWnResult(void) const;

    void addNewWeight(void);

    float getXnWnResult(unsigned int) const;


    friend std::ostream& operator<<( std::ostream& os, const PerceptronData& data)
    {
        os << "*--------PERCEPTRON DATA--------*" << std::endl;
        os << "Identifier: " << data.getName() << std::endl;
        os << "Weight: " << data.getWeight(0) << std::endl;
        os << "Value: " << data.getValue() << std::endl;
        os << "Expected: " << data.getExpected() << std::endl;
        os << "*-------------------------------*" << std::endl;
        return os;
    }

private:
    std::string _name;
    float _value;
    float _normalizedValue;
    float _sum;
    float _smallDelta;
    float _expected;
    float _error;
    std::vector<float> _weight;
    std::default_random_engine _generator;
};

#endif