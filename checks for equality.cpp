#include<stdio.h>
int arr1[1000],arr2[1000];
int size1,size2,count;
void check(int arr1[],int arr2[]){
	if(size1!=size2){
		printf("0");
	}
	else{
		for(int i=0;i<size1;i++){
			if(arr1[i]!=arr2[i]){
				count=1;
				break;
			}
		}
		if(count==1){
			printf("0");
		}
		else{
			printf("1");
		}
	}
}
int main(){
	int array1[1000],array2[1000];
	printf("Please enter the size of the first array: ");
	scanf("%d",&size1);
	printf("Please enter the list of the first array: ");
	for(int i=0;i<size1;i++){
		scanf("%d",&array1[i]);
	}
	printf("Please enter the size of the second array: ");
	scanf("%d",&size2);
	printf("Please enter the list of the second array: ");
	for(int i=0;i<size2;i++){
		scanf("%d",&array2[i]);
	}
	check(array1,array2);
}
