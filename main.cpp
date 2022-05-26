#include <iostream>  
#include <memory>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Config/Types.h"

#include <cstdlib>

// #include "Headers/graph.h"
// #include "Headers/node.h"

#include "Headers/CsvReader.h"

#include "Headers/SingleLayerPerceptron.h"
#include "Headers/MultiLayerPerceptron.h"
#include "Headers/PerceptronData.h"
#include "Headers/ParseData.h"
#include <iomanip>
#include <chrono>

#include <vector>
#include <cmath>

#include <fstream>



int main(int argc, char** argv) 
{

    std::setprecision(17);
    // auto start = std::chrono::steady_clock::now();

    ParseData parser;
    parser.openFile("Data/data.csv");
    // parser.disableShuffle();
    std::vector<unsigned int> hiddenLayersNumber;
    unsigned int inputsNumber = parser.getNumberOfInputs();
    unsigned int outputsNumber = parser.getNumberOfOutputs();

    MultiLayerPerceptron _perceptron;
    _perceptron.createMultiLayerPerceptron(inputsNumber, hiddenLayersNumber, outputsNumber);
    std::vector<float> errorTimeline;
    

    for (int j = 0; j < 200; j++)
    {   
        unsigned int count = 0;
        std::vector <float> hold;
        int errorCount = 0;
        while(parser.epochIsRunning())
        {
            count++;
            auto data = parser.getInputsAndExpected();
            _perceptron.setInputsAndExpected(data.first, data.second);
            _perceptron.executeOneIteraction();
            _perceptron.softMaxNormalization();
            _perceptron.updateWeights();
            // std::pair <unsigned int, float> result = _perceptron.getResult();
            // hold.push_back(result.second);
            // errorTimeline.push_back(result.second);
            // std::cout << "Result -> Class Number: " << result.first << " with percentage of: " << result.second*100 << "%." << std::endl;
            std::pair <unsigned int, float> result = _perceptron.getResultWithNormalized();
            std::pair <float, float> result2 = _perceptron.getSumOfValueAndSumOfErrors();
            std::cout << result.first << " " << result2.second << std::endl;
            if(round(result.first) != round(result2.first))
            {
                errorCount++;
            }
        
        }
        std::cout << "Epoch: " << j << "." << std::endl;

        errorTimeline.push_back(errorCount);
    }


    std::ofstream myfile ("error.txt");
    if (myfile.is_open())
    {
        for(auto &e: errorTimeline)
        {
            myfile << e << "\n";
        }
        myfile.close();
    }

    
    for (unsigned int i = 0; i < 10; i++)
    {
        _perceptron.setInputsAndExpected(parser.getInputs(i), parser.getExpecteds(i));
              _perceptron.executeOneIteraction();
        _perceptron.softMaxNormalization();
        // _perceptron.updateWeights();
        std::pair <unsigned int, float> result = _perceptron.getResultWithNormalized();
        std::pair <float, float> result2 = _perceptron.getSumOfValueAndSumOfErrors();
        std::cout << "---------------------------" << std::endl;
        std::cout << "Result -> Class Number: " << result.first << " with percentage of: " << result.second*100 << "%." << std::endl;
        std::cout << "Result -> Sum of Errors: " << result2.first << " SumOfValue: " << result2.second << "." << std::endl;
    }
    

    system("python3 teste.py");
 
    return 0;
}