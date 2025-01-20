/*Proponga una clase Persona para representar a una persona a partir de su nombre, apellido y fecha 
de nacimiento con día, mes y año. Diseñe una clase llamada RecursosHumanos que permita manejar los 
datos de un grupo de personas. La clase debe poseer métodos para:
1. Guardar los datos de las personas en un archivo binario.
2. Cargar los datos de las personas desde un archivo binario.
3. Agregar una persona.
4. Eliminar una persona a partir de su nombre o apellido.
5. Indicar la cantidad de personas en la base de datos.*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct fecha {
	int dia, mes, anio;
};

struct persona {
	string nombre_apellido;
	fecha fecha_nacimiento;
};

class Persona {
	persona m_anonima;
public:
	Persona(persona p) : m_anonima(p) {}
	string VerNombre() const {return m_anonima.nombre_apellido;}
	fecha VerFechaNacimiento() const {return m_anonima.fecha_nacimiento;}
};

class RecursosHumanos {
	vector<persona>m_v;
	string m_nombre;
public:
	RecursosHumanos(vector<persona>v, string n) : m_v(v), m_nombre(n) {}
	void GuardarDatos(){
		string s;
		for(size_t i=0;i<m_v.size();i++) { 
			s += m_v[i].nombre_apellido;
			s += m_v[i].fecha_nacimiento.dia;
			s += m_v[i].fecha_nacimiento.mes;
			s += m_v[i].fecha_nacimiento.anio;
		}
		char aux[100000];
		strcpy(aux,s.c_str());
		ofstream archi(m_nombre,ios::binary);
		archi.write(aux,sizeof(aux));
	}
};

int main() {
	
	return 0;
}

