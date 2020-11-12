// Nombre del alumno Mario Blanco Dominguez
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>



using namespace std;

struct tSol {
	int sumadura;
	bool caucasidad;
};

// función que resuelve el problema 
tSol resolver(const vector <int> & v,int ini, int fin) {
	tSol sol;
	sol.sumadura = 0;
	if (ini + 1 == fin) {
		if (v[ini] % 2 == 0) sol.sumadura++;
		sol.caucasidad = true;
		return sol;
	}
	else {
		int mitad = (ini + fin) / 2;
		tSol solI = resolver(v, ini, mitad);
		if (solI.caucasidad) {
			tSol solD = resolver(v, mitad, fin);
			sol.caucasidad = abs(solI.sumadura - solD.sumadura) <= 2 && solI.caucasidad && solD.caucasidad;
			sol.sumadura = solI.sumadura + solD.sumadura;
		}
		else sol.caucasidad = false;
		return sol;
	}
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	cin >> n;
	if (n == 0) return false;
	vector<int> v(n);
	for (int i = 0; i < n; i++){ 
		cin >> v[i];

	}
    tSol sol = resolver(v,0,n);
    
    // escribir sol
	if (sol.caucasidad)cout << "Si\n";
	else  cout << "No\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-09.1.in");
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