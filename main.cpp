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

bool a ()
{
    return true;
}


int main() 
{

    std::vector< std::vector<unsigned int>> myData
    (
        {
            {0, 0, 0},
            {0, 1, 0},
            {1, 0, 0},
            {1, 1, 1},
        }
    );

    // for (auto &l: myData)
    // {
    //     std::cout << "data line: ";
    //     for (auto &i: l)
    //     {
    //         std::cout << i << " ";
    //     }

    //     std::cout << std::endl;
    // }

    // Graph<var_type> _graph;
    unsigned int inputsN = 2 + 1; //for the bias
    unsigned int neuronN = 1;

    unsigned int biasValue = 1;
    // _graph.createSingleLayerPerceptron(inputsN, neuronN);

    SingleLayerPerceptron _perceptron;
    _perceptron.createSingleLayerPerceptron(inputsN, neuronN, 1);
    _perceptron.debugPerceptron();

    // std::cout << " neurons " << std::endl;
    // _graph.printAllPrevNodes();

    // std::cout << " inputs " << std::endl;
    // _graph.printAllNextNodes();

    // _graph.nextNode(4);
    // _graph.nextNode(0);
    // std::cout << " neurons " << std::endl;

    // _graph.printAllNextNodes();

    // std::cout << _graph.get

    return 0;
}