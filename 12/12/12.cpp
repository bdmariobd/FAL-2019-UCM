// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


// función que resuelve el problema
int resolver(vector<int>& v, int ini, int fin) {
	if (ini == fin-1) return 0;
	else {
		int mitad = (ini + fin) / 2;
		int inversiones = resolver(v, ini, mitad) + resolver(v, mitad, fin); //coste = O(n)
		int i = ini, j = mitad;
		while (i < mitad && j < fin) {
			if (v[i] > v[j]) {
				inversiones += (mitad - i); //tambien se cuentan los que estan delante
				j++;
			}
			else i++; //si no hay que invertir 
		}
		sort(v.begin()+ini,v.begin()+fin); //coste = O(n log n)
		return inversiones;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	cin >> n;
    if (! std::cin)
        return false;
	vector<int> v(n);
	for (int i = 0;i < n;i++)  cin >> v[i];	

    int sol = resolver(v,0,n);
    
    // escribir sol
	cout << sol << "\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-12.1.in");
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