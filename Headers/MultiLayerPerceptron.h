#ifndef MULTILAYERPERCEPTRON_H
#define MULTILAYERPERCEPTRON_H

#pragma once

#include "Perceptron.h"

class MultiLayerPerceptron: public Perceptron
{
public:
    MultiLayerPerceptron();
    ~MultiLayerPerceptron();
    void createMultiLayerPerceptron(unsigned int inputsNumber,  std::vector<unsigned int> hiddenLayersNumber, unsigned int outputsNumber);

private:

};

#endif