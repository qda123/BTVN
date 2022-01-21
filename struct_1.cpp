#include <stdio.h>
#include <string.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 100};
// the phone book structure
typedef struct phoneaddress_t {
	char name[20];
	char tel[11];
	char email[25];
}phoneaddress;
int BinarySearch(phoneaddress A[ ], char name[] , int N ){
	int Low, Mid, High;
	Low = 0; High = N - 1;
	while( Low <= High ) {
		Mid = ( Low + High ) / 2;
		if( strcmp(A[ Mid ].name, name) < 0 )
			Low = Mid + 1;
		else if(strcmp(A[ Mid ].name, name) > 0)
			High = Mid - 1;
		else
			return Mid; /* Found */
	}
	return -1; /* NotFound is defined as -1 */
}
int main(void){
	FILE *fp, *fpout;
	phoneaddress phonearr[MAX_ELEMENT];
	int i,n, irc; // return code
	char name[20];
	int reval = SUCCESS;
	printf("How many contacts do you want to enter (<100)?"); 
	scanf("%d", &n);
	if ((fp = fopen("input.txt","r")) == NULL){
		printf("Can not open %s.\n", "phonebook.dat");
		reval = FAIL;
	} 
	irc = fread(phonearr, sizeof(phoneaddress), n, fp);
	printf(" fread return code = %d\n", irc); 
	fclose(fp);
	if (irc <0) { 
		printf (" Can not read from file!");
		return -1;
	}
	printf("Let me know the name you want to search:"); 
	fflush(stdin);
	gets(name);
	irc = BinarySearch(phonearr, name,n);
	if (irc <0) { 
		printf (" No contact match the criteria!"); 
		fflush(stdin);
		return -1;
	}
// write result to outputfile
	fpout = fopen("output.txt","w");
	if (fpout == NULL){
		printf("Can create file to write.\n");
		reval = FAIL;
	}
	else 
	fprintf(fpout, "%s have the email address %s and telephone number:%s", phonearr[i].name, phonearr[i].email, phonearr[i].tel);
	fclose(fpout);
	return reval;
}

