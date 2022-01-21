#include<stdio.h>
int main(){
	int a[10100],b,n,m,k;
	printf("Nhap vao so phan tu cua day la: ");
	scanf("%d",&k);
	printf("\n");
	for(int i=1;i<=k;i++){
		printf("Phan tu thu %d cua day la: ",i);
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			if(a[i]>a[j]){
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	printf("Nhap vao so n: ");
	scanf("%d",&n);
	for(int i=1;i<=k;i++){
		if(a[i]>n){
			m=i;
			break;
		}
	}
	for(int i=k;i>=m;i--){
		a[i+1]=a[i];
	}
	a[m]=n;
	printf("Day sau khi sap xep va chen so la: ");
	for(int i=1;i<=k+1;i++){
		printf("%d ",a[i]);
	}
}
