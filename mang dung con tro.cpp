#include<stdio.h>
#include<stdlib.h>
int main(){
//	int list[1000];
//	int *ptr;
//	int n;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++){
//		scanf("%d",&list[i]);
//	}
//	ptr=list;
//	for(int i=0;i<n;i++){
//		printf("%d ",*(ptr+i));
//	}
	int b[3][4];
    
    int *p_array=(int*)malloc(5*sizeof(int));
    p_array[0]=10;
    p_array[3]=30;
    printf("%d %d\n",p_array[0],p_array[3]);
    *p_array=11;//sua lai noi dung cua p_array[0]
    *(p_array+3)=31;//sua lai noi dung cua p_array[3]
    printf("%d %d\n",*p_array,*(p_array+3));
    free(p_array);
}
