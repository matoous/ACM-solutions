#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

vector<pipii> edges;
vector<int> parents;

int find(int x)
{
    if(x != parents[x])
        parents[x] = find(parents[x]);
    return parents[x];
}

int Kruskal(int m){
    int total = 0;
    int a,b;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < m; i++){
        a = find(edges[i].second.first);
        b = find(edges[i].second.second);
        if(a != b){
            total += edges[i].first;
            parents[a] = parents[b];
        }
    }
    return total;
}

int main() {
    int m,n,n1,n2,c,total;
    while(scanf("%d %d", &n, &m)&&!(m == 0 && n == 0)){
        edges.clear();
        parents.resize(n+1);
        for(int i = 0; i < n; i++) parents[i] = i;
        total = 0;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &n1, &n2, &c);
            total += c;
            edges.push_back(pipii(c,pii(n1,n2)));
        }
        printf("%d\n", (total - Kruskal(m)));
    }
    return 0;
}