#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include<conio.h>
int main(){
	char line[1000];
   	FILE *fptr1,*fptr2;
 	fptr1 = fopen("program.txt", "r");
 	fptr2 = fopen("program1.txt", "w");
   	if(fptr1 == NULL){
   	   	printf("Error!");
  	    exit(1);
 	}
 	if (fptr1) {
    	while (fgets(line,sizeof(line),fptr1)){
    		fprintf(fptr2,"%s",line);
    		fprintf(fptr2,"\n");
        }
	}
	fclose(fptr1);
   	fclose(fptr2);
 	fptr1 = fopen("program.txt", "w");
 	fptr2 = fopen("program1.txt", "r");
 	while (fgets(line,sizeof(line),fptr2)){
        fprintf(fptr1,"%s",line);
    }
    fclose(fptr1);
   	fclose(fptr2);
   	return 0;
}
