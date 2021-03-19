#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define t 10
#define min_number 1
#define max_number 1024



void draw_hourglass(int height){

	int i=0,j=0,k,x,l;
	x=height;
	for (int i = 0; i < (height+1)/2; i++)
	{
		for ( j = 0; j < i; j++)
		{
			printf(" ");
		}
		for ( k = 0; k < x; k++)
		{
			printf("*");

		}
		x-=2;
		printf("\n");
	}
	x+=4;
	j-=1;
	  for (i = 0; i < height/2;i++)
	   {
		for ( k = 0; k < j; k++)
		 {
		   printf(" ");

			}
			j-=1;
			for (l = 0; l < x; l++)
			 {
			   printf("*");
				}
				x+=2;
				  printf("\n");
	    }

    }
    int distance(int guess_number,int lucky_number){
    	int x;
    	if (lucky_number>guess_number)
    		x=lucky_number-guess_number;
    	else if(lucky_number<=guess_number)
    		x=guess_number-lucky_number;
    	
    	if (x>=512 && x<=1024)
    		return 10;
    	else if (x>=256 && x<= 511)
    		return 9;
    	else if(x>=128 && x<=255)
    		return 8;
    	else if(x>=64 && x<=127)
    		return 7;
    	else if(x>=32 && x<= 63)
    		return 6;
    	else if(x>=16 && x<= 31)
    		return 5;
    	else if(x>=8 && x<=15)
    		return 4;
    	else if(x>=4 && x<=7)
    		return 3;
    	else if(x>=2 && x<=3)
    		return 2;
    	else if(x==1)
    		return 1;
    	else if(x==0)
    		return 0;
    	

    }
    

    int make_a_guess(int trial,int min,int max,int *score_human, int *score_program){
    	int i,guess,lucky_number;
    	lucky_number=rand()%1024+1;
    		for (i = 0; i < trial; i++)
    		{
    			printf("\n(%d.Trial) Make a guess between %d and %d \n",(i+1),min,max );
    			scanf("%d",&guess);
    			printf("\nDistance: %d",distance(guess,lucky_number));
    				if (guess<lucky_number)
    					min=guess;
    				else if(guess>lucky_number)
    					max=guess;
    				else if(guess==lucky_number){
    					printf("\nYou Win \n");
    					break;
    					}
    				}
    			if (i<trial)
    				*score_human=*score_human+1;
    				
    			else if(i==trial){
    				printf("\nProgram Win\n");
    				*score_program=*score_program+1;
    			}
    		return guess;
    		}


    	void show_scores(int score_human,int score_program){
    		printf("Your score : %d Program Score : %d",score_human,score_program);
    	}
    	void draw_mountain_road(int lenght,int max_radius){
    		int i,rad,j,k,l,m,p;
    		char a='/';
    		char b='|';
    		char c='\\';
    		char d=' ';
    		for (m = 0; m < lenght; m++)
    		{
    			rad=rand()%max_radius;
    			l=max_radius;    			    				
    				if (m%2==1)
    				{ 
    				 if (rad==0)
    					{
    				  for (i = 0; i < max_radius; i++)
    				  {
    					printf("%c",d );
    				  }
    				 printf("%c",b );
    				 printf("\n");
    					}
    					else{ 
    				j=0; 				
    				for (int i = 0; i < rad; i++) // sağa gidiş 
    				{
    						for (k = 0; k < max_radius; k++)
  	   				          {
    					         printf("%c",d);
    				           }
    					for (j = 0; j < i; j++)
    					{
    						printf("%c",d);
    					}
    					printf("%c",c);
    					printf("\n");
    				}
    				for (k = 0; k < max_radius; k++) //   İlk dik çizgi
  	   				   {
    			         printf("%c",d);
    		           }
    		           for (int i = 0; i <=j; i++)
    		           {
    		           	printf("%c",d );
    		           }
    		           printf("%c",b );
    		           printf("\n");
    		           for (int i = 0; i < rad; i++)// geri dönüş
    		           {
    		           	for (k = 0; k < max_radius; k++) 
  	   				   {
    			         printf("%c",d);
    		           }
    		           	for (int i = 0; i < j; i++)
    		           	{
    		           		printf("%c",d );
    		           	}
    		           	printf("%c",a);
    		           	printf("\n");
    		           	j--;
    		           } 
    		           }   				
    		}//if
    		else
    		{
    			j=0;
    			for ( i = 0; i < rad; i++)   //sola ilk geliş
    			{
    				for (j = 1; j < (l-i); j++)
    				{
    					printf("%c",d);
    				}
    				printf("%c",a );
    				printf("\n");   				
    			}
    			if (rad==0)
    			{
    				for (i = 0; i < max_radius; i++)
    				{
    					printf("%c",d );
    				}
    				printf("%c",b );
    				printf("\n");
    			}
    			else{
    			for (i = 1; i < (j-1); i++)
    			{
    				printf("%c", d);
    			}
    			printf("%c", b);
    			printf("\n");
    			for (i = 0; i < rad; i++)
    			{
    				for (p = 0; p <(j-1); p++)
    				{
    					printf("%c", d);
    				}
    				j++;
    				printf("%c",c );
    				printf("\n");
    			}
    		}    				
    		}    		
    	}//lenght
    }//fonk bitiş 

void menu(){

	int secim,height,score,lenght,max_radius;
	int score_human=0,score_program=0;
	int *p1;
	int *p2;
	p1=&score_human;
	p2=&score_program;
	do{
	printf("\n------MENU-------\n");
	printf("1.Play Lucky Number\n2.Draw Hourglass\n3.Draw Mountain Road\n4.Exit");
	printf("\n Secim yapin ");
	scanf("%d",&secim);

	switch(secim){
		case 1: 
		score=make_a_guess(t,min_number,max_number,p1,p2);
		
		show_scores(score_human,score_program);		
		break;
		case 2: printf("Height Girin");
		scanf("%d",&height);
		while(height%2==0){
			printf("\nPlease enter a odd number\n");
			scanf("%d",&height);
		}
		draw_hourglass(height);
		break;
		case 3: 
		printf("Please enter the lenght\n");
		scanf("%d",&lenght);
		printf("Please enter the maximum radius\n");
		scanf("%d",&max_radius);
		draw_mountain_road(lenght,max_radius);
		break;
		case 4: printf("\n Programdan çıkılıyor");
		break;
		default:printf("\n This is an invalid choice.Try Again\n");
	}
}while(secim!=4);

}

int main()
{
	srand(time(NULL));
	menu();
	return 0;
}