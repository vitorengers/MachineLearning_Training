#include "../Headers/SingleLayerPerceptron.h"


SingleLayerPerceptron::SingleLayerPerceptron()
{
    Perceptron();
}

SingleLayerPerceptron::~SingleLayerPerceptron()
{

}
void SingleLayerPerceptron::createSingleLayerPerceptron(unsigned int inputsNumber,  unsigned int outputsNumber)
{
    Perceptron::createPerceptron2(inputsNumber, std::vector<unsigned int> (), outputsNumber);
}