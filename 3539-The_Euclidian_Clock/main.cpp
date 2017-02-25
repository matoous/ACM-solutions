#include <math.h>
#include<cstdio>
using namespace std;

# define M_PI           3.14159265358979323846

int main(){
    double a, b, r;
    double h, m, s, u, h2, m2, s2, u2;
    int t;
    scanf("%d", &t);
    for(int x = 0; x < t; x++){
        scanf("%lf %lf %lf %lf", &h, &m, &s, &u);
        scanf("%lf %lf %lf %lf", &h2, &m2, &s2, &u2);
        scanf("%lf", &r);
        h2 -= h; m2 -= m; s2 -= s; u2 -= u;
        if(u2 < 0){
            u2 = 100.0 + u2;
            s2--;
        }
        if(s2 < 0){
            s2 = 60.0 + s2;
            m2--;
        }
        if(m2 < 0){
            m2 = 60.0+m2;
            h2--;
        }
        a = r*r*M_PI;
        b = h2/12.0;
        b += m2/(12.0*60.0);
        b += s2/(12.0*60.0*60.0);
        b += u2/(12.0*60.0*60.0*100.0);
        printf("%d. %.3f\n",x+1, round(b*a*1000)/1000);
    }
    return 0;
}