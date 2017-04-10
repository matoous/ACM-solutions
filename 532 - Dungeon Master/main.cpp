#include <cstdio>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

typedef struct{
    int x, y, z;
} coors;

int L,R,C;
int dx[]={0,0,0,0,1,-1};
int dy[]={1,-1,0,0,0,0};
int dz[]={0,0,1,-1,0,0};
char M[50][50][50];
int dist[50][50][50];

coors conscoors(int x, int y, int z){
    coors a;
    a.x = x;
    a.y = y;
    a.z = z;
    return a;
}

bool isOnPlan(coors a)
    return (a.x >= L || a.x < 0 || a.y >= R || a.y < 0 || a.z >= C || a.z < 0) ? false : true;

int dfs(coors S){
    queue<coors> Q;
    for(int i = 0; i < L; i++){
        for(int u = 0; u < R; u++){
            for(int l = 0; l < C; l++){
                dist[i][u][l] = 100000;
            }
        }
    }
    dist[S.x][S.y][S.z] = 0;
    Q.push(S);
    coors currn, neigh;
    while(!Q.empty()){
        currn = Q.front(); Q.pop();
        for(int i = 0; i < 6; i++){
            neigh = conscoors(currn.x + dx[i], currn.y + dy[i], currn.z + dz[i]);
            if(isOnPlan(neigh) && M[neigh.x][neigh.y][neigh.z] != '#'){
                bool wp = (dist[neigh.x][neigh.y][neigh.z] == 100000) ? true : false;
                dist[neigh.x][neigh.y][neigh.z] = min(dist[neigh.x][neigh.y][neigh.z], dist[currn.x][currn.y][currn.z] + 1);
                if(M[neigh.x][neigh.y][neigh.z] == 'E') return dist[neigh.x][neigh.y][neigh.z];
                if(wp) Q.push(neigh);
            }
        }
    }
    return -1;
}

int main(){
    coors S;
    while(scanf("%d %d %d", &L, &R, &C) == 3 && L != 0){
        for(int i = 0; i < L; i++){
            for(int u = 0; u < R; u++){
                for(int l = 0; l < C; l++){
                    cin >> M[i][u][l];
                    if(M[i][u][l] == 'S') S = conscoors(i,u,l);
                }
            }
        }
        (dfs(S) == -1) ? printf("Trapped!\n") : printf("Escaped in %d minute(s).\n", d);
    }
    return 0;
}
