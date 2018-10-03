#ifndef EDGE_H
#define EDGE_H

#include "node.h"

template <typename G>
class Edge {
    public:
        typedef typename G::E E;
        typedef typename G::node node;
        node* nodes[2];
        Edge(node* first_node, node* second_node,E data,bool dir){
            nodes[0]=first_node;
            nodes[1]=second_node;
            this->data=data;
            this->dir=dir;
        };
    private:
        E data;
        bool dir;
};

#endif
