#include<stdio.h>
int main(){
	int arr[1000];
	int n,pos1,pos2;
	int sum,max=-999999999;
	printf("Please enter a real number: ");
	scanf("%d",&n);
	printf("Please enter the array: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			if(sum>max){
				max=sum;
				pos1=i;
				pos2=j;
			}
		}
	}
	printf("The max value of substring: %d",max);
}
