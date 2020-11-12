


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector <int > const& numbers, int ini, int fin, int k) {
	if (ini + 1 == fin) 
		return true;
	else {
		int m = (ini + fin) / 2;
		bool ok1 = resolver(numbers, ini, m, k);
		bool ok2 = resolver(numbers, m, fin, k);
		return ok1 && ok2  && std::abs(numbers[ini] - numbers[fin - 1]) >= k;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int num;
	std::cin >> num;
    if (! std::cin)
        return false;
	int k;
	std::cin >> k;
	std::vector<int> numbers(num);
	for (int& n : numbers)
		std::cin >> n;

    // escribir sol
	if (resolver(numbers, 0, numbers.size(), k)) std::cout << "SI\n" ;
	else std::cout << "NO\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-01.1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
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