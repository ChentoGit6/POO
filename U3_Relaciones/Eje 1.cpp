/*a) Diseñe una clase Persona que contenga los siguientes atributos: apellido y nombre, y fecha de nacimiento. La
clase debe poseer, además, un método CalcularEdad(...) que permita obtener la edad actual de la persona en
base a la fecha de nacimiento y la fecha actual.
b) Implemente una clase Alumno para contener la siguiente información de un alumno: apellido y nombre, año de
nacimiento, promedio y cantidad de materias aprobadas. La clase debe poseer, además dos métodos adicionales:
AgregarMateria(...) para actualizar el promedio y la cantidad de materias cada vez que el alumno rinde una nueva
materia; y CalcularMeritoAcademico(...) que retorne el mérito académico del alumno, el cual se calcula como el
producto entre el promedio y la cantidad de materias aprobadas.
c) Cree, también, una clase Docente para modelar un docente a partir de la siguiente información: apellido y nombre,
año de nacimiento y fecha de ingreso. La clase debe poseer, además, un método CalcularAntiguedad(...) que
calcule la antigüedad del docente en base a su fecha de ingreso y la fecha actual.
Notas: Para b) y c) proponga una jerarquía de clases adecuada para evitar repetir atributos. Implemente todos los
constructores y los métodos adicionales que considere adecuados.
d) Codifique un programa cliente que cree instancias de Alumno y Docente y utilice sus métodos para verificar su
correcto funcionamiento.
e) Utilice las clases Alumno y Docente del ejercicio anterior para crear una clase Curso que modele el cursado de
una materia. Cada curso tiene un nombre, un profesor a cargo y un número máximo de alumnos. Implemente un
método AgregarAlumno(...) que permita agregar un alumno al curso (si es que no se llegó al cupo), y otro método
MejorPromedio(...) que devuelva el alumno con mejor promedio. Proponga los constructores y métodos extra que
considere necesarios.
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Persona {
	string m_nombre, m_apellido;
	int m_fecha_nac;
public:
	Persona(string nombre, string apellido, int fecha_nac) : m_nombre(nombre), m_apellido(apellido), m_fecha_nac(fecha_nac) {}
	int CalcularEdad (int fecha_act){
		int edad = trunc((fecha_act - m_fecha_nac) / 10000);
		return edad;
	}
	void Mostrar() {
		cout << "Apellido y nombre: " << m_apellido << " " << m_nombre << endl;
		cout << "Fecha de nacimiento: " << m_fecha_nac << endl;
	} 
};

class Alumno : public Persona {
	float m_prom;
	int m_cant_materias_aprob;
public:
	Alumno(string n, string a, int f, float p, int ma) : Persona(n,a,f), m_prom(p), m_cant_materias_aprob(ma) {}
	void AgregarMateria(float nota, int mat_rendida){
		m_prom = (m_prom * mat_rendida + nota) / (mat_rendida + 1);
		mat_rendida ++;
	}
	float CalcularMeritoAcademico() {return m_prom * m_cant_materias_aprob;}
	void Mostrar() {
		Persona :: Mostrar();
		cout << "Promedio: " << m_prom << endl;
		cout << "Materias aprobadas: " << m_cant_materias_aprob << endl;
	}
	float GetPromedio () {return m_prom;}
	
};
class Docente : public Persona {
	int m_fecha_ingreso;
public:
	Docente(string nom, string ap, int fn, int fi) : Persona(nom,ap,fn), m_fecha_ingreso(fi) {} 
	int CalcularAntiguedad (int fecha_act){
		int antiguedad = trunc((fecha_act - m_fecha_ingreso) / 10000);
		return antiguedad;
	}
	void Mostrar(int fecha_act) {
		cout << "Antiguedad: " << CalcularAntiguedad(fecha_act) << " años" << endl;
	}
	
};

class Curso {
	string m_nombre;
	Docente* m_d;
	int m_num_max_alu;
	vector<Alumno*>m_v;
public:
	Curso(string nombre, Docente* profesor, int max_alumnos) : m_nombre(nombre), m_d(profesor), m_num_max_alu(max_alumnos) {}
	bool Agregar_Alumno(Alumno* alu){
		if(m_v.size() < m_num_max_alu){
			m_v.push_back(alu);
			return true;
		} 
		return false;
	}
	Alumno* MejorPromedio() {
		if (m_v.empty()) {
			cout << "No hay alumnos en el curso." << endl;
			return nullptr;
		}
		Alumno* mejorAlumno = m_v[0];
		for (auto& alumno : m_v) {
			if (alumno->GetPromedio() > mejorAlumno->GetPromedio()) {
				mejorAlumno = alumno;
			}
		}
		return mejorAlumno;
	}
};
int main() {
	int opcion, fecha_actual = 20250101;
	vector<Alumno*> alumnos;
	Docente* docente = nullptr;
	Curso* curso = nullptr;
	
	cout << "Ingrese datos del docente a cargo del curso:" << endl;
	string nombre_docente, apellido_docente;
	int fecha_nac_docente, fecha_ingreso;
	cout << "Nombre: ";
	cin >> nombre_docente;
	cout << "Apellido: ";
	cin >> apellido_docente;
	cout << "Fecha de nacimiento (AAAAMMDD): ";
	cin >> fecha_nac_docente;
	cout << "Fecha de ingreso (AAAAMMDD): ";
	cin >> fecha_ingreso;
	docente = new Docente(nombre_docente, apellido_docente, fecha_nac_docente, fecha_ingreso);
	docente->Mostrar(fecha_actual);
	string nombre_curso;
	int max_alumnos;
	cout << "Ingrese el nombre del curso: ";
	cin >> nombre_curso;
	cout << "Ingrese el número máximo de alumnos: ";
	cin >> max_alumnos;
	curso = new Curso(nombre_curso, docente, max_alumnos);
	
	do {
		cout << "\n1. Agregar alumno\n2. Mostrar alumno con mejor promedio\n3. Salir\n";
		cout << "Ingrese una opción: ";
		cin >> opcion;
		
		if (opcion == 1) {
			string nombre, apellido;
			int fecha_nac;
			float promedio;
			int materias_aprobadas;
			
			cout << "Ingrese el nombre del alumno: ";
			cin >> nombre;
			cout << "Ingrese el apellido del alumno: ";
			cin >> apellido;
			cout << "Ingrese la fecha de nacimiento del alumno (AAAAMMDD): ";
			cin >> fecha_nac;
			cout << "Ingrese el promedio del alumno: ";
			cin >> promedio;
			cout << "Ingrese la cantidad de materias aprobadas: ";
			cin >> materias_aprobadas;
			
			Alumno* nuevo_alumno = new Alumno(nombre, apellido, fecha_nac, promedio, materias_aprobadas);
			if (curso->Agregar_Alumno(nuevo_alumno)) {
				alumnos.push_back(nuevo_alumno);
				cout << "Alumno agregado exitosamente al curso.\n";
			} else {
				cout << "El curso ya alcanzó el máximo de alumnos.\n";
				delete nuevo_alumno;
			}
		} else if (opcion == 2) {
			Alumno* mejor = curso->MejorPromedio();
			if (mejor) {
				cout << "El alumno con mejor promedio es:\n";
				mejor->Mostrar();
			} else {
				cout << "No hay alumnos en el curso.\n";
			}
		}
	} while (opcion != 3);
	
	// Liberar memoria dinámica
	delete docente;
	delete curso;
	for (Alumno* alumno : alumnos) {
		delete alumno;
	}
	
	return 0;
}
