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
    
    double get_detGauss() {
        double det = 1.0;
        int trocas = 0;
        double EPS = 1e-6;
        Matriz tempM = getMatriz();

        for(int i=0; i<n; i++){
            int pivotL = i;

            for(int k=i+1; k<n; k++){
                if (abs(tempM[k][i]) > abs(tempM[pivotL][i])) pivotL = k;
            }

            if (abs(tempM[pivotL][i]) < EPS) return 0.0;

            if (pivotL != i){
                    swap(tempM[i], tempM[pivotL]);
                    trocas++;
            }

            for(int j=0; j<n; j++){
                if(j == i) continue;

                double fator = tempM[j][i] / tempM[i][i]; 

                for(int k=i; k<n; k++){
                    tempM[j][k] -= fator * tempM[i][k];
                }
            }
        }

        for(int i=0; i<n; i++){
            det *= tempM[i][i];
        }

        if(trocas % 2 == 1) det = -det;
        
        return det;
    }

};

#endif