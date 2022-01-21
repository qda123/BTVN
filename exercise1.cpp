#include<stdio.h>
#include<string.h>
int main(){
	char str[1000];
	int count[52];
	printf("The input line: ");
	gets(str);
	for(int i=0;i<52;i++){
		count[i]=0;
	}
	for(int i=0;i<strlen(str);i++){
		if(str[i]<='z'&&str[i]>='a'){
			count[(int)str[i]-65]++;
		}
		else if(str[i]<='Z'&&str[i]>='A'){
			count[(int)str[i]-65]++;
		}
	}
	printf("The output for the input line: \"%s\"\n",str);
	for(int i=0;i<52;i++){
		if(count[i]!=0){
			printf("The letter '%c' appears %d time(s)).\n",i+65,count[i]);
		}
	}
}
