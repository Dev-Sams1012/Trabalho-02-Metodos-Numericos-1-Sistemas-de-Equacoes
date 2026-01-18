#ifndef GAUSS_ABS_HPP
#define GAUSS_ABS_HPP

#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<double>> Matriz;

class GaussAbs{
protected:
    Matriz M;
    int n;

    virtual void passoElimina(Matriz& A, int i) = 0;

public:
    GaussAbs(Matriz M) : M(M), n(M.size()) {}

    Matriz getMatriz() { return M; }
    
    int getOrdem() { return n; }

    virtual ~GaussAbs() = default;

    virtual GaussAbs* clone(const Matriz& M) const = 0;

    double get_detGauss() {
        Matriz A = M;
        double det = 1.0;
        int trocas = 0;
        double EPS = 1e-6;

        for (int i = 0; i < n; i++) {
            int pivot = i;

            for (int k = i + 1; k < n; k++) {
                if (abs(A[k][i]) > abs(A[pivot][i])) {
                    pivot = k;
                }
            }

            if (abs(A[pivot][i]) < EPS) return 0.0;

            if (pivot != i) {
                swap(A[i], A[pivot]);
                trocas++;
            }

            passoElimina(A, i);
        }

        for (int i = 0; i < n; i++)
            det *= A[i][i];

        if (trocas % 2 == 1) det = -det;

        return det;
    }
};

#endif