#ifndef QUADRO_HPP
#define QUADRO_HPP
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef vector<double> vf;
typedef vector<vector<double>> Matriz;

const string RED   = "\033[31m";
const string GREEN = "\033[32m";
const string RESET = "\033[0m";

class QuadroResposta {
private:
    string titulo;
    vf dados;
    double a;

    public:
        QuadroResposta(string titulo, vf dados, double a) : titulo(titulo), dados(dados), a(a) {}

        void imprime() {
            cout << "\n==============================================\n";
            cout << " " << titulo << "\n";
            cout << "==============================================\n";

            cout << left
                << setw(6)  << "i"
                << setw(15) << "d"
                << setw(15) << "Amplitude"
                << "Situacao\n";

            cout << "----------------------------------------------\n";

            for (int i = 0; i < (int)dados.size(); i++) {
                double di = (fabs(dados[i]) < 1e-6) ? 0.0 : dados[i];
                double A = a * di;

                string situacao = (fabs(A) > 3.0)
                    ? RED + "ROMPE" + RESET
                    : GREEN + "SEGURA" + RESET;

                cout << setw(6)  << i + 1
                    << setw(15) << fixed << setprecision(5) << di
                    << setw(15) << A
                    << situacao << endl;
            }

            cout << "==============================================\n\n";
        }

};

#endif