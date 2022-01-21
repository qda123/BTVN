#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"Item.h"
#include"STACK.h"
static Item *s;
static int N;
void STACKinit(int maxN){ 
	s = malloc(maxN*sizeof(Item)); 
	N = 0;
}
int STACKempty(){ 
	return N == 0; 
}
void STACKpush(Item item){ 
	s[N++] = item; 
}
Item STACKpop(){ 
	return s[--N]; 
}
main(int argc,char *argv[]){
	char *a=argv[1];
	int i,N=strlen(a);
	STACKinit(N);
	for(int i=0;i<N;i++){
		if(a[i]==')'){
			printf("%c",STACKpop());
		}
		if(a[i]=='+'||a[i]=='*'){
			STACKpush(a[i]);
		}
		if(a[i]>='0'&&a[i]<='9'){
			printf("%c",a[i]);
		}
	}
	printf("\n");
}
