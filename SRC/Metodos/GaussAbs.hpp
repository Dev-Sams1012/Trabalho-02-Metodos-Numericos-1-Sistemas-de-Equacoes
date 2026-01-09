#ifndef GAUSS_ABS_HPP
#define GAUSS_ABS_HPP

#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<double>> Matriz;

class GaussAbs
{
    protected:
        Matriz M;
        int n;
    public:
        GaussAbs(Matriz M) : M(M), n(M.size()) {}

        Matriz getMatriz() {
            return M;
        }
        int getOrdem() {
            return n;
        }

        virtual double get_detGauss() = 0;
    

};

#endif