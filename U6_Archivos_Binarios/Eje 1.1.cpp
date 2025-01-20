/*a) Escriba a través de un programa C++ un archivo binario llamado grupo.dat, formado por un conjunto de 200 pares
de números generados aleatoriamente. Cada par de datos se conforma por un entero y un flotante.
b) Escriba otro programa que lea el archivo generado por el primero para verificar si se escribieron correctamente.*/

#include <iostream>
#include <fstream>
using namespace std;

struct par {
	int entero;
	float flotante;
};

int main() {
	ofstream archi("grupo.dat",ios::binary);
	for(int i=0;i<200;i++) { 
		par p;
		p.entero = rand()%100+1;
		p.flotante = (rand()%1001)/1000.0;
		archi.write(reinterpret_cast<char*>(&p),sizeof(p));
	}
	archi.close();
	return 0;
}

