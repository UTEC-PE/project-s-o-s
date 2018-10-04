#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
template <typename G>
class Node {
    public:
        typedef typename G::N N;
        typedef typename G::E E;
        typedef typename G::edge edge;
        typedef typename G::EdgeSeq EdgeSeq;
        EdgeSeq edges;
        Node(double x,double y,N data){
            this->x=x;
            this->y=y;
            this->data=data;
        };
        N get(){
            return data;
        }
        ~Node(){
        };
    private:
        N data;
        double x;
        double y;
};

#endif
