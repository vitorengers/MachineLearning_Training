#include "../Headers/Node.h"

template <typename T>
unsigned int  Node<T>::_node_counter = 0;

template <typename T>
Node<T>::Node():
    _next(std::vector <std::shared_ptr <Node <T>>> ()),
    _prev(std::vector <std::shared_ptr <Node <T>>> ()),
    // _weight(0.0),
    _nodeId(_node_counter)
    // _nodeName("")
    // _nodeMethod(nullptr)
{
    _node_counter++;
}

template <typename T>
Node<T>::Node(T data):
    _data(std::make_shared<T> (data)),
    _next(std::vector <std::shared_ptr <Node <T>>> ()),
    _prev(std::vector <std::shared_ptr <Node <T>>> ()),
    // _weight(0.0),
    _nodeId(_node_counter)
    // _nodeName("")
{
    _node_counter++;
}

// template <typename T>
// Node<T>::Node(std::string name):
//     _next(std::vector <std::shared_ptr <Node <T>>> ()),
//     _prev(std::vector <std::shared_ptr <Node <T>>> ()),
//     _weight(0.0),
//     _nodeId(_node_counter),
//     _nodeName(name)
// {
//     _node_counter++;
// }

template <typename T>
Node<T>::~Node()
{
    _node_counter--;
}

template <typename T>
unsigned int Node<T>::getNodesCount(void) const
{
    return _node_counter;
}

template <typename T>
T Node<T>::getData(void) const
{
    return *_data;
}

// template <typename T>
// std::shared_ptr<T>  Node<T>::getDataPtr(void) const
// {
//     return _data;
// }

template <typename T>
std::shared_ptr<T> Node<T>::getDataPtr(void) const
{
    return _data;
}

template <typename T>
void Node<T>::setData(T data)
{
    // _data* = data;
}

// template <typename T>
// float Node<T>::getWeight(void)
// {
//     return _weight;
// }

// template <typename T>
// std::string Node<T>::getName() const
// {
//     return _nodeName;
// }

// template <typename T>
// void Node<T>::setName(std::string name)
// {
//     _nodeName = name;
// }

template <typename T>
bool Node<T>::addNext(std::shared_ptr<Node<T>> next)
{
    bool retval = false;

    try {
        _next.push_back(next);
        retval = true;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return retval;
}

template <typename T>
bool Node<T>::addPrev(std::shared_ptr<Node<T>> prev)
{
    bool retval;

    try {
        _prev.push_back(prev);
        retval = true;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        retval = false;
    }

    return retval;  
}

template <typename T>
bool Node<T>::addNext(T data)
{
    return addNext(std::make_shared<Node<T>>(data));
}

template <typename T>
bool Node<T>::addPrev(T data)
{
    return addPrev(std::make_shared<Node<T>>(data));   
}

template <typename T>
bool Node<T>::removeNext(std::shared_ptr<Node<T>> node)
{
    bool retval = false;

    for (unsigned int i = 0; i < _next.size(); i++)
    {
        if(_next.at(i) == node)
        {
            _next.erase(_next.begin() + i);
            retval = true;
        }
    }

    return retval;
}

template <typename T>
bool Node<T>::removePrev(std::shared_ptr<Node<T>> node)
{
    bool retval = false;
    
    for (unsigned int i = 0; i < _prev.size(); i++)
    {
        if(_prev.at(i) == node)
        {
            _prev.erase(_next.begin() + i);
            retval = true;
        }
    }

    return retval;
}

//CHANGE FOR T TO BE A POINTER

// // // // template <typename T>
// // // // bool Node<T>::removeNext(T data)
// // // // {
// // // //     bool retval = false;

// // // //     for (unsigned int i = 0; i < _next.size(); i++)
// // // //     {
// // // //         if(_next.at(i)->getData() == data)
// // // //         {
// // // //             _next.erase(_next.begin() + i);
// // // //             retval = true;
// // // //         }
// // // //     }

// // // //     return retval;
// // // // }

// // // // template <typename T>
// // // // bool Node<T>::removePrev(T data)
// // // // {
// // // //     bool retval = false;

// // // //     for (unsigned int i = 0; i < _next.size(); i++)
// // // //     {
// // // //         if(_prev.at(i)->getData() == data)
// // // //         {
// // // //             _prev.erase(_next.begin() + i);
// // // //             retval = true;
// // // //         }
// // // //     }

// // // //     return retval;
// // // // }

// template <typename T>
// std::list<std::shared_ptr<Node<T>>> getNextNodes()
// {
//     return _next;
// }

// template <typename T>
// std::list<std::shared_ptr<Node<T>>> getPrevNodes()
// {
//     return _prev;
// }

template <typename T>
std::shared_ptr<Node<T>> Node<T>::getNextNode(unsigned int index)
{
    std::shared_ptr<Node<T>> retval = nullptr;
    
    if(getNumberOfNextNodes() > index)
    {
        retval = _next.at(index);
    }

    return retval;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::getPrevNode(unsigned int index)
{
    std::shared_ptr<Node<T>> retval = nullptr;
    
    if(getNumberOfPrevNodes() > index)
    {
        retval = _prev.at(index);
    }

    return retval;
}


template <typename T>
unsigned int Node<T>::getNumberOfNextNodes()
{
    return _next.size();
}

template <typename T>
unsigned int Node<T>::getNumberOfPrevNodes()
{
    return _prev.size();
}


template <typename T>
void Node<T>::printNodeData()
{
    std::cout << *_data << std::endl;
}


template <typename T>
void Node<T>::printAllNext()
{
    for(std::shared_ptr<Node<T>> &n: _next)
    {
        std::cout << n->getData() << std::endl;
    }
}

template <typename T>
void Node<T>::printAllPrev()
{
    for(std::shared_ptr<Node<T>> &n: _prev)
    {
        std::cout << n->getData() << std::endl;
    }
}

// template <typename T>
// void Node<T>::setNodeMethod(std::function<T()> method)
// {
//     _nodeMethod = method;
// }


