#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
#include <iostream>
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
        Graph(bool option){
            dir=option;
        };
        void Insertar_Vertices(double ejex,double ejey,N data){
            node* nuevo_nodo= new node(ejex,ejey,data);
            nodes.push_back(nuevo_nodo);
        };
        void Insertar_Aristas(int first_node,int second_node,int weight){
            if(dir == true){
                edge* nueva_arista_1= new edge(nodes[first_node],nodes[second_node],weight);
                nodes[first_node]->edges.push_back(nueva_arista_1);
            }else{
                edge* nueva_arista_1= new edge(nodes[first_node],nodes[second_node],weight);
                nodes[first_node]->edges.push_back(nueva_arista_1);
                edge* nueva_arista_2= new edge(nodes[second_node],nodes[first_node],weight);
                nodes[second_node]->edges.push_back(nueva_arista_2);
            }
        };
        void Eliminar_Aristas(N first_node,N second_node){
            if(dir == true){
                node* nodo=nodes[int(first_node)-48];
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==second_node){
                        delete (*ei);
                        ei = nodo->edges.erase(ei);
                        ei2=ei;
                    }
                }
            }else{
                node* nodo=nodes[int(first_node)-48];
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==second_node){
                        delete (*ei);
                        ei = nodo->edges.erase(ei);
                        ei2=ei;
                    }
                }
                nodo=nodes[int(second_node)-48];
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==first_node){
                        delete (*ei);
                        ei = nodo->edges.erase(ei);
                    }
                }
            }
        };
        void Eliminar_Nodos(N first_node){
            node* nodo=nodes[int(first_node)-48];
            for(ei2=nodo->edges.begin();ei2!=nodo->edges.end();++ei2){
                Eliminar_Aristas(first_node,(*ei2)->nodes[1]->get());
            }
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                if((*ni)->get()==first_node){
                    delete (*ni);
                    ni = nodes.erase(ni);
                }
            }
        };
        void print(){
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                cout <<(*ni)->get()<<endl;
                for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                    cout <<"peso : " << (*ei)->get();
                    cout <<" nodo :" << (*ei)->nodes[1]->get();
                    cout <<" ";
                }
                cout <<endl;
            }
        }
    private:
        NodeSeq nodes;
        NodeIte ni;
        EdgeIte ei;
        EdgeIte ei2;
        bool dir;
};
typedef Graph<Traits> graph;

#endif
