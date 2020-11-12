//Nombre del alumno: Mario Blanco
//Usuario juez: E10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;
// función que resuelve el problema
char resolver(vector<char> v, int ini, int fin, const char & letraI, const char & letraD) {
	int mitad = (ini + fin) / 2;
	if (v[mitad] != letraI + mitad) //si mitad mal colocado, esta en la izquierda
	{
		if(ini + 1 == fin) return v[mitad] - 1;
		else if (v[mitad] - v[mitad - 1] == 1)//si entre mitad y el anterior no hay hueco
		{
			return resolver(v, ini, mitad, letraI, letraD);
		}
		else
		{
			return v[mitad]-1;
		}
	}
	else
	{
		if (ini + 1 == fin) return v[mitad] + 1;
		return resolver(v, mitad, fin, letraI, letraD);
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char ini, fin, aux;
	vector<char> letras;
	cin >> ini >> fin;
	cin.ignore();//lee el primer salto de linea
	aux = cin.get();
	while (aux != '\n' && !cin.fail()) {
		if (aux != ' ') letras.push_back(aux);
		aux = cin.get();
	}
	char sol = resolver(letras, 0, letras.size(),ini,fin);
	// escribir sol
	cout << sol << endl;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("sample-E04.1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}