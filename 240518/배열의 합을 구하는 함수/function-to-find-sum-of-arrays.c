#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int **arr = (int**)malloc(sizeof(int*)*(n+1));
    for (int i = 0; i < n+1; i++){
        arr[i] = (int*)malloc(sizeof(int)*(n+1));
        if (i == n) break;
        for (int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int sum = 0;
    int total = 0;
    // 열
    for (int i = 0; i < n; i++){
        sum = 0;
        for (int j = 0; j < n; j++){
            sum += arr[i][j];
        }
        arr[i][n] = sum;
        total += sum;
    }
    arr[n][n] = total;

    // 행
    for (int i = 0; i < n; i++){
        sum = 0;
        for (int j = 0; j < n; j++){
            sum += arr[j][i];
        }
        arr[n][i] = sum;
    }

    // 출력
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < n+1; j++){
            printf("%d", arr[i][j]);
            if (j != n) printf(" ");
        }
        if(i != n) printf("\n");
    }

    free(arr[0]);
    free(arr);


    return 0;
}