#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define pff pair<float, float>

std::vector< pii > ct;

double dist(pff a, pff b){
    pff vec = pff(a.first - b.first, a.second - b.second);
    return sqrt((double)(vec.first*vec.first) + (vec.second*vec.second));
}

int main(){
    int iter, nodes;
    float x, y, h;
    double total;
    scanf("%d", &iter);
    for(int t = 0; t < iter; t++){
        h = 0;
        total = 0;
        scanf("%d", &nodes);
        ct.resize(nodes);
        for(int i = 0; i < nodes; ++i){
            scanf("%f %f", &x, &y);
            ct[i] = pff(x,y);
        }
        std::sort(ct.begin(),ct.end());
        reverse(ct.begin(),ct.end());
        for(int i = 0; i < ct.size()-1; ++i){
            if(ct[i+1].second > h){
                total += dist(ct[i], ct[i+1])* (ct[i+1].second - h) / (ct[i+1].second - ct[i].second);
                h = ct[i+1].second;
            }
        }
        printf("%.2f\n", total);
        ct.clear();
    }
    return 0;
}