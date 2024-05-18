#include <stdio.h>
#include <stdlib.h>

int n, m;

int in_range(int x, int y){
    if ((x >= 0 && x < n) && (y >= 0 && y < m)) return 1;
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);

    // 동적할당
    int **arr = (int **)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++){
        arr[i] = (int *)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++){
            arr[i][j] = 0;
        }
    }

    // rotate
    int x = 0, y = 0;
    int nx, ny;
    arr[x][y] = 1;

    int direct[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // 우하좌상
    int dir_num = 0;

    for (int cnt = 2; cnt <= n * m; cnt++){
        nx = x + direct[dir_num][0];
        ny = y + direct[dir_num][1];
        
        if (in_range(nx, ny) && arr[nx][ny] == 0) {
        } else {
            //printf("rotate\n");
            dir_num = (dir_num + 1) % 4;
        }

        x = x + direct[dir_num][0];
        y = y + direct[dir_num][1];
        //printf("x : %d, y : %d, cnt : %d\n",x,y,cnt);
        arr[x][y] = cnt; 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}