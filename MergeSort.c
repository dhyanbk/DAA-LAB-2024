#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10000

void merge(int array[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int resarray[MAX];
    
    while (i <= mid && j <= high) {
        if (array[i] < array[j]) {
            resarray[k++] = array[i++];
        } else {
            resarray[k++] = array[j++];
        }
    }
    
    while (i <= mid) {
        resarray[k++] = array[i++];
    }
    
    while (j <= high) {
        resarray[k++] = array[j++];
    }
    
    for (int m = low; m <= high; m++) {
        array[m] = resarray[m];
    }
}

void sort(int array[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        sort(array, low, mid);
        sort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

int main() {
    int array[MAX];
    int i;
    printf("Enter the array size: ");
    int n;
    scanf("%d", &n);
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        array[i] = rand() % 10000;
    }
    printf("Array before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    clock_t start = clock();
    sort(array, 0, n - 1);
    clock_t end = clock();
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("Time taken to sort array is %lf milliseconds\n", elapsedTime);
    return 0;
}

