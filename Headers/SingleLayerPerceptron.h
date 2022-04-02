#ifndef SINGLE_LAYER_PERCEPTRON_H
#define SINGLE_LAYER_PERCEPTRON_H

#pragma once

#include "Perceptron.h"

class SingleLayerPerceptron: public Perceptron
{
public:
    SingleLayerPerceptron();
    ~SingleLayerPerceptron();
    void createSingleLayerPerceptron(unsigned int inputsNumber,  unsigned int neuronsNumber, int bias);


private:
    // void SingleLayerPerceptron::createPerceptron(unsigned int inputsNumber,  unsigned int neuronsNumber, int bias) override;


};

#endif