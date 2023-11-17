#include<iostream>
#include<string>
#include<vector>
#include<random>
using namespace std;

char consonante(string val) {
	for (int i = 1; i < val.size(); i++) {
		if (val[i] != 'a' && val[i] != 'e' && val [i] != 'o' && val[i] != 'u') {
			return toupper(val[i]);
		}
	}
	return '0';
}
int main() {
	string name, lastNameF, state, lastNameM, birth, genero;
	string curp = "";

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distribution(0,9);

	cout << "------------------ NOMBRE ----------------\n";
	getline(cin,name);
	cout << "\n------------------ APELLIDO PATERNO ----------------\n";
	cin >> lastNameF;
	cout << "\n------------------ APELLIDO MATERNO ----------------\n";
	cin >> lastNameM;
	cout << "\n------------------ ESTADO ----------------\n";
	cin >> state;
	cout << "\n------------------ FECHA (AA/MM/DD) ----------------\n";
	cin >> birth;
	cout << "\n------------------- GENERO -----------------------\n";
	cin >> genero;

	curp += lastNameF[0];
	while (true) {
		bool isBlank = false;
		for (int i = 0; i < lastNameF.size(); i++) {
			if (lastNameM[i] == 'a' || lastNameM[i] == 'e' || lastNameM[i] == 'o' || lastNameM[i] == 'u') {
				curp += toupper(lastNameF[i]);
				break;
			}
		}
		curp += toupper(lastNameM[0]);
		curp += toupper(name[0]);
		
		curp += birth;
		curp += toupper(genero[0]);
		size_t pos;
		while ((pos = curp.find("/")) != string::npos) {
			curp.erase(pos, 1);
		}
		curp += state;
		curp += consonante(lastNameF);
		curp += consonante(lastNameM);
		curp += consonante(name);
		curp += distribution(gen) + '0';
		curp += distribution(gen) + '0';
		break;
	}
	cout << curp;

	return 0;
}