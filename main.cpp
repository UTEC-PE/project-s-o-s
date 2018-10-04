//#include <GL/glut.h>
#include <iostream>
#include "read.h"

using namespace std;
int main(int argc, char *argv[]) {
    graph grafo;
    grafo.Insertar_Vertices(5,6,'0');
    grafo.Insertar_Vertices(3,4,'1');
    grafo.Insertar_Vertices(6,8,'2');
    grafo.Insertar_Aristas(0,1,5,0);
    grafo.Insertar_Aristas(1,2,5,0);
    grafo.Insertar_Aristas(0,2,5,0);
    grafo.print();
    //grafo.Eliminar_Aristas('0','1');
    grafo.Eliminar_Nodos('0');
    grafo.print();
    //read leer;
    system("PAUSE");
    return EXIT_SUCCESS;
}
