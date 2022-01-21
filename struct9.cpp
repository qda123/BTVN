#include<stdio.h>
#include<string.h>
typedef struct{
    char Name[30];
    char Id[12];
    char Home_town[30];
    float GPA;
}SinhVien;
int n,p,ii,pp,nn;
SinhVien DS[1000];
char maso[12],maso1[12];
float sum,GPAtb,diemso;
char quequan[30],quequan1[30],ten[30];
void menu(){
	printf("MENU CHINH\n\n");
	printf("DANH SACH CAC CHUC NANG\n\n");
	printf("1.Nhap thong tin sinh vien\n");
	printf("2.In thong tin cac sinh vien\n");
	printf("3.Tim kiem theo ma so sinh vien\n");
	printf("4.Tim kiem theo GPA va que quan\n");
	printf("5.Sap xep\n");
	printf("6.Thoat\n\n");
}
void one(int pos){
	if(pos==0){
		printf("So luong sinh vien : ");
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			printf("Nhap du lieu cho sv thu %d\n",i);
	      	printf("Ten SV : "); 
	      	fflush(stdin);
			gets(DS[i].Name);
			fflush(stdin);
			printf("MSSV : ");
			gets(DS[i].Id);
			fflush(stdin);
			printf("Que Quan : ");
			gets(DS[i].Home_town);
			fflush(stdin);
			printf("GPA : ");
			scanf("%f",&DS[i].GPA);
			fflush(stdin);
		}
	}
	else{
		printf("So luong sinh vien nhap them: ");
		scanf("%d",&nn);
		for(int i=n+1;i<=n+nn;i++){
			printf("Nhap du lieu cho sv thu %d\n",i);
	      	printf("Ten SV : "); 
	      	fflush(stdin);
			gets(DS[i].Name);
			fflush(stdin);
			printf("MSSV : ");
			gets(DS[i].Id);
			fflush(stdin);
			printf("Que Quan : ");
			gets(DS[i].Home_town);
			fflush(stdin);
			printf("GPA : ");
			scanf("%f",&DS[i].GPA);
			fflush(stdin);
		}
		n+=nn;
	}
}
void two(){
	sum=0;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=5;j++){
			if(i==1){
				printf("STT       Ten SV         MSSV      QueQuan    GPA");
				break;
			}
			else {
				if(j==1){
					printf("%d  ",i-1);
				}
				else if(j==2){
					printf("%-20s",DS[i-1].Name);
				}
				else if(j==3){
					printf("%-8s   ",DS[i-1].Id);
				}
				else if(j==4){
					printf(" %-10s ",DS[i-1].Home_town);
				}
				else if(j==5){
					printf("%.1f",DS[i-1].GPA);
					sum+=DS[i-1].GPA;
				}
			}
		}
		printf("\n");
	}
	GPAtb=sum/(float)n;
	printf("Diem GPA trung binh tat ca sinh vien: %.1f\n",GPAtb);
}
void three(){
	p=0;
	printf("Ma so sinh vien can tim kiem: ");
	fflush(stdin);
	gets(maso);
	for(int i=1;i<=n;i++){
		if(strcmp(DS[i].Id,maso)==0){
			printf("Ten SV : ");
			printf("%s\n",DS[i].Name);
			printf("MSSV : ");
			printf("%s\n",DS[i].Id);
			printf("Que Quan : ");
			printf("%s\n",DS[i].Home_town);
			printf("GPA : ");
			printf("%.1f\n",DS[i].GPA);
			p=1;
		}
	}
	if(p=0){
		printf("Khong tim thay\n");
	}
}
void four(){
	ii=1;
	pp=0;
	printf("Sinh vien can tim kiem co que quan: ");
	fflush(stdin);
	gets(quequan);
	printf("Tim thay cac sinh vien sau co diem GPA lon hon GPA trung binh gom:\n");
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=5;j++){
			if(i==1){
				printf("STT       Ten SV         MSSV      QueQuan    GPA");
				break;
			}
			else {
				if(strcmp(DS[i-1].Home_town,quequan)==0&&DS[i-1].GPA>GPAtb){
					if(j==1){
						printf("%d  ",ii);
						ii++;
					}
					else if(j==2){
						printf("%-20s",DS[i-1].Name);
					}
					else if(j==3){
						printf("%-8s   ",DS[i-1].Id);
					}
					else if(j==4){
						printf(" %-10s ",DS[i-1].Home_town);
					}
					else if(j==5){
						printf("%.1f",DS[i-1].GPA);
					}
				}
			}
		}
		printf("\n");
	}
}
void five(){
	for(int i=1;i<n;i++){
		for(int j=n;j>i;j--){
			if(DS[i].GPA<DS[j].GPA){
				diemso=DS[i].GPA;
				DS[i].GPA=DS[j].GPA;
				DS[j].GPA=diemso;
				strcpy(quequan1,DS[i].Home_town);
				strcpy(DS[i].Home_town,DS[j].Home_town);
				strcpy(DS[j].Home_town,quequan1);
				strcpy(maso1,DS[i].Id);
				strcpy(DS[i].Id,DS[j].Id);
				strcpy(DS[j].Id,maso1);
				strcpy(ten,DS[i].Name);
				strcpy(DS[i].Name,DS[j].Name);
				strcpy(DS[j].Name,ten);
			}
		}
	}
	sum=0;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=5;j++){
			if(i==1){
				printf("STT       Ten SV         MSSV      QueQuan    GPA");
				break;
			}
			else {
				if(j==1){
					printf("%d  ",i-1);
				}
				else if(j==2){
					printf("%-20s",DS[i-1].Name);
				}
				else if(j==3){
					printf("%-8s   ",DS[i-1].Id);
				}
				else if(j==4){
					printf(" %-10s ",DS[i-1].Home_town);
				}
				else if(j==5){
					printf("%.1f",DS[i-1].GPA);
					sum+=DS[i-1].GPA;
				}
			}
		}
		printf("\n");
	}
	GPAtb=sum/(float)n;
	printf("Diem GPA trung binh tat ca sinh vien: %.1f\n",GPAtb);
}
int main(){
	int f;
	int pos=0;
	do{
		menu();
		printf("Chuc nang ban muon lua chon: chuc nang so ");
		scanf("%d",&f);
		if(f==1){
			one(pos);
			pos++;
		}
		else if(f==2){
			two();
		}
		else if(f==3){
			three();
		}
		else if(f==4){
			four();
		}
		else if(f==5){
			five();
		}
		else if(f==6){
			break;
		}
	}while(1);
}
