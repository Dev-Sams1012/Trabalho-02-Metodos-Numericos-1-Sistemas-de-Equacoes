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

        double get_detGauss(){
            double det = 1.0;
            int trocas = 0;
            Matriz tempM = getMatriz();
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
                for(int j=i+1; j<n; j++){
                    double fator = tempM[j][i] / tempM[i][i];

                    for(int k=i; k<n; k++){
                        tempM[j][k] -= fator * tempM[i][k];
                    }
                }
            }
            for(int i=0; i<n; i++){
                det *= tempM[i][i];
            }
            if(trocas % 2 == 1){
                det = -det;
            }
            return det;
        }

};


#endif 