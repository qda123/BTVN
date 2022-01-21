#include<stdio.h>
#include<time.h>
void insertionSort(int arr[], int n){
   	int i,next,j;
   	for (i = 1; i < n; i++){
       	next = arr[i];
		for (j=i-1;j>=0 && arr[j] > next;j--){
           	arr[j+1] = arr[j];
       	}
       	arr[j+1] = next;
   	}
}

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
 
int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot){
        	left++;
		} 
        while(right >= left && arr[right] > pivot){
        	right--;
		} 
        if (left >= right){
        	break;
		} 
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 
void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr,low,pi - 1);
        quickSort(arr,pi + 1,high);
    }
}

int main(){
	int n;
	int array1[10000],array2[10000];
	clock_t start1,end1,start2,end2;
	double time_use1,time_use2;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter the array: ");
	for(int i=0;i<n;i++){
		scanf("%d",&array1[i]);
		array2[i]=array1[i];
	}
	start1 = clock();
	insertionSort(array1,n);
	printf("The array after using insertionsort: ");
	for(int i=0;i<n;i++){
		printf("%d ",array1[i]);
	}
	printf("\n");
	end1 = clock();
	time_use1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	printf("The execution time of insertion sort: %lf ",time_use1);
	printf("\n");
	start2 = clock();
	quickSort(array2,0,n-1);
	printf("The array after using quicksort: ");
	for(int i=0;i<n;i++){
		printf("%d ",array2[i]);
	}
	printf("\n");
	end2 = clock();
	time_use2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
	printf("The execution time of quick sort: %lf ",time_use2);
}
