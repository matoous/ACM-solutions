#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n, cc;
float x, y;
vector<pair<float, float>> coordinates;
vector<vector<int>> graph;
vector<int> colors;

bool inRange(pair<float, float> a, pair<float, float> b){
    pair<float, float> x(b.first-a.first, b.second-a.second);
    return x.first*x.first + x.second*x.second <= 400;
}

bool one_color(){
    for(int i = 0; i < n;i++) if(graph[i].size() != 0) return false;
    return true;
}

bool color(int x){
    for(int i = 0; i <= cc; i++){
        colors[x] = i;
        bool bad = false;
        for(int u = 0; u < graph[x].size() && !bad; u++){
            if(colors[graph[x][u]] == i) bad = true;
            else if(colors[graph[x][u]] == -1){
                if(!color(graph[x][u])) bad = true;
            }
        }
        if(!bad) return true;
    }
    return false;
}

int min_coloring(){
    if(one_color())
        return 1;
    colors.clear();
    colors.resize(n, -1);
    bool bip = true;
    for(int i = 0; i < n && bip; i++){
        if(colors[i] != -1) continue;
        queue<int> Q;
        colors[i] = 1;
        Q.push(i);
        while(!Q.empty() && bip){
            int curr = Q.front(); Q.pop();
            for(int u = 0; u < graph[curr].size(); u++){
                int neigh = graph[curr][u];
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
    if(bip)
        return 2;
    colors.clear();
    colors.resize(n, -1);
    colors[0] = 0;
    cc = 2;
    bool isok = true;
    for(int i = 1; i < n; i++){
        if(colors[i] == -1)
            //cout << "coaaaloring " << i << endl;
            isok = color(1);
            if(!isok){
                break;
            }
    }
    if(isok) return 3;
    else cc++;
    colors.clear();
    colors.resize(n, -1);
    colors[0] = 0;
    isok = true;
    for(int i = 1; i < n; i++){
        if(colors[i] == -1)
            isok = color(1);
        if(!isok) break;
    }
    if(isok) return 4;
    else return 5;
}

int main(){
    int c = 1;
    while(scanf("%d", &n) && n != 0){
        graph.resize(n, vector<int>(0));
        // read
        for(int i = 0; i < n; i++){
            scanf("%f %f", &x, &y);
            coordinates.push_back(pair<float, float>(x,y));
        }
        // build graph
        for(int i = 0; i < n; i++){
            for(int u = 0; u < n; u++){
                if(i != u && inRange(coordinates[i], coordinates[u])) graph[i].push_back(u);
            }
        }
        printf("The towers in case %d can be covered in %d frequencies.\n", c++, min_coloring());
        graph.clear();
        coordinates.clear();
    }
    return 0;
}
