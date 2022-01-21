#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 101};
 
struct AddressList{
    char name[50];
    char phone_number[20];
    char email_address[50];
    struct AddressList *next;
};
typedef struct AddressList *node;
char line[100],na[100],te[100],em[100],namename[50];
char nana[100],tete[100],emem[100];
 
node CreateNode(char value1[], char value2[], char value3[]){
    node temp; 
    temp = (node)malloc(sizeof(struct AddressList)); 
    temp->next = NULL;
    strcpy(temp->name, value1);
    strcpy(temp->phone_number, value2);
    strcpy(temp->email_address, value3);
    return temp;
}
 
node AddTail(node head, char value1[], char value2[], char value3[]){
    node temp,p;
    temp = CreateNode(value1, value2, value3);
    if(head == NULL){
        head = temp;    
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}
 
node InitHead(){
    node head;
    head = NULL;
    return head;
} 
 
void Traversing(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next){
        printf("Ho ten: %s\n", p->name);
        printf("So dien thoai: %s\n", p->phone_number);
        printf("Email: %s\n\n", p->email_address);
    }
}
 
int main(void){
    FILE *fp;
    int n; 
    char tmp1[50], tmp2[50], tmp3[50];
    int reval = SUCCESS;
    fp = fopen("input.txt", "r");
    if (fp == NULL){
        printf("Can not open %s.\n", "input.txt");
        reval = FAIL;
    } 
    else if (fp) {
        n=0;
        node head = InitHead();
        while (fgets(line,sizeof(line),fp)){
            if(n%3==0){
                strcpy(tmp1, line);
            }
            else if(n%3==1){
                strcpy(tmp2, line);
            }
            else{
                strcpy(tmp3, line);
                head = AddTail(head, tmp1, tmp2, tmp3);
            }
            n++;
        }
    	Traversing(head);
	    for(node p = head; p != NULL; p = p->next){
	    	for(node q = p->next; q != NULL; q = q->next){
	    		if(strcmp(p->name, q->name)>0){
	                  strcpy(nana,p->name);
	                  strcpy(p->name,q->name);
	                  strcpy(q->name,nana);
	                  
	                  strcpy(tete,p->phone_number);
	                  strcpy(p->phone_number,q->phone_number);
	                  strcpy(q->phone_number,tete);
	                  
	                  strcpy(emem,p->email_address);
	                  strcpy(p->email_address,q->email_address);
	                  strcpy(q->email_address,emem);
	            }
	        }
	    }
	    fclose(fp);
	    fp = fopen("input.txt", "w");
	    for(node p = head; p != NULL; p = p->next){
	        fprintf(fp,"%s", p->name);
	        fprintf(fp,"%s", p->phone_number);
	        fprintf(fp,"%s", p->email_address);
	    }
	    fclose(fp);
	    fp = fopen("output.txt", "w");
	    int position = 0;
	    printf("Enter a name \n");
	    fflush(stdin);
	    gets(namename);
	  	int nnsz = strlen(namename);
	  	int count=0;
	  	namename[nnsz] = (char) 10;
	    fflush(stdin);
	    for(node p = head; p != NULL; p = p->next){
	        if(strcmp(namename,p->name)==0){
	            fprintf(fp,"%s", p->name);
	        	fprintf(fp,"%s", p->phone_number);
	        	fprintf(fp,"%s", p->email_address);
	        	count=1;
	        }
	    }
	    if(count==0){
	    	fprintf(fp,"NotFound");
		}
    fclose(fp);
	}
	return reval;
}
