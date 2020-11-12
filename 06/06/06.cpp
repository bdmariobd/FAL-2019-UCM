// Nombre del alumno Mario Blanco
// Usuario del Juez E10
//Coste: O(log n)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int> & a, const vector<int>& b,int ini,int fin) {
	if (ini +1 >= fin ) return a[ini];
	else if (fin - ini == 2) { //caso base, vector b con solo un elemento
		if (a[ini] == b[ini]) return a[fin- 1];
		else return a[ini];
	}
	else{
		int mitad = (ini + fin) / 2;
		if (a[mitad] == b[mitad]) {//esta en la parte derecha
			return resolver(a, b, mitad+1, fin);
		}
		else { //esta en la izquierda
			return resolver(a, b, ini, mitad+1);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n-1);
	for (int i = 0;i < n;i++)	{
		cin >> a[i];
	}
	for (int i = 0;i < n-1;i++) {
		cin >> b[i];
	}
    int sol = resolver(a,b,0,n);
    // escribir sol
	cout << sol << endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-06.1.in");
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