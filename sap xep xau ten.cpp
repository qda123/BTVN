#include<stdio.h>
#include<string.h>
int main(){
	char str[1000][100],a[1000];
	int n;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++){
		gets(str[i]);
	}
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(strcmp(str[i],str[j])>0){
				strcpy(a,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],a);
			}
		}
	}
	for(int i=0;i<n;i++){
		puts(str[i]);
	}
}
