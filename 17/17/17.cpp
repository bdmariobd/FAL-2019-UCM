// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int> & v,vector<vector<int>> & tabla, int fin, int n) {
	if (n <= 0) return 1;
	else if (fin == 0) {
		if (v[fin] == n)return 1;
		return 0;
	}
	else {
		if (tabla[n][fin - 1] == -1) tabla[n][fin - 1] = resolver(v, tabla, fin - 1, n);
		if (n>=v[fin] && tabla[n - v[fin]][fin - 1] == -1) tabla[n - v[fin]][fin - 1] = resolver(v, tabla, fin - 1, n - v[fin]);
		if (n >= v[fin]) return tabla[n][fin - 1] + tabla[n - v[fin]][fin - 1];
		return tabla[n][fin - 1];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int tam, n;
	cin >> tam;
    if (! std::cin)
        return false;
	cin >> n;
	vector<int> v(tam);
	vector<vector<int>> tabla(n+1, vector<int>(tam, -1));
	for (int& n : v) std::cin >> n;

    int sol = resolver(v,tabla,tam-1,n);
    
    // escribir sol
    cout<<sol<<"\n";
    
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