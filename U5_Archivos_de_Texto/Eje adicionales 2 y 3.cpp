/*Escriba un archivo de texto desde un editor de textos cualquiera (por ejemplo: el Bloc de Notas de Windows). Dicho
archivo debe contener los nombres y números telefónicos de N personas con el formato mostrado en el recuadro.
Guarde el archivo con el nombre agenda.txt u otro nombre de su elección.
Lopez Javier
342569085
Garcia Ana
342778180
Farias Daniel
342606234
a)Diseñe una clase llamada Agenda con un arreglo de structs que permita almacenar nombres y números telefónicos
de un conjunto de personas. b) Implemente un método Cargar que reciba un objeto de tipo std::string con el
nombre del archivo que contiene los datos. El mismo debe abrir el archivo y cargar los datos de las personas en
retornando un bool que indique si la lectura se realizó con éxito (true) o si ocurrieron errores durante la apertura
del archivo (false). c) Implemente un método Buscar que debe recibir un std::string con parte del nombre o del
apellido de un contacto y devuelva los datos de la primer ocurrencia que coincida con dicha cadena. d) Codifique un
programa cliente que cargue los datos del archivo, informa la cantidad de personas cargadas y permita realizar un
búsqueda.
Ejercicio 3
Agregue a la clase desarrollada en el ejercicio anterior un método AgregarContacto(...) que reciba los datos de
un nuevo contacto, y lo agregue al arreglo; y agregue un método Guardar que actualice el archivo. Utilice la función
desde un programa cliente para agregar un nuevo contacto y abra nuevamente el archivo desde un editor de texto
para comprobar que los datos fueron agregados correctamente.
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Persona {
	string nombre;
	int telefono;
};

class Agenda {
	vector<Persona>m_p;
public:
	Agenda() {}
	bool Cargar(string s){
		ifstream archi(s);
		if(archi.is_open()){
			Persona a;
			while(getline(archi,a.nombre) and archi >> a.telefono){
				m_p.push_back(a);
				archi.ignore();
			}
			archi.close();
			return true;
		}
		return false;
	}
	Persona Buscar(string f){
		for(size_t i=0;i<m_p.size();i++) { 
			if (m_p[i].nombre.find(f) != string::npos){
				return {m_p[i].nombre,m_p[i].telefono};
			}
		}
		return {"no",0};
	}
	void AgregarContacto(Persona p){
		m_p.push_back(p);
	}
	void Guardar(string s) {
		ofstream archi2(s, ios::trunc);
		for(size_t i=0;i<m_p.size();i++) { 
			archi2 << m_p[i].nombre << endl;
			archi2 << m_p[i].telefono << endl;
		}
	}
};

int main() {
	Agenda agenda;
	agenda.Cargar("personastelefono.txt");
	Persona a;
	string s;
	cout << "Ingrese parte de cualquier nombre para buscarlo en el archivo: "; cin >> s;
	a = agenda.Buscar(s);
	cout << a.nombre << "  " << a.telefono;
	Persona p;
	cout << endl;
	cin.ignore();
	cout << "Agregar persona:" << endl;
	cout << "Nombre: ";getline(cin,p.nombre);
	cout << "Telefono: "; cin >> p.telefono;
	agenda.AgregarContacto(p);
	agenda.Guardar("personastelefono.txt");
	return 0;
}

