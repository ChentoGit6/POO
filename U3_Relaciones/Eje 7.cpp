/*a) Complete la clase RectaGeneral para representar una recta mediante su ecuación general: Ax + By + C = 0,
a partir de dos puntos. La definición de la clase se muestra en el siguiente recuadro:
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
b) Diseñe un árbol de herencia que incluya una clase Recta, y dos clases herederas llamadas RectaExplicita
y RectaGeneral (modifique las versiones ya implementadas en este ejercicio y el anterior). c) Utilizando los
conceptos de polimorfismo, métodos virtuales y abstractos, complemente el diseño con dos métodos virtuales:
obtenerEcuacion(…), para mostrar en pantalla la ecuación que corresponda para cada recta, y pertenece(…) para
saber si un tercer punto dado está en la recta.
Ayuda:
• Las ecuaciones para obtener los coeficientes a, b y c de la ecuación general son:
a = Qy - Py,  b= Px - Qx,  c= -aPx - bPy
*/
#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
	int x, y;
};

class Recta {
public:
	virtual string ObtenerEcuacion() const = 0;
	virtual bool Pertenece(Punto p) const = 0;
	virtual ~Recta() {};
};

class RectaGeneral : public Recta {
private:
	float a, b, c;
public:
	RectaGeneral(Punto p, Punto q) : a(q.y - p.y), b(p.x - q.x), c(-a*p.x - b*p.y) {}
	float verA()const &{return a;};
	float verB()const &{return b;};
	float verC()const &{return c;};
	string ObtenerEcuacion() const override {
		string a1 = to_string(a);
		string b1 = to_string(b);
		string c1 = to_string(c);
	return a1 + "x + " + b1 + "y + " + c1 + " = 0";	
	};
	bool Pertenece(Punto p) const override {
		if (0 == a*p.x + b*p.y + c){
			return true;
		}
		return false;
	};
};

class RectaExplicita : public Recta {
private:
	float m, b;
public:
	RectaExplicita(Punto P, Punto Q) : m((Q.y-P.y)/(Q.x-P.x)), b(P.y - ((Q.y-P.y)/(Q.x-P.x))*P.x){};
	float VerM()const &{return m;};
	float VerB()const &{return b;};
	string ObtenerEcuacion() const override {
		string m1 = to_string(m);
		string b1 = to_string(b);
		return "y = " + m1 + "x + " + b1;
	};
		bool Pertenece(Punto T) const override {
			if (fabs (m*T.x + b - T.y) < 1e-6){
				return true;
			}
			return false;
		};
};

int main() {
	Punto p1, p2, p3;

	cout << "Ingrese las coordenadas del primer punto (P1):\n";
	cout << "x: "; cin >> p1.x;
	cout << "y: "; cin >> p1.y;
	
	cout << "Ingrese las coordenadas del segundo punto (P2):\n";
	cout << "x: "; cin >> p2.x;
	cout << "y: "; cin >> p2.y;

	RectaGeneral rg(p1, p2);
	cout << "Ecuacion de la recta general: " << rg.ObtenerEcuacion() << endl;
	
	RectaExplicita re(p1, p2);
	cout << "Ecuacion de la recta explicita: " << re.ObtenerEcuacion() << endl;
	
	cout << "Ingrese las coordenadas de un punto para verificar si pertenece:\n";
	cout << "x: "; cin >> p3.x;
	cout << "y: "; cin >> p3.y;
	
	cout << "El punto pertenece a la recta general? " 
		<< (rg.Pertenece(p3) ? "Si" : "No") << endl;
	cout << "El punto pertenece a la recta explicita? " 
		<< (re.Pertenece(p3) ? "Si" : "No") << endl;
	
	return 0;
}

