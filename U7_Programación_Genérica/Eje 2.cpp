/*1. Implemente una funci�n clamp(...) que reciba como par�metros una variable (por referencia) y dos valores
indicando los l� mites superior e inferior para el valor de dicha variable. Si el valor de la variable supera su
m�ximo, este debe ajustarse al m�ximo valor permitido. De la misma forma si el valor es inferior al m�nimo.
2. Pruebe la funci�n templatizada desde un programa cliente. Explique el error que ocurre al invocar la funci�n
con float f=0.5; clamp(f, 0, 1); �C�mo lo solucionar�a?*/

#include <iostream>
using namespace std;

template<typename T, typename T1, typename T2>
void clamp (T &var, T1 inf, T2 sup) {
	if (var > sup) var = sup;
	else  if (var < inf )var = inf;
}

int main() {
	int var = 4;
	clamp (var,1,3);
	cout << var;
	cout << endl;
	float f = 0.5; 
	clamp(f, 0, 1);
	cout << f;
	return 0;
}

