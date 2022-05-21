#include "../Headers/MultiLayerPerceptron.h"

MultiLayerPerceptron::MultiLayerPerceptron()
{

}

MultiLayerPerceptron::~MultiLayerPerceptron()
{

}


void MultiLayerPerceptron::createMultiLayerPerceptron(unsigned int inputsNumber,  std::vector<unsigned int> hiddenLayersNumber, unsigned int outputsNumber)
{
        Perceptron::createPerceptron2(inputsNumber, hiddenLayersNumber, outputsNumber);
}
