#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>

#include "node.h"
#include "edge.h"

using namespace std;

class Traits {
	public:
		typedef char N;
		typedef int E;
};

template <typename Tr>
class Graph {
    public:
        typedef Graph<Tr> self;
        typedef Node<self> node;
        typedef Edge<self> edge;
        typedef vector<node*> NodeSeq;
        typedef list<edge*> EdgeSeq;
        typedef typename Tr::N N;
        typedef typename Tr::E E;
        typedef typename NodeSeq::iterator NodeIte;
        typedef typename EdgeSeq::iterator EdgeIte;
        void Insertar_Vertices(double ejex,double ejey,N data){
            Node<self>* nuevo_nodo= new node(ejex,ejey,data);
            nodes.push_back(nuevo_nodo);
        };
        void Insertar_Aristas(int first_node,int second_node,int weight,bool dir){
            Edge<self>* nueva_arista_1= new edge(nodes[first_node],nodes[second_node],weight,dir);
            nodes[first_node]->edges.push_back(nueva_arista_1);
            ///////////////////////////////////////////
            Edge<self>* nueva_arista_2= new edge(nodes[second_node],nodes[first_node],weight,dir);
            nodes[second_node]->edges.push_back(nueva_arista_2);
        };
    private:
        NodeSeq nodes;
        NodeIte ni;
        EdgeIte ei;
};
typedef Graph<Traits> graph;

#endif
