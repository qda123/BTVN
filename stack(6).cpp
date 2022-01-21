#include<string.h>
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
	char number1[1000],number2[1000];
	gets(number1);
	gets(number2);
	if(strlen(number1)>strlen(number2)){
		for(int i=0;i<strlen(number1);i++){
			value1=(int)number1[i]-48;
			n1 = push(n1,value1);
			printf("%d pushed to stack\n",value1);
			if(i<(strlen(number1)-strlen(number2))&&i>=0){
				value2=0;
			}
			else{
				value2=(int)number2[i-strlen(number1)+strlen(number2)]-48;
			}
			n2 = push(n2,value2);
			printf("%d pushed to stack\n",value2);
		}
	}
	else{
		for(int i=0;i<strlen(number2);i++){
			value2=(int)number2[i]-48;
			n2 = push(n2,value2);
			printf("%d pushed to stack\n",value2);
			if(i<(strlen(number2)-strlen(number1))&&i>=0){
				value1=0;
			}
			else{
				value1=(int)number1[i+strlen(number1)-strlen(number2)]-48;
			}
			n1 = push(n1,value1);
			printf("%d pushed to stack\n",value1);
		}
	}
	while(n1!=NULL){
		value=(value1+value2+add)%10;
		ans = push(ans,value);
		add=(value1+value2+add)/10;
		n1 = pop(n1,&value1);
		printf("%d popped from stack\n", value1);
		n2 = pop(n2,&value2);
		printf("%d popped from stack\n", value2);
	}
//	if(add!=0){
//		printf("%d",add);
//	}
	while(ans!=NULL){
		printf("%d",value);
		ans = pop(ans,&value);
	}
}
