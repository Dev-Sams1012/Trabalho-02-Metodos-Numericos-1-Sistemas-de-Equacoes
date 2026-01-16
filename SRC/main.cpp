#include <bits/stdc++.h>
#include <cstdlib>
#include "Metodos/Gauss.hpp"
#include "Metodos/GaussJordan.hpp"
#include "Metodos/Cramer.hpp"
#include "Resultados/QuadroResposta.hpp"
#include "Resultados/QuadroEntrada.hpp"

using namespace std;
typedef vector<double> vf;
typedef vector<vector<double>> Matriz;

void limparTerminalLinux(){
    system("clear");
}


void lerDados(int& n, double& a, Matriz& C, vf& v){
    cout << "Numero de cordas (n): ";
    cin >> n;

    cout << "Parametro a: ";
    cin >> a;

    C.assign(n, vector<double>(n));
    v.assign(n, 0.0);

    cout << "\nDigite os elementos da matriz C (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "C[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> C[i][j];
        }
    }

    cout << "\nDigite os elementos do vetor v (" << n << "x1):\n";
    for (int i = 0; i < n; i++) {
        cout << "v[" << i + 1 << "]: ";
        cin >> v[i];
    }
}

int main(){
    int n;
    Matriz M;
    vf v;
    double a;
    lerDados(n, a, M, v);
    limparTerminalLinux();
    QuadroEntrada quadroEntrada(n, v, M, a);
    quadroEntrada.imprime();
    GaussJordan GJ(M);
    try{
        vf d = get_dCramer(GJ, v);
        QuadroResposta quadro("QUADRO - METODO DE GAUSS-JORDAN + CRAMER", d, a);
        quadro.imprime();
    }
    catch(runtime_error &e){
        cout << e.what() << "\n";
    }

    Gauss G(M);
    try{
        vf d2 = get_dCramer(G, v);
        QuadroResposta quadro("QUADRO - METODO DE GAUSS + CRAMER", d2, a);
        quadro.imprime();
    }
    catch(runtime_error &e){
        cout << e.what() << "\n";
    }

    return 0;
}
