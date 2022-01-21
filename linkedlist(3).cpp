#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct AddressList{
	char name[50];
	char phone_number[20];
	char email_address[50];
	struct AddressList *next;
};
typedef struct AddressList *node; 
char ten[50],sdt[20],email[50];
char thongtin[50],ht[50],pn[20],em[50];
node CreateNode(int value){
	fflush(stdin);
    printf("\nNhap ho ten cua nguoi can them: ");
    fflush(stdin);
    gets(ten); 
    fflush(stdin);
    printf("\nNhap so dien thoai cua nguoi can them: ");
    fflush(stdin);
    gets(sdt); 
    fflush(stdin);
    printf("\nNhap email cua nguoi can them: ");
    fflush(stdin);
    gets(email);
    fflush(stdin);
	node temp; 
	temp = (node)malloc(sizeof(struct AddressList)); 
	temp->next = NULL;
	strcpy(temp->name,ten);
	strcpy(temp->phone_number,sdt);
	strcpy(temp->email_address,email);
	return temp;
}

node AddTail(node head){
    node temp,p;
    temp = CreateNode(1);
    if(head == NULL){
        head = temp;    
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

node AddHead(node head){
    node temp = CreateNode(1);
    if(head == NULL){
        head = temp;
    }else{
        temp->next = head; 
        head = temp; 
    }
    return head;
}
 
node AddAt(node head, int position){
    if(position == 0 || head == NULL){
        head = AddHead(head);
    }
	else{
        int k = 1;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
        if(k != position){
            head = AddTail(head);
        }
		else{
            node temp = CreateNode(1);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}

void Get(node head, int index){
    int k = 0;
    node p = head;
    while(p != NULL && k != index){
        p = p->next;
    }
    printf("Ho ten: %s\n", p->name);
    printf("So dien thoai: %s\n", p->phone_number);
    printf("Email: %s\n\n", p->email_address);
}
 
int Search(node head){
    int position = 0;
    printf("Thong tin can tim la: ");
    fflush(stdin);
    gets(thongtin);
    fflush(stdin);
    for(node p = head; p != NULL; p = p->next){
        if(strcmp(thongtin,p->name)==0){
            return position;
        }
        if(strcmp(thongtin,p->phone_number)==0){
            return position;
        }
        if(strcmp(thongtin,p->email_address)==0){
            return position;
        }
        ++position;
    }
    return -1;
}
 
node DelHead(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }
	else{
        head = head->next;
    }
    return head;
}
 
node DelTail(node head){
    if (head == NULL || head->next == NULL){
        return DelHead(head);
    }
    node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next;
    return head;
}
 
node DelAt(node head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = DelHead(head);
    }
	else{
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            head = DelTail(head);
            // printf("Vi tri xoa vuot qua vi tri cuoi cung!\n");
        }
		else{
            p->next = p->next->next;
        }
    }
    return head;
}
 
node DelByVal(node head, int value){
    int position = Search(head);
    while(position != -1){
        DelAt(head, position);
        position = Search(head);
    }
    return head;
}

void Traversing(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next){
        printf("Ho ten: %s\n", p->name);
        printf("So dien thoai: %s\n", p->phone_number);
        printf("Email: %s\n\n", p->email_address);
    }
}
node InitHead(){
    node head;
    head = NULL;
    return head;
} 

node Input(){
    node head = InitHead();
    int n;
    do{
    	fflush(stdin);
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);
 
    for(int i = 0; i < n; i++){
        head = AddTail(head);
    }
    return head;
}

int Length(node head){
    int length = 0;
    for(node p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}

main(){
	int pos1,pos2;
	printf("\n==Tao 1 danh sach lien ket==");
	fflush(stdin);
    node head = Input();
    printf("Nguoi can xoa khoi linkedlist la: nguoi thu ");
    fflush(stdin);
    scanf("%d",&pos1);
    head = DelAt(head,pos1-1);
    printf("Vi tri cua nguoi can them vao linked list la:");
    scanf("%d",&pos2);
    head = AddAt(head,pos2-1);
    Traversing(head);
}
