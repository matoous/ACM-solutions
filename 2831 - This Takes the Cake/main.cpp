#include <iostream>
#include <vector>
#include <math.h>

#define pff pair<double, double>

using namespace std;

pff a,b,c,d;
double ta, now, pl;

double side(pff x, pff y){
    pff vec = pff(y.first - x.first, y.second - x.second);
    return sqrt(vec.first*vec.first + vec.second*vec.second);
}

pff mid(pff x, pff y)
    return pff((x.first+y.first)/2, (x.second+y.second)/2);

double area(pff x, pff y, pff z){
    double one = side(x, y);
    double two = side(y, z);
    double three = side(z, x);
    double temp = (one + two + three)/2;
    return sqrt(temp*(temp-one)*(temp-two)*(temp-three));
}

double absolute(double x)
    return (x < 0) ? -x : x;

double smaller(double x, double y)
    return (x < y) ? x : y;

double bigger(double x, double y)
    return x > y ? x : y;

int main(){
    int cake = 1;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
                &a.first, &a.second,
                &b.first, &b.second,
                &c.first, &c.second,
                &d.first, &d.second)
          && a != b)
    {
        ta = area(a,b,c) + area(c,d,a);
        vector<pff> points = vector<pff>();
        points.push_back(a);
        points.push_back(mid(a,b));
        points.push_back(b);
        points.push_back(mid(b,c));
        points.push_back(c);
        points.push_back(mid(c,d));
        points.push_back(d);
        points.push_back(mid(d,a));
        double p1, best_diff = 10000000000;
        for(int i = 0; i < points.size()-2; i++){
            now = 0;
            for(int u = i + (i % 2 == 0 ? 3 : 2); u < points.size(); u++){
                now += area(points[i], points[u-1], points[u]);
                pl = ta - now;
                if(absolute(pl - now) < best_diff){
                    best_diff = absolute(pl - now);
                    p1 = now;
                }
            }
        }
        printf("Cake %d: %.3f %.3f\n", cake++, smaller(p1, ta-p1), bigger(p1, ta-p1));
    }
    return 0;
}
