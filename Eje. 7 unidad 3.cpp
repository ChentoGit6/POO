#include <iostream>
using namespace std;
/*a) Complete la clase RectaGeneral para representar una recta mediante su ecuaci�n general: Ax + By + C = 0,
a partir de dos puntos. La definici�n de la clase se muestra en el siguiente recuadro:
class RectaGeneral {
public:
RectaGeneral(Punto p, Punto q);
float verA();
float verB();
float verC();
string obtenerEcuacion();
bool pertenece(Punto p);
private:
float a, b, c;
};
b) Dise�e un �rbol de herencia que incluya una clase Recta, y dos clases herederas llamadas RectaExplicita
y RectaGeneral (modifique las versiones ya implementadas en este ejercicio y el anterior). c) Utilizando los
conceptos de polimorfismo, m�todos virtuales y abstractos, complemente el dise�o con dos m�todos virtuales:
obtenerEcuacion(�), para mostrar en pantalla la ecuaci�n que corresponda para cada recta, y pertenece(�) para
saber si un tercer punto dado est� en la recta.
Ayuda:
� Las ecuaciones para obtener los coeficientes a, b y c de la ecuaci�n general son:
a = Qy - Py,  b= Px - Qx,  c= -aPx - bPy
*/
struct Punto {
	int x, y;
};
class Recta {
	
};
class RectaGeneral {
private:
	float a, b, c;
public:
	RectaGeneral(Punto p, Punto q) : a(q.y - p.y), b(p.x - q.x), c(-a*p.x - b*p.y);
	float verA()const &{return a};
	float verB()const &{return b};
	float verC()const &{return c};
	string obtenerEcuacion(){
		string a1 = to_string(a);
		string b1 = to_string(b);
		string c1 = to_string(c);
	return a1 + "x + " + b1 + "y + " + c1 + " = 0";	
	};
	bool pertenece(Punto p){
		if (0== a*P.x + b*P.y + c){
			return true;
		}
		return false;
	};
};

int main() {
	
	return 0;
}

