#include "../Headers/Perceptron.h"
#include <cmath> 
// Perceptron::Perceptron(unsigned int inputsNumber, unsigned int neuronNumber)
// {

// }

Perceptron::Perceptron()
{

}

Perceptron::~Perceptron()
{

}

unsigned int Perceptron::getNumberOfHiddenLayers() const
{
    return _numbefOfHiddenLayers;
}

void Perceptron::setNumberOfHiddenLayers(unsigned int nHiddenLayers)
{
    _numbefOfHiddenLayers = nHiddenLayers;
}

void Perceptron::createPerceptron(unsigned int inputsNumber,  std::vector<unsigned int> hiddenLayersNumber, unsigned int outputsNumber)
{
    setNumberOfHiddenLayers(hiddenLayersNumber.size());
    //!> THIS COULD BE MADE IN ONLY ONE FOR/while. BUT FOR LEARNING PURPOUSE, EVERY STEP IS WELL SEPARATED.
    
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

void Perceptron::executeOneIteraction(void)
{
    std::shared_ptr<Node<var_type>> holdFeedbackNode = _perceptronGraph.getCurrent();

    //! We are currently on feedback node.
    //! Next node one time to go to the inputs layer
    _perceptronGraph.nextNode(0);
    // //! And then again to go to the first hidden layer
    // _perceptronGraph.nextNode(0);
        //    (_perceptronGraph.getCurrent()->getDataPtr()->getName() != "Expected"))

    //! While the next hidden layers 
    for (unsigned int hiddenLayerIndex = 0; hiddenLayerIndex < getNumberOfHiddenLayers() + 1; hiddenLayerIndex++)
    {
        unsigned int currNeuronIndex = 0;
        while (_perceptronGraph.nextNode(currNeuronIndex) == true)
        {
            float sum = 0.0f;

            unsigned int prevNeuronsIndex = 0;
            while (_perceptronGraph.prevNode(prevNeuronsIndex) == true)
            {
                float value = _perceptronGraph.getCurrent()->getDataPtr()->getValue();

                _perceptronGraph.nextNode(currNeuronIndex);

                sum += value*_perceptronGraph.getCurrent()->getDataPtr()->getWeight(prevNeuronsIndex);
                prevNeuronsIndex++;
            }

            //! Pass the sum thgough the sigmoid
            // float sigmoid = 1/(1 + std::exp(-sum));
            float sigmoid = sigmoidFunc(sum);
            //! And set the new value for the current neuron
            _perceptronGraph.getCurrent()->getDataPtr()->setSum(sum);
            _perceptronGraph.getCurrent()->getDataPtr()->setValue(sigmoid);

            if (hiddenLayerIndex == getNumberOfHiddenLayers())
            {
                _perceptronGraph.getCurrent()->getDataPtr()->setError(_perceptronGraph.getCurrent()->getDataPtr()->getExpected() - sigmoid);
            }

            _perceptronGraph.prevNode(0);
            currNeuronIndex++;

            // _perceptronGraph.getCurrent()->getDataPtr()->setValue(input.at(index));
            // // _perceptronGraph.getCurrent()->getDataPtr()->setExpected(input.at(input.size() - 1));
        }
        _perceptronGraph.nextNode(0);
    }

    _perceptronGraph.setCurrent(holdFeedbackNode);
}

void Perceptron::softMaxNormalization(void)
{
    std::shared_ptr<Node<var_type>> holdFeedbackNode = _perceptronGraph.getCurrent();

    float softMaxSum = 0.0f;

    unsigned int index = 0;
    while(_perceptronGraph.prevNode(index) == true)
    {
        softMaxSum += std::exp(_perceptronGraph.getCurrent()->getDataPtr()->getValue());
        _perceptronGraph.nextNode(0);
        index++;
    }

    _perceptronGraph.setCurrent(holdFeedbackNode);

    index = 0;
    while(_perceptronGraph.prevNode(index) == true)
    {
        float newSoftMaxData = std::exp(_perceptronGraph.getCurrent()->getDataPtr()->getValue())/softMaxSum;
        _perceptronGraph.getCurrent()->getDataPtr()->setNormalizedValue(newSoftMaxData);
        _perceptronGraph.nextNode(0);
        index++;
    }

    _perceptronGraph.setCurrent(holdFeedbackNode);
}

std::pair <unsigned int, float> Perceptron::getResultWithNormalized(void)
{
    std::pair retval = std::make_pair(0, 0.0f);

    unsigned int index = 0;

     while(_perceptronGraph.prevNode(index) == true)
    {
        // std::cout << "Output Num " << index << " sigmoid: " << _perceptronGraph.getCurrent()->getDataPtr()->getValue() << std::endl;
        // std::cout << "Output Num " << index << " value: " << _perceptronGraph.getCurrent()->getDataPtr()->getSum() << std::endl;
        // std::cout << "Output Num " << index << " error: " << _perceptronGraph.getCurrent()->getDataPtr()->getError() << std::endl;

        index++;
        _perceptronGraph.nextNode(0);
    }

    index = 0;
    while(_perceptronGraph.prevNode(index) == true)
    {
        float actualValue = _perceptronGraph.getCurrent()->getDataPtr()->getNormalizedValue();
        std::cout << actualValue << std::endl;
        if (actualValue > retval.second)
        {
            retval.first = index + 1;
            retval.second = actualValue;
        }

        // float actualValue = _perceptronGraph.getCurrent()->getDataPtr()->getNormalizedValue();
        _perceptronGraph.nextNode(0);
        index++;
    }

    return retval;
}

std::pair <float, float> Perceptron::getSumOfValueAndSumOfErrors(void)
{
    std::pair retval = std::make_pair(0.0, 0.0f);

    std::pair outputClass = getResultWithNormalized();
    
    float errorSum = 0.0f;
    int expectedIndex = 0;
    unsigned int index = 0;
    while(_perceptronGraph.prevNode(index) == true)
    {
        errorSum += _perceptronGraph.getCurrent()->getDataPtr()->getError();
        // std::cout << "Output Num " << index << " sigmoid: " << _perceptronGraph.getCurrent()->getDataPtr()->getValue() << std::endl;
        if ((int) round(_perceptronGraph.getCurrent()->getDataPtr()->getExpected()) == 1)
        {
            expectedIndex = index + 1;
        }

        index++;
        _perceptronGraph.nextNode(0);
    }

    retval.first = expectedIndex;
    retval.second = errorSum;


    return retval;
}



void Perceptron::updateWeights(void)
{
    if (getNumberOfHiddenLayers() + 1 > 0)
    {
        backPropagation();
    }
    else
    {
        fowardPropagation();
    }
}   

void Perceptron::fowardPropagation(void)
{
    
}

void Perceptron::backPropagation(void)
{
    std::shared_ptr<Node<var_type>> holdFeedbackNode = _perceptronGraph.getCurrent();

    // _perceptronGraph.prevNode(0);
    // //! And then again to go to the first hidden layer

    //! While the next hidden layers 
    for (unsigned int hiddenLayerIndex = 0; hiddenLayerIndex < getNumberOfHiddenLayers() + 1; hiddenLayerIndex++)
    {
        unsigned int currHidenLayerIndex = 0;
        while (_perceptronGraph.prevNode(currHidenLayerIndex) == true)
        {
            // float sum = 0.0f;
            float smallDelta = 0.0f;

            if (hiddenLayerIndex == 0)
            {
                float neuronValue = _perceptronGraph.getCurrent()->getDataPtr()->getValue();
                float neuronError = _perceptronGraph.getCurrent()->getDataPtr()->getError();
                smallDelta = neuronError*(neuronValue*(1 - neuronValue));
                // smallDelta = _perceptronGraph.getCurrent()->getDataPtr()->getError()*derivativeSigmoidFunc(_perceptronGraph.getCurrent()->getDataPtr()->getSum());
                _perceptronGraph.getCurrent()->getDataPtr()->setSmallDelta(smallDelta);
            }
            else
            {
 
                int indexNextNeuron = 0;

                float smallDeltaHiddenSum = 0.0f;
                while (_perceptronGraph.nextNode(indexNextNeuron) == true)
                {
                    float nextNeuronSmallDelta = _perceptronGraph.getCurrent()->getDataPtr()->getSmallDelta();
                    float nextNeuronWeight = _perceptronGraph.getCurrent()->getDataPtr()->getWeight(currHidenLayerIndex);
                    smallDeltaHiddenSum += nextNeuronSmallDelta*nextNeuronWeight;

                    _perceptronGraph.prevNode(currHidenLayerIndex);

                    indexNextNeuron++;
                }

                smallDelta = smallDeltaHiddenSum*derivativeSigmoidFunc(_perceptronGraph.getCurrent()->getDataPtr()->getSum());

                _perceptronGraph.getCurrent()->getDataPtr()->setSmallDelta(smallDelta);
            } 
            
            unsigned int prevNeuronsIndex = 0;
            while (_perceptronGraph.prevNode(prevNeuronsIndex) == true)
            {
                float deltaWeightPrevNeuron = 0.3*smallDelta*_perceptronGraph.getCurrent()->getDataPtr()->getValue();
                
                _perceptronGraph.nextNode(currHidenLayerIndex);

                float oldWeightPrevNeuron = _perceptronGraph.getCurrent()->getDataPtr()->getWeight(prevNeuronsIndex);
                _perceptronGraph.getCurrent()->getDataPtr()->setWeight(oldWeightPrevNeuron + deltaWeightPrevNeuron, prevNeuronsIndex);

                prevNeuronsIndex++;
            }

            _perceptronGraph.nextNode(0);
            currHidenLayerIndex++;
        }
        _perceptronGraph.prevNode(0);
    }

    _perceptronGraph.setCurrent(holdFeedbackNode);        
}

void Perceptron::createPerceptron2(unsigned int inputsNumber,  std::vector<unsigned int> neuronsNumberVector, unsigned int bias)
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

void Perceptron::executeOneIteraction2(std::vector<unsigned int> input)
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


// void Perceptron::getResult(std::vector<unsigned int> input)
// {
//         //for single layer yet
//     std::shared_ptr<Node<var_type>> holdFeedbackNode = _perceptronGraph.getCurrent();

//     unsigned int index = 0;

//     while(_perceptronGraph.nextNode(index) == true)
//     {
//         _perceptronGraph.getCurrent()->getDataPtr()->setValue(input.at(index));
//         _perceptronGraph.prevNode(0);
//         index++;
//     }

//     index = 0;

//     float sum = 0;

//     _perceptronGraph.prevNode(0);

//     while(_perceptronGraph.prevNode(index) == true)
//     {   
//         float XnWn = _perceptronGraph.getCurrent()->getDataPtr()->getXnWnResult(index);
        
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

//     std::cout << "Soma ??: " << sum << std::endl;
//     std::cout << "Resultado ??: " << y << std::endl;

// }



void Perceptron::debugPerceptron()
{
    std::cout << "Inputs" << std::endl;
    _perceptronGraph.printAllNextNodes();
    std::cout << "Neurons" << std::endl;
    _perceptronGraph.printAllPrevNodes();
}


float Perceptron::sigmoidFunc(float sum)
{
    return 1/(1 + std::exp(-sum));
}

float Perceptron::derivativeSigmoidFunc(float sum)
{
    return sigmoidFunc(sum)*(1 - sigmoidFunc(sum));
    // return sum*(1 - sum);
}
