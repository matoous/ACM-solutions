#include <stdio.h>
#include <stdlib.h>

int **arr;
int *arr_count;
int *visited;

short BFS(int x){
    visited[x] = 1;
    short visits = 0;
    for(int i = 0; i < arr_count[x]; i++){
        if(visited[arr[x][i]] == 1) visits++;
        if(visits == 2) return 0;
        if(visited[arr[x][i]] == 0) if(!BFS(arr[x][i])) return 0;
    }
    return 1;
}

int main(int argc, char  *argv[]){
    int n, m;
    scanf("%d %d", &n, &m);
    if(n != m + 1){
        printf("NO\n");
        return 0;
    }
    arr = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++){
        arr[i] = (int*)calloc(n,sizeof(int));
    }
    arr_count =(int*)calloc(n,sizeof(int));
    visited =(int*)calloc(n,sizeof(int));
    for(int i = 0; i < m; i++){
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        n1--;
        n2--;
        arr[n1][arr_count[n1]++] = n2;
        arr[n2][arr_count[n2]++] = n1;
    }
    short is_it = BFS(0);
    for(int i = 0; i < n; i++){
        if(visited[i] != 1){
            is_it = 0;
        }
    }
    printf(is_it ? "YES\n" : "NO\n");
    free(arr_count);
    free(visited);
    for(int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}
