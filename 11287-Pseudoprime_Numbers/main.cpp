#include <iostream>
#include <stdio.h>
using namespace std;

unsigned long long expoMod(unsigned long long a, unsigned long long b, unsigned long long m){
    unsigned long long result = 1;
    while (b){
        if (b&1)
            result = (a * result) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return result;
}

bool isPrime(unsigned long long x){
    if (!x % 2) return false;
    for(int i = 3; i*i <= x; i+=2)
        if(!x % i) return false;
    return true;
}

int main() {
    unsigned long long p, a;
    while(scanf("%llu %llu", &p, &a) == 2 && !(p == 0 && a == 0)
        isPrime(p) || expoMod(a, p, p) != a ? printf("no\n") : printf("yes\n");
    return 0;
}
