// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
void resolver(vector<int> &sol, vector<bool>& marcas,const vector<vector<int>> & sat,int k, int actual, int & maxima) {
	for (int i = 0;i < marcas.size();i++) {
		if (!marcas[i]) {
			sol[k] = i;
			marcas[i] = true;
			actual += sat[k][i];
			if (k == sol.size() - 1) {
				if (actual > maxima) maxima = actual;
			}
			else resolver(sol, marcas, sat, k + 1, actual, maxima);

			marcas[i] = false;
			actual -= sat[k][i];
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int j, n;
	cin >> j;
    if (! std::cin)
        return false;
	cin >> n;
	vector<vector<int>> sat(n,vector<int>(j));
	for (int i = 0;i < n;i++)
		for (int k = 0;k < j;k++) 
			cin >> sat[i][k];

	int maxima =0;
	for (int i = 0;i < n;i++) maxima += sat[i][i]; //la maxima es la diagonal(cortar ramas inferiores)
	vector<int>sol(n);
	vector<bool>marcas(j, false);
    resolver(sol,marcas,sat,0,0,maxima);
	cout << maxima << "\n";
    
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