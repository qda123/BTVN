#include<stdio.h>
#include<conio.h>
int dem(FILE *t)
{
 int dem=0;
 char c;
 while(c=getc(t)!=EOF) dem++;
 return dem;
}
main()
{
 FILE *t;
 t=fopen("E:\\toan.TXT","r");
 if(t==NULL)printf("open file error");
 else printf("tong so ki tu = %d",dem(t));
 fclose(t);
 getch();
}
