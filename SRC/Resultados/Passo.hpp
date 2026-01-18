#ifndef PASSO_HPP
#define PASSO_HPP
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef vector<double> vf;
typedef vector<vector<double>> Matriz;

class Passo{
    private:
        int n;
        int k;
        Matriz C;
        string Met;
        double det;
    
    public:
        Passo(int n, int k, Matriz C, string Met, double det):
        n(n), k(k), C(C), Met(Met), det(det) {}

        void imprime(){
            
            cout << "\n" << Met << " - Matriz Final A" << k << "\n";
            for (int i = 0; i < n; i++) {
                cout << "| ";
                for (int j = 0; j < n; j++) {
                    cout << setw(10) << C[i][j] << " ";
                }
                cout << "|\n";
            }
            cout << "Det A" << k << " = " << det << "\n";
        }

};

#endif