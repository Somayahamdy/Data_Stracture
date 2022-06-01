#include<stdio.h>
#include<stdlib.h>
//creat Node
typedef struct listnode
{
	int Data ;
	struct listnode* Next;
	
}ListNode;


typedef struct list
{
	int size ;
	ListNode* head;
	
}List;





void list_voidint(List* pl);
void insertinlist(int pos ,int val,List* pl);
void deletinlist(int pos ,List* pl,int *pd);
void retrivlist(int pos ,List* pl,int *pd);//get value from list
void replacelist(int pos ,int val,List* pl);
int isempty(List* pl);
int isfull(List* pl); //impossipole to be full always return 0
int listsize(List* pl);
void printlist(List* pl);
void Distroylist(List* pl);

int main(){
	int size;
	List L;
	int retritve;
	list_voidint(&L);
	insertinlist(0,7,&L);
	insertinlist(1 ,8,&L);
	insertinlist(2 ,9,&L);
	size = listsize(&L);
	printf("size of elements is \n %d",size);
	printf(" \nelements of list \n ");
	printlist(&L);
	retrivlist(0 ,&L,&retritve);
	printf("\n Retritive Value is \n %d",retritve);
	deletinlist(2 ,&L,&retritve);
	printf("\n deleted Value is \n %d",retritve);
	size = listsize(&L);
	printf("\nsize of elements is \n %d",size);
	printf(" \nelements of list \n ");
		printlist(&L);
}

void list_voidint(List* pl){
	pl -> head =NULL;
	pl -> size = 0;
}

int isempty(List* pl){
	return (pl -> head == NULL);
}

int isfull(List* pl){
	return 0;
}


int listsize(List* pl){
	return(pl -> size);
}

void insertinlist(int pos ,int val,List* pl){
	ListNode* q;
	int i;
  ListNode* pn =(ListNode*)malloc(sizeof(ListNode));
  pn -> Data = val;
  pn -> Next = NULL;

  
  if(pos == 0){
	  pn->Next = pl->head;
	  pl->head = pn;
	//q -> Next = pn;
 }  
 else{
	 for(q=pl->head,i=0;i<pos-1;i++){
		 q=q->Next;
	 }
	 pn->Next=q->Next;
	 q->Next=pn;
	
}
pl -> size++;

 }
 
 
 void replacelist(int pos ,int val,List* pl){
	 int i;
	 ListNode* q;
	 for(q=pl->head,i=0;i<pos;i++){
		 q=q->Next;
	 }
	 q->Data=val;
 }
 
 void Distroylist(List* ptr){
	ListNode*tmp;
	while(!isempty(ptr)){
		tmp = ptr->head->Next;
		free(ptr->head);
		ptr->head = tmp;
	}
	ptr->size=0;
}
 
 
 void printlist(List* ptr){
	ListNode* tmp=ptr->head;
while(tmp!=NULL)	{
	printf("\n %d\n",tmp->Data);
	tmp=tmp->Next;
}
 }
 
 
 void retrivlist(int pos ,List* pl,int *pd){
	 int i;
	  ListNode* q;
	  for(q=pl->head,i=0;i<pos;i++){
		  q=q->Next;
	  }
	  *pd = q->Data;
 }
 
void deletinlist(int pos ,List* pl,int *pd){
	int i;
	ListNode* q;
	ListNode* tmp;
	if(pos==0){
		*pd=pl->head->Data;
		tmp= pl->head->Next;
		free(pl->head);
		pl->head=tmp;
	}
	else{
		for(q=pl->head,i=0;i<pos-1;i++){
			q=q->Next;
			
		}
		*pd =q->Next->Data;
		tmp= q->Next->Next;
		free(q->Next);
		q->Next=tmp;
	}
	pl->size--;
} 
 
 











