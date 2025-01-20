/*Escriba una clase abstracta IA para representar a una inteligencia artificial que responde
preguntas. La clase debe recibir el nombre de la misma en su constructor, guardarlo y tener un método
para consultarlo. Debe tener además un método virtual ObtenerRespuesta que reciba una pregunta y
retorne una respuesta (ambas serán strings).
b) Implemente 2 clases representando 2 inteligencias diferentes:
- Memory: Debe recibir en su constructor una lista de preguntas y respuestas. El método
ObtenerRespuesta debe buscar la pregunta en esa lista y retornar la respuesta correspondiente. Si la
pregunta no está en la lista, debe elegir una respuesta al azar.
- Multivac: El método ObtenerRespuesta debe responder a todo con "Datos insuficientes para una
respuesta esclarecedora.".
c) Escriba una función que reciba una IA (que pueda ser cualquiera, una de las 2 implementadas en b,
o incluso otra) y permita al usuario ingresar preguntas y ver las respuestas hasta que ingrese "Salir".
Escriba un programa cliente que permita al usuario elegir uno de los dos tipos de inteligencia, cree la
instancia de la clase adecuada e invoque con ella a la función. Nota: en el main, donde se debería
carga u obtener la lista de preguntas y respuestas para Memory, solo declare la o las variables
necesarias y ponga simplemente una comentario diciendo “// aquí debería cargar la lista”
*/

#include <iostream>
#include <vector>
using namespace std;

class IA {
	string m_nombre;
public:
	IA(string nombre) : m_nombre(nombre) {}
	string VerNombre() const {return m_nombre;}
	virtual string ObtenerRespuesta(string pregunta) = 0;
	virtual ~IA() {}
};

class Memory : public IA {
	vector<string>preguntas;
	vector<string>respuestas;
public:
	Memory(vector<string>p, vector<string>r) : IA("Memory"), preguntas(p), respuestas(r) {}
	string ObtenerRespuesta(string pregunta) override {
		for(size_t i=0;i<preguntas.size();i++) { 
			if (pregunta == preguntas[i]) {
				return respuestas[i];
			}
		}
		int a = rand()% respuestas.size();
		return respuestas[a];
	}
};

class Multivac : public IA {
public:
	Multivac() : IA("Multivac") {}
	string ObtenerRespuesta(string pregunta) override {
		return "Datos insuficientes para una respuesta esclarecedora.";
	}
};

void funcion (IA &ia) {
	string s;
	cout << "Ingrese Pregunta o sino salir" << endl;
	cin >> s;
	while (s != "Salir" and s != "salir"){
		cout << ia.ObtenerRespuesta(s) << endl;
		cout << "Ingrese Pregunta o sino salir" << endl;
		cin >> s;
	}
}

int main() {
	cout << "Elige el tipo de IA: 1-Memory o 2-Multivac:" << endl;
	int ia;
	cin >> ia;
	if(ia == 1){
		vector<string>preguntas, respuestas;
		Memory ia_memory(preguntas, respuestas);
		//aquí debería cargar la lista
		funcion(ia_memory);
	}
	if(ia == 2){
		Multivac ia_multivac;
		funcion(ia_multivac);
	}
	return 0;
}

