// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esValida( int max, const vector <int>& sol, int k, const vector<int>& marcas) {
	bool ok = true;
	if (k % 2 != 0) ok = sol[k] != sol[k - 1]; //compruebo que los niños son diferentes
	return ok && marcas[sol[k]] <= max; //el niño asignado no hacemas tareas de las asignadas
}


// función que resuelve el problema
void resolver(int max, int a, vector <int>& sol, int k, const vector<vector<int>>& stf, vector<int>& marcas, int sMax, int& mayor) {
	for (int i = 0; i < a; i++) {
		sol[k] = i;
		marcas[i] += 1;
		sMax += stf[i][k / 2];
		if (esValida(max, sol, k, marcas)) {
			if (k == sol.size() - 1) {
				if (sMax > mayor)	mayor = sMax;
			}
			else {
				resolver(max, a, sol, k + 1, stf, marcas, sMax, mayor);
			}
		}
		sMax -= stf[i][k / 2];
		marcas[i] -= 1;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() { // n = tareas
	// leer los datos de la entrada
	int n, a, max;
	cin >> n;
	if (n == 0)
		return false;
	cin >> a;
	cin >> max;
	vector<vector<int>> stf(a, vector<int>(n)); // las filas son alum y las colm lo q le gusta a cada alum tarea
	vector<int> sol(n * 2);
	vector<int> marcas(a, 0);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < n; j++) {
			cin >> stf[i][j];
		}
	}
	
	int mayor = 0;
	resolver(max, a, sol, 0, stf, marcas, 0, mayor);
	cout << mayor << "\n";

	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
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