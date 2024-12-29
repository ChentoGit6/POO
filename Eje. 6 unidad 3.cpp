#include <iostream>
using namespace std;
/*Una fábrica de tanques los hace de forma de cilindro y de esfera. En ambos envases debemos rotular el volumen
en m3 y el peso en kg. Modele una clase base Tanque con un constructor que reciba el peso, un método para
consultarlo, y un método virtual para calcular su volumen. Modele la clase hija Cilindro que se construirá a partir
de los argumentos adicionales radio y altura, cuya fórmula de volumen es: área de la base * altura, donde el área de
la base se calcula como pi * radio2; y otra clase hija Esfera con el radio como argumento adicional, cuya fórmula de
volumen es: 4/3* pi * radio3. En el programa principal debe usar un único puntero de tipo Tanque para crear primero
un Cilindro y mostrar su volúmen, y luego una Esfera y también mostrar su volúmen.
*/
class Tanque {
	float peso;
public:
	Tanque (float m_peso) : peso(m_peso){}
	float VerPeso(){return peso;}
	virtual float CalcVol() = 0;
};
class Cilindro : public Tanque{
private:
	float radio, altura;
public:
	Cilindro(float m_radio, float m_altura, float peso) : radio(m_radio), altura(m_altura), Tanque(peso){}
	float CalcVol () override {return radio * radio * 3.1416 * altura;}
	
};
class Esfera : public Tanque{
private:
	float radio;
public:
	Esfera(float m_radio, float peso) : radio(m_radio), Tanque(peso){}
	float CalcVol () override {return 4/3 * 3.1416 * radio * radio * radio;}
};

int main() {
	cout << "Ingrese radio y altura para calcular el volumen del cilindro: "<<endl;
	float r, a;
	cout << "Radio: "; cin >> r;
	cout << "Altura: "; cin >> a;
	Tanque *p = new Cilindro(r,a,1);
	cout << "El volumen de cilindro es: "<< p->CalcVol()<<endl;
	delete p;
	cout << "Ingrese radio para calcular el volumen de la esfera: "<<endl;
	float r2, a2;
	cout << "Radio: "; cin >> r2;
	p = new Esfera(r2,1);
	cout << "El volumen de la esfera es: "<< p->CalcVol();
	delete p;
	return 0;
}

