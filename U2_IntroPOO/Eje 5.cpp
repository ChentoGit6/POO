/*Se dispone del siguiente tipo de dato:
struct Alumno {
string nombre;
float nota;
};
En base al mismo se desea crear una clase Curso para modelar el cursado de una materia. La clase deberá contener
el nombre de la materia y la cantidad de alumnos en el curso junto con una lista de los mismos. Proponga los
siguientes métodos:
1. Constructores y destructor según lo considere conveniente.
2. Un método que permita agregar un alumno recibiendo su nombre.
3. Un método que permita modificar la nota de un alumno (buscándolo por su nombre).
4. Métodos para poder consultar estos datos.
5. Un método que determine el promedio del curso.
6. Un método para obtener la calificación más alta y el nombre del alumno que la obtuvo
*/

#include <iostream>
#include <vector>
using namespace std;

struct Alumno {
	string nombre;
	float nota;
};

class Curso {
	string m_materia;
	vector<Alumno>v;
public:
	Curso (string nom) : m_materia(nom) {}
	void Agregar_Alu (string nombre){
		v.push_back({nombre,0});
	}
	void Cant_Alum(){cout << v.size();}
	void Modificar_Nota (string name, float note){
		for(size_t i=0;i<v.size();i++) { 
			if (v[i].nombre == name) {
				v[i].nota = note;
				break;
			}
		}
	}
	void Mostrar_Alumnos(){
		for(size_t i=0;i<v.size();i++) { 
			cout << "Alumno: " << v[i].nombre << " - Nota: " << v[i].nota << endl;
		}
	}
	void Ver_Datos (string name){
		for(size_t i=0;i<v.size();i++) { 
			if (v[i].nombre == name){
				cout << "Alumno: " << v[i].nombre << " - Nota: " << v[i].nota << endl;
				return;
			}
		}
		cout << "Alumno no encontrado";
	}
	float Prom_Curso(){
		float p = 0;
		for(size_t i=0;i<v.size();i++) { 
			p += v[i].nota;
		}
		return p/v.size();
	}
	Alumno Mejor_Alu(){
		float mayor = 0.0;
		string s;
		for(size_t i=0;i<v.size();i++) { 
			if (v[i].nota > mayor){
				mayor = v[i].nota;
				s = v[i].nombre;
			}
		}
		return {s,mayor};
	}
};

int main() {
	Curso curso("Matemáticas");
	
	curso.Agregar_Alu("Juan");
	curso.Agregar_Alu("María");
	curso.Agregar_Alu("Pedro");
	
	curso.Modificar_Nota("Juan", 9.5);
	curso.Modificar_Nota("María", 8.0);
	curso.Modificar_Nota("Pedro", 7.5);
	
	curso.Ver_Datos("María");
	
	curso.Mostrar_Alumnos();
	
	cout << "Promedio del curso: " << curso.Prom_Curso() << endl;
	
	Alumno mejor = curso.Mejor_Alu();
	cout << "Mejor Alumno: " << mejor.nombre << " con nota: " << mejor.nota << endl;
	return 0;
}

