#include "../Headers/node.h"

// #pragma once

template <typename T>
unsigned int  Node<T>::_node_couter = 0;

template <typename T>
Node<T>::Node():
    _next(std::vector <std::shared_ptr <Node <T>>> ()),
    _prev(std::vector <std::shared_ptr <Node <T>>> ())
{
    _node_couter++;
}

template <typename T>
Node<T>::Node(T data):
    _data(data),
    _next(std::vector <std::shared_ptr <Node <T>>> ()),
    _prev(std::vector <std::shared_ptr <Node <T>>> ())
{
    _node_couter++;
}

template <typename T>
Node<T>::~Node()
{
    _node_couter--;
}

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
void Node<T>::printNodeData()
{
    std::cout << _data << std::endl;
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

template <typename T>
T Node<T>::getData() const
{
    return _data;
}

template <typename T>
void Node<T>::setData(T data)
{
    _data = data;
}

template <typename T>
unsigned int Node<T>::getNodesCount(void) const
{
    return _node_couter;
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
std::shared_ptr<Node<T>> Node<T>::getNextNode(unsigned int index)
{
    std::shared_ptr<Node<T>> retval = nullptr;
    
    if(getNumberOfNextNodes() >= index)
    {
        retval = _next.at(index);
    }

    return retval;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::getPrevNode(unsigned int index)
{
    std::shared_ptr<Node<T>> retval = nullptr;
    
    if(getNumberOfPrevNodes() >= index)
    {
        retval = _prev.at(index);
    }

    return retval;
}