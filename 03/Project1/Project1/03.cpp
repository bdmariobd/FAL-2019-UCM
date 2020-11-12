//Nombre: Mario Blanco
//Juez: E10
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<string>

// función que resuelve el problema
bool resolver(std::vector <int > const& numbers, int ini, int fin) {
	if (ini + 1 == fin)
		return true;
	else {
		int mitad = (ini + fin) / 2;
		int MaxDcha= numbers[mitad], MinIzq = numbers[ini];
		for (int i = ini+1; i < mitad; i++) //calcula Minimo parte izquierda
		{
			if (MinIzq > numbers[i]) MinIzq = numbers[i];
		}
		for (int i = mitad+1; i < fin; i++) //calcula Maximo parte derecha
		{
			if (MaxDcha < numbers[i]) MaxDcha = numbers[i];
		}
		bool exito = true;
		for (int i = ini; exito && i < mitad; i++) 
		{
			if (MaxDcha < numbers[i]) exito = false;
		}
		for (int i = mitad; exito && i < fin; i++) 
		{
			if (MinIzq > numbers[i]) exito = false;
		}
		if (exito)
		{
			bool ok1 = resolver(numbers, ini, mitad);
			bool ok2 = resolver(numbers, mitad, fin);
			return ok1 && ok2;
		}
		else return false;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	if (!std::cin)
		return false;
	std::vector<int> numbers;
	int n;
	std::cin >> n;
	if (n != 0)
	{
		while (n != 0)
		{
			numbers.push_back(n);
			std::cin >> n;
		}
		if (resolver(numbers, 0, numbers.size())) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
	else return false;
	

	return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-03.1.in");
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