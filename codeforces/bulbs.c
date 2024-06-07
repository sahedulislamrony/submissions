// https://codeforces.com/problemset/problem/615/A
// December 16,2023

#include <stdio.h>
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
 
    int bulbs[m + 1];  // To keep track of which bulbs are turned on
    for (int i = 1; i <= m; i++) {
        bulbs[i] = 0;  // Initially, all bulbs are turned off
    }
 
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
 
        for (int j = 0; j < x; j++) {
            int y;
            scanf("%d", &y);
            bulbs[y] = 1;  // Mark the bulb as turned on
        }
    }
 
    // Check if all bulbs are turned on
    int allBulbsOn = 1;
    for (int i = 1; i <= m; i++) {
        if (bulbs[i] == 0) {
            allBulbsOn = 0;
            break;
        }
    }
 
    if (allBulbsOn) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
 
    return 0;
    
}