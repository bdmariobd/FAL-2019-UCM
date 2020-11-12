// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
struct juguete {
	int ud, usadas;
	string tipo;
};
// función que resuelve el problema

bool esValida(const vector<int>& sol, int k, const vector<juguete>& j, const vector<int>& stf, int min) {
	if (k % 2 == 0) return true; //en las etapas pares es solucion valida, es su primer juguete asignado
	
	return stf[k/2]>=min && j[sol[k]].tipo != j[sol[k - 1]].tipo && sol[k] > sol[k - 1];
}
void escribir(const vector<int>& sol) {
	for (int i = 0;i < sol.size();i++) {
		cout << sol[i] << " ";
	}
	cout << "\n";
}
void resolver(vector<int>& sol, vector<juguete>& j, int k, bool& ok, vector<int>& stf, int min, const vector<vector<int>>&sat) {
	for (int i = 0;i < j.size();i++) {
		if (j[i].usadas < j[i].ud) {
			sol[k] = i;
			j[i].usadas++;
			stf[k/2] += sat[k / 2][i];
			if (esValida(sol, k, j,stf,min)) {
				if (k == sol.size() - 1) {
						escribir(sol); ok = true;
				}
				else resolver(sol, j, k + 1, ok, stf, min, sat);
			}
			j[i].usadas--;
			stf[k / 2] -= sat[k / 2][i];
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int toys, kids,minSat;
	cin >> toys;
	if (!std::cin)
		return false;
	cin >> kids>>minSat;
	vector<int> sol(2 * kids);
	vector<juguete>j(toys, { 0,0,"" });
	for (juguete& i : j)cin >> i.ud;
	for (juguete& i : j)cin >> i.tipo;
	vector<vector<int>>sat(kids, vector<int>(toys));
	for (int i = 0; i < kids; i++) {
		for (int j = 0; j < toys; j++) {
			cin >> sat[i][j];
		}
	}
	bool ok = false;
	vector<int>stf(kids, 0);

	resolver(sol, j, 0, ok,stf,minSat, sat);
	if (!ok) cout << "SIN SOLUCION\n";
	cout << "\n";
	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("sample-22.1.in");
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