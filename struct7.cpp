#include<stdio.h>
#include<string.h>
struct thisinh{
	char hoten[20];
	float diemtoan;
	float diemly;
	float diemhoa;
	float tongdiem;
};
main(){
	int n,K;
	thisinh ds[1000],sv;
	int ccc=0;
	float diemchuan,max=0;
	n=0;
	do{
		printf("\nNhap DL cho sv thu %d\n",n+1);
      	printf("Ten SV: ");
		gets(ds[n].hoten);
        if(strlen(ds[n].hoten)==0){
        	break;	
		}
      	else{
	        printf("Diem thi toan ly hoa cua SV %s : ",ds[n].hoten);
	        scanf("%f %f %f",&ds[n].diemtoan,&ds[n].diemly,&ds[n].diemhoa);
	        fflush(stdin);
	        ds[n].tongdiem = ds[n].diemtoan + ds[n].diemly + ds[n].diemhoa;
	        n++;
		}
	}while(1);
	printf("Diem chuan dau vao la: ");
	scanf("%f",&diemchuan);
	printf("Danh sach trung tuyen\n");
	for(int i=0;i<n;i++){
		if(ds[i].tongdiem >= diemchuan && ds[i].diemtoan * ds[i].diemly * ds[i].diemhoa > 0){
			printf("%s\n",ds[i].hoten);
		}
	}
	max=ds[0].tongdiem;
	for(int i=1;i<n;i++){
		if(ds[i].tongdiem > max && ds[i].diemtoan * ds[i].diemly * ds[i].diemhoa > 0){
			max = ds[i].tongdiem;
		}
	}
	printf("Danh sach thu khoa\n");
	for(int i=0;i<n;i++){
		if(ds[i].tongdiem == max){
			printf("%s\n",ds[i].hoten);
		}
	}
	printf("So nguoi trung tuyen la: ");
	scanf("%d",&K);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(ds[i].tongdiem > ds[j].tongdiem){
				sv=ds[i];
				ds[i]=ds[j];
				ds[j]=sv;
			}
		}
	}
	for(int i=n-1;i>=n-K;i--){
		if(ds[i].tongdiem==ds[n-K-1].tongdiem && ds[i].diemtoan * ds[i].diemly * ds[i].diemhoa > 0){
			ccc++;
		}
	}
	if(ccc==0){
		printf("Diem chuan dau vao la: ");
		printf("%.1f\n",ds[n-K-1].tongdiem+0.1);
		return 0;
	}
	printf("Diem chuan dau vao la: ");
	printf("%.1f\n",ds[n-K].tongdiem);
	return 0;
}
