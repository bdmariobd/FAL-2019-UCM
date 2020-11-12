// Nombre del alumno Mario Blanco
// Usuario del Juez E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// función que resuelve el problema

bool sortComp(pair<int, int> o1, pair<int, int> o2) {
	return (float)o1.second / o1.first > (float)o2.second / o2.first;
}


int estimar(int obj, const vector<pair<int, int>>& objetos, int presu, int PresuActual, int k, int mayor, int SupActual) {
	int sup = 0;
	bool supera = false;
	while (!supera&& k<obj) {
		PresuActual+=objetos[k].first;
		supera = PresuActual > presu;		
		if (!supera) {
			sup += objetos[k].second;
			k++;
		}
	}
	return sup;
}
void resolver(int obj, const vector<pair<int,int>>& objetos, int presu, int PresuActual, int k, int SupActual, int& mayor,vector<bool>&sol) {
	PresuActual += objetos[k].first;
	SupActual+= objetos[k].second;
	sol[k] = true;
	if (PresuActual <= presu) {
		if (k == obj - 1) {
			if (SupActual > mayor) mayor = SupActual;
		}
		else {
			if (estimar(obj, objetos, presu, PresuActual, k + 1, mayor, SupActual) + SupActual > mayor) 
				resolver(obj, objetos, presu, PresuActual, k + 1, SupActual, mayor,sol);
		}
	}
	PresuActual -= objetos[k].first;
	SupActual -= objetos[k].second;
	sol[k] = false;
	if (PresuActual <= presu) {
		if (k == obj - 1) {
			if (SupActual > mayor) mayor = SupActual;
		}
		else {
			if(estimar(obj,objetos,presu,PresuActual,k+1,mayor,SupActual)+SupActual>mayor)
				resolver(obj, objetos, presu, PresuActual, k + 1, SupActual, mayor,sol);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int obj, presu;
	cin >> obj;
    if (! std::cin)
        return false;
	cin >> presu;
	vector<pair<int,int>> objetos(obj);
	for (int i = 0;i < obj;i++) {
		cin >> objetos[i].first;
		cin >> objetos[i].second;
	}
	sort(objetos.begin(), objetos.end(), sortComp);
	int mayor = 0;
	int costeAux = 0;
	bool supera = false;
	for (int i = 0;!supera && i < obj;i++) {
		costeAux+= objetos[i].first;
		supera = costeAux > presu;
		if (!supera) mayor+= objetos[i].second;
	}
	vector<bool>sol(obj,false);
    resolver(obj,objetos,presu,0,0,0,mayor,sol);
	cout << mayor << "\n";
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-27.1.in");
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