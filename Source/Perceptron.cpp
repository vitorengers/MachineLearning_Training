#include "../Headers/Perceptron.h"

// Perceptron::Perceptron(unsigned int inputsNumber, unsigned int neuronNumber)
// {

// }

Perceptron::Perceptron()
{

}

Perceptron::~Perceptron()
{

}


void Perceptron::createPerceptron(unsigned int inputsNumber,  std::vector<unsigned int> neuronsNumberVector, unsigned int bias)
{

    //for now its only single layer
    unsigned int numberOfLayers = neuronsNumberVector.size();
    unsigned int neuronsNumber = neuronsNumberVector.at(0);

    _perceptronGraph.addFirstNode("Feedback");

    std::shared_ptr<Node<var_type>> holdFirstNode = _perceptronGraph.getCurrent();

    for (unsigned int n = 0; n < neuronsNumber; n++)
    {
        std::shared_ptr<Node<var_type>> neuron = std::make_shared<Node<var_type>>("Neuron");

        if (n == 0) //will create the first neuron
        {

            for (unsigned int i = 0; i < inputsNumber; i++)
            {

                // addNextNode(11 + i);
                _perceptronGraph.addNextNode("Input");

                _perceptronGraph.nextNode(i);
                _perceptronGraph.addNextNode(neuron);

                if (i == 0)
                {
                    _perceptronGraph.nextNode(n);
                    _perceptronGraph.addNextNode(holdFirstNode);
                    _perceptronGraph.prevNode(i);
                }

                _perceptronGraph.prevNode(0);
            }
        }
        else    //for the other neuron. Shoudnt create another inputs to point to new neurons
        {

            for (unsigned int i = 0; i < inputsNumber; i++)
            {

                _perceptronGraph.nextNode(i);
                _perceptronGraph.addNextNode(neuron);

                if (i == 0)
                {

                    _perceptronGraph.nextNode(n);
                    _perceptronGraph.addNextNode(holdFirstNode);
                    _perceptronGraph.prevNode(i);
                }

                _perceptronGraph.prevNode(0);
            }
        }
    }
}


void Perceptron::debugPerceptron()
{
    std::cout << "Inputs" << std::endl;
    _perceptronGraph.printAllNextNodes();
    std::cout << "Neurons" << std::endl;
    _perceptronGraph.printAllPrevNodes();
}
