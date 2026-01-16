#ifndef QUADRO_ENTRADA_HPP
#define QUADRO_ENTRADA_HPP
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef vector<double> vf;
typedef vector<vector<double>> Matriz;




class QuadroEntrada {
    private:
        int n;
        vf v;
        Matriz C;
        double a;

    public:
        QuadroEntrada(int n, vf v, Matriz C, double a) : 
         n(n), v(v), C(C), a(a) {}

        void imprime() {
            cout << "\n==============================================\n";
            cout << "        QUADRO DE PARAMETROS DE ENTRADA\n";
            cout << "==============================================\n";

            cout << "Numero de cordas (n): " << n << endl;
            cout << "Parametro a: " << fixed << setprecision(5) << a << endl;

            cout << "\nMatriz C (" << n << " x " << n << "):\n";
            for (int i = 0; i < n; i++) {
                cout << "| ";
                for (int j = 0; j < n; j++) {
                    cout << setw(10) << C[i][j] << " ";
                }
                cout << "|\n";
            }

            cout << "\nVetor v (" << n << " x 1):\n";
            for (int i = 0; i < n; i++) {
                cout << "| " << setw(10) << v[i] << " |\n";
            }

            cout << "==============================================\n";
        }


};

#endif