#include <iostream>
#include <fstream>
using namespace std;

struct par {
	int entero;
	float flotante;
};

int main() {
	ifstream archi("grupo.dat", ios::binary);
	for(int i=0;i<200;i++) { 
		par p;
		archi.read(reinterpret_cast<char*>(&p), sizeof(p));
		cout << p.entero << "  " << p.flotante << endl;
	}
	archi.close();
	return 0;
}

