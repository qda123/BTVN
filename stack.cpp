#include<stdio.h>
#include<stdlib.h>
struct node { 
	int data;
	struct node *link;
};

struct node *push(struct node *p, int value){
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

struct node *pop(struct node *p, int *value){
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
	int n,value;
	do{
		do{
			printf("Enter the element to be pushed\n");
			scanf("%d",&value);
			top = push(top,value);
			printf("%d pushed to stack\n",value);
			printf("Enter 1 to   continue\n");
			scanf("%d",&n);
		} while(n == 1);
		printf("Enter 1 to pop an element\n");
		scanf("%d",&n);
		while(n==1){
			top = pop(top,&value);
			printf("The value poped is %d\n",value);
			printf("%d popped from stack\n", value);
			printf("Enter 1 to pop an element\n");
			scanf("%d",&n);
		}
		printf("Enter 1 to continue\n");
		scanf("%d",&n);
	} while(n == 1);
}
