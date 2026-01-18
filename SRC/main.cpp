#include <bits/stdc++.h>
#include <cstdlib>
#include <limits>
#include "Metodos/Gauss.hpp"
#include "Metodos/GaussJordan.hpp"
#include "Metodos/Cramer.hpp"
#include "Resultados/QuadroResposta.hpp"
#include "Resultados/QuadroEntrada.hpp"

using namespace std;
typedef vector<double> vf;
typedef vector<vector<double>> Matriz;

void limparTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int lerInteiroPositivo(const string& msg) {
    string linha;
    int x;

    while (true) {
        cout << msg;
        getline(cin, linha);

        try {
            x = stoi(linha);
            if (x > 0) return x;
            throw invalid_argument("Valor invalido");
        } catch (...) {
            cout << "Valor invalido. Digite um inteiro positivo.\n";
        }
    }
}

double lerDouble(const string& msg) {
    string linha;
    double x;
    
    while (true) {
        cout << msg;
        getline(cin, linha);

        try {
            x = stod(linha);
            if (x > 0) return x;
            throw invalid_argument("Valor invalido");
        } catch (...) {
            cout << "Valor invalido. Digite um numero real.\n";
        }
    }
}


void lerDados(int& n, double& a, Matriz& C, vf& v){
    n = lerInteiroPositivo("Numero de cordas (n): ");
    a = lerDouble("Parametro a: ");

    C.assign(n, vector<double>(n));
    v.assign(n, 0.0);

    cout << "\nDigite os elementos da matriz C (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = lerDouble("C[" + to_string(i + 1) + "][" + to_string(j + 1) + "]: ");
        }
    }

    cout << "\nDigite os elementos do vetor v (" << n << "x1):\n";
    for (int i = 0; i < n; i++) {
        v[i] = lerDouble("v[" + to_string(i + 1) + "]: ");
    }
}

bool executaPrograma(){
    limparTerminal();

    int n;
    Matriz M;
    vf v;
    double a;

    lerDados(n, a, M, v);
    limparTerminal();

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

    string resposta;
    while (true) {
        cout << "Deseja executar novamente? (s/n): ";
        getline(cin, resposta);

        if (resposta == "s" || resposta == "S" ){
            cout << "\n\n";
            return true;
        } else if (resposta == "n" || resposta == "N"){
            cout << "\n\nEncerrando o programa.\n\n";
            return false;
        }

        cout << "Resposta invalida. Digite 's' ou 'n'.\n";
    }
}

int main(){
    while (executaPrograma());
}
