#include<stdio.h>
#include <time.h>
#include<stdlib.h>		//hocam ödevimde zamanı milisaniyeye çevirirken sürekli 0 bulduğu için %.2f %.3f gibi değer kullanamadım
						// o yüzden ekrana saniye * 10^-6 şeklinde yazdırdım çünkü 10^-3 yapınca hep sıfır buldu
						// değerimi bu yüzden milisaniye yerine milisaniyenin karesi şeklinde hesaplayabildim
typedef struct tree{
	int data1;
	struct tree *left;
	struct tree *right;
}bst;
typedef struct que{
	int data2;
	struct que *next;

}queue;
typedef struct sta{
	int data3;
	struct sta *next;
}stack;

stack *top;
queue *head;
bst *root;
int counter=0,step=0;

void dolas(bst *root){
	if(root==NULL){
		return;
	}
	dolas(root->right);
	printf("%d ",root->data1 );
	dolas(root->left);
}
bst *init_bst(bst *root_bst,int num){
	bst *root2;

	if(root_bst==NULL){
		root2=malloc(sizeof(bst));
		root2->data1=num;
		root2->right=NULL;
		root2->left=NULL;
		return root2;
	}
	if (root_bst->data1<num)
	{
		root_bst->right=init_bst(root_bst->right,num);	
		return root_bst;
	}
		root_bst->left=init_bst(root_bst->left,num);
		return root_bst;
}

void init_queuee(queue *queue_,int data[20]){
int i=0;
do
{
	if (queue_->next==NULL)
	{
		queue_->next=malloc(sizeof(queue));
	}
	queue_->data2=data[i];
	
	queue_=queue_->next;
	i++;
}
while(i<20);

}
void init_stack(stack *stack_,int data[20]){
	stack *top2;
	int i=1;
	while(i<20){
		top2=malloc(sizeof(stack_));
		top2->data3=data[i];
		top2->next=stack_;
		stack_=top2;
		i++;
	}
	
	top=top2;
}


void fill_structures(stack ** stack_, queue ** queue_, bst ** bst_, int data[20]){

*stack_=malloc(sizeof(stack));
*queue_=malloc(sizeof(queue));
*bst_=malloc(sizeof(bst));
(*bst_)->right=NULL;
(*bst_)->left=NULL;
int i=0;
clock_t total_time,time_bst_start,time_queue_start,time_stack_start,time_bst_end,time_queue_end,time_stack_end;
top=(*stack_);
head=(*queue_);
root=(*bst_);
//------------------bst startedddd------------------------
time_bst_start=clock();
while(i<20){
(*bst_)=init_bst((*bst_),data[i]);
i++;
}
time_bst_end=clock();
total_time=((double)(time_bst_end-time_bst_start))/CLOCKS_PER_SEC*1000000;
printf("exec. time bst %ld * 10^-6 s\n",total_time );
(*bst_)=root;
//------------------bst finished------------------------------
//-------------queue started---------------------------------
time_queue_start=clock();
init_queuee((*queue_),data);
(*queue_)=head;
time_queue_end=clock();
total_time=((double)(time_queue_end-time_queue_start))/CLOCKS_PER_SEC*1000000;
printf("exec. time queue %ld * 10^-6 s\n",total_time );

//-------------queue finished-------------------------------

//--------------stack started------------------------------
time_stack_start=clock();

(*stack_)->data3=data[0];
(*stack_)->next=NULL;
init_stack((*stack_),data);
(*stack_)=top;
time_stack_end=clock();
total_time=((double)(time_stack_end-time_stack_start))/CLOCKS_PER_SEC*1000000;
printf("exec. time stack %ld * 10^-6 s\n",total_time );

//-------------stack finished-------------------------------

}
void ordered_print(stack * stack_, queue * queue_, bst * bst_){
int array[20],i=0,temp;
clock_t start,end,total;
//--------------bst print started---------------
printf("\n");
start=clock();
dolas(bst_);
end=clock();
total=((double)(end-start))/CLOCKS_PER_SEC*1000000;
printf("\nexec. time bst ordered %ld * 10^-6 s\n",total );



//--------------bst prnt finished------------------------

//--------------stack started------------------------
printf("\n");
start=clock();
while(top!=NULL){
	array[i]=top->data3 ;
	top=top->next;
	i++;
}
i=0;
stack_=top;
for (i = 0; i < 20; i++)
{
	for (int j = 0;  j< 19; j++)
	{
		if(array[j]<array[j+1]){
			temp=array[j+1];
			array[j+1]=array[j];
			array[j]=temp;
		}
	}
}

i=0;
while(i<20){
	printf("%d ",array[i]);
	i++;
}
end=clock();
total=((double)(end-start))/CLOCKS_PER_SEC*1000000;
printf("\nexec. time stack ordered %ld * 10^-6 s\n",total );
//-------------stack finished------------------------
i=0;
printf("\n");
//-------------queue started------------------------
start=clock();
while(head->next!=NULL){
	array[i]=head->data2 ;
	head=head->next;
	i++;
}
i=0;
for (i = 0; i < 20; i++)
{
	for (int j = 0;  j< 19; j++)
	{
		if(array[j]<array[j+1]){
			temp=array[j+1];
			array[j+1]=array[j];
			array[j]=temp;
		}
	}
}

i=0;
while(i<20){
	printf("%d ",array[i]);
	i++;
}
head=queue_;
end=clock();
total=((double)(end-start))/CLOCKS_PER_SEC*1000000;
printf("\nexec. time queue ordered %ld * 10^-6 s\n",total );
//-------------queue finished-----------------------

}

void dolas2(bst *root,int *array){
	if(root==NULL){
		return;
	}
	dolas2(root->right,array);
	*(array+counter)=root->data1;
	counter++;
	dolas2(root->left,array);
}

void special_traverse(stack * stack_, queue * queue_, bst * bst_){
	int array[20],ilk=0,son=19,i=0,temp;
	clock_t start,end,total;

	//------------------------------start bst-----------------
	printf("\n");
	start=clock();
	dolas2(bst_,array);
	while(ilk<=9){
		printf("%d %d ",array[ilk],array[son] );
		ilk++;
		son--;
	}
	end=clock();
	total=((double)(end-start))/CLOCKS_PER_SEC*1000000;
	printf("\nexec. time bst traverse %ld * 10^-6 s\n",total );

	//------------------------------finished bst--------------

	//------------------------------start stack---------------
	printf("\n");
	start=clock();
while(top!=NULL){
	array[i]=top->data3 ;
	top=top->next;
	i++;
}
i=0;
stack_=top;
for (i = 0; i < 20; i++)
{
	for (int j = 0;  j< 19; j++)
	{
		if(array[j]<array[j+1]){
			temp=array[j+1];
			array[j+1]=array[j];
			array[j]=temp;
		}
	}
}

i=0;
ilk=0;
son=19;
while(ilk<=9){
		printf("%d %d ",array[ilk],array[son] );
		ilk++;
		son--;
	}	
	end=clock();
	total=((double)(end-start))/CLOCKS_PER_SEC*1000000;
	printf("\nexec. time stack traverse %ld * 10^-6 s\n",total );

	//------------------------------finished stack------------

	//---------------------------started queue----------------
	printf("\n");
	start=clock();
while(head->next!=NULL){
	array[i]=head->data2 ;
	head=head->next;
	i++;
}
i=0;
for (i = 0; i < 20; i++)
{
	for (int j = 0;  j< 19; j++)
	{
		if(array[j]<array[j+1]){
			temp=array[j+1];
			array[j+1]=array[j];
			array[j]=temp;
		}
	}
}

i=0;
ilk=0;
son=19;
while(ilk<=9){
		printf("%d %d ",array[ilk],array[son] );
		ilk++;
		son--;
	}	
head=queue_;
	end=clock();
	total=((double)(end-start))/CLOCKS_PER_SEC*1000000;
	printf("\nexec. time queue traverse %ld * 10^-6 s\n",total );

	//---------------------------finished queue----------------
}
void dolas3(bst *root,int val_to_search){
	if(root==NULL){
		return;
	}
	dolas3(root->left,val_to_search);
	if (root->data1==val_to_search)
	{
		counter++;
	}
	dolas3(root->right,val_to_search);
}
void dolas4(bst *root,int val_to_search){
		if(root==NULL){
		return;
	}
	step++;
	dolas4(root->left,val_to_search);
	if (root->data1==val_to_search)
	{
		counter--;
		if (counter==0)
		{
			return;
		}
	}
	dolas4(root->right,val_to_search);

}
void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search){
	int count=0;
	clock_t start,end,total;
	//-------------------------bst started---------------------
	counter=0;
	start=clock();
	dolas3(bst_,val_to_search);
	count=counter;
	dolas4(bst_,val_to_search);
	end=clock();
	total=((double)(end-start))/CLOCKS_PER_SEC*1000000;
	printf("\n %d result founded on %d.step\n",count,step);
	printf("\nexec. time bst search %ld * 10^-6 s\n",total );
	
	//--------------------------bst finished-------------------
	printf("\n");

	//------------------------stack started----------------------
	count=0;
	counter=0;
	step=0;
	start=clock();
		while(top!=NULL){
			if (top->data3==val_to_search)
			{
				counter++;
			}
			top=top->next;
		}
		count=counter;
		top=stack_;
		while(top!=NULL){
			step++;
			if (top->data3==val_to_search)
			{
				counter--;
				
				if (counter==0)
				{
					break;
				}
			}
			top=top->next;	
		}
		printf("%d result founded on %d.step\n",count,step );
		end=clock();
		total=((double)(end-start))/CLOCKS_PER_SEC*1000000;
	printf("\nexec. time stack search %ld * 10^-6 s\n",total );

		top=stack_;
	//----------------------stack finished-----------------------
		printf("\n");
	//----------------------que started--------------------------
	count=0;
	counter=0;
	step=0;
	start=clock();
		while(head!=NULL){
			if (head->data2==val_to_search)
			{
				counter++;
			}
			head=head->next;
		}
		count=counter;
		head=queue_;
		while(head!=NULL){
			step++;
			if (head->data2==val_to_search)
			{
				counter--;
				
				if (counter==0)
				{
					break;
				}
			}
			head=head->next;	
		}
		printf("%d result founded on %d.step\n",count,step );
		end=clock();
		total=((double)(end-start))/CLOCKS_PER_SEC*1000000;
	printf("\nexec. time queue search %ld * 10^-6 s\n",total );

		head=queue_;
	//----------------------que finished-------------------------	
}

int main()
{
int data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17,8, 23, 4};
bst * bst_;
queue * queue_;
stack * stack_;
fill_structures(&stack_, &queue_, &bst_, data);
ordered_print(stack_, queue_, bst_);
search(stack_, queue_, bst_, 5);
special_traverse(stack_, queue_, bst_);
return 0;
}