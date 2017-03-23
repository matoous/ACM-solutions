#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    long b, e, m;
} w;

int n;
vector<w> weds;

bool cmp(w U, w D){
    return U.b + U.m < D.b + D.m;
}

int main() {
    while(cin >> n && n != 0){
        weds.resize(n);
        for(int i = 0; i < n; i++){
            cin >> weds[i].b >> weds[i].e;
            weds[i].m = (weds[i].e - weds[i].b) / 2 + 1;
        }
        sort(weds.begin(), weds.end(), cmp);
        long long time = weds[0].b;
        bool cool = true;
        for(int i = 0; i < n; i++){
            if(time < weds[i].b) time = weds[i].b;
            time += weds[i].m;
            if(time > weds[i].e){
                cool = false;
                break;
            }
        }
        if(cool) cout << "YES" << endl;
        else cout << "NO" << endl;
        weds.clear();
    }
    return 0;
}