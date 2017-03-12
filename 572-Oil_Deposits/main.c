#include <stdio.h>
#include <stdlib.h>

char **map;
int m,n,pockets;

void find(int x, int y){
    map[x][y] = '*';
    if(x + 1 < m && map[x+1][y] == '@') find(x+1,y);
    if(x + 1 < m && y + 1 < n && map[x+1][y+1] == '@') find(x+1,y+1);
    if(y+1<n && map[x][y+1] == '@') find(x,y+1);
    if(x + 1 < m && y - 1 >= 0 && map[x+1][y-1] == '@') find(x+1,y-1);
    if(x - 1 >= 0 && y+1 < n && map[x-1][y+1] == '@') find(x-1,y+1);
    if(x - 1 >= 0 && map[x-1][y] == '@') find(x-1,y);
    if(x -1 >= 0 && y - 1 >= 0 && map[x-1][y-1] == '@') find(x-1,y-1);
    if(y -1 >= 0 && map[x][y-1] == '@') find(x,y-1);
}

int main(void){
    scanf("%d %d ", &m, &n);
    while(m != 0){
        map = (char**)malloc(m*sizeof(char*));
        for(int i = 0; i < m; i++){
            map[i]=(char*)calloc(n,sizeof(char));
        }
        for(int i = 0; i < m; i++){
            for(int u = 0; u < n; u++){
                scanf("%c ", &map[i][u]);
            }
        }
        pockets = 0;
        for(int i = 0; i < m; i++){
            for(int u = 0; u < n; u++){
                if(map[i][u] == '@'){
                    pockets++;
                    find(i,u);
                }
            }
        }
        printf("%d\n",pockets);
        scanf("%d %d ", &m, &n);
    }
    return 0;
}
