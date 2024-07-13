#include <stdio.h>
#include <stdlib.h>

int count = 0;
int x[10];  // Increased size to accommodate larger n values

void n_queen(int, int);
int place(int, int);

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    n_queen(1, n);
    if (count == 0)
        printf("No solutions found.\n");
    else
        printf("Number of solutions found: %d\n", count);
    return 0;
}

int place(int k, int i) {
    for (int j = 1; j < k; j++)
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    return 1;
}

void n_queen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                count++;
                printf("Solution %d:\n", count);
                for (int j = 1; j <= n; j++) {
                    for (int p = 1; p <= n; p++)
                        printf(x[j] == p ? "$\t" : "0\t");
                    printf("\n");
                }
                printf("\n");
            } else {
                n_queen(k + 1, n);
            }
        }
    }
}
