#ifndef CRAMER_HPP
#define CRAMER_HPP
#include <bits/stdc++.h>
#include "Gauss.hpp"
#include "GaussJordan.hpp"

using namespace std;
typedef vector<vector<double>> Matriz;
typedef vector<double> vf;

vf get_dCramer(GaussAbs &G, const vf &v){
    int n = G.getOrdem();
    double detA = G.get_detGauss();
    double EPS = 1e-6;

    if(abs(detA) < EPS){
        throw runtime_error("Sistema nao possui solucao unica.");
    }

    vf d(n);

    for(int i=0; i<n; i++){
        Matriz Ai = G.getMatriz();

        for(int j=0; j<n; j++){
            Ai[j][i] = v[j];
        }

        GaussAbs *Gi;

        if(dynamic_cast<GaussJordan*>(&G)){
            Gi = new GaussJordan(Ai);
        } else{
            Gi = new Gauss(Ai);
        }

        double detAi;
        detAi = Gi->get_detGauss();

        d[i] = detAi / detA;
    }

    return d;
}

#endif