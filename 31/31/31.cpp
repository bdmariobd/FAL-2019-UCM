// Nombre del alumno Mario Blanco
// Usuario del Juez E10
//Coste de la solucion: O(N)(solo se recorre una vez

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
bool resolver(const vector <int>& v, int p) {
	if (v.size() == 0) return true;
	int maximo=v[0];
	for (int i = 1; i <= p; i++) {
		if (maximo < v[i]) maximo = v[i];
	}
	for (int i = p + 1; i < v.size(); i++) {
		if (v[i] <= maximo) return false;
	}
	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int n, p;
	cin >> n>>p;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
    
	
    // escribir sol
	if(resolver(v,p)) cout << "SI";
	else cout << "NO";
	cout << "\n";
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
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