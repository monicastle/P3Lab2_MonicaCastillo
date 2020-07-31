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
            double vertice, izquierda, derecha;
            int inicio = 0;
            vertice = -b / (2 * a);
            izquierda = vertice - 200;
            derecha = vertice + 200;
            // Ejecucion por la izquierda
            Polinomio(int a, int b, int c, izquierda, 0);
            // Ejecucion por la derecha
            Polinomio(int a, int b, int c, inicio, derecha);
            break; }
        case 2: {
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
            for (int i = 0; i < tam; i++){
                for (int j = 0; j < tam; j++){
                    matriz[i][j] = (rand() % 89) + 10;
                } // Fin For
            } // Fin For
            cout << "Matriz generada:" << endl;
            for (int i = 0; i < tam; i++){
                cout << "[";
                for (int j = 0; j < tam; j++){
                    cout << " " << setw(3) << matriz[i][j];
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
            // Obtener los la matriz estandarizada
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
                    cout << " " << setw(1) << mestandar[i][j] << " ";
                } // Fin For
                cout << "]" << endl;
            } // Fin For
            break; }
        case 3:{
            int limite = 0, cont = 0;
            double sumatoria;
            cout << "Ingrese el limite de la sumatoria: ";
            cin >> limite;
            while (limite <= 0){
                cout << "¡El limite no puede ser negativo!" << endl;
                cout << "Ingrese el limite de la sumatoria: ";
                cin >> limite;
            } // Fin While Validacion  
            sumatoria = 4 * Sumatoria(limite, cont); 
            cout << "Pi es igual a: " << sumatoria << endl;
            break; }
        case 4:{
            respuesta = 'n';
            break; }
        default:
            cout << "¡Entrada no valida!";
        } // Fin Switch
    } // Fin While Respuesta
} // Fin Main

double Sumatoria(int lim, int cont){
    if (lim == cont){
        return 0;
    } else {     
        return ((pow(-1, cont)) / ((2 * cont) + 1) ) + Sumatoria(lim, cont + 1);
    } // Fin If
} // Fin Sumatoria

double Polinomio(){

}