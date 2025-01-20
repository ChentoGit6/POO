/*Escriba un programa abra el archivo generado en el ejercicio anterior y solicite al usuario que ingrese un entero, un
flotante y una posición. El programa debe sobrescribir el par en la posición ingresada por el usuario por el nuevo par.
Luego muestre la lista de datos en consola mostrando un par por línea.*/

#include <iostream>
#include <fstream>
using namespace std;

struct par {
	int entero;
	float flotante;
};

int main() {
	fstream archi("grupo.dat",ios::in | ios::out | ios::binary);
	par p;
	int pos;
	cin >> p.entero >> p.flotante >> pos;
	archi.seekp((pos-1)*sizeof(par));
	archi.write(reinterpret_cast<char*>(&p), sizeof(p));
	archi.seekp(0);
	par p1;
	for(int i=0;i<200;i++) { 
		archi.read(reinterpret_cast<char*>(&p1),sizeof(par));
		cout << p1.entero << "  " << p1.flotante << endl;
	}
	archi.close();
	return 0;
}

