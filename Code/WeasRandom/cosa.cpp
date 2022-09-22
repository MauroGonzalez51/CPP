#include <iostream>
#include <string>

using namespace std;

int main() {
	int m, c1 = 0, c2 = 0;
	
	do {
		cout << "Ingrese la cantidad de trabajadores: ";
		cin >> m;
	} while (m < 1);

	string Codigo[m];
	int Grupo[m];
	int Salario[m];

	// Llenando las arrays 
	for (int i = 0; i < m; i++) {
		cout << "Empleado " << i + 1 << ", Ingrese su Codigo: ";
		cin >> Codigo[i];

		do {
			cout << "Empleado " << i + 1 << ", Ingrese su Grupo: ";
			cin >> Grupo[i];
		} while ((Grupo[i] != 1) && (Grupo[i] != 2));

		do {
			cout << "Empleado " << i + 1 << ", Ingrese su Salario semanal: ";
			cin >> Salario[i];
		} while (Salario[i] < 1);
	}

	// Aplicando el aumento del Salario
	for (int i = 0; i < m; i++) {
		if (Grupo[i] == 1) {
			Salario[i] += 250000;
			c1++;
		} else {
			Salario[i] += 150000;
			c2++;
		}
	}

	// Buscando los promedios de salarios de cada Grupo 
	float sum1 = 0.0, sum2 = 0.0, prom1 = 0.0, prom2 = 0.0;
	for (int i = 0; i < m; i++) {
		if (Grupo[i] == 1) {
			sum1 += Salario[i];
		} else {
			sum2 += Salario[i];
		}
	}

	if (c1 != 0)
		prom1 = sum1 / c1;

	if (c2 != 0)
		prom2 = sum2 / c1;

	// Aplicando los cambios de Grupo
	int cambios = 0;
	for (int i = 0; i < m; i++) {
		if ((Grupo[i] == 1) && (Salario[i] > prom1)) {
			Grupo[i] = 2;
			cambios++;
		}
	}

	cout << endl;
	cout << "Nuevos salarios" << endl;
	cout << "Cantidad de trabajadores de que cambiaron de Grupo: " << cambios << endl;

	for (int i = 0; i < m; i++) {
		cout << "Codigo: " << Codigo[i] << " - Grupo: " << Grupo[i] << " - Salario: " << Salario[i] << endl;
	}

	return 0;
}