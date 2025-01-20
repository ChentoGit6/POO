/*1. Implemente una función clamp(...) que reciba como parámetros una variable (por referencia) y dos valores
indicando los lí mites superior e inferior para el valor de dicha variable. Si el valor de la variable supera su
máximo, este debe ajustarse al máximo valor permitido. De la misma forma si el valor es inferior al mínimo.
2. Pruebe la función templatizada desde un programa cliente. Explique el error que ocurre al invocar la función
con float f=0.5; clamp(f, 0, 1); ¿Cómo lo solucionaría?*/

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

