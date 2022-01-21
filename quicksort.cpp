#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 101};

typedef struct{
	char name[50];
	char tel[20];
	char email[50];
}phoneaddress;

char line[100],na[100],te[100],em[100];

int partition (phoneaddress pa[], int low, int high){
    char pivot[100]; 
    strcpy(pivot,pa[high].name);
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && strcmp(pa[left].name, pivot) < 0){
        	left++;
		} 
        while(right >= left && strcmp(pa[right].name, pivot) > 0){
        	right--;
		} 
        if (left >= right){
        	break;
		} 
        strcpy(na,pa[left].name);
	    strcpy(pa[left].name,pa[right].name);
	    strcpy(pa[right].name,na);
	        			
	    strcpy(te,pa[left].tel);
	    strcpy(pa[left].tel,pa[right].tel);
	    strcpy(pa[right].tel,te);
	        			
	    strcpy(em,pa[left].email);
	    strcpy(pa[left].email,pa[right].email);
	    strcpy(pa[right].email,em);
        left++;
        right--;
    }
    strcpy(na,pa[left].name);
	strcpy(pa[left].name,pa[high].name);
	strcpy(pa[high].name,na);
	        			
	strcpy(te,pa[left].tel);
	strcpy(pa[left].tel,pa[high].tel);
	strcpy(pa[high].tel,te);
	        			
	strcpy(em,pa[left].email);
	strcpy(pa[left].email,pa[high].email);
	strcpy(pa[high].email,em);
    return left;
}

void quickSort(phoneaddress pa[], int low, int high){
    if (low < high){
        int pi = partition(pa, low, high);
        quickSort(pa, low, pi - 1);
        quickSort(pa, pi + 1, high);
    }
}

int main(void){
	FILE *fp;
	phoneaddress phonearr[MAX_ELEMENT];
	int i,n,nn; 
	int reval = SUCCESS;
	fp = fopen("input.txt", "r");
	if (fp == NULL){
		printf("Can not open %s.\n", "input.txt");
		reval = FAIL;
	} 
	else if (fp) {
		n=0;
		nn=0;
    	while (fgets(line,sizeof(line),fp)){
    		if(n%3==0){
    			strcpy(phonearr[nn].name,line);
			}
			else if(n%3==1){
    			strcpy(phonearr[nn].tel,line);
			}
			else if(n%3==2){
    			strcpy(phonearr[nn].email,line);
    			nn++;
			}
        	n++;
        }
		quickSort(phonearr,0,nn-1);
		fclose(fp);
		fp = fopen("output.txt", "w");
		for (i=0; i<nn; i++){
        	fprintf(fp,"%s", phonearr[i].name);
        	fprintf(fp,"%s", phonearr[i].tel);
        	fprintf(fp,"%s", phonearr[i].email);
		}
	}
	fclose(fp);
	return reval;
}
