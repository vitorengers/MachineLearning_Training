#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <initializer_list>

#ifndef Node_H
#define Node_H

#pragma once

template <typename T>
class Node {

//public functions
public: 
    Node();
    Node(T);
    ~Node();

    unsigned int getNodesCount(void) const;

    T getData(void) const;
    void setData(T);

    bool addNext(std::shared_ptr<Node<T>>);
    bool addPrev(std::shared_ptr<Node<T>>);
    bool addNext(T);
    bool addPrev(T);

    bool removeNext(std::shared_ptr<Node<T>>);
    bool removePrev(std::shared_ptr<Node<T>>);
    bool removeNext(T);
    bool removePrev(T);

    // std::list<std::shared_ptr<Node<T>>> getNextNodes();
    // std::list<std::shared_ptr<Node<T>>> getPrevNodes();
    std::shared_ptr<Node<T>> getNextNode(unsigned int);
    std::shared_ptr<Node<T>> getPrevNode(unsigned int);

    unsigned int getNumberOfNextNodes();
    unsigned int getNumberOfPrevNodes();
    
    void printNodeData(void);
    void printAllNext(void);
    void printAllPrev(void);
    
    void setNodeMethod(std::function<T()>);

    std::function<T()> _nodeMethod;

//private functions
private:    


//public attributes
public: 


//private attributes
private:    
    T _data;
    std::vector<std::shared_ptr<Node<T>>> _next;
    std::vector<std::shared_ptr<Node<T>>> _prev;
    static unsigned int _node_counter;
    

};

#endif