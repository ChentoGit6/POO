/*En un juego el usuario controla una partícula que debe moverse por la pantalla e ir
absorbiendo otras partículas más pequeñas. Al tocar una partícula más pequeña, la del jugador la
absorbe y entonces crece en tamaño. Pero si intenta absorber una más grande, pierde una vida.
a) Diseñe una clase Particula. Debe tener un constructor que reciba su radio, y un método para obtener
su área (pi*r²). b) Implemente una sobrecarga del operador < para comparar dos partículas según su
radio. c) Implemente una sobrecarga para el operador += que permita sumar dos partículas (el
resultado debe guardarse en la primera). La partícula resultante debe tener un área igual a la suma de
las dos originales (entonces, si a1 y a2 son las áreas originales, el radio de la nueva será raíz((a1+a2)/pi)).
d) Implemente una clase Jugador que represente la partícula del jugador. Esta, además de su radio,
debe tener una cantidad de vidas (que se reciba como argumento en su constructor).
e) Implemente una función libre (no será método de ninguna clase) colision que reciba al jugador y otra
partícula contra la cual colisiona. Si la otra es menor a la del jugador, debe sumar ambas en la del
jugador (es decir, crece la del jugador). Si la otra es mayor o igual, debe restarle una vida al jugador. La
función retornará false cuando las vidas lleguen a 0; true en caso contrario.*/

#include <iostream>
#include <cmath>
using namespace std;

class Particula {
	float m_radio;
public:
	Particula(float radio) : m_radio(radio) {}
	float ObtenerArea() {return 3.14*m_radio*m_radio;}
	float ObtenerRadio() const {return m_radio;}
	bool operator<(const Particula &p) const {
		return m_radio<p.m_radio;
	}
	Particula &operator+=(Particula p2) {
		m_radio = sqrt((this->ObtenerArea() + p2.ObtenerArea())/3.14);
		return *this;
	}
};

class Jugador : public Particula  {
	int m_vidas;
public:
	Jugador(int vidas, float radio) : m_vidas(vidas), Particula(radio) {}
	int VerVidas() const {return m_vidas;}
	void PerderVida() {--m_vidas;}
};

bool colision (Jugador &j, Particula p) {
	if (p < j) {
		j += p;
	} else {
		j.PerderVida();
		if(j.VerVidas() == 0) return false;
	}
	return true;
}

int main() {
	
	return 0;
}

