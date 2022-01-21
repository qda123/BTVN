#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum{SUCCESS, FAIL, MAX_ELEMENT = 101};
// A linked list (LL) node to store a queue entry
struct QNode{
    char name[50];
    char phone_number[20];
    char email_address[50];
    struct QNode* next;
};

// The queue, front stores the front node of LL and rear stores the
// last node of LL
struct Queue{
    struct QNode *front, *rear;
};

// A utility function to create a new linked list node.
struct QNode* newNode(char value1[], char value2[], char value3[]){
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    strcpy(temp->name, value1);
    strcpy(temp->phone_number, value2);
    strcpy(temp->email_address, value3);
    return temp;
}

// A utility function to create an empty queue
struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// The function to add a key k to q
void enQueue(struct Queue* q,char value1[], char value2[], char value3[]){
    // Create a new LL node
    struct QNode* temp = newNode(value1,value2,value3);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove a key from given queue q
void deQueue(struct Queue* q){
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;

    // Store previous front and move front one node ahead
    struct QNode* temp = q->front;

    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Driver Program to test anove functions
int main(){
	FILE *fp;
	int reval = SUCCESS;
	int n,nn;
	char line[100],tmp1[50],tmp2[50],tmp3[50];
	fp = fopen("input.txt", "r");
	if (fp == NULL){
        printf("Can not open %s.\n", "input.txt");
        reval = FAIL;
    } 
    else if (fp){
    	n=0;
    	nn=0;
    	struct Queue* q = createQueue();
    	while (fgets(line,sizeof(line),fp)){
            if(n%3==0){
                strcpy(tmp1, line);
            }
            else if(n%3==1){
                strcpy(tmp2, line);
            }
            else{
                strcpy(tmp3, line);
                enQueue(q,tmp1,tmp2,tmp3);
                nn++;
            }
            n++;
        }
	    fclose(fp);
	    fp = fopen("input.txt", "w");
	    nn--;
	    while(nn>=0){
	    	printf("%s", q->front->name);
	    	printf("%s", q->front->phone_number);
	    	printf("%s", q->front->email_address);
	    	fprintf(fp,"%s", q->front->name);
	    	fprintf(fp,"%s", q->front->phone_number);
	    	fprintf(fp,"%s", q->front->email_address);
	    	deQueue(q);
	    	nn--;
		}
	}
    return reval;
}
