#ifndef GAUSS_JORDAN_HPP
#define GAUSS_JORDAN_HPP

#include <bits/stdc++.h>
#include "GaussAbs.hpp"

using namespace std;
typedef vector<vector<double>> Matriz;

class GaussJordan : public GaussAbs
{
public:
    GaussJordan(Matriz M) : GaussAbs(M) {}

    GaussAbs* clone(const Matriz& M) const override { return new GaussJordan(M); }

protected:
    void passoElimina(Matriz& A, int i) {
        for(int j=0; j<n; j++){
            if(j == i) continue;

            double fator = A[j][i] / A[i][i]; 

            for(int k=i; k<n; k++){
                A[j][k] -= fator * A[i][k];
            }
        }
    }
};

#endif