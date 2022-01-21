#include<stdio.h>
#include<string.h>
void replace(char str[],char a,char b){
	for(int i=0;i<strlen(str);i++){
		if(str[i]==a){
			str[i]=b;
		}
	}
}
int main(){
	char strstr[1000];
	char aa,bb;
	printf("Please enter the string: ");
	gets(strstr);
	fflush(stdin);
	printf("Please enter the first char: ");
	scanf("%c",&aa);
	fflush(stdin);
	printf("Please enter the second char: ");
	scanf("%c",&bb);
	replace(strstr,aa,bb);
	printf("The string after replace: ");
	printf("%s",strstr);
}
