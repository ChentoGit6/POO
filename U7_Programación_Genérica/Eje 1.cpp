/*Implemente una función templatizada llamada mayor(...) que reciba dos valores y devuelva el mayor.
Compruebe el correcto funcionamiento de la rutina utilizándola desde un programa cliente con valores de tipo
int, float y string
2. Programe una sobrecarga de la función mayor(...) que reciba un std::vector y retorne la posición del mayor
elemento del mismo. Pruebe la función sobrecargada desde un programa cliente con diversos tipos de datos.
3. Responda: ¿Servirán las funciones anteriores con datos del tipo mostrado en el recuadro? Justifique su
respuesta. Si responde que no, implemente los cambios necesarios.
struct Persona {
string nombre;
string apellido;
int dni;
};*/

#include <iostream>
#include <vector>
using namespace std;

struct Persona {
	string nombre;
	string apellido;
	int dni;
};

bool operator> (Persona p1, Persona p2) {
	return p1.dni > p2.dni;
}

template<typename T>
T mayor (T valor1, T valor2) {
	if(valor1 > valor2) return valor1;
	return valor2;
}

template<typename T>
int mayor (vector<T>&v) {
	int pos_mayor = 0;
	for(size_t i=1;i<v.size();i++) { 
		if(v[i] > v[pos_mayor]) pos_mayor = i;
	}
	return pos_mayor;
}

int main() {
	int a = rand();
	int b = rand();
	int ab = mayor (a,b);
	cout << a << ", " << b << " - Mayor: " << ab << endl;
	float c = rand();
	float d = rand();
	float cd = mayor (c,d);
	cout << c << ", " << d << " - Mayor: " << cd << endl;
	string e = "Hola";
	string f = "mundo";
	string ef = mayor (e,f);
	cout << e << ", " << f << " - Mayor: " << ef << endl;
	
	vector<int> vInt = {1, 5, 3, 9, 2};
	cout << "Posición del mayor en vInt: " << mayor(vInt) << endl;
	vector<float> vFloat = {2.5f, 3.1f, 1.8f, 3.1f};
	cout << "Posición del mayor en vFloat: " << mayor(vFloat) << endl;
	vector<string> vStr = {"perro", "gato", "elefante", "jirafa"};
	cout << "Posición del mayor en vStr: " << mayor(vStr) << endl;
	
	vector<Persona> personas = {{"Juan", "Perez", 12345678},{"Ana", "Lopez", 87654321},{"Pedro", "Gomez", 23456789}};
	int posPersonaMayor = mayor(personas);
	cout << "La persona con el mayor DNI es: "
		<< personas[posPersonaMayor].nombre << " "
		<< personas[posPersonaMayor].apellido << " (DNI: "
		<< personas[posPersonaMayor].dni << ")" << endl;
	return 0;
	
	
}

