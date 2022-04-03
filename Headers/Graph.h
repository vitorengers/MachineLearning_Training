#ifndef Graph_H
#define Graph_H

#pragma once

#include <iostream>
#include <memory>

#include "Node.h"

template <typename T>
class Graph
{

public:
    Graph();
    Graph(T);
    Graph(std::shared_ptr<Node<T>>);
    ~Graph();

    bool isGraphEmpty();
    unsigned int getGraphSize();

    std::shared_ptr<Node<T>> createNodePtr();
    std::shared_ptr<Node<T>> createNodePtr(T);
    std::shared_ptr<Node<T>> createNodePtr(std::string name);

    bool addFirstNode();
    bool addFirstNode(T);
    bool addFirstNode(std::string name);

    std::shared_ptr<Node<T>> getCurrent(void);
    void setCurrent(std::shared_ptr<Node<T>>);
    bool goBack();
    bool nextNode(unsigned int);
    bool prevNode(unsigned int);
    bool addNextNode(std::shared_ptr<Node<T>>);
    bool addPrevNode(std::shared_ptr<Node<T>>);
    bool addNextNode(T);
    bool addPrevNode(T);
    bool addNextNode(std::string name);
    // bool addPrevNode(T);

    // bool removeNextNodeByIndex(unsigned int);
    // bool removePrevNodeByIndex(unsigned int);
    // bool removeNextNode(T);
    // bool removePrevNode(T);
    // bool removeNextNode(std::shared_ptr<Node<T>>);
    // bool removePrevNode(std::shared_ptr<Node<T>>);

    void printCurrentNodeData();
    void printAllNextNodes();
    void printAllPrevNodes();

    // void createSingleLayerPerceptron(unsigned int inputsNumber,  unsigned int neuron, int bias = 1);
    

public:
private:

private:
    std::shared_ptr<Node<T>> _currentNode;
    std::shared_ptr<Node<T>> _prevNode;
};

#endif