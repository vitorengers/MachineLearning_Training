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
#include <iomanip>
#include <chrono>

bool a ()
{
    return true;
}

std::vector<unsigned int> getInputs()
{
    std::string fname = "Data/input.csv";

	std::vector<std::vector<unsigned int>> myData;
	std::vector<unsigned int> row;
	std::string line, word;
 
	std::fstream file (fname, std::ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			std::stringstream str(line);

            // std::cout << line << std::endl;
 
			while(std::getline(str, word, ','))
            {
				row.push_back((unsigned int) std::atoi(word.c_str()));
            }
			
		}
	}
    return row;
}

int main() 
{

    std::setprecision(17);
    // auto start = std::chrono::steady_clock::now();

    std::vector<std::vector<float>> inputs
    (
        {
           //x1,    x2,    b
            {11.0f, 12.0f, 13.0f},
            {0.0f,  1.0f,  1.0f},
            {1.0f,  0.0f,  1.0f},
            {1.0f,  1.0f,  1.0f},
        }
    );

    std::vector<std::vector<float>> expected
    (
        {
            //y
            {55.0f, 11.0f, 4.0f},
            {56.0f, 12.0f, 5.0f},
            {57.0f, 13.0f, 6.0f},
            {58.0f, 14.0f, 7.0f},
        }
    );

    std::vector<unsigned int> hidenLayersNumber = {5, 3};

    unsigned int inputsNumber = 2 + 1;

    unsigned int outputsNumber = 3;


    MultiLayerPerceptron _perceptron;
    _perceptron.createMultiLayerPerceptron(inputsNumber, hidenLayersNumber, outputsNumber);
    
    for (unsigned int i = 0; i < inputs.size(); i++)
    {
        _perceptron.setInputsAndExpected(inputs.at(i), expected.at(i));
        _perceptron.executeOneIteraction();
        // _perceptron.softMaxNormalization();
        _perceptron.updateWeights();
        std::pair <unsigned int, float> result = _perceptron.getResult();
        std::cout << "Result -> Class Number: " << result.first << " with percentage of: " << result.second << std::endl;
    }



    
	// std::string fname = "Data/cars.csv";

	// std::vector<std::vector<unsigned int>> myData;
	// std::vector<unsigned int> row;
	// std::string line, word;
 
	// std::fstream file (fname, std::ios::in);
	// if(file.is_open())
	// {
	// 	while(getline(file, line))
	// 	{
	// 		row.clear();
 
	// 		std::stringstream str(line);

    //         std::cout << line << std::endl;
 
	// 		while(std::getline(str, word, ','))
    //         {
	// 			row.push_back((unsigned int) std::atoi(word.c_str()));
    //         }
	// 		myData.push_back(row);
	// 	}
	// }
	// else
	// 	std::cout<<"Could not open the file\n";
 
    // for(auto &i: content)
    // {
    //     for(auto &j: i)
    //     {
    //         std::cout << j;
    //     }
    //     std::cout << std::endl;
    // }

    // std::vector<std::string> teste = content.at(0);
    // for(auto &i: teste)
    // {
    //     std::cout << i << std::endl;
    // }


	// for(int i=0;i<content.size();i++)
	// {
	// 	for(int j=0;j<content[i].size();j++)
	// 	{
	// 		std::cout<<content[i][j]<<" ";
	// 	}
	// 	std::cout<<"\n";
	// }







    // // std::vector<unsigned int> teste = myData.at(0);

    // unsigned int inputsN = 2 + 1; //for the bias
    // unsigned int neuronN = 1;
    // unsigned int biasValue = 1;

    // SingleLayerPerceptron _perceptron;
    // _perceptron.createSingleLayerPerceptron(inputsN, neuronN, 1);

    
 
    // for (int j = 0; j < 10; j++)
    // {
    //     for (int i = 0; i < 4; i ++)
    //     {
    //         std::cout << "  ITERACTION NUMBER  " << i + 1 << std::endl;
    //         std::vector<unsigned int> teste = myData.at(i);
    //         _perceptron.executeOneIteraction(teste);
    //         _perceptron.debugPerceptron(); 
    //     }
    // }

    // while (1)
    // {
    //     std::string a;
    //     std::cin >> a;
    //     _perceptron.getResult(getInputs());

    // }
    // // auto end = std::chrono::steady_clock::now();

    // // std::cout << "Elapsed time in microseconds: "
    //     // << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
    // //     << " µs" << std::endl;

    // // _perceptron.createPerceptron(inputsN, 5, biasValue);


 
 
    return 0;
}