#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int> > dominoes;
vector<bool> fresh;

void kick(int x){
    fresh[x] = false;
    for(int i = 0; i < dominoes[x].size(); i++) if(fresh[dominoes[x][i]]) kick(dominoes[x][i]);
}

int main(){
    int t, m, n, l, x, y;
    cin >> t;
    while(t-->0){ // love this
        cin >> n >> m >> l;
        dominoes.resize(n,vector<int>(0));
        fresh.resize(n, true);
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            dominoes[x-1].push_back(y-1);
        }
        for(int i = 0; i < l; i++){
            cin >> x;
            kick(x-1);
        }
        int out = 0;
        for(int i = 0; i < n; i++){
            if(!fresh[i]) out++;
        }
        cout << out  << endl;
        fresh.clear();
        dominoes.clear();
    }
    return 0;
}
