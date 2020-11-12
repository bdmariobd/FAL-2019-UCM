// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
void resolver(vector<int>&sol, vector<bool>&marcas, const vector<vector<int>>&tiempos, int k, int actual, int & minimo,const vector<int>& acum) {
	for (int i = 0;i < marcas.size();i++) {
		if (!marcas[i]) {
			sol[k] = i;
			marcas[i] = true;
			actual += tiempos[k][i];
			if (k == sol.size() - 1) {
				if (actual < minimo) minimo = actual;
			}
			else {
				if(actual+acum[k+1]<minimo) resolver(sol, marcas, tiempos, k + 1, actual, minimo,acum);
			}
			marcas[i] = false;
			actual -= tiempos[k][i];
		}
	}
 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	cin >> n;
    if (n==0)
        return false;
	vector<int> sol(n);
	vector<bool>marcas(n, false);
	vector<vector<int>> tiempos(n, vector<int>(n));
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			cin >> tiempos[i][j];
	int minimo=0;
	for (int i = 0;i < n;i++) minimo += tiempos[i][i];

	vector<int>acum(n);
	int min;
	for (int i = 0;i < n;i++) {
		min = tiempos[i][0];
		for (int j= 1;j < n;j++) {
			if (tiempos[i][j] < min)min = tiempos[i][j];
		}
		acum[i] = min;
	}

	for (int i = n - 1; i > 0; --i) acum[i - 1] += acum[i];
    resolver(sol,marcas,tiempos,0,0,minimo,acum);
	cout << minimo << "\n";
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-25.1.in");
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