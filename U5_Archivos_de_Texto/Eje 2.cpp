/*En un archivo de texto llamado lista.txt, como el que se muestra en el recuadro, se encuentran los nombres y notas
de los alumnos de una comisión de Programación Orientada a Objetos.
Lopez Javier
56 90
Garcia Ana
77 81
Farias Daniel
60 62
a) Escriba una función que reciba el nombre de un alumno y dos notas, y modifique el archivo reemplazando las dos
notas de ese alumno.
b) Escriba una función que lea la lista del archivo y genere otro archivo de texto promedios.txt con una tabla
donde cada línea posea el nombre, el promedio, y la condición final de cada uno de los alumnos. Ayuda: utilice
manipuladores de flujo (setw, right, left, fixed, setprecision) para dar formato a la tabla del archivo que se
genera en b.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

struct alumno {
	string nombre;
	int nota1;
	int nota2;
};

void reemplazar_notas (alumno a, string s){
	ifstream archi(s);
	if(not archi.is_open()) throw runtime_error("No se pudo leer lista.txt");
	vector<alumno>v;
	alumno b;
	while(getline(archi,b.nombre) and archi >> b.nota1 >> b.nota2){
		v.push_back(b);
		archi.ignore();
	}
	archi.close();
	bool encontro = false;
	for(size_t i=0;i<v.size();i++) { 
		if(a.nombre == v[i].nombre){
			v[i].nota1 = a.nota1;
			v[i].nota2 = a.nota2;
			encontro = true;
			break;
		}
	}
	ofstream archi1(s,ios::trunc);
	for(size_t i=0;i<v.size();i++) { 
		archi1 << v[i].nombre << endl;
		archi1 << v[i].nota1 << " " << v[i].nota2 << endl;
	}
	if(!encontro) cout << "No se encontro al alumno";
}

void cargar_tabla (vector<alumno>f, string s){
	ofstream archivo1(s);
	float prom;
	string condicion;
	archivo1 << setw(15) << left << "Nombre"
		<< setw(10) << right << "Promedio"
		<< setw(15) << right << "Condicion" << endl;
	archivo1 << "----------------------------------------" << endl;
	for(size_t i=0;i<f.size();i++) { 
		prom = (f[i].nota1 + f[i].nota2)/2;
		if (prom >= 60) {condicion = "Aprobado";}
		else {condicion = "Desaprobado";}
		archivo1 << setw(15) << left << f[i].nombre << setw(10)<< right 
			<< fixed << setprecision(2) << prom << setw(15) << right << condicion << endl;
	}
}

int main() {
	alumno a = {"Garcia Ana",90,90};
	reemplazar_notas(a,"lista.txt");
	ifstream archivo("lista.txt");
	if(not archivo.is_open()) throw runtime_error("No se pudo leer lista.txt");
	vector<alumno>f;
	alumno b;
	while(getline(archivo,b.nombre) and archivo >> b.nota1 >> b.nota2){
		f.push_back(b);
		archivo.ignore();
	}
	archivo.close();
	ifstream archivo1("promedios.txt");
	cargar_tabla(f,"promedios.txt");
	return 0;
}

