//Nombre: Mario Blanco
//Usuario : E10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int> & v, int ini, int fin) {

	if (ini+1 == fin) return v[ini];
	else {
		int m = (fin + ini) / 2;

		if (v[ini] < v[fin-1]) {
			if (v[m] < v[m + 1]) return v[m];
			else if (v[m] > v[ini]) return resolver(v, ini, m);
			else return resolver(v, m, fin);
		}
		else return v[fin-1];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;

	if (!std::cin)return false;
	vector<int> v(tam);

	for (int i = 0; i < v.size(); ++i)
		cin >> v[i];

	int sol = resolver(v, 0, tam);

	// escribir sol
	 cout << sol << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("sample-07.1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}