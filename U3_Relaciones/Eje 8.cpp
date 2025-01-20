/*a) Defina una clase Tecla para representar una tecla de un piano. Cada tecla puede estar o no apretada, y tiene
adem�s una nota asociada (cuyo nombre se representar� con un string). Su interfaz debe tener tener entonces:
� un constructor que reciba el nombre de la nota
� un m�todo VerNota que retorne el nombre de la nota
� un m�todo Apretar que cambie el estado de la tecla a apretada.
� un m�todo Soltar que cambie el estado de la tecla a no apretada.
� un m�todo EstaApretada que retorne true si la tecla est� apretada, false en caso contrario
b) Defina una clase Pedal para representar el pedal de un piano. El pedal debe almacenar un valor (float) que
indique la presi�n que el m�sico ejerce sobre el pedal. El constructor debe inicializar la presi�n en 0, y la clase debe
tener m�todos para modificarla y consultarla.
c) Reutilizando las clases Tecla, Pedal e Instrumento:
class Instrumento {
public:
Instrumento(string nombre) : m_nombre(nombre) { }
string VerNombre() const { return m_nombre; }
virtual string Sonido() const = 0;
virtual ~Instrumento() { }
private:
string m_nombre;
};
defina una clase Piano que modele un instrumento de tipo �piano� con solo 7 teclas (�do�, �re�, �mi�, �fa�, �sol�, �la� y
�si�) y 1 pedal. La clase piano debe tener m�todos para:
� apretar una tecla, indicando el n�mero de tecla, y que retorne la nota que deber�a sonar.
� soltar una tecla, indicando el n�mero de tecla
� presionar el pedal, indicando la presi�n que se aplica
Nota: el m�todo Sonido de Instrumento debe retornar el sonido que har�a el instrumento en su estado actual. En el
piano, ser� la suma de las teclas que est�n apretadas.
d) Utilizando la siguiente funci�n:
void mostrarEnPantalla(const Instrumento *inst) {
cout << "El " << inst->VerNombre() << " suena: " << inst->Sonido() << endl;
}
*/

#include <iostream>
#include <vector>
using namespace std;

class Tecla {
	string m_nota;
	bool m_apretada;
public:
	Tecla (string nota) : m_nota(nota), m_apretada(false) {}
	string VerNota() const {return m_nota;}
	void Apretar() {m_apretada = true;}
	void Soltar() {m_apretada = false;}
	bool EstaApretada() const {return m_apretada;}
};

class Pedal {
	float m_presion;
public:
	Pedal() : m_presion(0) {}
	float VerPresion() {return m_presion;}
	float ModificarPresion(float p) {
		m_presion = p;
		return m_presion;
	}
};

class Instrumento {
	string m_nombre;
public:
	Instrumento(string nombre) : m_nombre(nombre) {}
	string VerNombre() const { return m_nombre; }
	virtual string Sonido() const = 0;
	virtual ~Instrumento() { }
};

class Piano : public Instrumento {
	vector<Tecla>teclas;
	Pedal m_pedal;
public:
	Piano() : Instrumento("Piano") {
		vector<string> notas = {"do", "re", "mi", "fa", "sol", "la", "si"};
		for(size_t i=0;i<notas.size();i++) { 
			teclas.push_back(Tecla(notas[i]));
		}
	}
	string ApretarTecla(int nro) {
		if (nro >= 1 and nro <= 7){
			teclas[nro-1].Apretar();
			return teclas[nro-1].VerNota();
		} else {
			return "N�mero de tecla inv�lido";
		}
	}
	void SoltarTecla(int nro) {
		if (nro >= 1 && nro <= 7) {
			teclas[nro - 1].Soltar();
		} else {
			cout << "N�mero de tecla inv�lido." << endl;
		}
	}
	void PresionarPedal(float presion) {
		m_pedal.ModificarPresion(presion);
	}
	string Sonido () const override {
		string sonido = "";
		for(size_t i=0;i<teclas.size();i++) { 
			if (teclas[i].EstaApretada()) {
				sonido += teclas[i].VerNota() + " ";
			}
		}
		return sonido;
	}
};

void mostrarEnPantalla(const Instrumento *inst) {
	cout << "El " << inst->VerNombre() << " suena: " << inst->Sonido() << endl;
}

int main() {
	Piano piano;
	cout << piano.ApretarTecla(1) << " apretada." << endl;
	cout << piano.ApretarTecla(3) << " apretada." << endl;
	cout << piano.ApretarTecla(5) << " apretada." << endl;
	mostrarEnPantalla(&piano);
	piano.SoltarTecla(1);
	cout << "Despu�s de soltar la tecla 'do':" << endl;
	mostrarEnPantalla(&piano);
	piano.PresionarPedal(5.0);
	return 0;
}

