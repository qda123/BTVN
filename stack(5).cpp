#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node { 
	int number;
	struct node *link;
};

struct node *push(struct node *p, int value){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("No Memory available Error\n");
		exit(0);
	}
	temp->number = value;
	temp->link = p;
	p = temp;
	return(p);
}

struct node *pop(struct node *p,int *value){
	struct node *temp;
	if(p==NULL){
		printf(" The stack is empty can not pop Error\n");
		exit(0);
	}
	*value = p->number;
	temp = p;
	p = p->link;
	free(temp);
	return(p);
}

main(){
	struct node *n1 = NULL;
	struct node *n2 = NULL;
	struct node *ans = NULL;
	int n,add=0;
	int value,value1,value2;
	do{
		printf("Enter the number to be pushed for the first number\n");
		fflush(stdin);
		scanf("%d",&value1);
		fflush(stdin);
		n1 = push(n1,value1);
		printf("%d pushed to stack\n",value1);
		fflush(stdin);
		printf("Enter 1 to continue\n");
		scanf("%d",&n);
		fflush(stdin);
	} while(n == 1);
	do{
		printf("Enter the number to be pushed for the second number\n");
		fflush(stdin);
		scanf("%d",&value2);
		fflush(stdin);
		n2 = push(n2,value2);
		printf("%d pushed to stack\n",value2);
		fflush(stdin);
		printf("Enter 1 to continue\n");
		scanf("%d",&n);
		fflush(stdin);
	} while(n == 1);
	while(n1!=NULL){
		value=(value1+value2)%10+add;
		ans = push(ans,value);
		add=(value1+value2)/10;
		n1 = pop(n1,&value1);
		printf("%d popped from stack\n", value1);
		n2 = pop(n2,&value2);
		printf("%d popped from stack\n", value2);
	}
	if(add!=0){
		ans = push(ans,add);
	}
	while(ans!=NULL){
		printf("%d",value);
		ans = pop(ans,&value);
	}
}
