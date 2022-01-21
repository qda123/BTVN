#include<stdio.h>
void split(double parameter,int* integer,double* fraction_part){
	*integer=(int)parameter;
	*fraction_part=parameter- *integer;
}
int main(){
	double para,frac;
	int int_part;
	printf("Please enter a real number: ");
	scanf("%lf",&para);
	split(para,&int_part,&frac);
	printf("The integer part: %d\n",int_part);
	printf("The fraction part: %lf",frac);
}
