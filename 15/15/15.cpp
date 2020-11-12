// Nombre del alumno Mario Blanco
// Usuario del Juez E10


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
	if (n < 10) {
		return{ 9 - (n % 10), 9 - (n % 10) , 10 };
	}
	else {
		sol s = resolver(n / 10);
		int digito = 9 - (n % 10);
		s.num = s.num * 10 + digito;
		s.inv = s.inv + (digito * s.pot);
		return { s.num , s.inv , s.pot * 10};
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
 
	int n;
	cin >> n;
	sol s = resolver(n);

	cout << s.num <<" "<< s.inv<<endl;
 
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-15.1.in");
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