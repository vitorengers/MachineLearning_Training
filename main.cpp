#include <iostream>  
#include <memory>
#include "Headers/node.h"
#include "Config/types.h"

int main() 
{

    Node<var_type> a(2);
    
    std::shared_ptr<Node<var_type>> b = std::make_shared<Node<var_type>> (23);

    a.addNext(b);
    a.printAllNext();

    return 0;
}