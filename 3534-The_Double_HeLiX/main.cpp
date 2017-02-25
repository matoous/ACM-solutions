#include <math.h>
#include<cstdio>
#include <vector>
#include <queue>
using namespace std;
queue<int> v1;
queue<int> v2;

int main(){
    int t1, t2, n;
    long s1, s2, s;
    while(scanf("%d", &t1) && t1 != 0){
        for(int i = 0; i < t1; i++){
            scanf("%d", &n);
            v1.push(n);
        }
        scanf("%d", &t2);
        for(int i = 0; i < t2; i++){
            scanf("%d", &n);
            v2.push(n);
        }
        s = s1 = s2 = 0;
        while(!v1.empty() && !v2.empty()){
            if(v1.front() < v2.front()) {
                s1 += v1.front();
                v1.pop();
            } else if(v2.front() < v1.front()){
                s2 += v2.front();
                v2.pop();
            } else if(v1.front() == v2.front()){
                s += max(s1, s2) + v1.front();
                v1.pop();
                v2.pop();
                s1 = s2 = 0;
            }
        }
        while(!v1.empty()){
            s1 += v1.front(); v1.pop();
        }
        while(!v2.empty()){
            s2 += v2.front(); v2.pop();
        }
        s += max(s1, s2);
        printf("%ld\n", s);
    }
    return 0;
}