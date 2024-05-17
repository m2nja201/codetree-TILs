#include <stdio.h>

int main() {
    int x, y;
    char a;
    int result;

    scanf("%d %c %d", &x, &a, &y);
    if (a == '+'){
        result = x + y;
    } else if (a == '-'){
        result = x - y;
    } else if (a == '*'){
        result = x * y;
    } else if (a == '/'){
        result = x / y;
    }

    printf("%d %c %d = %d", x, a, y, result);

    return 0;
}