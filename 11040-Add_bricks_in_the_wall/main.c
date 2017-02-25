#include <stdio.h>
#include <stdlib.h>

int main(int argc, char  *argv[]){
    int k;
    int *arr;
    int *result;
    //TEST CASES
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        //ALLOC
        arr = (int*)calloc(15,sizeof(int));
        result = (int*)calloc(45,sizeof(int));
        //IN
        for(int i = 0; i < 15; i++){
            scanf("%d ", &arr[i]);
        }
        //OUT
        printf("%d\n", arr[0]);
        printf("%d %d\n", (arr[0] - arr[1] - arr[2])/2 + arr[1], (arr[0] - arr[1] - arr[2])/2 + arr[2]);
        printf("%d %d %d\n", arr[1], (arr[0] - arr[1] - arr[2])/2, arr[2]);
        printf("%d %d %d %d\n", (arr[1] - arr[3] - arr[4])/2 + arr[3], (arr[1] - arr[3] - arr[4])/2 + arr[4], (arr[2] - arr[4] - arr[5])/2 + arr[4], (arr[2] - arr[4] - arr[5])/2 + arr[5]);
        printf("%d %d %d %d %d\n", arr[3], (arr[1] - arr[3] - arr[4])/2, arr[4], (arr[2] - arr[4] - arr[5])/2, arr[5]);
        printf("%d %d %d %d %d %d\n", (arr[3] - arr[6] - arr[7])/2 + arr[6], (arr[3] - arr[6] - arr[7])/2 + arr[7], (arr[4] - arr[7] - arr[8])/2 + arr[7], (arr[4] - arr[7] - arr[8])/2 + arr[8], (arr[5] - arr[8] - arr[9])/2 + arr[8], (arr[5] - arr[8] - arr[9])/2 + arr[9]);
        printf("%d %d %d %d %d %d %d\n", arr[6], (arr[3] - arr[6] - arr[7])/2, arr[7], (arr[4] - arr[7] - arr[8])/2, arr[8], (arr[5] - arr[8] - arr[9])/2, arr[9]);
        printf("%d %d %d %d %d %d %d %d\n", (arr[6] - arr[10] - arr[11])/2 + arr[10], (arr[6] - arr[10] - arr[11])/2 + arr[11], (arr[7] - arr[11] - arr[12])/2 + arr[11],(arr[7] - arr[11] - arr[12])/2 + arr[12], (arr[8] - arr[12] - arr[13])/2 + arr[12], (arr[8] - arr[12] - arr[13])/2 + arr[13], (arr[9] - arr[13] - arr[14])/2 + arr[13], (arr[9] - arr[13] - arr[14])/2 + arr[14]);
        printf("%d %d %d %d %d %d %d %d %d\n", arr[10], (arr[6] - arr[10] - arr[11])/2, arr[11], (arr[7] - arr[11] - arr[12])/2, arr[12], (arr[8] - arr[12] - arr[13])/2, arr[13], (arr[9] - arr[13] - arr[14])/2 , arr[14]);
        //FREE
        free(arr);
        free(result);
    }
    return 0;
}