#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    short size;
    int number;
    short arr[10];
    short arr_count;
    scanf("%d ", &size);
    while(size != 0){
        char c = getchar();
        arr_count = 0;
        while(c != '\n'){
            switch(c){
                case '0':
                    arr[arr_count++] = 0;
                    break;
                case '1':
                    arr[arr_count++] = 1;
                    break;
                case '2':
                    arr[arr_count++] = 2;
                    break;
                case '3':
                    arr[arr_count++] = 3;
                    break;
                case '4':
                    arr[arr_count++] = 4;
                    break;
                case '5':
                    arr[arr_count++] = 5;
                    break;
                case '6':
                    arr[arr_count++] = 6;
                    break;
                case '7':
                    arr[arr_count++] = 7;
                    break;
                case '8':
                    arr[arr_count++] = 8;
                    break;
                case '9':
                    arr[arr_count++] = 9;
                    break;
            }
            c = getchar();
        }
        // TOP
        for(int a = 0; a < arr_count; a++){
            switch(arr[a]){
                case 0:
                case 2:
                case 3:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                    printf(" ");
                    for(int i = 0; i < size; i++){
                        printf("-");
                    }
                    printf(" ");
                    break;
                case 1:
                case 4:
                    for(int i = 0; i < size + 2; i++){
                        printf(" ");
                    }
                    break;
            }
            if(a != arr_count -1){
                printf(" ");
            }
        }
        printf("\n");
        // TOP MID
        for(int i = 0; i < size; i++){ // ROWS
            for(int a = 0; a < arr_count; a++){ // NUMS
                    switch(arr[a]){
                    case 0:
                    case 4:
                    case 8:
                    case 9:
                        for(int u = 0; u < size + 2; u++){
                            if(u == 0 || u == size + 1){
                                printf("|");
                            } else{
                                printf(" ");
                            }
                        }
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 7:
                        for(int u = 0; u < size + 2; u++){
                            if(u == size + 1){
                                printf("|");
                            } else{
                                printf(" ");
                            }
                        }
                        break;
                    case 5:
                    case 6:
                        for(int u = 0; u < size + 2; u++){
                            if(u == 0){
                                printf("|");
                            } else{
                                printf(" ");
                            }
                        }
                        break;
                }
                if(a != arr_count -1){
                    printf(" ");
                }
            }
            printf("\n");
        }
        // MIDLLE
        for(int a = 0; a < arr_count; a++){
            switch(arr[a]){
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 8:
                case 9:
                    printf(" ");
                    for(int i = 0; i < size; i++){
                        printf("-");
                    }
                    printf(" ");
                    break;
                case 1:
                case 0:
                case 7:
                    for(int i = 0; i < size + 2; i++){
                        printf(" ");
                    }
                    break;
            }
            if(a != arr_count -1){
                printf(" ");
            }
        }
        printf("\n");
        // BOTTOM MID
        for(int i = 0; i < size; i++){
            for(int a = 0; a < arr_count; a++){
                for(int u = 0; u < size + 2; u++){
                    switch(arr[a]){
                        case 0:
                        case 6:
                        case 8:
                            if(u == 0 || u == size + 1){
                                printf("|");
                            } else{
                                printf(" ");
                            }
                            break;
                        case 2:
                            if(u == 0){
                                printf("|");
                            } else{
                                printf(" ");
                            }
                            break;
                        case 1:
                        case 3:
                        case 4:
                        case 5:
                        case 7:
                        case 9:
                            if(u == size + 1){
                                printf("|");
                            } else{
                                printf(" ");
                            }
                            break;
                    }
                }
                if(a != arr_count -1){
                    printf(" ");
                }
            }
            printf("\n");
        }
        // BOTTOM
        for(int a = 0; a < arr_count; a++){
            switch(arr[a]){
                case 0: case 2: case 3: case 5: case 6: case 8: case 9:
                    printf(" ");
                    for(int i = 0; i < size; i++){
                        printf("-");
                    }
                    printf(" ");
                break;
                case 4: case 7: case 1:
                    for(int i = 0; i < size + 2; i++){
                        printf(" ");
                    }
                break;

            }
            if(a != arr_count -1){
                printf(" ");
            }
        }
        printf("\n\n");

        scanf("%d", &size);
        arr_count = 0;
    }
    return 0;
}