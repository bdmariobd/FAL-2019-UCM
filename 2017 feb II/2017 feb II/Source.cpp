#include <iostream>
#include<vector>
using namespace std;

/* 
	ESPECIFICACION
	P: 0<=n<=1000 && d>0
	bool cumple(const vector<int>& v, int d)
	Q : sol =  esCreciente(v) && esDivertido(v,d)
		esCreciente(v,n)= paratodo k: 0<=k<n-1 : v[k]+1==v[k+1] ||  v[k]==v[k+1]
		esDivertido(v,d,n) = paratodo K : 0<=k<n : (#l : 0 <= l < n : v[l] = v[k])<=d

	INVARIANTE
	paratodo k : 0<=k<=i : esCreciente(v,i) && esDivertido(v,d,i)
	funcion cota n-i

	COSTE O(N)

*/

bool cumple(const vector<int>& v, int d) {
	int i = 0, repes=0;
	while (i < v.size()-1) {
		if (v[i] + 1 == v[i + 1]) { // es creciente x los pelos
			repes = 0;
		}
		else if (v[i] == v[i + 1]) {
			repes++;
		}
		else return false;
		if (repes+1 > d) return false;
		i++;
	}
	return true;
}
bool procesa_caso1() {
	int d,n;
	cin >> d>>n;
	vector<int> v(n);
	for (int& i : v)cin >> i;
	//llamar a la solucion
	if (cumple(v, d)) cout << "Si\n";
	else cout << "No\n";

	return true;
}

bool cumple2(const vector<int>& v, int ini, int fin) {
	if (ini == fin) return true;
	if (ini == fin - 1) return true;
	if (ini == fin - 2) {
		if (v[ini] + 1 == v[ini + 1] || v[ini] == v[ini + 1]) return true;
		return false;
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad-1] + 1 == v[mitad] || v[mitad-1] == v[mitad])
			return cumple2(v, ini, mitad) && cumple2(v, mitad, fin);
		return false;
	}
}

bool procesa_caso2() {
	int n;
	cin >>n;
	vector<int> v(n);
	for (int& i : v)cin >> i;
	//llamar a la solucion
	if (cumple2(v,0,n)) cout << "Si\n";
	else cout << "No\n";

	return true;
}

void generar(vector<int>& v, int d, int k, vector<int>& acum, int actual, int e){
	for (int i = actual;i < v.size() + e;i++) {
		if ((v[k - 1] + 1 == i || v[k - 1] == i) &&
			acum[i-e] < d) {
			acum[i -e]++;
			if (acum[i - e] == d) actual++;
			v[k] = i;
			if (k + 1 == v.size()) {
				for (int& i : v)cout << i;
				cout << "\n";
			}
			else generar(v, d, k + 1, acum,actual,e);
			acum[i - e]--;
		}
		
	}
}
bool procesa_caso3() {
	int d, n,e;
	cin >> n >> d>>e;
	vector<int> v(n);
	v[0] = e;
	//llamar a la solucion
	vector<int> acum(n,0);
	acum[0] = 1;
	generar(v, d, 1,acum,e, e);

	return true;
}

int main() {
	//while (procesa_caso1());
	//while (procesa_caso2());
	while (procesa_caso3());
}