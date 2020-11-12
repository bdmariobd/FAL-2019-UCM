#include <iostream>
#include<vector>
using namespace std;

/*Especifica, dise ̃na e implementa un problema que dada una serie de
n ́umeros enteros obtenga el n ́umero de segmentos de la serie que cumplen que cada valor del segmento
no difiere del valor siguiente en m ́as de una unidad y que la longitud del segmento sea mayor o igual
que L. Dado un segmento con un n ́umero mayor que L de valores que no difieren en m ́as de una unidad
cada uno con el siguiente, se contar ́a  ́unicamente el segmento completo. Por ejemplo, dada la serie 2 2 2
2 7 3 3 con valor L = 2 se contar ́an dos segmentos, el 2 2 2 2 y el 3 3.*/
//coste O(N)
/*
	P : n>0 && 2<=L<=N && para todo k: o<=K<n : -1000<=v[k]<=1000
	primero(datos,l)

	Q: sol : #

*/
int primero(const vector<int>& datos, int l) {
	int segmentos = 0, rachaActual=0;
	for (int i = 1;i < datos.size();i++) {
		if (abs(datos[i] - datos[i - 1]) < 2) {
			rachaActual++;
		}
		else {
			if (rachaActual +1>= l) {
				rachaActual = 0;
				segmentos++;
			}
		}
	}
	if (rachaActual >= l) segmentos++;
	return segmentos;
}

//coste log(N)
/*
t
*/
int segundo(const vector<int>& datos, int ini, int fin) {
	if (ini == fin - 1) {
		if (datos[ini] == 1) return datos.size()-1 - ini;
		else return datos.size();
	}
	else {
		int mitad = (ini + fin) / 2;
		if (datos[mitad] == 1) return segundo(datos, mitad, fin);
		else return segundo(datos, ini, mitad);
	}
}
pair<int,int> tercero(const vector<int>& v1, const vector<int>& v2, int ini, int fin) {
	if (ini == fin - 1) {
		if (ini == 0) return{ -1,0 };
		return{ ini,fin };
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v1[mitad] <= v2[mitad]) return tercero(v1, v2, mitad, fin);
		else return tercero(v1, v2, ini, mitad);
	}
}
bool procesa_caso1() {
	int n;
	cout << "Tamanho: ";
	cin >> n;
	if (n == -0) {
		return false;
	}
	else {
		vector<int> datos(n);
		int l;
		cin >> l;
		for (int& i : datos)cin >> i;
		cout << "solucion: " << primero(datos,l)<<"\n";
	}

	return true;
		
}



bool procesa_caso2() {
	int n;
	cout << "Tamanho: ";
	cin >> n;
	if (n == -1) return false;
	if (n == 0) cout << "0\n";
	else {
		vector<int> datos(n);
		for (int& i : datos)cin >> i;
		cout << "solucion: " << segundo(datos,0,n) << "\n";
	}
	return true;
}

bool procesa_caso3() {
	int n;
	cout << "Tamanho: ";
	cin >> n;
	if (n == 0) return false;
	else {
		vector<int> v1(n);
		vector<int> v2(n);
		for (int& i : v1)cin >> i;
		for (int& i : v2)cin >> i;
		pair<int, int>sol = tercero(v1, v2, 0, n);
		cout << "solucion: " << sol.first<<" "<<sol.second << "\n";
	}
	return true;
}
int main() {
	//while (procesa_caso1());
	//while (procesa_caso2());
	while (procesa_caso3());
}