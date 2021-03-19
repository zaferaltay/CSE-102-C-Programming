#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define xsize 25
struct person {
	char name[xsize];
	char surname[xsize];
	char musical_word[xsize];
	int age;
	struct person *next;
}*top;

struct person *tail;
struct person *temp;

void menu(){
	printf("--------------------MENU-------------------------\n1- Add a Person to the Stack\n2- Pop a Person from the Stack\n3- Sort Alphabetical Order\n4- Sort Age in Increasing Order\n5- Exit menu\n-------------------------\n");

}
void addNode(char name[],char surname[],char creation[],int age){
	struct person *prnt;
	int i=0,j=0;
	temp=malloc(sizeof(struct person));
	temp->next=top;
	top=temp;
	strcpy(top->name,name);
	strcpy(top->surname,surname);
	strcpy(top->musical_word,creation);
	top->age=age;
	prnt=top;
	while(prnt->next!=NULL){
		i++;
		prnt=prnt->next;
	}
	prnt=top;
	while(j<i){
		printf("%d-)\nname %s\nsurname %s\nmusic %s\nage %d\n",j+1,prnt->name,prnt->surname,prnt->musical_word,prnt->age);
		prnt=prnt->next;
		j++;
	}
}
void print_stack(struct person *ptr){
	int i=0;
	while(ptr->next!=NULL){
		i++;
		printf("\n\n%d-)\nname:%s\nsurname:%s\nmusic:%s\nage:%d\n\n",i,ptr->name,ptr->surname,ptr->musical_word,ptr->age );
		ptr=ptr->next;
	}
}
void deleteNode(){
	temp=top;
	top=top->next;
	free(temp);
	temp=NULL;
	print_stack(top);
}
void Sort_Increasingly(int size){
	int i=0,j=0,a=0,b=0,flag=0;
	struct person temporary;
	while(i<size){
		while(j<size-1){
			if(temp->age > temp->next->age){
				temporary.age=temp->age;
				strcpy(temporary.name,temp->name);
				strcpy(temporary.surname,temp->surname);
				strcpy(temporary.musical_word,temp->musical_word);
				temp->age=temp->next->age;
				strcpy(temp->name,temp->next->name);
				strcpy(temp->surname,temp->next->surname);
				strcpy(temp->musical_word,temp->next->musical_word);
				temp->next->age=temporary.age;
				strcpy(temp->next->name,temporary.name);
				strcpy(temp->next->surname,temporary.surname);
				strcpy(temp->next->musical_word,temporary.musical_word);
			}
			j++;
			temp=temp->next;
		}
		temp=top;
		j=0;
		i++;
	}
	print_stack(top);
}
void Sort_Alphabetically(int size){
	struct person temporary;
	int i=0,j=0,a=0,b=0,count=0;

	while(i<size){
		while(j<size-1){			
			while(temp->name[count]==temp->next->name[count]){
				count++;
			}
			if(temp->name[count]>temp->next->name[count]){ 
				temporary.age=temp->age;
				strcpy(temporary.name,temp->name);
				strcpy(temporary.surname,temp->surname);
				strcpy(temporary.musical_word,temp->musical_word);
				temp->age=temp->next->age;
				strcpy(temp->name,temp->next->name);
				strcpy(temp->surname,temp->next->surname);
				strcpy(temp->musical_word,temp->next->musical_word);
				temp->next->age=temporary.age;
				strcpy(temp->next->name,temporary.name);
				strcpy(temp->next->surname,temporary.surname);
				strcpy(temp->next->musical_word,temporary.musical_word);
			}
			j++;
			temp=temp->next;
			count=0;
		}
		temp=top;
		j=0;
		i++;
	}
	print_stack(top);
}
int main(){
	tail=malloc(sizeof(struct person));
	tail->next=NULL;
	char name[20],surname[20],creation[20];
	int age,choice,i=0;
	top=tail;

	do{
		menu();
		scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Enter a name\n");
			scanf(" %[^\n]s",name);
			printf("\nEnter a surname\n");
			scanf(" %[^\n]s",surname);
			printf("\nEnter a creation\n");
			scanf(" %[^\n]s",creation);
			printf("\nEnter a age\n");
			scanf("%d",&age);
			addNode(name,surname,creation,age);
			break;
		case 2:
			deleteNode();
			break;
		case 3:
		temp=top;
			while(temp->next!=NULL){
				i++;
				temp=temp->next;
			}
			temp=top;
			Sort_Alphabetically(i);
			i=0;
			break;
		case 4:
			temp=top;
			while(temp->next!=NULL){
				i++;
				temp=temp->next;
			}
			temp=top;
			Sort_Increasingly(i);
			i=0;
			break;	
		}

	}while(choice!=5);

	free(top);
	free(tail);
}