#include<cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N;
vector<vector<int> > edges;

int distance(int start){
    queue<int> q;
    vector<bool> fresh(N, true);
    vector<int> dist(N, N+1);
    int max_dist = 0;
    q.push( start );
    fresh[start] = false;
    dist[start] = 0;
    int currn, neigh;
    while( !q.empty() ){
        currn = q.front(); q.pop();
        for( int j = 0; j < edges[currn].size(); j++ ){
            neigh = edges[currn][j];
            dist[neigh] = min(dist[neigh], 1+dist[currn]);
            if(dist[neigh] > max_dist) max_dist = dist[neigh];
            if( fresh[neigh] ){
                q.push( neigh );
                fresh[neigh] = false;
            }
        }
    }
    return max_dist;
}

int fNode(int start){
    queue<int> q;
    vector<bool> fresh(N, true);
    vector<int> dist(N, N+1);
    q.push( start );
    fresh[start] = false;
    dist[start] = 0;
    int currn, neigh;
    while( !q.empty() ){
        currn = q.front(); q.pop();
        for( int j = 0; j < edges[currn].size(); j++ ){
            neigh = edges[currn][j];
            dist[neigh] = min(dist[neigh], 1+dist[currn]);
            if( fresh[neigh] ){
                q.push( neigh );
                fresh[neigh] = false;
            }
        }
    }
    int maxdist = 0, maxdistnode = start;
    for( int i = 0; i < N; i++ )
        if( dist[i] > maxdist )
        { maxdist = dist[i]; maxdistnode = i;}
    return maxdistnode;
}

int main(){
    int n1, n2;
    scanf("%d", &N);
    edges.resize(N,vector<int>(0));
    while(scanf("%d %d", &n1, &n2) ==  2){
        n1--;
        n2--;
        edges[n1].push_back(n2);
        edges[n2].push_back(n1);
    }
    int most_dist = fNode(0);
    int dist = distance(most_dist);
    printf("%d", dist);
    return 0;
}