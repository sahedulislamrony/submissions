// https://codeforces.com/problemset/problem/747/A
// December 16,2023
#include <stdio.h>

int main() {
    int n,a,b;
    scanf("%d", &n);
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            a = i;
            b = n / i;
        }
    }

    printf("%d %d\n", a, b);

    return 0;
    
}