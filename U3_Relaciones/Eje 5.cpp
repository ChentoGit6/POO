/*Proponga un struct Punto con atributos para definir un punto en el plano (coordenadas x e y). Luego, complete
la clase RectaExplicita para definir la ecuación explícita de la recta a partir de dos puntos: y = mx + b. La
declaración de dicha clase se muestra en el recuadro siguiente:
class RectaExplicita {
public:
RectaExplicita(Punto p, Punto q);
float verM();
float verB();
string obtenerEcuacion();
bool pertenece(Punto p);
private:
float m, b;
};
El método obtenerEcuacion() debe retornar una cadena de texto con la ecuación explícita de la recta, mientras que
el método pertenece(p) debe determinar si el punto p está o no sobre la recta (si satisface la ecuación).
Ayudas:
• Las ecuaciones para obtener m y b a partir de dos puntos P y Q son:
m = (Qy - Py)/(Qx - Px) b = Py - mPx
• La función string to_string(float) le permitirá convertir los coeficientes a strings; y además es posible
concatenar strings con el operador + (s=s1+s2).
• Al comparar flotantes en pertenece, no debe utilizar ==, sino preguntar de alguna otra forma si son muy
parecidos en lugar de exactamente iguales (los cálculos con floats tienen errores de truncamiento/redondeo
menores a 1e-6)
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
	float x, y;
};

class RectaExplicita {
private:
	float m, b;
public:
	RectaExplicita(Punto P, Punto Q) : m((Q.y-P.y)/(Q.x-P.x)), b(P.y - ((Q.y-P.y)/(Q.x-P.x))*P.x){};
	float VerM()const &{return m;};
	float VerB()const &{return b;};
	string ObtenerEcuacion(){
		string m1 = to_string(m);
		string b1 = to_string(b);
		return "y = " + m1 + "x + " + b1;
	};
	bool Pertenece(Punto T){
		if (fabs (m*T.x + b - T.y) < 1e-6){
			return true;
		}
		return false;
	};
};

int main() {
	Punto p,q,t;
	cout << "Declare dos puntos para armar la recta:" << endl;
	cout << " Punto P:" << endl; 
	cout << "         x = "; cin >> p.x; 
	cout << "         y = "; cin >> p.y;
	cout << " Punto Q:" << endl; 
	cout << "         x = "; cin >> q.x; 
	cout << "         y = "; cin >> q.y;
	RectaExplicita f(p, q);
	cout << f.ObtenerEcuacion()<<endl;
	cout << "Declare un punto para ver si pertenece a la recta:" << endl;
	cout << " Punto T:" << endl; 
	cout << "         x = "; cin >> t.x; 
	cout << "         y = "; cin >> t.y;
	if (f.Pertenece(t) == 1){
		cout << "El punto pertenece a la recta";
	} else {
		cout << "El punto no pertenece a la recta";
	}
	cout << endl;
	return 0;
}

