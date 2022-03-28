#include <iostream>  
#include <memory>

#include "Config/types.h"

#include "Headers/graph.h"
#include "Headers/node.h"

int main() 
{

    // Node<var_type> a(2);
    
    // std::shared_ptr<Node<var_type>> b = std::make_shared<Node<var_type>> (23);
    // std::shared_ptr<Node<var_type>> c = std::make_shared<Node<var_type>> (13);

    // a.addNext(b);
    // a.addNext(c);
    // a.printAllNext();

    Graph<bool> _graph;
    Graph<var_type> _graph2;
    // std::cout << _graph.addFirstNode(12) << std::endl;
    // std::cout << _graph.addNextNode(13) << std::endl;
    // std::cout << _graph.addNextNode(14) << std::endl;
    // std::cout << _graph.addNextNode(15) << std::endl;
    // std::cout << _graph.addNextNode(16) << std::endl;
    // std::cout << _graph.addNextNode(17) << std::endl;

    // std::cout << _graph.addPrevNode(18) << std::endl;
    // std::cout << _graph.addPrevNode(19) << std::endl;
    // std::cout << _graph.addPrevNode(20) << std::endl;
    // std::cout << _graph.addPrevNode(21) << std::endl;
    // std::cout << _graph.addPrevNode(22) << std::endl;

    // std::cout << "print antes do remove" << std::endl;
    // _graph.printAllNextNodes();

    // std::cout << "print depois do remove" << std::endl;
    // std::cout << _graph.removeNextNode(13) << std::endl;

    // _graph.printAllNextNodes();

    // // _graph.prevNode(1);
    // // _graph.printCurrentNodeData();
    // // _graph.printAllNextNodes();
    return 0;
}