#include <stdio.h>
#include <stdlib.h> 
#include<conio.h>
int main(){
	int *arr;
	int n;
	int sum=0;
   	printf("Input: ");
   	scanf("%d",&n);
   	arr = (int *)malloc(n*sizeof(int)); 
   	for(int i=0;i<n;i++){
   		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
   	FILE *fptr;
 	fptr = fopen("output.txt", "w");
	for(int i=n-1;i>=0;i--){
		fprintf(fptr,"%d ", arr[i]);
	}
	fprintf(fptr,"%d",sum);
   	fclose(fptr);
 	free(arr);
   	return 0;
}
