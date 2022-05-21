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
    void createPerceptron2(unsigned int inputsNumber,  std::vector<unsigned int> hiddenLayersNumber, unsigned int outputsNumber);

    void debugPerceptron();
    void setInputsAndExpected(std::vector<float> input, std::vector<float> expected);
    void executeOneIteraction(std::vector<unsigned int> input);
    void executeOneIteraction2(void);
    void getResult(std::vector<unsigned int> input);
public:

private:
    Graph<var_type> _perceptronGraph;


private:

};

#endif