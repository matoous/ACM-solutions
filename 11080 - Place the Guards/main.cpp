#include <cstdio>
#include <deque>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

vector< vector<int> > streets;
vector< char > colors;
int T, v, e, a, b, total;

int main(){
    cin >> T;
    while(T-->0){
        cin >> v >> e;
        streets.resize(v, vector<int>(0));
        for(int i = 0; i < e; i++){
            cin >> a >> b;
            streets[a].push_back(b);
            streets[b].push_back(a);
        }
        total = 0;
        colors.resize(v, -1);
        bool bip = true;
        for(int i = 0; i < v && bip; i++){
            if(colors[i] != -1) continue;

            queue<int> Q;
            colors[i] = 1;
            int cnt[2] = {0};
            ++cnt[colors[i]];
            Q.push(i);
            while(!Q.empty() && bip){
                int curr = Q.front(); Q.pop();
                for(int u = 0; u < streets[curr].size(); u++){
                    int neigh = streets[curr][u];
                    if(colors[neigh] == colors[curr]){
                        bip = false;
                        break;
                    }
                    else if(colors[neigh] == -1){
                        colors[neigh] = 1 - colors[curr];
                        ++cnt[colors[neigh]];
                        Q.push(neigh);
                    }
                }
            }

            total += max(1, min(cnt[0],cnt[1]));
        }
        bip ? cout << total << endl : cout << "-1" << endl;
        streets.clear();
        colors.clear();
    }
    return 0;
}