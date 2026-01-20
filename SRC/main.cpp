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
            return x;
        } catch (...) {
            cout << "Valor invalido. Digite um numero real.\n";
        }
    }
}

double lerDoublePositivo(const string& msg) {
    string linha;
    double x;
    
    while (true) {
        cout << msg;
        getline(cin, linha);

        try {
            x = stod(linha);
            if (x > 0.0) return x;
            throw invalid_argument("Valor invalido");
        } catch (...) {
            cout << "Valor invalido. Digite um numero real positivo.\n";
        }
    }
}

void lerDados(int& n, double& a, Matriz& C, vf& v){
    cout << "\033[33m";
    cout << R"(
    .___  ___.  _______ .___________.  ______    _______    ______        _______.   .__   __.  __    __  .___  ___.  _______ .______       __    ______   ______        _______.
    |   \/   | |   ____||           | /  __  \  |       \  /  __  \      /       |   |  \ |  | |  |  |  | |   \/   | |   ____||   _  \     |  |  /      | /  __  \      /       |
    |  \  /  | |  |__   `---|  |----`|  |  |  | |  .--.  ||  |  |  |    |   (----`   |   \|  | |  |  |  | |  \  /  | |  |__   |  |_)  |    |  | |  ,----'|  |  |  |    |   (----`
    |  |\/|  | |   __|      |  |     |  |  |  | |  |  |  ||  |  |  |     \   \       |  . `  | |  |  |  | |  |\/|  | |   __|  |      /     |  | |  |     |  |  |  |     \   \
    |  |  |  | |  |____     |  |     |  `--'  | |  '--'  ||  `--'  | .----)   |      |  |\   | |  `--'  | |  |  |  | |  |____ |  |\  \----.|  | |  `----.|  `--'  | .----)   |
    |__|  |__| |_______|    |__|      \______/  |_______/  \______/  |_______/       |__| \__|  \______/  |__|  |__| |_______|| _| `._____||__|  \______| \______/  |_______/
    )";
    cout << "\033[0m";

    cout << "\n";

    cout << "\033[38;5;208m";

    cout << R"(
     _____                _             _   _               __    ___              ___                  _            ___   _               _     _             
    |_   _|  _ _   __ _  | |__   __ _  | | | |_    ___     /  \  |_  )    ___     / __|  ___   _ _   __| |  __ _    | __| | |  __ _   ___ | |_  (_)  __   __ _ 
      | |   | '_| / _` | | '_ \ / _` | | | | ' \  / _ \   | () |  / /    |___|   | (__  / _ \ | '_| / _` | / _` |   | _|  | | / _` | (_-< |  _| | | / _| / _` |
      |_|   |_|   \__,_| |_.__/ \__,_| |_| |_||_| \___/    \__/  /___|            \___| \___/ |_|   \__,_| \__,_|   |___| |_| \__,_| /__/  \__| |_| \__| \__,_|
    )";

    cout << "\033[0m";

    cout << "\n";

    cout << "\033[32;5;208m";

    cout << R"(
     _____       _                _           _           _         _             _ 
    |   __| ___ | |_  ___  ___  _| | ___    _| | ___    _| | ___  _| | ___  ___  |_|
    |   __||   ||  _||  _|| .'|| . || .'|  | . || -_|  | . || .'|| . || . ||_ -|  _ 
    |_____||_|_||_|  |_|  |__,||___||__,|  |___||___|  |___||__,||___||___||___| |_|
    )";

    cout << "\033[0m";

    cout << "\n\n";

    n = lerInteiroPositivo("Numero de cordas (n): ");
    a = lerDoublePositivo("Parametro a: ");

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

void executarMetodo(GaussAbs &metodo, const vf &v, double &a) {
    try {
        vf d = get_dCramer(metodo, v);
        string titulo = "QUADRO - METODO DE " + metodo.getNomeMetodo() + " + CRAMER";
        
        QuadroResposta quadro(titulo, d, a);
        quadro.imprime();
    }
    catch(runtime_error &e) {
        cout << e.what() << "\n";
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

    Gauss G(M);
    executarMetodo(G, v, a);

    cout<< "\n===============================================================\n\n";

    GaussJordan GJ(M);
    executarMetodo(GJ, v, a);

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
