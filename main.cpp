#include <iostream>  
#include <memory>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Config/Types.h"

// #include "Headers/graph.h"
// #include "Headers/node.h"

#include "Headers/CsvReader.h"

#include "Headers/SingleLayerPerceptron.h"
#include "Headers/PerceptronData.h"
bool a ()
{
    return true;
}


int main() 
{

    std::vector< std::vector<unsigned int>> myData
    (
        {
            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {1, 0, 1, 0},
            {1, 1, 1, 1},
        }
    );

    std::vector<unsigned int> teste = myData.at(0);

    unsigned int inputsN = 2 + 1; //for the bias
    unsigned int neuronN = 1;
    unsigned int biasValue = 1;

    SingleLayerPerceptron _perceptron;
    _perceptron.createSingleLayerPerceptron(inputsN, neuronN, 1);
 
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 4; i ++)
        {
            std::cout << "  ITERACTION NUMBER " << i + 1 << std::endl;
            std::vector<unsigned int> teste = myData.at(i);
            _perceptron.executeOneIteraction(teste);
            _perceptron.debugPerceptron();
        }
    }

    return 0;
}