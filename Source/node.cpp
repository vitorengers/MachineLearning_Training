#include "../Headers/node.h"

// #pragma once

template <typename T>
unsigned int  Node<T>::_node_couter = 0;

template <typename T>
Node<T>::Node(T data)
{
    _data = data;
    _next = std::list <std::shared_ptr <Node <T>>> ();
    _prev = std::list <std::shared_ptr <Node <T>>> ();
    _node_couter++;
}

template <typename T>
Node<T>::~Node()
{
    _node_couter--;
}

template <typename T>
void Node<T>::addNext(std::shared_ptr<Node<T>> next)
{
    _next.push_back(next);
}

template <typename T>
void Node<T>::addPrev(std::shared_ptr<Node<T>> prev)
{
    _prev.push_back(prev);
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
T Node<T>::getData()
{
    return _data;
}
