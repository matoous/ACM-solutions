#include <cstdio>
#include <deque>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

vector< vector<int> > bugs;
vector< char > colors;
int T, v, e, a, b, total;

int main(){
    cin >> T;
    for(int q = 0; q < T; q++){
        cin >> v >> e;
        bugs.resize(v, vector<int>(0));
        for(int i = 0; i < e; i++){
            cin >> a >> b;
            a--;
            b--;
            bugs[a].push_back(b);
            bugs[b].push_back(a);
        }
        total = 0;
        colors.resize(v, -1);
        bool bip = true;
        for(int i = 0; i < v && bip; i++){
            if(colors[i] != -1) continue;
            queue<int> Q;
            colors[i] = 1;
            Q.push(i);
            while(!Q.empty() && bip){
                int curr = Q.front(); Q.pop();
                for(int u = 0; u < bugs[curr].size(); u++){
                    int neigh = bugs[curr][u];
                    if(colors[neigh] == colors[curr]){
                        bip = false;
                        break;
                    }
                    else if(colors[neigh] == -1){
                        colors[neigh] = 1 - colors[curr];
                        Q.push(neigh);
                    }
                }
            }
        }
        cout << "Scenario #" << q+1 << ":" << endl;
        bip ? cout << "No suspicious bugs found!" << endl : cout << "Suspicious bugs found!" << endl;
        bugs.clear();
        colors.clear();
    }
    return 0;
}