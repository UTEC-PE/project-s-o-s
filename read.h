#ifndef READ_H
#define READ_H
#include <fstream>
#include "graph.h"
#include <string>

/**
 * Clase de ayuda para leer el grafo desde un archivo,
 * no es necesario que la utilicen, podrían implementar su lector
 * desde su grafo o algún otro lado
 **/
template <typename G>
class Read {
	typedef typename G::N N;
	typedef typename G::E E;
	public:
		Read() {
            // TODO
            int v_inicial,v_final,peso;
            ////////////////
            string data;
            ifstream archivo("graph.txt");
            archivo >> data;
            graph grafo(stoi(data));
            archivo >> data;
            for(int x=0;x<stoi(data);x++){
                grafo.Insertar_Vertices(0,0,x);
            }
            while (!archivo.eof()) {
                for(int x=0;x<3;x++){
                    archivo >> data;
                    switch(x){
                    case 0:
                        v_inicial=stoi(data);
                        break;
                    case 1:
                        v_final=stoi(data);
                        break;
                    case 2:
                        peso=stoi(data);
                        break;
                    }
                }
                grafo.Insertar_Aristas(v_inicial,v_final,peso);
            }
            archivo.close();
            grafo.Inicio();
        };

		graph& getGraph() {
            // TODO
        };
};
typedef Read<Traits> read;
#endif
