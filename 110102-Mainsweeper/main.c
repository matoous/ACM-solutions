#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define CISLO 10000


char **arr;

int main(int argc, char  *argv[]){
    short j, k;
    short num = 0;
    while(scanf("%hi %hi ", &j, &k) && j != 0){
        if(num != 0){
            printf("\n");
        }
        num++;
        arr = (char**)malloc(j*sizeof(char*));
        for(int i = 0; i < j; i++){
            arr[i] = (char*)calloc(k,sizeof(char));
        }
        char c;
        for(int i = 0; i < j; i++){
            for(int u = 0; u <= k; u++){
                c = getchar();
                if(c == '*' && c != '\n'){
                    //PRO OKOLI +1
                    if(i - 1 >= 0 && arr[i - 1][u] != '*'){
                        arr[i - 1][u] += 1;
                    }
                    if(i - 1 >= 0 && arr[i - 1][u-1] != '*' && u - 1 >= 0){
                        arr[i - 1][u - 1] += 1;
                    }
                    if(i - 1 >= 0 && arr[i - 1][u+1] != '*' && u + 1 < k){
                        arr[i - 1][u + 1] += 1;
                    }
                    if(i + 1 < j && arr[i + 1][u] != '*'){
                        arr[i + 1][u] += 1;
                    }
                    if(i + 1 < j && arr[i + 1][u + 1] != '*' && u + 1 < k){
                        arr[i + 1][u + 1] += 1;
                    }
                    if(i + 1 < j && arr[i + 1][u - 1] != '*' && u - 1 >= 0){
                        arr[i + 1][u - 1] += 1;
                    }
                    if(u - 1 >= 0 && arr[i][u - 1] != '*'){
                        arr[i][u - 1] += 1;
                    }
                    if(u + 1 < k && arr[i][u + 1] != '*'){
                        arr[i][u + 1] += 1;
                    }
                    arr[i][u] = c;
                } else if(c != '\n'){
                    arr[i][u] += 48;
                }
            }
        }
        printf("Field #%d:\n", num);
        for(int i = 0; i < j; i++){
            for(int u = 0; u < k; u++){
                printf("%c",arr[i][u]);
            }
            printf("\n");
            free(arr[i]);
        }
        free(arr);
    }

    return 0;
}
