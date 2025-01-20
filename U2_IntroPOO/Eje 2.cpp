/*Proponga una clase EcuacionCuadratica para modelar ecuaciones cuadr�ticas de la forma ax^2 + bx + c = 0 .
La clase debe incluir:
1. Un constructor que reciba los valores de los coeficientes a, b y c.
2. Un m�todo TieneRaicesReales(...) que retorne verdadero si las ra�ces de la ecuaci�n son reales.
3. Dos m�todos VerRaiz1(...) y VerRaiz2(...) que permitan obtener las ra�ces reales (en caso de que lo
sean).
4. Dos m�todos VerParteReal(...) y VerParteImag(...) que permitan obtener las partes real e imaginaria de
las ra�ces complejas (en caso de que lo sean).
5. Cree un programa cliente que utilice un objeto de la clase Ecuaci�nCuadratica para determinar las ra�ces de
una ecuaci�n cuadr�tica cuyos coeficientes sean ingresados por el usuario, y las muestre en el formato que
corresponda (seg�n sean reales o complejas).
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
	cout << "Ingrese los coeficientes de la ecuaci�n cuadr�tica (a, b, c):" << endl;
	cin >> a >> b >> c;
	EcuacionCuadratica eq(a, b, c);
	if (eq.TieneRaicesReales()) {
		cout << "Las ra�ces son reales:" << endl;
		cout << "Ra�z 1: " << eq.VerRaiz1() << endl;
		cout << "Ra�z 2: " << eq.VerRaiz2() << endl;
	} else {
		cout << "Las ra�ces son complejas:" << endl;
		cout << "Ra�z 1: " << eq.VerParteReal() << " + " << eq.VerParteImag() << "i" << endl;
		cout << "Ra�z 2: " << eq.VerParteReal() << " - " << eq.VerParteImag() << "i" << endl;
	}
	
	return 0;
}

