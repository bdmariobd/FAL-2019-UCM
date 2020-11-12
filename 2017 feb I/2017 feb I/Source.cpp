#include <iostream>
#include<vector>
using namespace std;

/*  PISTALARGA
	ESPECIFICACION
	P: N>=0

	Q: existe k : 0<=k<N (: paratodo i: 0<=i<k: v[i]>=0 AND paratodo j: k<=j<N: v[j]<0)



	INVARIANTE
	para todo k menor que i son todos positivos AND para todo k mayor que j todos son negativos


	COSTE O(N)(caso peor de todos positivos o todos negativos)

*/

int reordena(vector<int> & v) { //no se consiguio hacer lo de devolver el num
	int i = 0, j = v.size() - 1, pos= v.size();
	while (i <j) {
		if (v[i] >= 0 && v[j] < 0) { i++;j--; pos=j; }
		else if (v[i] < 0 && v[j] < 0) { j--; pos = j;}
		else if (v[i] >= 0 && v[j] >= 0) { j--; }
		else if (v[i] < 0 && v[j] >= 0) { swap(v[i], v[j]); i++;j--; pos = i; }
	}
	return pos;
} 
bool procesa_caso1() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& i : v)cin >> i;
	//llamar a la solucion
	int sol = reordena(v);
	for (int& i : v)cout << i<<" ";
	cout << endl<<sol<<endl;

	return true;
}


int noRepetido(const vector<int>& v, int ini, int fin) { 
	if (ini == fin - 1) { return ini; }
	else{
		int mitad = (ini + fin) / 2;
		if (v[mitad] != v[mitad - 1] && v[mitad] != v[mitad + 1]) return mitad;
		if (mitad % 2 == 0) {
			if (v[mitad] == v[mitad + 1]) return noRepetido(v, mitad, fin);
			else return noRepetido(v, ini, mitad);
		}
		else {
			if (v[mitad-1] == v[mitad])  noRepetido(v, mitad, fin);
			else return  noRepetido(v, ini, mitad);
		}
	}
}

/*int noRepetido(const vector<int>& v, int ini, int fin, int mitad) {
	if (ini == fin - 1) { return ini; }
	//1 1 2 2 9
	else if (ini == fin - 3) {
		if (v[ini] != v[ini + 1] && v[ini] != v[ini + 2]) return ini;
		else if (v[ini + 2] != v[ini] && v[ini + 2] != v[ini + 1] && v[ini + 2] != mitad) return ini + 2;
		else return -1;
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad] != v[mitad - 1] && v[mitad] != v[mitad + 1]) return mitad;
		else {
			int iz = noRepetido(v, ini, mitad + 1, v[mitad]);
			if (iz != -1) return iz;
			else return noRepetido(v, mitad, fin, v[mitad]);
		}
	}
}*/
bool procesa_caso2() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& i : v)cin >> i;
	//llamar a la solucion
	int sol = noRepetido(v,0,v.size());
	cout << endl << sol << endl;

	return true;
	return true;
}

void tercero(vector<int>& sol, int k, int& soluciones, vector<pair<int,int>> &posiciones, int n) {
	for (int i = 1;i <= n;i++) {
		if (posiciones[i-1].first == -1 || posiciones[i-1].second == -1 && k - posiciones[i-1].first - 1 == i) {
			sol[k] = i;
			if (posiciones[i-1].first == -1) posiciones[i-1].first = k;
			else posiciones[i - 1].second = k;
			if (k + 1 == sol.size()) {
				soluciones++;
				for (int& i : sol) cout << i << " ";
				cout << endl;
			}
			else tercero(sol, k + 1, soluciones, posiciones, n);
			if (posiciones[i - 1].second == -1) posiciones[i - 1].first = -1;
			else posiciones[i - 1].second = -1;
		}
	}
}
bool procesa_caso3() {
	int n;
	cin >> n;
	vector<int> v(2*n);
	int soluciones = 0;
	vector<pair<int,int>> posiciones(n,pair<int,int>(-1,-1));
	tercero(v, 0, soluciones, posiciones,n);
	cout << "soluciones " << soluciones << endl;
	return true;
}
int main() {
	//while (procesa_caso1());
	while (procesa_caso2());
	//while (procesa_caso3());
}