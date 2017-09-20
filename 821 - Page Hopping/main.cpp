#include <iostream>
#include <vector>

#define max(a,b) (a > b ? a : b)

using namespace std;

int main() {
    int a,b,cs=1;
    while(true){
        int m = 0;
        vector<vector<int>> matrix(101, vector<int>(101, 9999));
        while(scanf("%d %d", &a, &b) != 0 && !(a==0 && b==0)){
            matrix[--a][--b] = 1;
            m = max(m, max(a,b));
        }
        if (m == 0){
            break;
        }
        for(int k = 0; k <= m; k++){
            for(int i = 0; i <= m; i++){
                for(int j = 0; j <= m; j++){
                    if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
        int cnt = 0, total = 0;
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= m; j++){
                if(i != j && matrix[i][j]!=9999){
                    total += matrix[i][j];
                    cnt++;
                }
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n",cs++, (double)total/cnt);
    }
    return 0;
}