/*Diseñe una clase Polinomio que contenga:
1. un constructor que reciba el grado el polinomio e inicialice sus coeficientes en 0.
2. un método que permita cambiar un coeficiente.
3. un método evaluar que permita evaluar el polinomio para un valor dado de la variable x.
4. el/los métodos que considere necesarios para poder mostrar un polinomio desde un programa cliente.
5. una función que permita sumar dos polinomios retornando un tercer polinomio con el resultado (ej. p_res =
Sumar(p1, p2);).
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polinomio{
	int m_g;
	vector<float>v;
public:
	Polinomio (int g) : m_g(g) {
		v.resize(m_g + 1, 0);
	}
	void CambiarCoeficiente (int pos, float cof){
		v[pos] = cof;
	}
	float Evaluar (float x){
		float res = 0;
		for(size_t i=0;i<v.size();i++) { 
			res += v[i]  * pow(x,i);
		}
		return res;
	}
	void VerPoli() {
		for(int i=m_g;i>0;i--){
			cout << v[i] << "x^" << i << " + ";
		}
		cout << v[0];
	}
	static Polinomio Suma_Poli (const Polinomio &p1, const Polinomio &p2){
		int grado_max = max(p1.m_g , p2.m_g);
		Polinomio p3(grado_max);
		for(int i=0;i<=grado_max;i++) { 
			if (i <= p1.m_g) {
				p3.v[i] += p1.v[i];
			}
			if (i <= p2.m_g) {
				p3.v[i] += p2.v[i];
			}
		}
		return p3;
	}
};

int main() {
	Polinomio p1(3); 
	Polinomio p2(3);

	p1.CambiarCoeficiente(3, 4);
	p1.CambiarCoeficiente(1, -2);
	p1.CambiarCoeficiente(0, 3);
	
	p2.CambiarCoeficiente(2, 1);
	p2.CambiarCoeficiente(1, 5);
	p2.CambiarCoeficiente(0, -1);
	
	cout << "Polinomio 1: ";
	p1.VerPoli();
	cout << endl;
	cout << "Polinomio 2: ";
	p2.VerPoli();
	cout << endl;
	int valor = 2;
	cout << "Evaluación del polinomio 1 en x = " << valor << ": " << p1.Evaluar(valor) << endl;
	cout << endl;
	Polinomio p3 = Polinomio::Suma_Poli(p1, p2);
	cout << "Suma de p1 y p2: ";
	p3.VerPoli();
	return 0;
}

