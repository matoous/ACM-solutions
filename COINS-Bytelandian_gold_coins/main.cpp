#include <iostream>
#include <stdio.h>
using namespace std;

#include "vector"
vector<long> arr;

long long output(long long d){
    if(d == 0) return 0;
    if(d < 1000000 && arr[d] != 0) return arr[d];
    else{
        long long sum = 0;
        sum += output(d/2);
        sum += output(d/3);
        sum += output(d/4);
        if(sum > d){
            if(d < 1000000) arr[d] = sum;
            return sum;
        } else{
            if(d < 1000000) arr[d] = d;
            return d;
        }
    }
}

int main() {
    arr.resize(1000001,(long)(0));
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    long long d;
    while((scanf("%lld", &d))!= EOF) cout << output(d) << endl;
    return 0;
}
