// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
struct tSol {
	int ini, ganancia;
};
using namespace std;

// función que resuelve el problema
tSol resolver(int nv,int t, const vector<int> &ganancia) { //coste ->O(n) siendo n el numero de vagones del tren
	tSol sol = { 0,0 };
	int aux;
	for (int i = 0;i < t;i++)sol.ganancia += ganancia[i]; //caculo del primer posible robo
	aux = sol.ganancia;
	for (int i = 1;i < nv-t+1;i++) {
		aux -= ganancia[i - 1];
		aux += ganancia[i + t-1];
		if (aux >= sol.ganancia) {
			sol.ganancia = aux;
			sol.ini = i;
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nv, t;
	cin  >>  nv  >>  t;
	vector <int> ganancia(nv);
	for(int& i : ganancia) cin >> i;
	tSol sol;
	sol = resolver(nv,t,ganancia);
	// escribir sol
	cout << sol.ini << " " << sol.ganancia << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("sample-32.1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}