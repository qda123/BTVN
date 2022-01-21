#include<stdio.h>
#include<stdlib.h>
struct node { 
	char data;
	struct node *link;
};

struct node *push(struct node *p, char value){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("No Memory available Error\n");
		exit(0);
	}
	temp->data = value;
	temp->link = p;
	p = temp;
	return(p);
}

struct node *pop(struct node *p,char *value){
	struct node *temp;
	if(p==NULL){
		printf(" The stack is empty can not pop Error\n");
		exit(0);
	}
	*value = p->data;
	temp = p;
	p = p->link;
	free(temp);
	return(p);
}

main(){
	struct node *top = NULL;
	struct node *toptop = NULL;
	int n;
	char value;
	do{
		printf("Enter the element to be pushed\n");
		fflush(stdin);
		scanf("%c",&value);
		fflush(stdin);
		top = push(top,value);
		printf("%c pushed to stack\n",value);
		fflush(stdin);
		printf("Enter 1 to continue\n");
		scanf("%d",&n);
		fflush(stdin);
	} while(n == 1);
	printf("The reversed string is ");
	while(top!=NULL){
		toptop = push(toptop,value);
		top = pop(top,&value);
		printf("%c",value);
	}
}
