#include <iostream>
#include <stdio.h>
#include "math.h"
using namespace std;
#include "vector"

double tight;
int k, n;
vector<vector <double> > arr;

double tights(int prev, int lenght){
    if(lenght == 0){
        return (double)1.0;
    } else{
        if(arr[prev][lenght] != 0){
            return arr[prev][lenght];
        } else{
            double num = 0.0;
            if(prev - 1 >= 0){
                num += tights(prev-1, lenght-1);
            }
            if(prev + 1 <= k){
                num += tights(prev+1, lenght-1);
            }
            num += tights(prev,lenght-1);
            arr[prev][lenght] = num;
            return num;
        }
    }
}

int main() {
    while(scanf("%d %d", &k, &n) != EOF){
        arr.resize(k+1, vector<double>(0));
        for (int i = 0; i <= k; i++){
            arr[i].resize(n+1,double(0));
        }
        tight = 0;
        for (int i = 0; i <= k; ++i) {
            tight += tights(i, n-1);
        }
        printf("%.5f\n", ((double)tight / pow((double)k+1,n))*100.0);
        for(int i = 0; i <= k; i++){
            arr[i].clear();
        }
        arr.clear();
    }
    return 0;
}