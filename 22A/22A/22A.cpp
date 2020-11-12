// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema

bool esValida(const vector<int>& sol, int k, const vector<string>& tipo) {
	if (k % 2 == 0) return true; //en las etapas pares es solucion valida, es su primer juguete asignado
	//si en la lista hay 2 juguetes iguales no es valido, ya que repite
	return tipo[sol[k]] != tipo[sol[k - 1]] && sol[k] > sol[k - 1];
}
void escribir(const vector<int>& sol) {
	for (int i = 0;i < sol.size();i++) {
		cout << sol[i] << " ";
	}
	cout << "\n";
}
void resolver(vector<int>& sol, const vector<string>& tipo, int k, bool& ok) {
	for (int i = 0;i < tipo.size();i++) {
		sol[k] = i;
		if (esValida(sol, k, tipo)) {
			if (k == sol.size() - 1) {
				escribir(sol); ok = true;
			}
			else resolver(sol, tipo, k + 1, ok);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int toys, kids;
	cin >> toys;
	if (!std::cin)
		return false;
	cin >> kids;
	vector<int> sol(2 * kids);
	vector<string> tipo(toys);
	for (int i = 0;i < toys;i++) {
		cin >> tipo[i];
	}
	bool ok = false;
	resolver(sol, tipo, 0, ok);
	if (!ok) cout << "SIN SOLUCION\n";
	cout << "\n";
	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("sample-22A.1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}