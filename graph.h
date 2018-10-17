#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
#include <iostream>
#include "node.h"
#include "edge.h"
//////////////////////////////////////
#include <queue>
#include <stack>
#include <map>
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
            bipartito=true;
        };
        ~Graph(){
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                (*ni)->edges.clear();
            }
            nodes.clear();
        }
        void Insertar_Vertices(double ejex,double ejey,E data){
            node* nuevo_nodo= new node(ejex,ejey,data);
            nodes.push_back(nuevo_nodo);
        };
        ///////////////////////////////////////////////////////////////////////////////
        void Insertar_Aristas(int first_node,int second_node,int weight){
            if(dir == true){
                node* nodo=nodes[first_node];
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==second_node){
                        return;
                    }
                }
                edge* nueva_arista_1= new edge(nodes[first_node],nodes[second_node],weight);
                nodes[first_node]->edges.push_back(nueva_arista_1);
            }else{
                node* nodo=nodes[first_node];
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==second_node){
                        return;
                    }
                }
                edge* nueva_arista_1= new edge(nodes[first_node],nodes[second_node],weight);
                nodes[first_node]->edges.push_back(nueva_arista_1);
                //edge* nueva_arista_2= new edge(nodes[second_node],nodes[first_node],weight);
                nodes[second_node]->edges.push_back(nueva_arista_1);
            }
        };
        ///////////////////////////////////////////////////////////////////////////////
        void Eliminar_Aristas(N first_node,N second_node){
            edge* temp;
            if(dir==false){
                node* nodo=nodes[first_node];
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==second_node && (*ei)->nodes[0]->get()==first_node){
                        temp= (*ei);
                        ei = nodo->edges.erase(ei);
                        ei2=ei;
                        break;
                    }
                    else if((*ei)->nodes[1]->get()==second_node && (*ei)->nodes[0]->get()==first_node){
                        temp= (*ei);
                        ei = nodo->edges.erase(ei);
                        ei2=ei;
                        break;
                    }
                }
                nodo=nodes[second_node];
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==second_node && (*ei)->nodes[0]->get()==first_node){
                        ei = nodo->edges.erase(ei);
                        break;
                    }
                    else if((*ei)->nodes[1]->get()==second_node && (*ei)->nodes[0]->get()==first_node){
                        ei = nodo->edges.erase(ei);
                        break;
                    }
                }
            }
            else{
                node* nodo=nodes[first_node];
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==second_node){
                        temp= (*ei);
                        ei = nodo->edges.erase(ei);
                        ei2=ei;
                        break;
                    }
                }
            }
            delete temp;
        };
        ///////////////////////////////////////////////////////////////////////////////
        void Eliminar_Nodos(E first_node){
            node* nodo=nodes[first_node];
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                for(ei2=(*ni)->edges.begin();ei2!=(*ni)->edges.end();++ei2){
                    if((*ni)->get()==first_node){
                        break;
                    }
                    if((*ei2)->nodes[1]->get()==first_node){
                        Eliminar_Aristas((*ni)->get(),first_node);
                    }
                    else if((*ei2)->nodes[0]->get()==first_node){
                        Eliminar_Aristas((*ni)->get(),first_node);
                    }
                }
            }
            for(ei2=nodo->edges.begin();ei2!=nodo->edges.end();++ei2){
                Eliminar_Aristas(first_node,(*ei2)->nodes[1]->get());
            }
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                if((*ni)->get()==first_node){
                    delete (*ni);
                    nodes.erase(ni);
                    break;
                }
            }
        };
        ///////////////////////////////////////////////////////////////////////////////
        bool BFS(){
            node* nodo = nodes[0];
            queue<node*> cola;
            cola.push(nodo);
            map<E,bool> visitado;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                visitado[(*ni)->get()]=false;
            }
            visitado[nodo->get()]=true;
            do{
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if(visitado.find((*ei)->nodes[1]->get())->second==false){
                        visitado[(*ei)->nodes[1]->get()]=true;
                        cola.push((*ei)->nodes[1]);
                    }
                    else if(visitado.find((*ei)->nodes[0]->get())->second==false){
                        visitado[(*ei)->nodes[0]->get()]=true;
                        cola.push((*ei)->nodes[0]);
                    }
                }
                //cout << nodo->get() << " ";
                cola.pop();
                nodo= cola.front();
            }
            while(!cola.empty());
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                if(visitado.find((*ni)->get())->second==false){
                    return false;
                }
            }
            return true;
        }
        ///////////////////////////////////////////////////////////////////////////////
        bool DFS(){
            node* nodo = nodes[0];
            stack<node*> cola;
            cola.push(nodo);
            map<E,bool> visitado;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                visitado[(*ni)->get()]=false;
            }
            visitado[nodo->get()]=true;
            cout << nodo->get() << " ";
            do{
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if(visitado.find((*ei)->nodes[1]->get())->second==false){
                        visitado[(*ei)->nodes[1]->get()]=true;
                        cola.push((*ei)->nodes[1]);
                        nodo = cola.top();
                        cout << nodo->get() << " ";
                        break;
                    }
                    else if(visitado.find((*ei)->nodes[0]->get())->second==false){
                        visitado[(*ei)->nodes[0]->get()]=true;
                        cola.push((*ei)->nodes[0]);
                        nodo = cola.top();
                        cout << nodo->get() << " ";
                        break;
                    }
                }
                if(ei==nodo->edges.end()){
                    cola.pop();
                    if(!cola.empty()){
                        nodo= cola.top();
                    }
                }
            }
            while(!cola.empty());
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                if(visitado.find((*ni)->get())->second==false){
                    return false;
                }
            }
            return true;
        }
        ///////////////////////////////////////////////////////////////////////////////
        void conexo(bool option){
            cout << "Los nodos son: ";
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                cout << (*ni)->get() << " ";
            }
            cout << endl;
            if(option == 0){
                if(DFS()){
                    cout << "Es conexo" << endl;
                }
                else{
                    cout << "No es conexo" << endl;
                }
            }else{
                if(BFS()){
                    cout << "Es conexo" << endl;
                }
                else{
                    cout << "No es conexo" << endl;
                }
            }
        }
        ///////////////////////////////////////////////////////////////////////////////
        void grado(){
            node* nodo=nodes[0];
            cout << nodo->edges.size() << endl;
            if(dir==1){
                bool fuente=true;
                for (ni=nodes.begin();ni!=nodes.end();++ni){
                    for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                        if((*ei)->nodes[1]->get()==nodo->get()){
                            fuente=false;
                            break;
                        }
                    }
                }
                if(fuente){
                    cout << "El nodo es fuente" << endl;
                }
                else{
                    cout << "El nodo no es fuente" << endl;
                }
                if(nodo->edges.size()==0){
                    cout << "El nodo es hundido" << endl;
                }
                else{
                    cout << "El nodo no es hundido" << endl;
                }
            }
        }
        ///////////////////////////////////////////////////////////////////////////////
        void densidad(){
        map<edge*,bool> aristas;
        double cota=0.5;
        double n_vertices=0,n_aristas=0;
        double operacion=0;
        for (ni=nodes.begin();ni!=nodes.end();++ni){
            for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                    aristas.insert(pair<edge*,bool>(*ei,0));
            }
            n_vertices++;
        }
        n_aristas=aristas.size();
        cout << n_aristas << endl;
        cout << n_vertices << endl;
        if(dir==1){
            operacion= n_aristas/(n_vertices*(n_vertices-1));
            cout << operacion << endl;
            if(operacion>cota){
                cout << "Es denso" << endl;
            }
            else{
                cout << "Es disperso" << endl;
            }
        }
        else{
            operacion=2*n_aristas/(n_vertices*(n_vertices-1));
            cout << operacion << endl;
            if(operacion>cota){
                cout << "Es denso" << endl;
            }
            else{
                cout << "Es disperso" << endl;
            }
        }
        }
        ///////////////////////////////////////////////////////////////////////////////
        /*void fuertemente_conexo(bool option){
            cout << "Los nodos son: ";
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                cout << (*ni)->get() << " ";
            }
            cout << endl;
            if(option == 0){
                if(DFS()){
                    cout << "Es fuertemente conexo" << endl;
                }
                else{
                    cout << "No es fuertemente conexo" << endl;
                }
            }else{
                if(BFS()){
                    cout << "Es  fuertemente conexo" << endl;
                }
                else{
                    cout << "No es fuertemente conexo" << endl;
                }
            }
        }*/
        ///////////////////////////////////////////////////////////////////////////////
        void prim(){
            node* nodo=nodes[0];
            map<E,bool> visitado;
            int contador=0;
            multimap<E,edge*> aristas;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                visitado[(*ni)->get()]=false;
            }
            do{
                visitado[nodo->get()]=true;
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if(visitado.find((*ei)->nodes[1]->get())->second==false){
                        aristas.insert(pair<E,edge*>((*ei)->get(),*ei));
                    }
                    else if(visitado.find((*ei)->nodes[0]->get())->second==false){
                        aristas.insert(pair<E,edge*>((*ei)->get(),*ei));
                    }
                }
                if(visitado.find((aristas.begin()->second)->nodes[1]->get())->second==false){
                    nodo=(aristas.begin()->second)->nodes[1];
                }
                else{
                    nodo=(aristas.begin()->second)->nodes[0];
                }
                contador++;
                cout << (aristas.begin()->second)->nodes[0]->get() << (aristas.begin()->second)->nodes[1]->get() << endl;
                aristas.erase(aristas.begin());
            }
            while(contador!=visitado.size()-1);
            /*node* nodo=nodes[0];
            map<E,bool> visitado;
            visitado[nodo->get()]=true;
            int contador=1;
            multimap<E,edge*> aristas;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                visitado[(*ni)->get()]=false;
            }
            do{
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if(visitado.find((*ei)->nodes[1]->get())->second==false){
                        aristas.insert(pair<E,edge*>((*ei)->get(),*ei));
                    }
                }
                nodo=(aristas.begin()->second)->nodes[1];
                visitado[nodo->get()]=true;
                contador++;
                cout << (aristas.begin()->second)->nodes[0]->get() << (aristas.begin()->second)->nodes[1]->get() << endl;
                aristas.erase(aristas.begin());
            }
            while(contador!=visitado.size());*/
        }
        ///////////////////////////////////////////////////////////////////////////////
        void kruskal(){
            map<edge*,bool> visitado;
            multimap<E,edge*> aristas;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                    if(visitado.find((*ei))->second==false){
                        visitado[(*ei)]=true;
                        aristas.insert(pair<E,edge*>((*ei)->get(),*ei));
                    }
                }
            }
            typename multimap<E,edge*>::iterator it=aristas.begin();
            for(int x=0;x<nodes.size()-1;x++){
                cout << (*it).second->nodes[0]->get() << (*it).second->nodes[1]->get() << endl;
                it++;
            }
        }
        void Bipartito(){
            //DFS();
            if(bipartito){
                cout << "Es bipartito" << endl;
            }
            else{
                cout << "No es bipartito" << endl;
            }
        }
        ///////////////////////////////////////////////////////////////////////////////
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
        bool bipartito;
};
typedef Graph<Traits> graph;

#endif
