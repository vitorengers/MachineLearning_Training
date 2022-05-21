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

void Perceptron::createPerceptron2(unsigned int inputsNumber,  std::vector<unsigned int> hiddenLayersNumber, unsigned int outputsNumber)
{
    //!> THIS COULD BE MADE IN ONLY ONE FOR. BUT FOR LEARNING PURPOUSE, EVERY STEP IS WELL SEPARATED.
    
    //!>>>> TODO: Rename hiddenLayersArray to LayersArray, since that it contais all the layers, not only the hidden.

    //! Create two vectors to construct the graph. 
    //! The hiddenLayer is used to create layer by layer and then inserted on hiddenLayersArray
    //! The hiddenLayersArray will have all layers and then be used to connect the nodes.
    std::vector<std::vector<std::shared_ptr<Node<var_type>>>> hiddenLayersArray;
    std::vector<std::shared_ptr<Node<var_type>>>  hiddenLayer;

    //! Create the layer for the inputs. Insert n inputs in the hiddenLayer vector
    for(unsigned int nNumber = 0; nNumber < inputsNumber; nNumber++)
    {
        var_type neuronData ("Input");
        hiddenLayer.emplace_back(std::make_shared<Node<var_type>> (neuronData));
    }

    //! Insert the hiddenLayer on the HiddenLayersArray to save it
    hiddenLayersArray.emplace_back(hiddenLayer);

    //! Create the all the hidden layers. This will be a for for every hidden layer size defined on the input array.
    for(auto &hNumber: hiddenLayersNumber)
    {
        //! Need to clear this to don't duplicate the before content
        hiddenLayer.clear();

        //! Same as for the inputs. But for every index of the hiddenLayersNumber parameter.
        for(unsigned int nNumber = 0; nNumber < hNumber; nNumber++)
        {
            var_type neuronData ("HiddenLayer");
            hiddenLayer.emplace_back(std::make_shared<Node<var_type>> (neuronData));
        }

        //! Insert the hiddenLayer on the HiddenLayersArray to save it
        hiddenLayersArray.emplace_back(hiddenLayer);
    }

    //! Need to clear this to don't duplicate the before content
    hiddenLayer.clear();

    //! Create the layer for the outputs. Insert n outputs in the hiddenLayer vector
    for(unsigned int nNumber = 0; nNumber < outputsNumber; nNumber++)
    {
        var_type neuronData ("Output");
        hiddenLayer.emplace_back(std::make_shared<Node<var_type>> (neuronData));
    }

    //! Insert the hiddenLayer on the HiddenLayersArray to save it
    hiddenLayersArray.emplace_back(hiddenLayer);

    std::cout << "Parar aqui" << std::endl;

    //! Create the first node for the perceptron. 
    //! This feedback node will play a role as the bridge between outputs and inputs
    _perceptronGraph.addFirstNode("Feedback");

    //! Lets connect the feedback with all the inputs.

    //! Saving the feedback node to recover this pointer later
    std::shared_ptr<Node<var_type>> holdFeedbackNode = _perceptronGraph.getCurrent();

    //! Will set all the inputs (which is the first position of hiddenLayersArray) as next nodes for the feedback.
    for(auto &neuron: hiddenLayersArray.front())
    {
        _perceptronGraph.addNextNode(neuron);
    }

    //! Index used to orientation since that i'm using for enhanced
    unsigned int index = 0;
    
    //! For every layer of the layerArray
    for(auto &hiddenLayer: hiddenLayersArray)
    {
        //> This will run for last. 
        if (hiddenLayer == hiddenLayersArray.back())
        {   
            //! Recover the current position to the feedback node.
            _perceptronGraph.setCurrent(holdFeedbackNode);

            //! Set all the neurons from the output (last position of the array of layers) as a previous nodes for the feedback node.
            for(auto &neuron: hiddenLayer)
            {
                _perceptronGraph.addPrevNode(neuron);
            }

            break;
        }
        else         //> This will run first
        {
            //! Count to track which node i need to go next on the next iteration
            unsigned int nodeCount = 0;

            //! For every neuron inside the layer of the current iteration
            for(auto &neuron: hiddenLayer)
            {   
                //! Go to next (since that we always keep behinde one node and goes to the one that we want to set the next ptr)
                _perceptronGraph.nextNode(nodeCount);
                //! For used to set all nodes from the next layer as the next from the current layer
                for(auto &next: hiddenLayersArray.at(index + 1))
                {
                    next->getDataPtr()->addNewWeight();
                    _perceptronGraph.addNextNode(next);
                }
                //! Need to go back to got next with another nodeCount
                _perceptronGraph.prevNode(0);

                nodeCount++;
            }
        }

        //! This is needed to navigate to the next layer
        _perceptronGraph.nextNode(0);

        //!> I don't need to comment that.
        index++;
    }
}

void Perceptron::setInputsAndExpected(std::vector<float> input, std::vector<float> expected)
{
    std::shared_ptr<Node<var_type>> holdFeedbackNode = _perceptronGraph.getCurrent();

    unsigned int index = 0;
    while(_perceptronGraph.nextNode(index) == true)
    {
        _perceptronGraph.getCurrent()->getDataPtr()->setValue(input.at(index));
        // _perceptronGraph.getCurrent()->getDataPtr()->setExpected(input.at(input.size() - 1));
        _perceptronGraph.prevNode(0);

        index++;
    }

    index = 0;
    while(_perceptronGraph.prevNode(index) == true)
    {
        _perceptronGraph.getCurrent()->getDataPtr()->setExpected(expected.at(index));
        // _perceptronGraph.getCurrent()->getDataPtr()->setExpected(input.at(input.size() - 1));
        _perceptronGraph.nextNode(0);

        index++;
    }

    _perceptronGraph.setCurrent(holdFeedbackNode);

 
}

void Perceptron::executeOneIteraction2(void)
{
    // std::shared_ptr<Node<var_type>> holdFeedbackNode = _perceptronGraph.getCurrent();

    // unsigned int index = 0;

    // while(_perceptronGraph.nextNode(index) == true)
    // {
    //     _perceptronGraph.getCurrent()->getDataPtr()->setValue(input.at(index));
    //     // _perceptronGraph.getCurrent()->getDataPtr()->setExpected(input.at(input.size() - 1));
    //     _perceptronGraph.prevNode(0);

    //     index++;
    // }
 
}


void Perceptron::createPerceptron(unsigned int inputsNumber,  std::vector<unsigned int> neuronsNumberVector, unsigned int bias)
{

    //for now its only single layer
    // unsigned int numberOfLayers = neuronsNumberVector.size();
    unsigned int neuronsNumber = neuronsNumberVector.at(0);

    _perceptronGraph.addFirstNode("Feedback");

    std::shared_ptr<Node<var_type>> holdFirstNode = _perceptronGraph.getCurrent();

    for (unsigned int n = 0; n < neuronsNumber; n++)
    {

        std::shared_ptr<Node<var_type>> holdCurrent = _perceptronGraph.getCurrent();

        var_type neuronData ("Neuron");
        std::shared_ptr<Node<var_type>> neuron = std::make_shared<Node<var_type>>(neuronData);

        if (n == 0) //will create the first neuron
        {

            for (unsigned int i = 0; i < inputsNumber; i++)
            {

                // addNextNode(11 + i);
                _perceptronGraph.addNextNode("Input");

                _perceptronGraph.nextNode(i);
                _perceptronGraph.addNextNode(neuron);
                
                _perceptronGraph.nextNode(n);
                _perceptronGraph.getCurrent()->getDataPtr()->addNewWeight();

                if (i == 0)
                {
                    _perceptronGraph.addNextNode(holdFirstNode);
                }
                
                _perceptronGraph.prevNode(i);
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

        _perceptronGraph.setCurrent(holdCurrent);
    }
}

void Perceptron::executeOneIteraction(std::vector<unsigned int> input)
{
    //for single layer yet
    // _perceptronGraph.prevNode(0);

    std::shared_ptr<Node<var_type>> holdFeedbackNode = _perceptronGraph.getCurrent();

    unsigned int index = 0;

    while(_perceptronGraph.nextNode(index) == true)
    {
        _perceptronGraph.getCurrent()->getDataPtr()->setValue(input.at(index));

        _perceptronGraph.getCurrent()->getDataPtr()->setExpected(input.at(input.size() - 1));
        _perceptronGraph.prevNode(0);

        index++;
    }

    index = 0;

    float sum = 0;

    _perceptronGraph.prevNode(0);

    while(_perceptronGraph.prevNode(index) == true)
    {   
        float XnWn = _perceptronGraph.getCurrent()->getDataPtr()->getXnWnResult(0);
        
        sum += XnWn;
        _perceptronGraph.nextNode(0);
        index++;
    }

    _perceptronGraph.nextNode(0);

    index = 0;

    float y = 0;

    
    if(sum > 0)
    {   
        y = 1;
    }
    else
    {
        y = 0;
    }
    
    if (sum < 0.0001) sum = 0.0000;

    std::cout << sum << std::endl;

    while(_perceptronGraph.nextNode(index) == true)
    {
        float weight = _perceptronGraph.getCurrent()->getDataPtr()->getWeight(0);
        float value = _perceptronGraph.getCurrent()->getDataPtr()->getValue();
        float expected = _perceptronGraph.getCurrent()->getDataPtr()->getExpected();

        float newWeight = weight + value*0.1*(expected - y);

            if ((newWeight < 0.0001) &&
                (newWeight > 0.0000000))
                {
                    newWeight = 0;
                }


        _perceptronGraph.getCurrent()->getDataPtr()->setWeight(newWeight, 0);

        _perceptronGraph.prevNode(0);

        index++;
    }
}

// void Perceptron::executeOneIteraction(std::vector<unsigned int> input)
// {
//     //for single layer yet
//     // _perceptronGraph.prevNode(0);

//     std::shared_ptr<Node<var_type>> holdFeedbackNode = _perceptronGraph.getCurrent();

//     unsigned int index = 0;

//     //  b  x1 x2  e
//     // <1, 0, 0, 0>
//     // <1, 0, 1, 0>
//     // <1, 1, 0, 0>
//     // <1, 1, 1, 1>

//     while(_perceptronGraph.nextNode(index) == true)
//     {
//         _perceptronGraph.getCurrent()->getDataPtr()->setValue(input.at(index));

//         _perceptronGraph.getCurrent()->getDataPtr()->setExpected(input.at(3));
//         _perceptronGraph.prevNode(0);

//         index++;
//     }

//     index = 0;

//     float sum = 0;

//     _perceptronGraph.prevNode(0);

//     while(_perceptronGraph.prevNode(index) == true)
//     {   
//         float XnWn = _perceptronGraph.getCurrent()->getDataPtr()->getXnWnResult();
        
//         sum += XnWn;
//         _perceptronGraph.nextNode(0);
//         index++;
//     }

//     _perceptronGraph.nextNode(0);

//     index = 0;

//     float y = 0;

    
//     if(sum > 0)
//     {   
//         y = 1;
//     }
//     else
//     {
//         y = 0;
//     }
    
//     if (sum < 0.0001) sum = 0.0000;

//     std::cout << sum << std::endl;

//     while(_perceptronGraph.nextNode(index) == true)
//     {
//         float weight = _perceptronGraph.getCurrent()->getDataPtr()->getWeight();
//         float value = _perceptronGraph.getCurrent()->getDataPtr()->getValue();
//         float expected = _perceptronGraph.getCurrent()->getDataPtr()->getExpected();

//         float newWeight = weight + value*0.1*(expected - y);

//             if ((newWeight < 0.0001) &&
//                 (newWeight > 0.0000000))
//                 {
//                     newWeight = 0;
//                 }


//         _perceptronGraph.getCurrent()->getDataPtr()->setWeight(newWeight);

//         _perceptronGraph.prevNode(0);

//         index++;
//     }
// }


void Perceptron::getResult(std::vector<unsigned int> input)
{
        //for single layer yet
    std::shared_ptr<Node<var_type>> holdFeedbackNode = _perceptronGraph.getCurrent();

    unsigned int index = 0;

    while(_perceptronGraph.nextNode(index) == true)
    {
        _perceptronGraph.getCurrent()->getDataPtr()->setValue(input.at(index));
        _perceptronGraph.prevNode(0);
        index++;
    }

    index = 0;

    float sum = 0;

    _perceptronGraph.prevNode(0);

    while(_perceptronGraph.prevNode(index) == true)
    {   
        float XnWn = _perceptronGraph.getCurrent()->getDataPtr()->getXnWnResult(index);
        
        sum += XnWn;
        _perceptronGraph.nextNode(0);
        index++;
    }

    _perceptronGraph.nextNode(0);

    index = 0;

    float y = 0;

    
    if(sum > 0)
    {   
        y = 1;
    }
    else
    {
        y = 0;
    }
    
    if (sum < 0.0001) sum = 0.0000;

    std::cout << "Soma é: " << sum << std::endl;
    std::cout << "Resultado é: " << y << std::endl;

}



void Perceptron::debugPerceptron()
{
    std::cout << "Inputs" << std::endl;
    _perceptronGraph.printAllNextNodes();
    std::cout << "Neurons" << std::endl;
    _perceptronGraph.printAllPrevNodes();
}
