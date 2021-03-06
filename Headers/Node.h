#ifndef Node_H
#define Node_H

#pragma once

#include <memory>
#include <vector>
#include <functional>
#include <initializer_list>
#include <string>
#include <iostream>

template <typename T>
class Node {

//public functions
public: 
    Node();
    Node(T);
    ~Node();

    unsigned int getNodesCount(void) const;

    T getData(void) const;
    // std::shared_ptr<T> getDataPtr(void);
    std::shared_ptr<T> getDataPtr(void) const;
    void setData(T);

    // float getWeight(void);

    // std::string getName(void) const;
    // void setName(std::string name);


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

    //maybe move the below methods into graph

    void printAllNext(void);
    void printAllPrev(void);

    // void setNodeMethod(std::function<T()>);

    // std::function<T()> _nodeMethod;

//private functions
private:    


//public attributes
public: 


//private attributes
private:    
    std::shared_ptr<T> _data;
    std::vector<std::shared_ptr<Node<T>>> _next;
    std::vector<std::shared_ptr<Node<T>>> _prev;

    // float _weight;
    unsigned int _nodeId;
    // std::string _nodeName;

    //include a vertex class later
    static unsigned int _node_counter;
    

};

#endif