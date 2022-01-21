#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char exp[1000]; 

struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack( unsigned capacity ){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 
    if (!stack){
    	return NULL;
	}
    
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity *sizeof(int));
 
 	if (!stack->array){
    	return NULL;
	} 
	
    return stack;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1 ;
}

char peek(struct Stack* stack){
    return stack->array[stack->top];
}

char pop(struct Stack* stack){
    if (!isEmpty(stack)){
    	return stack->array[stack->top--] ;
	}
    return '$';
}

void push(struct Stack* stack, char op){
    stack->array[++stack->top] = op;
}

int Prec(char ch){
    switch (ch){
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

int infixToPostfix(char* exp){
    int i, k;
    struct Stack* stack = createStack(strlen(exp));
    if(!stack){
    	return -1 ;
	}
 
    for (i = 0, k = -1; exp[i]; ++i){
        if (exp[i]>='1' && exp[i]<='9'){
        	exp[++k] = exp[i];
		}
        
        else if (exp[i] == '('){
        	push(stack, exp[i]);
		}
            
        else if (exp[i] == ')'){
            while (!isEmpty(stack) && peek(stack) != '('){
            	exp[++k] = pop(stack);
			}
            if (!isEmpty(stack) && peek(stack) != '('){
            	return -1;   
			}       
            else{
            	pop(stack);
			}
        }
        
        else{
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack))){
            	exp[++k] = pop(stack);
			}
            push(stack, exp[i]);
        }
    }
    
    while (!isEmpty(stack)){
    	exp[++k] = pop(stack );
	}
    exp[++k] = '\0';
    for(int i=0;i<strlen(exp);i++){
    	printf( "%c ", exp[i] );
	}
	printf("\n");
}

int evaluatePostfix(char* exp){
    struct Stack* stack = createStack(strlen(exp));
    int i;
 
    if (!stack){
    	return -1;
	} 
 
    for (i = 0; i<strlen(exp);i++){
        if (isdigit(exp[i])){
        	push(stack, exp[i]-'0');
		}
            
        else if(exp[i]!=' '){
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]){
            case '*': push(stack, val2 * val1); break;
            case '/': push(stack, val2 / val1); break;
            case '+': push(stack, val2 + val1); break;
            case '-': push(stack, val2 - val1); break;
            }
        }
    }
    return pop(stack);
}
int main(){
    printf("Enter an expression in the infix notation\n");
    fflush(stdin);
    gets(exp);
    printf("The expression in the postfix notation is ");
    fflush(stdin);
    infixToPostfix(exp);
    fflush(stdin);
    printf("\n");
    printf ("The evaluation of expression in the infix notation is %d", evaluatePostfix(exp));
    return 0;
}
