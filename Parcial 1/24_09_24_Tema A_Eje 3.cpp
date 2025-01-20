/* En un juego de plataformas el personaje puede juntar estrellas para conseguir cosas. Hay
distintos colores de estrellas que le dan distintos beneficios. a) Implemente una clase Jugador que guarde
los puntos y la cantidad de vidas de un jugador, y que tenga métodos para consultar su estado, sumar o
restar una vida, y sumar puntos. b) Implemente una clase Estrella para modelar una estrella cualquiera,
que tenga como atributo su color (que deberá inicializar en el constructor) y un método Aplicar que reciba
un Jugador y le aplique el beneficio de juntar esa estrella. c) Implemente dos clases para dos tipos de
estrellas en particular: una roja cuyo beneficio es ganar una vida, y una azul cuyo beneficio será sumar una
cierta cantidad de puntos (que se indique en su constructor). d) Implemente una función de prueba que
reciba una estrella cualquiera (la roja y la azul son solo ejemplos, podría haber más) y un jugador, y
aplique el beneficio, informando el estado del jugador antes y después de hacerlo. Desde un programa
cliente cree un jugador e invoque a la función una vez con cada tipo de estrella del punto c.*/

#include <iostream>
using namespace std;

class Jugador {
	int m_puntos;
	int m_vidas;
public:
	Jugador(int vidas) : m_puntos(0), m_vidas(vidas) {}
	pair<int,int>Estado() {return {m_puntos,m_vidas};}
	int VerPuntos() const {return m_puntos;}
	int VerVidas() const {return m_vidas;}
	void SumarVidas() {m_vidas++;}
	void RestarVidas() {m_vidas--;}
	void SumarPuntos(int pts) {m_puntos += pts;}
};

class Estrella {
	string m_color;
public:
	Estrella(string color) : m_color(color) {}
	string VerColor() {return m_color;}
	virtual void Aplicar(Jugador &j) = 0;
	virtual ~Estrella() {}
};

class EstrellaRoja : public Estrella {
public:
	EstrellaRoja() : Estrella("Roja") {}
	void Aplicar(Jugador &j) override {j.SumarVidas();}
};

class EstrellaAzul : public Estrella {
	int m_pts;
public:
	EstrellaAzul(int pts) : Estrella("Azul"), m_pts(pts) {}
	void Aplicar(Jugador &j) override {j.SumarPuntos(m_pts);}
};

void funcion_de_prueba(Estrella &e, Jugador &j){
	cout << "Vidas: " << j.VerVidas() << "  Puntos: " << j.VerPuntos() << endl;
	cout << "El jugador juntó la estrella " << e.VerColor() << endl;
	e.Aplicar(j);
	cout << "Vidas: " << j.VerVidas() << "  Puntos: " << j.VerPuntos() << endl;
}

int main() {
	Jugador j(5);
	EstrellaRoja e1;
	EstrellaAzul e2(10);
	funcion_de_prueba(e1,j);
	cout << endl;
	funcion_de_prueba(e2,j);
	return 0;
}

