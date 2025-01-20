/*a) Defina una clase para representar a un jugador del juego piedra-papel-tijera. La clase debe
guardar el nombre del jugador (que se inicializará en su constructor) y tener un método para jugar que
retorne “piedra”, “papel” o “tijera”. b) Defina dos clases para representar a dos formas de jugar en
particular: una cuyo método jugar elija su jugada al azar; y otra que siempre juegue “tijera”. c) Implemente
una función comparar(...) que pueda recibir dos jugadores de cualquier tipo (los del punto b son solo
ejemplos, podría haber más), simule 1000 partidas entre ellos e informe el porcentaje de ganados de cada
uno. d) Escriba un programa cliente que genere dos jugadores, uno de cada tipo (del punto b), e invoque a
la función de prueba.*/

#include <iostream>
#include <ctime>
using namespace std;

class Jugador {
	string m_nombre;
public:
	Jugador(string nombre) : m_nombre(nombre) {}
	string VerNombre() const {return m_nombre;}
	virtual string Jugar() = 0;
	virtual ~Jugador() {}
};

class JugadaAleatoria : public Jugador {
public:
	JugadaAleatoria(string nombre) : Jugador(nombre) {}
	string Jugar() override {
		int x = rand()%3;
		if (x == 0) return "Piedra";
		if (x == 1) return "Papel";
		return "Tijera";
	}
};

class JugadaTijera : public Jugador {
public:
	JugadaTijera(string nombre) : Jugador(nombre) {}
	string Jugar() override {return "Tijera";}
};

void comparar(Jugador &j1, Jugador &j2){
	int n1 = 0, n2 = 0;
	for(int i=0;i<1000;i++) { 
		string s1 = j1.Jugar();
		string s2 = j2.Jugar();
		if (s1 == s2) continue;
		if (s1 == "Tijera" and s2 == "Papel") 
			++n1;
		else if (s1 == "Piedra" and s2 == "Tijera") 
			++n1;
		else if (s1 == "Papel" and s2 == "Piedra") 
			++n1;
		else 
			++n2;
	}
	cout << j1.VerNombre() << ": " << (static_cast<float>(n1)/1000*100) << "% partidas ganadas" << endl;
	cout << j2.VerNombre() << ": " << (static_cast<float>(n2)/1000*100) << "% partidas ganadas" << endl;
}

int main() {
	srand(time(0));
	string a,b;
	cout << "Ingrese dos nombres para jugar piedra papel o tijera:" << endl;
	cin >> a >> b;
	JugadaAleatoria j1(a);
	JugadaTijera j2(b);
	comparar(j1,j2);
	return 0;
}

