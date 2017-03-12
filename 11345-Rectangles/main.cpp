#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int main(){
    int iter, num;
    int rx1,rx2,ry1,ry2;
    int x1,x2,y1,y2;
    bool bad;
    scanf("%d", &iter);
    for(int t = 0; t < iter; t++){
        scanf("%d", &num);
        x1 = -100000;
        y1 = -100000;
        x2 = 100000;
        y2 = 100000;
        bad = false;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int n = 1; n < num; n++){
            scanf("%d %d %d %d", &rx1, &ry1, &rx2, &ry2);
            if(rx1 > x1) x1 = rx1;
            if(ry1 > y1) y1 = ry1;
            if(rx2 < x2) x2 = rx2;
            if(ry2 < y2) y2 = ry2;
        }
        if(x1 > x2 || y1 > y2) printf("Case %d: %d\n", t+1, 0);
        else printf("Case %d: %d\n", t+1, (x2 - x1)*(y2 - y1));
    }
    return 0;
}
