#include <iostream>
using namespace std;
/*Proponga un struct Punto con atributos para definir un punto en el plano (coordenadas x e y). Luego, complete
la clase RectaExplicita para definir la ecuaci�n expl�cita de la recta a partir de dos puntos: y = mx + b. La
declaraci�n de dicha clase se muestra en el recuadro siguiente:
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
El m�todo obtenerEcuacion() debe retornar una cadena de texto con la ecuaci�n expl�cita de la recta, mientras que
el m�todo pertenece(p) debe determinar si el punto p est� o no sobre la recta (si satisface la ecuaci�n).
Ayudas:
� Las ecuaciones para obtener m y b a partir de dos puntos P y Q son:
m = (Qy - Py)/(Qx - Px) b = Py - mPx
� La funci�n string to_string(float) le permitir� convertir los coeficientes a strings; y adem�s es posible
concatenar strings con el operador + (s=s1+s2).
� Al comparar flotantes en pertenece, no debe utilizar ==, sino preguntar de alguna otra forma si son muy
parecidos en lugar de exactamente iguales (los c�lculos con floats tienen errores de truncamiento/redondeo
menores a 1e-6)
*/

struct Punto {
	int x, y;
};
class RectaExplicita {
private:
	float m, b;
public:
	RectaExplicita(Punto P, Punto Q) : m((Q.y-P.y)*1.0/(Q.x-P.x)), b(P.y - ((Q.y-P.y)/(Q.x-P.x))*1.0*P.x){};
	float verM()const &{return m;};
	float verB()const &{return b;};
	string obtenerEcuacion(){
		string m1 = to_string(m);
		string b1 = to_string(b);
		return "y = " + m1 + "x + " + b1;
	};
	bool pertenece(Punto P){
		if (P.y == m*P.x + b){
			return true;
		}
		return false;
	};
	
};

int main() {
	Punto p,q,t;
	p.x = 5;
	p.y = 3;
	q.x = 2;
	q.y = 2;
	t.x = 1;
	t.y = 1;
	RectaExplicita f(p, q);
	cout << f.obtenerEcuacion()<<endl;
	cout << f.pertenece(t)<<endl;
	cout << f.verM()<<endl;
	cout << f.verB();
	return 0;
}

