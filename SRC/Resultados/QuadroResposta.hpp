#ifndef QUADRO_HPP
#define QUADRO_HPP
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef vector<double> vf;
typedef vector<vector<double>> Matriz;



class QuadroResposta {
private:
    string titulo;
    vf dados;
    double a;

    public:
        QuadroResposta(string titulo, vf dados, double a) : titulo(titulo), dados(dados), a(a) {}

        void imprime() {
            cout << "\n\n==============================================\n";
            cout << " " << titulo << "\n";
            cout << "==============================================\n";

            cout << left
                << setw(6)  << "i"
                << setw(15) << "d"
                << setw(15) << "Amplitude"
                << "Situacao\n";

            cout << "----------------------------------------------\n";

            for (int i = 0; i < (int)dados.size(); i++) {
                double A = a * dados[i];
                string situacao = (fabs(A) > 3.0) ? "\033[31mROMPE\033[0m" : "\033[32mSEGURA\033[0m";

                if(fabs(dados[i]) < 1e-6) dados[i] = 0;

                cout << setw(6)  << i + 1
                    << setw(15) << fixed << setprecision(5) << dados[i]
                    << setw(15) << A
                    << situacao << endl;
            }

            cout << "==============================================\n\n";
        }

};

#endif