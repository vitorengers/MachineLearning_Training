#ifndef Perceptron_H
#define Perceptron_H

#pragma once

#include <iostream>
#include <memory>

#include "Node.h"
#include "Graph.h"
#include "../Config/Types.h"

class Perceptron
{
public:
    // virtual Perceptron(unsigned int inputsNumber, unsigned int neuronNumber);
     Perceptron();
    ~Perceptron();

    void createPerceptron(unsigned int inputsNumber,  std::vector<unsigned int> neuronsNumberVector, unsigned int bias = 1);
    void debugPerceptron();


public:

private:
    Graph<var_type> _perceptronGraph;


private:

};

#endif