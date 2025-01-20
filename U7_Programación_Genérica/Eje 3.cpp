/*Programe una clase templatizada llamada VectorDinamico. La clase debe poseer:
1. Un constructor que reciba el tamaño inicial del vector, y reserve la memoria necesaria.
2. Un destructor que se encargue de liberar la memoria reservada.
3. Una sobrecarga del operador [] que reciba el número de elemento, devuelva su valor, y permita modificarlo.
4. Modifique o sobrecargue el constructor para que permita generar valores aleatorios con los cuales inicializar
las posiciones del arreglo que reserva.
5. Utilice la clase desde un programa cliente creando vectores aleatorios con diversos tipos de datos (int, float,
string, etc).*/

#include <iostream>
#include <ctime>
using namespace std;

template<typename U>
U generar_valor_random();

template<>
int generar_valor_random<int>() {
	return rand()%101;
}
template<>
float generar_valor_random<float>() {
	return (rand()%1001)/100.0;
}
template<>
string generar_valor_random<string>() {
	string resultado;
	int longitud = rand() % 5 + 5; // Longitud entre 5 y 10
	for (int i = 0; i < longitud; i++) {
		resultado += static_cast<char>('a' + rand() % 26); // Caracteres aleatorios
	}
	return resultado;
}

template<typename T>
class VectorDinamico {
	T *v;
	int m_tamanio;
public:
	VectorDinamico(int tamanio){
		m_tamanio = tamanio;
		v = new T [m_tamanio];
		for(int i=0;i<m_tamanio;i++) { 
			v[i] = generar_valor_random<T>();
		}
	}
	T& operator[](int num) {
		return v[num];
	}
	~VectorDinamico() {
		delete []v;
	}
};

int main() {
	srand(static_cast<unsigned>(time(0)));
	VectorDinamico<int> vecInt(5);
	cout << "Vector de enteros aleatorios: ";
	for (int i = 0; i < 5; i++) {
		cout << vecInt[i] << " ";
	}
	cout << endl;
	VectorDinamico<float> vecFloat(5);
	cout << "Vector de flotantes aleatorios: ";
	for (int i = 0; i < 5; i++) {
		cout << vecFloat[i] << " ";
	}
	cout << endl;
	VectorDinamico<string> vecString(5);
	cout << "Vector de strings aleatorios: ";
	for (int i = 0; i < 5; i++) {
		cout << vecString[i] << " ";
	}
	cout << endl;
	return 0;
}

