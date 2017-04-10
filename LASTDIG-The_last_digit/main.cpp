#include <iostream>
#include <stdio.h>
#include "math.h"

using namespace std;

int main() {
    int iterations, a, b, temp;
    scanf("%d", &iterations);
    for(int q = 0; q < iterations; q++){
        scanf("%d %d", &a, &b);
        a = a % 10;
        int out;
        if(!b) cout << "1" << endl;
        else{
            b = !(b % 4) ? 4 : b % 4;
            out = a;
            for(int i = 1; i < b; i++){
                out *= a;
                out = out%10;
            }
            cout << out << endl;
        }
    }
    return 0;
}
