#include<stdio.h>

//-----------------------------PART 1 STARTED-------------------------------------------------------------
int prime_num(int num){
	num++;
	int i=2;
	while(i<num){
		if(num%i==0){
			break;
		}
		i++;
	}
	if (i==num)
	{
	return num;
	}
	else{
		prime_num(num);
	}
}
int ebob(int num1,int num2,int pnum,int gcd){	
	while(pnum<=num1 && pnum<=num2){
		if(num1%pnum==0 && num2%pnum==0){
			gcd*=pnum;
			num1=num1/pnum;
			num2=num2/pnum;
			}
		else if(num1%pnum==0){
			num1=num1/pnum;
		}	
		else if(num2%pnum==0){
			num2=num2/pnum;
		}
		else{
			pnum=prime_num(pnum);
		}
		ebob(num1,num2,pnum,gcd);
	}
	return gcd;
}
//---------------------------------------PART 1 FINISHED-------------------------------------
//---------------------------------------PART 2 STARTED--------------------------------------
void parcala(int array[],int sol,int orta,int sag){
	int sayi1=0,sayi2=0,sayi3=sol,num1,num2;
	num2=sag-orta;
	num1=orta-sol+1;
	int sol_array[num1];
	int sag_array[num2];
	while(sayi1<num1){
		sol_array[sayi1]=array[sol+sayi1];
		sayi1++;
	}
	
	sayi1=0;
	while(sayi2<num2){
		sag_array[sayi2]=array[1+orta+sayi2];
		sayi2++;
	}
	sayi2=0;

	while( num2>sayi2 && num1>sayi1){
		if(sag_array[sayi2]>=sol_array[sayi1]){
			array[sayi3]=sol_array[sayi1]; sayi1++;
		}
		else{
		array[sayi3]=sag_array[sayi2]; sayi2++;
	}
	sayi3++;
}

	for(;sayi1<num1;sayi1++){
		array[sayi3]=sol_array[sayi1];
		sayi3++;
	}
	for(;sayi2<num2;sayi2++){
		array[sayi3]=sag_array[sayi2];
		sayi3++;
	}
}
void sorting_merge(int array[],int num1,int num2){
	int q;
	if(num2>num1){
		q=num1+(num2-1);
		q=q/2;
		
		sorting_merge(array,num1,q);
		sorting_merge(array,q+1,num2);
		parcala(array,num1,q,num2);
	}
}
void array_doldurma(int array[],int size,int adim){
	int q;
	if(adim<size){
		scanf("%d",&q);
		array[adim]=q;
		adim++;
		array_doldurma(array,size,adim);
	}

}
void bastir(int array[],int size,int i){

	if(i<size){
		printf("%d ",array[i]);
		i++;
		bastir(array,size,i);
	}

}
void array_olusturma(int size){
	int array[size];
	array_doldurma(array,size,0);
	sorting_merge(array,0,size-1);
	bastir(array,size,0);
}

//---------------------------------------PART 2 FINISHED-------------------------------------
//---------------------------------------PART 3 STARTED--------------------------------------
void formula(int n){
	printf("%d ",n );		
		if(n!=1){
			if(n%2==0){
				formula(n/2);
			}
			else{
				formula(3*n+1);
			}
		}
}

//---------------------------------------PART 3 FINISHED-------------------------------------
//---------------------------------------PART 4 STARTED--------------------------------------
int number_of_digit(int num1,int count){	
	num1=num1/10;
	if(num1==0){
		return count;
	}
	else{
		count++;
		number_of_digit(num1,count);
	}
}
int power(int num1,int N){
	if(N==0){
		return 1;
	}
	else{
		N--;
		return num1*power(num1,N);
	}
}
int sums(int num1,int N,int toplam){
int q;
 q=num1%10;
 if(num1!=0){
 	toplam=toplam+power(q,N);
 	sums(num1/10,N,toplam);
 }
 else{
 	return toplam;
 }
}
//---------------------------------------PART 4 FINISHED-------------------------------------
//---------------------------------------PART 5 STARTED--------------------------------------
int Capital(char a[20],int i){
	if (a[i]>=97)
	{
		i++;
		Capital(a,i);
	}
	else{
		return i;
	}	
}
//---------------------------------------PART 5 FINISHED-------------------------------------
int main(){

int num1,num2,gcd,choice,q,i,count=1,x,toplam=0;
char a[20];

	do{
		printf("\n-------MENU------\n1-)GCD\n2-)Merge Sorting\n3-)Formulas output\n4-)Equal or Not Equal\n5-)First Capital Letter\n6-)Exit\n");
		scanf("%d",&choice);
		switch(choice){
		  case 1:
			printf("Enter two number \n");
			scanf("%d %d",&num1,&num2);
			gcd=ebob(num1,num2,2,1);
			printf("\n The greatest common divided= %d",gcd);
			break;
		  case 2:
		  	printf("Enter size \n");
			scanf("%d",&num1);
			array_olusturma(num1);
			break;
		  case 3:
		    printf("Enter a num \n");
			scanf("%d",&num1);
			formula(num1);
			break;
		  case 4:
			printf("Enter num\n");
			scanf("%d",&num1);
			i=number_of_digit(num1,count);
			x=sums(num1,i,toplam);
			if(x==num1){
			printf("\nEQUAL");
			}
			else
			printf("NOT EQUAL");
			break;
		  case 5:
			printf("enter a string(max 20 letters)\n");
			scanf("%s",a);
			q=Capital(a,0);
			printf("\nThe first capital letter is %c",a[q]);
			break;
		  case 6:
		  	break;	
		default:
			printf("Wrong Choice\n");
			break;	
	}
}while(choice!=6);


}