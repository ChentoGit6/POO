#include <iostream>
#include <vector>
using namespace std;
/**Dise�e una clase Polinomio que contenga:
1. un constructor que reciba el grado el polinomio e inicialice sus coeficientes en 0.
2. un m�todo que permita cambiar un coeficiente.
3. un m�todo evaluar que permita evaluar el polinomio para un valor dado de la variable x.
4. el/los m�todos que considere necesarios para poder mostrar un polinomio desde un programa cliente.
5. una funci�n que permita sumar dos polinomios retornando un tercer polinomio con el resultado (ej. p_res =
Sumar(p1, p2);). �C�mo variar�a si en lugar de ser una funci�n libre fuera un m�todo de la clase?
Verifique el funcionamiento de la funci�n Sumar(...) mediante un programa cliente.
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

