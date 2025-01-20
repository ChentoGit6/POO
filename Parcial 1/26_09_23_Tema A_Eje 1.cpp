/*Un color en un programa se suele modelar mediante 3 valores numéricos (entre 0 y 1)
que indican cuánto de luz roja(r), cuánto de luz verde(g) y cuánto de luz azul(b) hay que mezclar para
formarlo. Escriba una clase Color para representar un color de esta forma, con:
- un constructor que reciba los 3 valores, y métodos para consultarlos.
- una sobrecarga para el operador + que permita sumar dos colores. Por ej, si el primero tiene los
valores r=1, g=0.5, b=0, y el 2do r=0.2, g=0.2, b=0.2, el resultado tendrá r=1.2, g=0.7, b=0.2 (se suma
rojo con rojo, verde con verde y azul con azul).
- un método Normalizar que corrija los valores: si alguno es mayor a 1, que se le asigne 1. Por ej: r=1.2,
g=0.7, b=0.2 pasaría a ser r=1, g=0.7, b=0.2.
- una sobrecarga para mostrar un color por pantalla (debe mostrar los tres valores identificándolos con
las letras r, g y b. Por ej: "r=1.2, g=0.7, b=0.2")
b) En un videojuego, el personaje principal va cambiando de color a medida que adquiere poderes.
Cada vez que obtiene un nuevo poder el color del poder se suma a su color actual. Implemente una
clase Personaje con:
- Un constructor que reciba el nombre del jugador y su color inicial, y métodos para consultarlos.
- Un método TienePoder que reciba el nombre de un poder y retorne true si el personaje ya lo tiene (la
clase deberá guardar internamente los nombres de los poderes que tiene el personaje).
- Un método AgregarPoder que reciba el nombre (string) y el color de un poder. Si el personaje ya tenía
ese poder, el método debe retornar false. Si no lo tenía debe debe actualizar el color normalizado del
personaje (es decir, sumarlo al que tenía y normalizar el resultado) y retornar true.*/

#include <iostream>
#include <vector>
using namespace std;

class Color {
	float m_r, m_g, m_b;
public:
	Color(float r, float g, float b) : m_r(r), m_g(g), m_b(b) {}
	float VerRojo() const {return m_r;}
	float VerVerde() const {return m_g;}
	float VerAzul() const {return m_b;}
	Color operator+ (const Color &c) const {
		Color color(this->m_r + c.m_r, this->m_g + c.m_g, this->m_b + c.m_b);
		return color;
	}
	void Normalizar() {
		if (m_r > 1) m_r = 1;
		if (m_g > 1) m_g = 1;
		if (m_b > 1) m_b = 1;
	}
};

ostream& operator<<(ostream &o, const Color& c) {
	o << "r=" << c.VerRojo() << ", g=" << c.VerVerde() << ", b=" << c.VerAzul() << endl;
	return o;
}

class Personaje {
	string m_nombre;
	Color m_color;
	vector<string>poderes;
public:
	Personaje(string nombre, Color color) : m_nombre(nombre), m_color(color) {}
	string VerNombre() const {return m_nombre;}
	Color VerColor() const {return m_color;}
	bool TienePoder(string poder) {
		for(size_t i=0;i<poderes.size();i++) { 
			if(poder == poderes[i]) return true;
		}
		return false;
	}
	bool AgregarPoder(string poder, Color c){
		if(TienePoder(poder)) return false;
		poderes.push_back(poder);
		m_color = m_color + c;
		m_color.Normalizar();
		return true;
	}
};

int main() {
	Color c(1,0.5,0.5);
	Personaje f("Hello world",c);
	cout << f.VerColor();
	Color cc(1,1,1);
	f.AgregarPoder("fire",cc);
	cout << f.VerColor();
	return 0;
}

