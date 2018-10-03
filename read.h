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
            double data;
            ifstream archivo("graph.txt");
            while (!archivo.eof()) {
            archivo >> data;
            cout << data << endl;
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
