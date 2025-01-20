/*Proponga una clase EcuacionCuadratica para modelar ecuaciones cuadráticas de la forma ax^2 + bx + c = 0 .
La clase debe incluir:
1. Un constructor que reciba los valores de los coeficientes a, b y c.
2. Un método TieneRaicesReales(...) que retorne verdadero si las raíces de la ecuación son reales.
3. Dos métodos VerRaiz1(...) y VerRaiz2(...) que permitan obtener las raíces reales (en caso de que lo
sean).
4. Dos métodos VerParteReal(...) y VerParteImag(...) que permitan obtener las partes real e imaginaria de
las raíces complejas (en caso de que lo sean).
5. Cree un programa cliente que utilice un objeto de la clase EcuaciónCuadratica para determinar las raíces de
una ecuación cuadrática cuyos coeficientes sean ingresados por el usuario, y las muestre en el formato que
corresponda (según sean reales o complejas).
*/

#include <iostream>
#include <cmath>
using namespace std;

class EcuacionCuadratica {
	float m_a, m_b, m_c, m_r1, m_r2;
	bool son_reales;
	void Calcular();
public:
	EcuacionCuadratica (float a, float b, float c) : m_a(a), m_b(b), m_c(c) {
		son_reales = false;
		Calcular();
	}
	bool TieneRaicesReales() {return son_reales;}
	float VerRaiz1(){return son_reales ? m_r1 : 0;}
	float VerRaiz2(){return son_reales ? m_r2 : 0;}
	float VerParteReal(){return !son_reales ? m_r1 : 0;}
	float VerParteImag(){return !son_reales ? m_r2 : 0;}
};

void EcuacionCuadratica :: Calcular (){
	float d = m_b*m_b-4*m_a*m_c;
	if (d >= 0){
		son_reales = true;
		m_r1 = (-m_b+sqrt(d))/(2*m_a);
		m_r2 = (-m_b-sqrt(d))/(2*m_a);
	} else {
		m_r1 = -m_b/(2*m_a);
		m_r2 = sqrt(-d)/(2*m_a);
	}
}

int main() {
	float a, b, c;
	cout << "Ingrese los coeficientes de la ecuación cuadrática (a, b, c):" << endl;
	cin >> a >> b >> c;
	EcuacionCuadratica eq(a, b, c);
	if (eq.TieneRaicesReales()) {
		cout << "Las raíces son reales:" << endl;
		cout << "Raíz 1: " << eq.VerRaiz1() << endl;
		cout << "Raíz 2: " << eq.VerRaiz2() << endl;
	} else {
		cout << "Las raíces son complejas:" << endl;
		cout << "Raíz 1: " << eq.VerParteReal() << " + " << eq.VerParteImag() << "i" << endl;
		cout << "Raíz 2: " << eq.VerParteReal() << " - " << eq.VerParteImag() << "i" << endl;
	}
	
	return 0;
}

