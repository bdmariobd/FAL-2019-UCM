// Nombre del alumno Mario Blanco
// Usuario del Juez E10
//Coste de la solucion : O (2 ^a-b) resultado de calcular (a comb b)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(int a, int b , vector<vector<int>> & tabla) {
	if (a == b) return tabla[a][b]=1; //a comb a = 1
	else if (b == 1 ) return tabla[a][b]=a; // a comb 1 = a
	else {
		// a comb b = (a-1 comb b) + (a-1 comb b-1)
		if (tabla[a - 1][b] == -1) tabla[a - 1][b] == resolver(a - 1, b, tabla);
		if(tabla[a-1][b-1] == -1) tabla[a - 1][b - 1] = resolver(a - 1, b-1, tabla);

		return tabla[a][b] = tabla[a - 1][b] + tabla[a - 1][b - 1];
	}
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int a, b;
	cin >> a;
    if (! std::cin)
        return false;
	cin >> b;
	
	vector<vector<int>> tabla(a+1, vector<int>(b+1, -1));
	//vector<int> tabla(1);
    int sol = resolver(a,b, tabla);
	cout << sol << endl;
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-16.1.in");
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