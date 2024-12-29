#include <iostream>
#include <vector>
using namespace std;
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
e) Finalmente responda:
• Puede crearse un objeto de tipo persona? ¿Para qué podría servir?
• ¿Existe alguna clase abstracta en la jerarquía?
*/

class Persona{
private:
	string apellido, nombre;
	int fecha_nac;
	
public:
	Persona(string a, string n, int f) : apellido(a), nombre(n), fecha_nac(f) {}
	
	float calc_edad(int fecha_act){
		int edad = (fecha_act - fecha_nac) / 10000;
//		int dia = fecha_act/1000000;
//		int mes = (fecha_act/10000) % 100;
//		int anio = fecha_act % 10000;
//		
//		int dianac = fecha_nac/1000000;
//		int mesnac = (fecha_nac/10000) % 100;
//		int anionac = fecha_nac % 10000;
		return edad;
	}
};

class Alumno : public Persona{
private: 
	int anio_nac;
	float prom;
	int materias_aprob;
	
public:
	Alumno(string a, string n, int an, float p, int ma, int f) : Persona(a, n, f), anio_nac(an), prom(p), materias_aprob(ma){}
	
	void agregarmateria (int nota, int mat_rend){
		prom = ((prom * mat_rend + nota) / (mat_rend + 1);
		mat_rend ++;
	}
	float calcularmeritoacademico (){
		float merito = prom * materias_aprob;
		return merito;
	}
	float verpromedio(){
		return prom;
	}
};

class Docente : Persona{
private: 
	int fecha_ing;
	
public:
	Docente(string a, string n, int f, int fi) : Persona(a, n, f), fecha_ing(fi){}
	
	int calcularantiguedad (int fecha_act){
		int antiguedad = (fecha_act - fecha_ing) / 10000;
		return antiguedad;
	}
};

class Curso{
private:
	string m_nombre_curso;
	Docente m_profe;
	int m_cant_max;
	vector<Alumno>v;
public:
	void agregar_alumno(Alumno alu){
		if(v.size() < m_cant_max){
			v.push_back(alu);
		}
	}
	Alumno mejorpromedio(){
		int may = 0;
		int indice = -1;
		for(size_t i=0;i<v.size();i++) { 
			if (v[i].verpromedio() > may){
				may = v[i].verpromedio();
				indice = i;
			}
		}
		return v[indice];
	}
	
};

int main() {
	int fecha_act = 20240906, fecha_nac, nota, mat_rend, mat_aprob;
	int anio = fecha_nac/10000;
	float prom;
	string nombre, apellido;
	cout << "Ingrese la fecha de nacimiento: "; cin >> fecha_nac;
	cout << "Ingrese el nombre y apellido: "; cin >> nombre >> apellido;
	cout << "Ingrese el promedio y cantidad de materias aprobadas: "; cin >> prom >> mat_aprob;
	Alumno alumno1(apellido, nombre, anio, prom, mat_aprob, fecha_nac);

	cout << "Edad del alumno: "<< alumno1.calc_edad(fecha_act) << " años"<< endl;
	cout << "Ingrese la nota del alumno y el número de materia rendida: "; cin >> nota >> mat_rend;
	alumno1.agregarmateria(nota, mat_rend);
	cout << "Mérito del alumno: "<< alumno1.calcularmeritoacademico() << endl;
	return 0;
}

