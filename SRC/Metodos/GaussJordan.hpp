#ifndef GAUSS_NORMAL_HPP
#define GAUSS_NORMAL_HPP
#include <bits/stdc++.h>
#include "Gauss.hpp"
using namespace std;
typedef vector<vector<double>> Matriz;

class GaussJordan : public Gauss
{
public:
    GaussJordan(Matriz M) : Gauss(M) {}
    
    double get_detGauss() {
        double det = 1.0;
        int trocas = 0;
        Matriz tempM = getMatriz();
        int n = tempM.size();
        for(int i=0; i<n; i++){
            if(tempM[i][i] == 0){
                for(int k=i+1; k<n; k++){
                    if(tempM[k][i] != 0){
                        swap(tempM[i], tempM[k]);
                        trocas++;
                        break;
                    }
                }
            }

            double pivot = tempM[i][i];
            det *= pivot;
            for(int k=0; k<n; k++){
                tempM[i][k] /= pivot;
            }
            for(int j=0; j<n; j++){
                if(j == i) continue;
                double fator = tempM[j][i] / tempM[i][i];   
                for(int k=i; k<n; k++){
                    tempM[j][k] -= fator * tempM[i][k];
                }
            }
        }
        if(trocas % 2 == 1){
            det = -det;
        }
        return det;
    }
};






#endif

