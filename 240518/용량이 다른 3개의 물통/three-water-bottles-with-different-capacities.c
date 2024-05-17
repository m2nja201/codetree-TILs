#include <stdio.h>

int pump[3][2] = {0};

void n2y(int rem){
    int source = rem - 1;
    int target = rem;
    if (rem == 3){
        source = 2;
        target = 0;    
    }
    int possible = pump[target][0] - pump[target][1]; // target에 더 넣을 수 있는 용량
    if (pump[source][1] <= possible){ // source에 있는 걸 모두 넣을 수 있을 때
        pump[target][1] += pump[source][1];
        pump[source][1] = 0;
    } else {
        pump[target][1] = pump[target][0];
        pump[source][1] -= possible;
    }
}

int main() {
    
    // 입력
    for (int i = 0; i < 3; i++){
        scanf("%d %d", &pump[i][0], &pump[i][1]); // 용량, 내용물
    }

    // 물통 옮기기
    for (int i = 0; i < 100; i++){
        n2y(i % 3 + 1);
    }

    // 출력
    for (int i = 0; i < 3; i++){
        printf("%d\n", pump[i][1]);
    }
    return 0;
}