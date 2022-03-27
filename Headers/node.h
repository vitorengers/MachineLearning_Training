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
    ~Node();
    void addNext(std::shared_ptr<Node<T>> next);
    void addPrev(std::shared_ptr<Node<T>> prev);
    void printAllNext();
    void printAllPrev();
    T getData();

private:
    std::list<std::shared_ptr<Node<T>>> _next;
    std::list<std::shared_ptr<Node<T>>> _prev;
    T _data;
    static unsigned int _node_couter;

public:



};

#endif