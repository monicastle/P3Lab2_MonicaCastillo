// P3Lab2_MonicaCastillo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int[][] Lectura(int tam);
void Imprimir(int[][], int tam);
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

int[][] Lectura(int tam) {
	int matriz[tam][tam];
	srand(time(0));
	for (int i = 0; i < tam; i++) {
		for (int i = 0; i < tam; i++) {
			matriz[i][j] << (rand() % 99) + 10;
		} // Fin For
	} // Fin For
} // Fin Lectura

void Imprimir(int matriz[][], int tam) {
	for (int i = 0; i < tam; i++) {
		for (int i = 0; i < tam; i++) {
			cout << matriz[i][j];
		} // Fin For
	} // Fin For
}