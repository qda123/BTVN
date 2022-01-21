#include<stdio.h>
int main(){
	int n,a[1000];
	printf("Please enter the amount of numbers you want to fill: ");
	scanf("%d",&n);
	printf("Please enter numbers:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Numbers in reversed order:\n");
	for(int i=n-1;i>=0;i--){
		printf("%d ",a[i]);
	}
}
