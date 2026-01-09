#include <bits/stdc++.h>
#include "Metodos/Gauss.hpp"
#include "Metodos/GaussJordan.hpp"
#include "Metodos/Cramer.hpp"


using namespace std;
typedef vector<double> vf;
typedef vector<vector<double>> Matriz;


int main(){
    Matriz M = {
        {10, 1, 1},
        {1, 10, 1},
        {1, 1, 10}
    };
    vf v = {12, 12, 12};

    GaussJordan GJ(M);
    try{
        vf d = get_dCramer(GJ, v);
        cout << "Solução pelo método de Cramer com Gauss-Jordan:\n";
        for(int i=0; i < (int) d.size(); i++){
            cout << "x" << i+1 << " = " << d[i] << "\n";
        }
    }
    catch(runtime_error &e){
        cout << e.what() << "\n";
    }

    Gauss G(M);
    try{
        vf d2 = get_dCramer(G, v);
        cout << "Solução pelo método de Cramer com Gauss:\n";
        for(int i=0; i< (int) d2.size(); i++){
            cout << "x" << i+1 << " = " << d2[i] << "\n";
        }
    }
    catch(runtime_error &e){
        cout << e.what() << "\n";
    }

    return 0;
}
