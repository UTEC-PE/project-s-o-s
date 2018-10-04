#ifndef READ_H
#define READ_H
#include <fstream>
#include "graph.h"

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
            int ejex,ejey;
            char vertice_data;
            int n_vertices;
            int v_inicial,v_final,peso;
            bool direccion;
            ////////////////
            string data;
            int aux;
            ifstream archivo("graph.txt");
            while(getline(archivo, data)) {
                for(int x=0;x<data.size();x++){
                    if(data[x]==' '){
                    }
                }
            }
            archivo.close();
            system("pause");
        };

		graph& getGraph() {
            // TODO
        };
};
typedef Read<Traits> read;

#endif
