#include <iostream>
#include <list>
#include <memory>
#include "node.h"
// #include "types.h"

#ifndef Graph_H
#define Graph_H

#pragma once

template <typename T>
class Graph
{

public:
    Graph();
    Graph(T);
    Graph(std::shared_ptr<Node<T>>);
    ~Graph();
    std::shared_ptr<Node<T>> createNodePtr();
    std::shared_ptr<Node<T>> createNodePtr(T);
    bool addFirstNode();
    bool addFirstNode(T);
    bool isGraphEmpty();
    unsigned int getGraphSize();
    void setCurrent(std::shared_ptr<Node<T>>);
    bool goBack();
    bool nextNode(unsigned int);
    bool prevNode(unsigned int);
    bool addNextNode(std::shared_ptr<Node<T>>);
    bool addPrevNode(std::shared_ptr<Node<T>>);
    bool addNextNode(T);
    bool addPrevNode(T);
    bool removeNextNodeByIndex(unsigned int);
    bool removePrevNodeByIndex(unsigned int);
    bool removeNextNode(T);
    bool removePrevNode(T);
    bool removeNextNode(std::shared_ptr<Node<T>>);
    bool removePrevNode(std::shared_ptr<Node<T>>);
    void printCurrentNodeData();
    void printAllNextNodes();
    void printAllPrevNodes();

public:
private:

private:
    std::shared_ptr<Node<T>> _currentNode;
    std::shared_ptr<Node<T>> _prevNode;
};

#endif