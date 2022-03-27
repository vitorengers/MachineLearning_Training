#include <iostream>
#include <list>
#include <memory>

#ifndef Node_H
#define Node_H


#pragma once

template <typename T>
class Node {

public:
    Node(T);
    ~Node(void);
    void addNext(std::shared_ptr<Node<T>>);
    void addPrev(std::shared_ptr<Node<T>>);
    void printAllNext(void);
    void printAllPrev(void);
    T getData(void) const;
    void setData(T);
    unsigned int getNodesCount(void) const;

private:
    T _data;
    std::list<std::shared_ptr<Node<T>>> _next;
    std::list<std::shared_ptr<Node<T>>> _prev;
    static unsigned int _node_couter;

public:



};

#endif