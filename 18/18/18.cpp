// Nombre del alumno Mario Blanco
// Usuario del Juez E10
//Coste de la solucion O(log n) n = tamaño vector


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Sol {
	int a, b;
	bool punto;
};


// función que resuelve el problema
Sol resolver(const vector<int> & v1, const vector<int>& v2, int ini, int fin){
	if (ini + 1 == fin) {
		if (v1[ini] == v2[ini]) return { ini,ini,true };
		if (v1[ini] > v2[ini]) return { ini-1,ini,false }; //el corte estaria a la derecha
		if (v1[ini] < v2[ini]) return { fin - 1,fin,false }; //a la izquierda
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v1[mitad] > v2[mitad])	return resolver(v1, v2, ini, mitad); 
		else if (v1[mitad] < v2[mitad])	return resolver(v1, v2, mitad, fin);
		else return { mitad,0,true };
	}
}

bool resuelveCaso()
{
	int numElem;
	std::cin >> numElem;
	if (numElem == 0) return false;
	std::vector<int> v1(numElem);
	std::vector<int> v2(numElem);
	for (int& i : v1) std::cin >> i;
	for (int& i : v2) std::cin >> i;

	// Aqui codigo del alumno
	Sol sol = resolver(v1,v2,0,numElem);
	if (sol.punto) cout << "Si " << sol.a<<endl;
	else cout << "No " << sol.a << " " << sol.b<<endl;
	return true;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample-18.1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso())
		;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}