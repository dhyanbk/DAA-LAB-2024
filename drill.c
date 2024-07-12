#include <stdio.h>

int a[10][10], visited[10], n, cost = 0;

int least(int c) {
    int i, nc = 999, min = 999, kmin;
    for (i = 1; i <= n; i++) {
        if ((a[c][i] != 0) && (visited[i] == 0)) {
            if (a[c][i] < min) {
                min = a[i][1] + a[c][1];
                kmin = a[c][i];
                nc = i;
            }
        }
    }
    if (min != 999)
        cost += kmin;
    return nc;
}

void mincost(int city) {
    visited[city] = 1;
    printf("%d-->", city);
    int ncity = least(city);
    if (ncity == 999) {
        ncity = 1;
        printf("%d", ncity);
        cost += a[city][ncity];
        return;
    }
    mincost(ncity);
}

int main() {
    int i, j;
    printf("Enter No. of cities:\n");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        printf("Enter elements of row %d:\n", i);
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0;
    }
    printf("The cost list is:\n");
    for (i = 1; i <= n; i++) {
        printf("\n");
        for (j = 1; j <= n; j++) {
            printf("%d\t", a[i][j]);
        }
    }
    printf("\nThe path is:\n");
    mincost(1);
    printf("\nMinimum cost: %d\n", cost);
    return 0;
}
