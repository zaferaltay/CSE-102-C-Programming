#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define Square 1
#define Rectangular 2
#define Circular 3
#define PI 3
#define Red 0
#define Yellow 1
#define Blue 2
#define Black 3
#define White 4


double CreateBody(int shape){

  double num1,num2;
	if (shape==1)
	{
	  printf("Enter the edge \n");
	  scanf("%lf",&num1);	
	   return num1*num1;	
		}
	   		else if (shape==2)
	   		{
	   		  printf("Enter the edges \n");
	   		  scanf("%lf%lf",&num1,&num2);
	   	 	   return num1*num2;
	   			}
	   				else if (shape==3)
	   				{
	   				   printf("Enter the radius \n");
	   				   scanf("%lf",&num1);
	   				    return PI*num1*num1;
	   					}

								}
	

	int SetColor(int color){
		if (0<=color || color<=1000)
		 {
		  return color%5;
		   }
			else
			{
			 	return 1;
			     }

						}

		double LoadMoves(int shape,double size_of_body){

			int move;
				if (shape==1)
				{
					move=sqrt(size_of_body);
					return 4*move;
					 }
					   else if (shape==2)
					   {
					   	  move=size_of_body/5;
					  	  return 2*(move+5);
					    	 }
					      	  else if (shape==3)
					      	  {
					      		
					      		move=sqrt(size_of_body/PI);
					      		return 2*PI*move;
					         	  }
									
										}	

			int SetAttackPower(int lower_bound,int upper_bound){

				srand(time(NULL));
				 int power;
				  power=lower_bound+rand()%(upper_bound-lower_bound);
				   return power;
					
					 	}


				void ShowPokemon(int shape,double body_size,int color,double move_length,int attack_power){

				  int edge,i,j,r,ii=0,q=1;
					if (shape==1)
					{
					  edge=sqrt(body_size);
					  for (i = 0; i < edge;i++)
					  	{
					  	  for (j = 0; j < edge;j++)
					  	  {
					  		printf("x");
					  	    }
					  		 printf("\n");
					  	      }	

					  	      printf("NAME:Square Pokemon\n");
								 }
								 else if (shape==2)
					 			  {
					 				edge=body_size/5;
					 				for (i = 0; i < 5;i++)
					 				 {
					 					for (j = 0; j < edge;j++)
					 					 {
					 					   printf("x");
					 					   }
					 					    printf("\n");
					 						  }

					 						  printf("NAME: Rectangular Pokemon\n");
					 			  				}
					 			  				else if (shape==3)
					 			  				 {
					 			  				   
					 			  				   r=sqrt(body_size/PI);

					 			  				   if (r%2==1)// yarıçap tek ise
					 			  				   {
					 			  				   	if (r==1)
					 			  				   	{
					 			  				   		printf("x\n");
					 			  				   	}
					 			  				   	else{
					 			  				   	 for (i = 0; i < (r-1)/2; i++) //ilk satırda ki tek x li kısım
					 			  				   	 {
					 			  				   	 	printf("\t");
					 			  				   	 }
					 			  				   	 	printf("x\n"); // tek x 
					 			  				   	 	
					 			  				   	 	for (int j = 1; j < (r/2)+1; j++) //çapa kadar çift x li üst kısım satır sayısı
					 			  				   	 	{					 			  				   	 							 			  				   	 	
					 			  				   	 	 for ( i = 0; i <(((r-1)/2)-j); i++)
					 			  				   	 	{
					 			  				   	 		printf("\t");
					 			  				   	 	}	
					 			  				   	 		printf("x");
					 			  				   	 		ii=ii+2;
					 			  				   	 		for ( i = 0; i < ii; i++)//iç boşluk basma
					 			  				   	 		{
					 			  				   	 			printf("\t");
					 			  				   	 		}
					 			  				   	 		printf("x\n");
					 			  				   	 		
					 			  				   	 	}	//bitiş çap

					 			  				   	 	for (j = (r/2)-1; 0<j ; j--)//çapın altı tek x e kadar satır
					 			  				   	 	{	
					 			  				   	 		i=0;
					 			  				   	 		while(i<q){
					 			  				   	 			printf("\t");
					 			  				   	 			i++;
					 			  				   	 		}
					 			  				   	 		q++;
					 			  				   	 		printf("x");
					 			  				   	 		ii-=2;
					 			  				   	 		for ( i = 0; i < ii; i++)//iç boşluk basma
					 			  				   	 		{
					 			  				   	 			printf("\t");
					 			  				   	 		}
					 			  				   	 		printf("x\n");					 			  				   	 		
					 			  				   	 	}
					 			  				   	 	for (i = 0; i < (r-1)/2; i++) //son satırda ki tek x li kısım
					 			  				   	 {
					 			  				   	 	printf("\t");
					 			  				   	 }
					 			  				   	 	printf("x\n"); // tek x 
					 			  				   	 }
					 			  					}
					 			  					else if (r%2==0)//çap tek ise
					 			  					{
					 			  						for (i = 0; i < (r-1)/2; i++) //ilk satırda ki tek x li kısım
					 			  				   	 {
					 			  				   	 	printf("\t");
					 			  				   	 }
					 			  				   	 	printf("    ");
					 			  				   	 	printf("x\n"); // tek x 
					 			  				   	 	
					 			  				   	 	ii=1;
					 			  				   	 	for (int j = 0; j < (r/2); j++) //çapa kadar x li üst kısım satır sayısı
					 			  				   	 	{					 			  				   	 	
					 			  				   	 	 for ( i = 0; i <(((r-1)/2)-j); i++)
					 			  				   	 	{
					 			  				   	 		printf("\t");
					 			  				   	 	}	
					 			  				   	 		printf("x");					 			  				   	 		
					 			  				   	 		for ( i = 0; i < ii; i++)//iç boşluk basma
					 			  				   	 		{
					 			  				   	 			printf("\t");
					 			  				   	 		}
					 			  				   	 		printf("x\n");
					 			  				   	 		ii+=2;
					 			  				   	 	}	//bitiş çap
					 			  				   	 		ii-=2;
					 			  				   	 	for (j = (r/2)-1; 0<j ; j--)//çapın altı tek x e kadar satır
					 			  				   	 	{	
					 			  				   	 		i=0;
					 			  				   	 		while(i<q){
					 			  				   	 			printf("\t");
					 			  				   	 			i++;
					 			  				   	 		}
					 			  				   	 		q++;
					 			  				   	 		printf("x");
					 			  				   	 		ii-=2;
					 			  				   	 		for ( i = 0; i < ii; i++)//iç boşluk basma
					 			  				   	 		{
					 			  				   	 			printf("\t");
					 			  				   	 		}
					 			  				   	 		printf("x\n");					 			  				   	 		
					 			  				   	 	}
					 			  				   	 	for (i = 0; i < (r-1)/2; i++) //son satırda ki tek x li kısım
					 			  				   	 {
					 			  				   	 	printf("\t");
					 			  				   	 }
					 			  				   	 	printf("    ");
					 			  				   	 	printf("x\n"); // tek x 
					 			  					}
					 			  					printf("NAME: Circular Pokemon\n");
					 			  				}
				
							  printf("Size:%lf \n",body_size );
					  	      if (color==0)
					  	      {
					  	      	printf("Color: Red \n");
					  	       }
					  	       else if (color==1)
					  	       {
					  	       	printf("Color: Yellow \n");
					  	       }
					  	       else if (color==2)
					  	       {
					  	       	printf("Color: Blue \n");
					  	       }
					  	       else if (color==3)
					  	       {
					  	       	printf("Color: Black \n");
					  	       }
					  	       else if (color==4)
					  	       {
					  	       	printf("Color: White \n");
					  	       }
					  	       printf("Move:%lf \n",move_length );
					  	       printf("Attack Power: %d \n",attack_power );
					  	   }
int main ()
{
int shape, color, attack_power;
double size_of_body, move_length;
shape = Circular; // Pick one of them
size_of_body = CreateBody (shape);
color = 798;
color = SetColor(color);
move_length = LoadMoves(shape, size_of_body);
attack_power = SetAttackPower (0, 150);
ShowPokemon(shape, size_of_body, color, move_length, attack_power);
}
