#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

double Sumatoria(int, int);
double Polinomio(int, int, int, int, double);
int main(){
    char respuesta = 's';
    while (respuesta == 's'){
        int opcion;
        cout << "1. Ejercicio #1" << endl;
        cout << "2. Ejercicio #2" << endl;
        cout << "3. Ejercicio #3" << endl;
        cout << "4. Salida" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion){
        case 1:{
            // Aqui va el Ejercicio #1
            int a, b, c;
            cout << "Se ingresara un polinomio de la siguiente forma: ax^2 + bx + c" << endl;
            cout << "Ingrese el valor de a: ";
            cin >> a;
            while (a == 0){
            cout << "¡El valor de a no puede ser 0!" << endl;
            cout << "Ingrese el valor de a: ";
            cin >> a;
            } // Fin While Validacion 
            cout << "Ingrese el valor de b: ";
            cin >> b;
            cout << "Ingrese el valor de c: ";
            cin >> c;
            double vertice, xizquierda, xderecha;
            int inicio = 0;
            // Se calcula el Vertice del polinomio:
            vertice = -b / (2 * a);
            // Se le suma a dicho vertice 200 por la derecha y 
            // se le resta 200 por la izquierda 
            xizquierda = vertice - 200;
            xderecha = vertice + 200;
            // Ejecucion por la derecha
            cout << "Raiz encontrada #1: " << Polinomio(a, b, c, inicio, xderecha) << endl;
            // Ejecucion por la izquierda
            cout << "Raiz encontrada #2: " << Polinomio(a, b, c, inicio, xizquierda) << endl;
            break; }
        case 2: {
            // Aqui va el Ejercicio #2
            int tam = 0;
            cout << "Ingrese el tamano de la matriz: ";
            cin >> tam;
            while (tam <= 0){
                cout << "¡El tamano no puede ser negativo!" << endl;
                cout << "Ingrese el tamano de la matriz: ";
                cin >> tam;
            } // Fin While Validacion         
            int matriz[tam][tam];
            srand(time(0));
            // Genera la matriz con numero random
            for (int i = 0; i < tam; i++){
                for (int j = 0; j < tam; j++){
                    matriz[i][j] = (rand() % 89) + 10;
                } // Fin For
            } // Fin For
            // Imprime la matriz generada
            cout << "Matriz generada:" << endl;
            for (int i = 0; i < tam; i++){
                cout << "[";
                for (int j = 0; j < tam; j++){
                    cout << " " << setw(2) << matriz[i][j];
                } // Fin For
                cout << "]" << endl;
            } // Fin For
            double acum = 0, acumdes = 0;
            double media, desv, result, res;
            double mestandar[tam][tam];
            // Suma de todos los valores en la matriz
            for (int i = 0; i < tam; i++){
                for (int j = 0; j < tam; j++){
                    acum += matriz[i][j];
                } // Fin For
            } // Fin For
            media = acum / (tam * tam);
            // Obtener los valores de la desviacion estandar
            for (int i = 0; i < tam; i++){
                for (int j = 0; j < tam; j++){
                    res = matriz[i][j] - media;
                    acumdes += pow(res, 2);
                } // Fin For
            } // Fin For
            result = acumdes / (tam * tam);
            desv = sqrt(result);
            // Obtener los valores de la matriz estandarizada
            for (int m = 0; m < tam; m++){                
                for (int c = 0; c < tam; c++){                  
                    mestandar[m][c] = (matriz[m][c] - media) / desv;
                } // Fin For
            } // Fin For
            cout << "Matriz estandarizada:" << endl;
            // Impresion de la Matriz Estandarizada
            for (int i = 0; i < tam; i++){
                cout << "[";
                for (int j = 0; j < tam; j++){
                    cout << setw(11) << mestandar[i][j] << " ";
                } // Fin For
                cout << "]" << endl;
            } // Fin For
            break; }
        case 3:{
            // Aqui va el Ejercicio #3
            int limite = 0, cont = 0;
            double sumatoria;
            cout << "Ingrese el limite de la sumatoria: ";
            cin >> limite;
            while (limite <= 0){
                cout << "¡El limite no puede ser negativo!" << endl;
                cout << "Ingrese el limite de la sumatoria: ";
                cin >> limite;
            } // Fin While Validacion  
            // Calcula la aproximacion de pi
            sumatoria = 4 * Sumatoria(limite, cont); 
            cout << "Pi es igual a: " << sumatoria << endl;
            break; }
        case 4:{
            // Aqui va la Salida
            respuesta = 'n';
            break; }
        default:
            cout << "¡Entrada no valida!";
        } // Fin Switch
    } // Fin While Respuesta
} // Fin Main

// Metodo que calcula la aproximacion de pi, sumandole al contador 1 en cada vuelta
// para que se vaya acumulando cada suma
double Sumatoria(int lim, int cont){
    if (lim == cont){
        return 0;
    } else {     
        return ((pow(-1, cont)) / ((2 * cont) + 1) ) + Sumatoria(lim, cont + 1);
    } // Fin If
} // Fin Sumatoria

// Metodo que obtiene las raices de un polinomio, ya sea por la izquierda o derecha
// Iterará 100 veces y se ira restando la funcion a la anterior
double Polinomio(int a, int b, int c, int inicio, double lado){
    double x;
    if (inicio == 100){
        return lado;
    } else {
        x = Polinomio(a, b, c, inicio + 1, lado);
        return x - ((a * pow(x, 2) + (b * x) + c) / ((2 * a * x) + b));
    } // Fin If
} // Fin Polinomio