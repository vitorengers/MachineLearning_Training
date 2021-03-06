#include "../Headers/Graph.h"

template <typename T>
Graph<T>::Graph():
    _currentNode(nullptr),
    _prevNode(nullptr)
{

}

template <typename T>
Graph<T>::Graph(T data):
    _currentNode(std::make_shared<Node<T>>(data)),
    _prevNode(nullptr)
{

}

// template <typename T>
// Graph<T>::Graph(std::shared_ptr<Node<T>> node):
//     _currentNode(node),
//     _prevNode(nullptr)
// {

// }

template <typename T>
Graph<T>::~Graph()
{

}

template <typename T>
bool Graph<T>::isGraphEmpty()
{
    bool retval = false;

    if(_currentNode == nullptr)
    {
        retval = true;
    }

    return retval;
}

template <typename T>
unsigned int Graph<T>::getGraphSize()
{
    unsigned int retval = 0;

    if(isGraphEmpty() == false)
    {
        retval = _currentNode->getNodesCount();
    }
    
    return retval;
}

template <typename T>
std::shared_ptr<Node<T>> Graph<T>::createNodePtr()
{
    std::shared_ptr<Node<T>> retval = nullptr;
    
    try
    {
        retval = std::make_shared<Node<T>>();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        retval = nullptr;
    }
    
    return retval;
}

template <typename T>
std::shared_ptr<Node<T>> Graph<T>::createNodePtr(T data)
{
    std::shared_ptr<Node<T>> retval = nullptr;
    
    try
    {
        retval = std::make_shared<Node<T>>(data);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        retval = nullptr;
    }
    
    return retval;
}

template <typename T>
std::shared_ptr<Node<T>> Graph<T>::createNodePtr(std::string name)
{
    std::shared_ptr<Node<T>> retval = nullptr;
    
    try
    {
        retval = std::make_shared<Node<T>>(name);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        retval = nullptr;
    }
    
    return retval;
}


template <typename T>
bool Graph<T>::addFirstNode(T data)
{
    bool retval = false;

    if(isGraphEmpty() == true)
    {
        std::shared_ptr<Node<T>> node = createNodePtr(data);

        if (node != nullptr)
        {
            _currentNode = node;
            retval = true;
        }
    }

    return retval;

}

template <typename T>
bool Graph<T>::addFirstNode(std::string name)
{
    bool retval = false;

    if(isGraphEmpty() == true)
    {
        std::shared_ptr<Node<T>> node = createNodePtr(name);

        if (node != nullptr)
        {
            _currentNode = node;
            retval = true;
        }
    }

    return retval;

}




template <typename T>
void Graph<T>::setCurrent(std::shared_ptr<Node<T>> node)
{
    _currentNode = node;
}

template <typename T>
std::shared_ptr<Node<T>> Graph<T>::getCurrent(void)
{
    return _currentNode;
}

template <typename T>
bool Graph<T>::goBack()
{
    bool retval = false;

    if(_prevNode != nullptr)
    {
        std::shared_ptr<Node<T>> hold = nullptr;

        hold = _currentNode;
        _currentNode = _prevNode;
        _prevNode = hold;

        retval = true;
    }

    return retval;
}


template <typename T>
bool Graph<T>::nextNode(unsigned int index)
{
    bool retval = false;

    std::shared_ptr<Node<T>> node = _currentNode->getNextNode(index);

    if(node != nullptr)
    {
        _prevNode = _currentNode;
        _currentNode = node;
        retval = true;

    }
    return retval;
}


template <typename T>
bool Graph<T>::prevNode(unsigned int index)
{
    bool retval = false;

    std::shared_ptr<Node<T>> node = _currentNode->getPrevNode(index);

    if(node != nullptr)
    {
        _prevNode = _currentNode;
        _currentNode = node;
        retval = true;
    }

    return retval;
}


template <typename T>
bool Graph<T>::addNextNode(std::shared_ptr<Node<T>> node)
{
    bool retval = false;
    
    if (node != nullptr)
    {
        if(node->addPrev(_currentNode) == true)
        {
            if(_currentNode->addNext(node) == true)
            {
                retval = true;
            }
            else{
                //remove prev from node
            }
        }
    }

    return retval;
}


template <typename T>
bool Graph<T>::addPrevNode(std::shared_ptr<Node<T>> node)
{
    bool retval = false;
    
    if (node != nullptr)
    {
        if(node->addNext(_currentNode) == true)
        {
            if(_currentNode->addPrev(node) == true)
            {
                retval = true;
            }
            else
            {
                //remove next from node
            }
        }
    }

    return retval;
}


template <typename T>
bool Graph<T>::addNextNode(T data)
{
    return addNextNode(std::make_shared<Node<T>>(data));
}


template <typename T>
bool Graph<T>::addPrevNode(T data)
{
    return addPrevNode(std::make_shared<Node<T>>(data));
}

template <typename T>
bool Graph<T>::addNextNode(std::string name)
{
    return addNextNode(std::make_shared<Node<T>>(name));
}

// template <typename T>
// bool Graph<T>::removeNextNodeByIndex(unsigned int)
// {
//     return false;
// }


// template <typename T>
// bool Graph<T>::removePrevNodeByIndex(unsigned int)
// {
//     return false;
// }


// template <typename T>
// bool Graph<T>::removeNextNode(T data)
// {
//     return _currentNode->removeNext(data);
// }

// template <typename T>
// bool Graph<T>::removePrevNode(T data)
// {
//     return _currentNode->removeNext(data);
// }


// template <typename T>
// bool Graph<T>::removeNextNode(std::shared_ptr<Node<T>> node)
// {
//     return _currentNode->removeNext(node);
// }


// template <typename T>
// bool Graph<T>::removePrevNode(std::shared_ptr<Node<T>> node)
// {
//     return _currentNode->removeNext(node);
// }


template <typename T>
void Graph<T>::printCurrentNodeData()
{
    _currentNode->printNodeData();
}


template <typename T>
void Graph<T>::printAllNextNodes()
{
    _currentNode->printAllNext();
}


template <typename T>
void Graph<T>::printAllPrevNodes()
{
    _currentNode->printAllPrev();
}

// template <typename T>
// void Graph<T>::createSingleLayerPerceptron(unsigned int inputsNumber,  unsigned int neuronsNumber, int biasValue)
// {
//     addFirstNode(10);

//     std::shared_ptr<Node<T>> holdFirstNode = getCurrent();

//     for (unsigned int n = 0; n < neuronsNumber; n++)
//     {
//         std::shared_ptr<Node<T>> neuron = std::make_shared<Node<T>>();

//         if (n == 0) //will create the first neuron
//         {
//             for (unsigned int i = 0; i < inputsNumber; i++)
//             {
//                 // addNextNode(11 + i);
//                 addNextNode(0);

//                 nextNode(i);
//                 addNextNode(neuron);

//                 if (i == 0)
//                 {
//                     nextNode(n);
//                     addNextNode(holdFirstNode);
//                     prevNode(i);
//                 }
//                 prevNode(0);
//             }
//         }
//         else    //for the other neuron. Shoudnt create another inputs to point to new neurons
//         {
//             for (unsigned int i = 0; i < inputsNumber; i++)
//             {
//                 nextNode(i);
//                 addNextNode(neuron);

//                 if (i == 0)
//                 {
//                     nextNode(n);
//                     addNextNode(holdFirstNode);
//                     prevNode(i);
//                 }

//                 prevNode(0);
//             }
//         }
//     }
// }
