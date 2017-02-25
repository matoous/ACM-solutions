#include <stdio.h>
#include <iostream>

using namespace std;

bool fits(int l,int c,int r1,int r2){
    int min = (l < c) ? (l) : (c);
    if(2*r1 > min || 2*r2 > min) return false; // circles would owerlap
    int x = l - r1 - r2, y = c - r1 - r2, r = r1 + r2; // circle centers are more distant than sum of their radii
    if (x * x + y * y >= r * r) return true;
    else return false;
}

int main(){
    int l, c, r1, r2;
    while(scanf("%d %d %d %d", &l, &c, &r1, &r2) &&  !(l==0 && c == 0 && r1 == 0 && r2 == 0)){
        if(fits(l,c,r1,r2)){
            cout << "S" << endl;
        } else{
            cout << "N" << endl;
        }
    }
    return 0;
}