#include <iostream>
#include <vector>
#include <memory>

#ifndef Node_H
#define Node_H


#pragma once

template <typename T>
class Node {

public:
    Node();
    Node(T);
    ~Node();
    bool addNext(std::shared_ptr<Node<T>>);
    bool addPrev(std::shared_ptr<Node<T>>);
    bool addNext(T);
    bool addPrev(T);
    // std::list<std::shared_ptr<Node<T>>> getNextNodes();
    // std::list<std::shared_ptr<Node<T>>> getPrevNodes();
    void printNodeData(void);
    void printAllNext(void);
    void printAllPrev(void);
    T getData(void) const;
    void setData(T);
    unsigned int getNodesCount(void) const;

    unsigned int getNumberOfNextNodes();
    unsigned int getNumberOfPrevNodes();

    std::shared_ptr<Node<T>> getNextNode(unsigned int);
    std::shared_ptr<Node<T>> getPrevNode(unsigned int);

private:

private:
    T _data;
    std::vector<std::shared_ptr<Node<T>>> _next;
    std::vector<std::shared_ptr<Node<T>>> _prev;
    static unsigned int _node_couter;

public:

};

#endif