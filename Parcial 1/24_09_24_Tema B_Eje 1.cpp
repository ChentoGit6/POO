/*“Programadores Anónimos” es una página de preguntas y respuestas de programación, donde
los usuarios van ganando insignias y subiendo de nivel a medida que cumplen ciertos hitos (publicar su
primer pregunta, o su primer respuesta, recibir el primer “me gusta”, que su pregunta llega a las 1000
visitas, etc).
a) Implemente una clase Usuario para guardar los datos de un usuario: nombre y lista de insignias
(strings). La clase debe tener (1) un constructor para inicializar el nombre, (2) un método para consultarlo,
(3) un método para agregarle una insignia, (4) otro para consultar si el usuario tiene determinada insignia,
y (5) uno para calcular el nivel (nivel 0 si no tiene insignias, 1 si tiene menos de 5, 3 si tiene más de 10).
b) Implemente una clase ListaUsuarios para representar la lista de usuarios del sistema. La clase debe
tener métodos para: (1) agregar un nuevo usuario al sistema indicando su nombre; (2) métodos que
permitan consultar la lista completa; (3) agregarle una insignia a un usuario; y (4) calcular el porcentaje de
usuarios que tienen una determinada insignia que se pase como parámetro.
c) Escriba un programa de prueba que permita primero intentar registrar 10 usuarios (debe verificar que el
nombre no exista, y mostrar un mensaje de error si ya existe), luego registrar 50 insignias (ingresando por
cada una dos strings, nombre de usuario e insignia), y muestre la lista de usuarios completa indicando por
cada uno nombre y nivel. Finalmente permita ingresar una insignia e informe el porcentaje de usuarios que
la han conseguido.*/

#include <iostream>
#include <vector>
using namespace std;

class Usuario {
	string m_nombre;
	vector<string>m_insignias;
public:
	Usuario(string nombre) : m_nombre(nombre) {}
	string VerNombre() const {return m_nombre;}
	void AgregarInsignia(string i) {
		m_insignias.push_back(i);
	}
	bool TieneInsignia(string ins) const {
		for(size_t i=0;i<m_insignias.size();i++) { 
			if (m_insignias[i] == ins) return true;
		}
		return false;
	}
	int CalcularNivel() const {
		if (m_insignias.size() > 0 and m_insignias.size() < 5) return 1;
		if (m_insignias.size() > 5 and m_insignias.size() <= 10) return 2;
		if (m_insignias.size() > 10) return 3;
		return 0;
	}
};

class ListaUsuarios {
	vector<Usuario>u;
public:
	void AgregarUsuario(string nombre) {
		Usuario a(nombre);
		u.push_back(a);
	}
	int CantidadUsuarios() const {return u.size();}
	Usuario VerUsuario(int i) const {return u[i];}
	void AgregarInsigniaUsuario(string nombre, string ins){
		for(size_t i=0;i<u.size();i++) { 
			if (u[i].VerNombre() == nombre){
				u[i].AgregarInsignia(ins);
				break;
			}
		}
	}
	float PorcentajeInsignia(string ins) const {
		int cont = 0;
		for(size_t i=0;i<u.size();i++) { 
			if (u[i].TieneInsignia(ins)) ++cont;
		}
		return (cont/u.size() * 100);
	}
	bool Existe(string nombre) const {
		for(const Usuario &usuario : u){
			if(usuario.VerNombre() == nombre)
				return true;
		}
		return false;
	}
};

int main() {
	ListaUsuarios lu;
	for(int i=0;i<10;i++) { 
		string nombre;
		cout << "Ingrese nombre de ususario para armar la lista de ususarios" << endl;
		cin >> nombre;
		if (lu.Existe(nombre)) {
			cout << "Error! El usuario ya existe" << endl;
		} else {
			lu.AgregarUsuario(nombre);
		}
	}
	for(int i=0;i<50;i++) {
		string n,i;
		cout << "Ingrese nombre de la insignia y al usuario que le corresponde" << endl;
		cin >> i >> n;
		lu.AgregarInsigniaUsuario(n,i);
	}
	for(int i=0;i<lu.CantidadUsuarios();i++) { 
		cout << "Usuario: " << lu.VerUsuario(i).VerNombre() << " " << "Nivel: " << lu.VerUsuario(i).CalcularNivel() << endl;
	}
	string insignia;
	cout << "Ingrese insignia para ver el porcentaje de jugadores que la obtuvieron: ";
	cin >> insignia;
	cout << "%" << lu.PorcentajeInsignia(insignia) << " de jugadores obtuvieron la insignia " << insignia << endl;
	return 0;
}

