#ifndef GAUSS_HPP
#define GAUSS_HPP

#include <bits/stdc++.h>
#include "GaussAbs.hpp"

using namespace std;
typedef vector<vector<double>> Matriz;

class Gauss : public GaussAbs
{
public:
    Gauss(Matriz M) : GaussAbs(M) {}

    string getNomeMetodo() const override { return "Gauss"; }

    GaussAbs* clone(const Matriz& M) const override { return new Gauss(M); }

protected:
    void passoElimina(Matriz& A, int i) {
        for(int j=i+1; j<n; j++){
            double fator = A[j][i] / A[i][i];

            for(int k=i; k<n; k++){
                A[j][k] -= fator * A[i][k];

                if(fabs(A[j][k]) < 1e-6) A[j][k] = 0;
            }
        }
    }
};

#endif 