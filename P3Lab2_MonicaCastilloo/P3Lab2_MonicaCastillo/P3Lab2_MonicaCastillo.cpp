// P3Lab2_MonicaCastillo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
int main() {
	char respuesta = 's';
	while (respuesta == 's') {
		int opcion;
		cout << "1. Ejercicio #1" << endl;
		cout << "2. Ejercicio #2" << endl;
		cout << "3. Ejercicio #3" << endl;
		cout << "4. Salida" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
			break; }
		case 2: {
			break; }
		case 3: {
			break; }
		case 4: {
			respuesta = 'n';
			break; }
		default:
		} // Fin Switch
	} // Fin While Respuesta
} // Fin Main
