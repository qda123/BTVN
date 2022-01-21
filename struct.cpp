#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 101};

typedef struct{
	char name[50];
	char tel[20];
	char email[50];
}phoneaddress;

int binarySearch(phoneaddress pa[], int nn, char nana[]) {
    int lo = 0, hi = nn, mid, ans = 0;
	int res = 0;
    while (lo <= hi) {
        mid = (hi + lo)/2;
		res = strcmp(pa[mid].name,nana);
        if (res < 0){
        	lo = mid+1;
		}
		else {
			ans= mid;
        	hi = mid-1;
		}
    }

    if(ans <= nn && strcmp(pa[ans].name,nana)==0){
    	return ans;
	}
	else{
		return -1;
	}
}    

int main(void){
	FILE *fp;
	phoneaddress phonearr[MAX_ELEMENT];
	char line[100],na[100],te[100],em[100],namename[50];
	int i,n,nn,pos; 
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
        for (i=0; i<nn-1; i++){
        	for(int j=i+1;j<nn;j++){
        		if(strcmp(phonearr[i].name, phonearr[j].name)>0){
        			strcpy(na,phonearr[i].name);
        			strcpy(phonearr[i].name,phonearr[j].name);
        			strcpy(phonearr[j].name,na);
        			
        			strcpy(te,phonearr[i].tel);
        			strcpy(phonearr[i].tel,phonearr[j].tel);
        			strcpy(phonearr[j].tel,te);
        			
        			strcpy(em,phonearr[i].email);
        			strcpy(phonearr[i].email,phonearr[j].email);
        			strcpy(phonearr[j].email,em);
				}
			}
		}
		fclose(fp);
		fp = fopen("input.txt", "w");
		for (i=0; i<nn; i++){
        	fprintf(fp,"%s", phonearr[i].name);
        	fprintf(fp,"%s", phonearr[i].tel);
        	fprintf(fp,"%s", phonearr[i].email);
		}
        fclose(fp);
        fp = fopen("output.txt", "w");
        printf("Enter a name \n");
        fflush(stdin);
        gets(namename);
		int nnsz = strlen(namename);
		namename[nnsz] = (char) 10;
        fflush(stdin);
        pos=binarySearch(phonearr, nn-1, namename);
        if(pos==-1){
        	fprintf(fp,"NotFound");
		}
		else{
			fprintf(fp,"%s", phonearr[pos].name);
        	fprintf(fp,"%s", phonearr[pos].tel);
        	fprintf(fp,"%s", phonearr[pos].email);
		}
	}
	fclose(fp);
	return reval;
}
