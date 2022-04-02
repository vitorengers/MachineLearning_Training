#include "../Headers/SingleLayerPerceptron.h"


SingleLayerPerceptron::SingleLayerPerceptron()
{
    Perceptron();
}

SingleLayerPerceptron::~SingleLayerPerceptron()
{

}
void SingleLayerPerceptron::createSingleLayerPerceptron(unsigned int inputsNumber,  unsigned int neuronsNumber, int bias)
{
    std::vector <unsigned int> n;
    n.push_back(neuronsNumber);

    Perceptron::createPerceptron(inputsNumber, n, bias);
}










// //private methods
// void SingleLayerPerceptron::createPerceptron(unsigned int inputsNumber,  unsigned int neuronsNumber, int bias) 
// {
//     Perceptron::createPerceptron(inputsNumber, 1, bias);
// }
