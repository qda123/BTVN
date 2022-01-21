#include <stdio.h>
#include <string.h>

 

typedef struct{
    char Ten[30];
    struct{
        int T, L, H, S;
    } DT;
}SinhVien;

 

main(){
    SinhVien DS[100], TK, SV;
    int N,i,j,K;
    float C;
    
    N = 0;
    do{
      printf("\nNhap DL cho sv thu %d\n",N+1);
      printf("Ten SV : "); gets(DS[N].Ten);
      if(strlen(DS[N].Ten)==0) 
         break;
      else{
         printf("Diem thi T L H cua SV %s : ",DS[N].Ten);
         scanf("%d%d%d",&DS[N].DT.T,&DS[N].DT.L,&DS[N].DT.H);
         fflush(stdin);
         DS[N].DT.S = DS[N].DT.T + DS[N].DT.L + DS[N].DT.H;
         N++;
      }    
    }while(1);
    
    printf("\n\n DANH SACH SINH VIEN\n\n");
    printf("      Ten SV          Toan  Ly   Hoa Tong \n");
    for(i = 0; i < N; i ++) 
       printf("%-20s%5d%5d%5d%6d\n",DS[i].Ten,   
              DS[i].DT.T,DS[i].DT.L,DS[i].DT.H,DS[i].DT.S);
    
    printf("\n\nDiem Chuan : ");scanf("%f",&C);    
    printf("\n\n DANH SACH SINH VIEN TRUNG TUYEN \n\n");  
    for(i = 0; i < N; i ++) 
      if( (DS[i].DT.S >= C)&&
             (DS[i].DT.T*DS[i].DT.L*DS[i].DT.H > 0))
          printf("%s\n",DS[i].Ten);
        
    TK = DS[0];
    for(i = 1; i < N; i ++) 
        if(DS[i].DT.S > TK.DT.S)
               TK = DS[i];        
    printf("\n\n THU KHOA: %s \n\n",TK.Ten);    
    
    printf("\nSO nguoi trung tuyen:"); scanf("%d",&K); 
    for(i = 0; i < N - 1; i ++) 
          for(j = i+1; j < N; j ++) 
            if(DS[i].DT.S < DS[j].DT.S ){
                SV= DS[i];
                DS[i]=DS[j];
                DS[j] = SV;
            }
    while((K>0)&&(DS[K-1].DT.S==DS[K].DT.S))K--;
    if(K>0){
         printf("Diem Chuan La : %4d",DS[K-1].DT.S);
         printf("\n\n Danh Sach sinh vien trung tuyen \n");
         for(i=0; i < K; i++)
             printf("%s\n",DS[i].Ten);
     }
}//main
