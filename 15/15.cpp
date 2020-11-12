// Nombre del alumno Mario Blanco
// Usuario del Juez E10
//Coste 

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
struct sol {
	int num;
	int inv;
	int pot = 0;
};
// función que resuelve el problema
sol resolver(int n) {
	if (n == 0) {
		return { 0, 0, 1 };
	}
	else {
		sol s = resolver(n / 10);

		return {s.num + (n % 10 * s.pot) , 0 , s.pot * 10 };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	cin >> n;
    if (!cin)
        return false;
	sol s = resolver(n);
	
     cout<< s.num<<endl;
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-15.1.in");
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