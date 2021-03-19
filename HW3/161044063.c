#include<stdio.h>
#define GRADES 10
#define NOTES 2



//part1 kısmında + boşluk 2 boşluk 3 enter veya + boşluk 2 enter şeklinde yaptım işlemleri,inputlar arası 1 boşluk işlem bitince enter şeklinde


// part2 functions 
int take_grades(int array[])
{	
	for (int i = 0; i < GRADES; i++)
	{
		scanf("%d",&array[i]);
	}
}
int take_exam_grades(int array[])
{	printf("Enter the midterm and final notes:\n");
		for (int i = 0; i < NOTES; i++)
	{
		scanf("%d",&array[i]);
	}
}
double calculate_homework(int array[]){
	double x;
	for (int i = 0; i < GRADES; i++)
	{
		x+=array[i];
	}
	x=x/(double)GRADES;
	printf("hw ort %lf\n", x);
	return x;
}
double calculate_lab(int array[]){
	double x;
	for (int i = 0; i < GRADES; i++)
	{
		x+=array[i];
	}
	x=x/(double)GRADES;
	printf("lab ort %lf\n", x);
	
	return x;
}
double calculate_all(int a,int array[],int b){
	double all;
	all=(a*0.2)+(b*0.1)+((0.3)*array[0])+((0.4)*array[1]);
	printf("Your Average =%lf",all );
	return all;
}
//--------------------------------part2 functions finished--------------------------------------------------

//--------------------------------part1 functions started---------------------------------------------------
int add(int num1,int num2){
	int x;
	x=num1+num2;

	return x;
}
int sub(int num1,int num2){
	int x;
	x=num1-num2;
	return x;
}
int multp(int num1,int num2){
	int x;
	x=num1*num2;
	return x;
}
int divi(int num1,int num2){
	int x;
	x=num1/num2;
	return x;
}
int mod(int num1,int num2){
	int x;
	if (num1<0)
	{
		while(num1<0){
			num1+=num2;
		}
	}
	x=num1%num2;
	return x;
}
int power(int num1,int num2){
	int x=1,i;
	if(num1==0)
		return 1;
	else{
	for(i=0;i<num2;i++){
		x*=num1;
	}
	return x;
	}
}
int doit(int (*f)(int,int),int num1,int num2){
	int x;
	x=(*f)(num1,num2);
	printf("\n%d\n",x);
	return x;
}
int char_to_integer(char *str){
	int x=0;
	sscanf(str,"%d",&x);
	return x;
}

void menu_for_calculator(){

	char islem[20];	
	char c;
	char b;
	int x,nums[2],num1,num2,current=0,count=0,bosluk_sayisi,last_result=0;
	

	printf("\n--------Menu for calculator------\n1-)Press + for adding\n2-)Press - for subraction\n3-)Press * for multiplication \n4-)Press / for division\n5-)Press %% for modula\n6-)Press ** for power\n7-)Press a/A for first menu\n");
	
	
	do{
		bosluk_sayisi=0;// Kaç tane sayı olduğunu bulmak için
		scanf(" %[^\t\n]s",islem);
		while(islem[count]!='\0'){
			if(islem[count]==' ')
			bosluk_sayisi++;
			count++;
			}
		count=0;
		c=islem[1];

	if (c=='*')
	{
		b='?';
		if (bosluk_sayisi<2)
		{
			num1=last_result;
			num2=char_to_integer(islem+3);			
		}
		else{
			num1=char_to_integer(islem+3);
			while(islem[current+3]!=' '){
				current++;			
			}
			num2=char_to_integer(islem+current+3);
			current=0;
		}
	}
	else{
		b=islem[0];
		if (bosluk_sayisi<2)
			{
				num1=last_result;
				num2=char_to_integer(islem+2);				
			}
		else{
			num1=char_to_integer(islem+2);
			while(islem[current+2]!=' '){
			current++;
			}
			num2=char_to_integer(islem+current+2);
			current=0;
			}
	}
	switch(b){
		case '*':
		last_result=doit(multp,num1,num2);
		break;
		case '/':
		last_result=doit(divi,num1,num2);
		break;
		case '+':
		last_result=doit(add,num1,num2);
		break;
		case '-':
		last_result=doit(sub,num1,num2);
		break;
		case '%':
		last_result=doit(mod,num1,num2);
		break;
		case '?':
		last_result=doit(power,num1,num2);
		break;
	}
	}
	while(b!='a' && b!='A');	
}
//-----------------------------part1 funtions finished------------------------------------------------------
//-----------------------------part3 function started-------------------------------------------------------
void show_diamond(){
	int h,size,i,j,k;
	printf("Enter a height\n");
	scanf("%d",&h);
	size=h;
		for (i = 1; i <= h;i++)
		{
			for(j=1;j<=(h-i);j++){
				printf(" ");
			}
			printf("/");
			for (k = 0; k < (i-1)*2; k++)
			{
				printf("*");
			}
			printf("\\");
			printf("\n");			
		}		
		for ( i = 0; i < h; i++)
		{
			for(j=0;j<i;j++){
				printf(" ");
			}
			printf("\\");
			for (k = 0; k <(size-1)*2 ; k++)
			{
				printf("*");
			}
			size-=1;
			printf("/");
			printf("\n");
		}
}
//----------------------------part3 function finished------------------------------------------------------	
//--------------------------------First Menu---------------------------------------------------------------
	void menu(){
		int lab_grades[10];
		int homeworks[10];
		int exams[2];
		int lab,hw,exm,choice;
		double average;
		do{
			printf("\n------MENU------\n1-)Simple Calculator\n2-)Grades Calculator\n3-)Diamond\n4-)Exit\n");
			scanf("%d",&choice);
		switch(choice){
			case 1:
				menu_for_calculator();
			break;
			case 2:
			printf("Enter lab grades:\n");
			take_grades(lab_grades);
			lab=calculate_lab(lab_grades);
			printf("Enter homeworks grades:\n");
			take_grades(homeworks);
			hw=calculate_homework(homeworks);
			exm=take_exam_grades(exams);
			average=calculate_all(lab,exams,hw);
			break;
			case 3:
			show_diamond();
			break;
			}
		}while(choice!=4);
		}	
int main(){
	menu();
}