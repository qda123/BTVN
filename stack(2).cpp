#include<stdio.h>
#include<string.h>
int top;
void  check (char str[ ], int n, char stack [ ])
{
    for(int i = 0 ; i < n ; i++ )
    {
        if (str [ i ] == '(')
        {
            top = top + 1;
            stack[ top ] = '(';
        }
        if(str[ i ] == ')' )
        {
            if(top == 0 )
            {
                top = top -1 ;
                break ;
             }
            else
            {
                 top = top -1 ;
            }
        }
    }
    if(top == 0)
        printf("String is balanced!\n");
    else
        printf("String is unbalanced!\n");
}
 
int main( ){
    char str[ ] = "(())()";
    char str1 [] = "((()";
    char stack [15] ;
    top = 0;   
    check (str , strlen(str) , stack );
    top = 0 ;
    check(str1 , strlen(str1) , stack) ;
    return 0;
}
