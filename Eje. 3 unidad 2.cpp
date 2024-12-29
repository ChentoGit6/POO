#include <iostream>
#include <vector>
using namespace std;
/**Diseñe una clase Polinomio que contenga:
1. un constructor que reciba el grado el polinomio e inicialice sus coeficientes en 0.
2. un método que permita cambiar un coeficiente.
3. un método evaluar que permita evaluar el polinomio para un valor dado de la variable x.
4. el/los métodos que considere necesarios para poder mostrar un polinomio desde un programa cliente.
5. una función que permita sumar dos polinomios retornando un tercer polinomio con el resultado (ej. p_res =
Sumar(p1, p2);). ¿Cómo variaría si en lugar de ser una función libre fuera un método de la clase?
Verifique el funcionamiento de la función Sumar(...) mediante un programa cliente.
**/

class polinomio{

private:
	int grado;
	vector<float>v(grado);
public:
	polinomio(int gr){
	grado = gr;
	v.resize(gr,0);
}
	void cambiar_cof (int pos, float cof){
		v[pos] = cof;
	}
	float evaluar (int x){
		float rta; int exp;
		for(size_t i=0;i<v.size();i++) { 
			/*exp = i+v.size();*/
			rta += v[i] * pow(x,i);
		}
	}


};

int main() {
	
	return 0;
}

