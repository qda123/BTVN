#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *num1, int *num2) {
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int randomElementInArray(int a, int b){
   return a + rand() % (b - a + 1);
}


void interchangeSort(int *arr, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if(arr[j] > arr[i]){
                swap(&arr[j], &arr[i]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    
    clock_t start, end;
    double duration;
    
    int n = 99;
    // init data
    int *arr = (int*)malloc(n);
    for (int i = 0; i < n; i++) {
        arr[i] = randomElementInArray(0, n);
    }
    
    start = clock();
    interchangeSort(arr, n);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("interchangeSort take %f seconds", duration);
    
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    
    return 0;
}
