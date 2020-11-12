#include <iostream>
#include<vector>
using namespace std;


void primero(const vector<int> & edadesRec, const vector<int>& edades, 
	const vector<vector<int>>&sat, int min, int k,
	vector<int>& marcasNin, int& satMax, int satActual) {
	bool todostienen = true;
	for (int i = 0;i < edades.size();i++) {
		if (edades[i]>= edadesRec[k] ) {
			satActual += sat[i][k];
			marcasNin[i]++;
			if (k == edadesRec.size()-1) {
				for (int aux = 0; aux < marcasNin.size();aux++) if (marcasNin[aux] < min)todostienen = false;
				if (todostienen && satActual > satMax)	satMax = satActual;
			}
			else primero(edadesRec, edades, sat, min, k + 1, marcasNin, satMax, satActual);
			//desmarcar
			satActual -= sat[i][k];
			marcasNin[i]--;
		}
	}
}
bool procesa_caso1() {
	int j, n, min;
	cin >> j >> n >> min;
	vector<int> edadesRec(j);
	for (int& i : edadesRec)cin >> i;
	vector<int> edades(n);
	for (int& i : edades)cin >> i;
	vector<vector<int>> sat(n, vector<int>(j));
	for (int x = 0;x < n;x++)
		for (int y = 0;y < j;y++)
			cin >> sat[x][y];
	vector<bool> marcasJug(j, false);
	vector<int> marcasNin(n, 0);
	int satMax=0;
	//procesar
	
	primero(edadesRec, edades, sat, min, 0,  marcasNin,satMax,0);

	cout << satMax;
	return true;
}


int main() {
	while (procesa_caso1());
		
}