#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define NUM 10

typedef enum  {Charmander,Pikachu,Squirtle,Bulbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby} pokemon;
typedef enum  {quadratic,linear} attack_type;

void menu(char Pokemon_name[10][11],pokemon Pokemons[],pokemon *My_Pokemons);
int str_comp(char Pokemon_name[10][11],char poke[]);
void pokemon_print(char Pokemon_name[10][11],int range[],attack_type type[],int attack_power[],int stamina[],int index);
void pokedex(char Pokemon_name[10][11],int range[],attack_type type[],int attack_power[],int stamina[]);
int count_pokemon(pokemon array[]);
void show_pokemons(char Pokemon_name[10][11],pokemon Pokemons[],int Pokemon_count);
void catch_a_pokemon(char Pokemon_name[10][11],pokemon Pokemons[],pokemon *my_pocket);
void release_a_pokemon(char Pokemon_name[10][11],pokemon Pokemons[],pokemon *my_pocket);
void oaks_laboratory(char Pokemon_name[10][11],pokemon Pokemons[],pokemon *My_Pokemons);
void battle(char Pokemon_name[10][11],int range[],attack_type type[],int stamina[],int attack_power[],pokemon user_Pokemons[]);
int yerlestirme(int area[8][8],int x,int y,int stamina);
void print_pokemon_in_area(char Pokemon_name[10][11],int x);
void show_area(char Pokemon_name[10][11],int area[8][8],int pokemon_staminas[2][4]);
void stamina_reld(int area[8][8],int pokemon_staminas[2][4],int stamina[]);
int kalan_stamina(int pokemon_staminas[2][4]);

int main()
{
	char Pokemon_name[10][11]={"Charmander","Pikachu","Squirtle","Bulbasaur","Pidgeotto","Ratata","Mug","Caterpie","Zubat","Krabby"};
	
	
	pokemon Pokemons[10]={Charmander,Pikachu,Squirtle,Bulbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby};
	pokemon My_Pokemons[4];
	My_Pokemons[0]=10;
	menu(Pokemon_name,Pokemons,My_Pokemons);
	srand(time(NULL));
	
	return 0;
}
//----------------------------Part1 Started---------------------------------------------------------------------------------
int str_comp(char Pokemon_name[10][11],char poke[]){ // Kullanıcnın girdiği pokemonun kaçıncı indiste olduğunu bulmak için "PART 1"
	int i=0,j=0;
	char aa[]="Exit";
	
		while(aa[i]==poke[i]){
			i++;
			if(i==4){
				return 15;
			}
		}
		for ( i = 0; i < NUM; i++)
	{
		while(Pokemon_name[i][j]==poke[j]){
			j++;
			if (Pokemon_name[i][j]=='\0')
			{
				return i;
			}

		}
		j=0;		
	}
}
		void pokemon_print(char Pokemon_name[10][11],int range[],attack_type type[],int attack_power[],int stamina[],int index){// part1 pokemon özelliklerini ekrana basma fonksiyonu
			int j=0;
			printf("\nName:");
			while(Pokemon_name[index][j]!='\0'){
				printf("%c",Pokemon_name[index][j] );
				j++;
			}
			printf("\nA.Type:");
			j=type[index];
			switch(j){
				case 0:
				printf("Quadratic\n");
				break;
				case 1:
				printf("Linear\n");
				break;
			}
			printf("Range: %d block\n",range[index]);
			printf("A.Power: %d \n",attack_power[index] );
			printf("Stamina: %d \n",stamina[index] );
		}


void pokedex(char Pokemon_name[10][11],int range[],attack_type type[],int attack_power[],int stamina[]){
	int i=0,j=0;
	char poke[10];
	
	do{
	printf("\nPlease type name of pokemon(Exit for close pokedex)\n");
	scanf("%s",poke);
	i=str_comp(Pokemon_name,poke);
	if(i!=15)
	pokemon_print(Pokemon_name,range,type,attack_power,stamina,i);
	}while(i<15);
	
	
	}
//------------------------Part1 Finished---------------------------------------------------------------------------------

//------------------------Part2 Started----------------------------------------------------------------------------------
	int count_pokemon(pokemon array[]){
		int i=0;
		while(array[i]!=10){
			i++;
		}
		return i;
	}

	void show_pokemons(char Pokemon_name[10][11],pokemon Pokemons[],int Pokemon_count){
		int j=0,x;
		for (int i = 0; i < Pokemon_count; i++)
		{	
			x=Pokemons[i];
			printf("%d-",x);
			while(Pokemon_name[x][j]!='\0'){
				printf("%c",Pokemon_name[x][j]);
				j++;
			}
			j=0;
			printf("\n");
		}
			}
		void catch_a_pokemon(char Pokemon_name[10][11],pokemon Pokemons[],pokemon *my_pocket){
			int i=0,j=0,k=0;
			
			k=count_pokemon(my_pocket);
			if(k<4){
			printf("%d pokemon you have \n",k );
			printf("Enter a pokemon number\n");
			scanf("%d",&i);

			*(my_pocket+k)=Pokemons[i];
			k++;
			*(my_pocket+k)=10;
		}
		else
			printf("You have max Pokemon\n");
		}

		void release_a_pokemon(char Pokemon_name[10][11],pokemon Pokemons[],pokemon *my_pocket){
			int i,j=0,k;
			i=count_pokemon(my_pocket);
			show_pokemons(Pokemon_name,my_pocket,i);
			
			printf("Enter a pokemon number \n");
			scanf("%d",&k);
			
			while(my_pocket[j]!=k){
				j++;
			}
			my_pocket[j]=10;
			k=0;
			while(k<(i-1)){
				if (my_pocket[k]==10)
				{
					my_pocket[k]=my_pocket[k+1];
					my_pocket[k+1]=10;
				}
				k++;
			}

		}
	
	void oaks_laboratory(char Pokemon_name[10][11],pokemon Pokemons[],pokemon *My_Pokemons){
		
		int Pokemon_count=10,choice,p;
		p=count_pokemon(My_Pokemons);
		
		//my_pocket[0]=10;
		do{
		printf("\nWelcome to laboratory of Professor Oak.How Can I Help You ? \n1-)Show Pokemons\n2-)Catch a Pokemon \n3-)Release a pokemon \n4-)Show my pocket \n5-)Back");
		printf("\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			printf("\n");
			show_pokemons(Pokemon_name,Pokemons,Pokemon_count);
			break;
			case 2:
			show_pokemons(Pokemon_name,Pokemons,Pokemon_count);			
			catch_a_pokemon(Pokemon_name,Pokemons,My_Pokemons);
			break;
			case 3:
			release_a_pokemon(Pokemon_name,Pokemons,My_Pokemons);
			break;
			case 4:
			show_pokemons(Pokemon_name,My_Pokemons,count_pokemon(My_Pokemons));
			break;
			case 5:
			menu(Pokemon_name,Pokemons,My_Pokemons);
			break;
		}

	}while(choice!=7);
}

//------------------------Part2 Finished---------------------------------------------------------------------------------	
//------------------------Part3 Started ---------------------------------------------------------------------------------
int yerlestirme(int area[8][8],int x,int y,int stamina){
	if(area[x][y]==0){
	area[x][y]=stamina;
	return 1;
	}
	else{
		return 0;
	}

}
void battle(char Pokemon_name[10][11],int range[],attack_type type[],int stamina[],int attack_power[],pokemon user_Pokemons[]){
	int area[8][8]={0},count=0,x=0,y=0,z=0,l=0,j,count2=0,i=0,count3=0,count4=0,flag=1,num1=0,num2=0,pokemon_staminas[2][4]={0},xc=0,xx=0,num3=0,sxc=0,ap=0,nsxc=0;
	
	
	int pc_poke[4]={0};
	count=count_pokemon(user_Pokemons);
	while(i<count)
	{	
		show_pokemons(Pokemon_name,user_Pokemons,count);
		printf("\nEnter the pokemon number\n");
		scanf("%d",&z);
		printf("\nEnter coordinates x(0-1) and y(0-7) (first x please)\n");
		scanf("%d %d",&x,&y);
		flag=yerlestirme(area,x,y,(z+1));
		if (flag==1)
		{
			printf("\nIt's Done.\n");
			i++;
		}
		else{
			printf("\nThe area is not available.Please again\n");
		}
		
	}
i=0;
	while(count2<4){  // random atama pokemonları
		z=rand()%9+1;

		while(z!=pc_poke[i] && i<4){
			count4++;
			i++;
			
			}
			if (count4==4)
			{
				
		
			pc_poke[l]=z;
		for (i = 0; i <count ; i++)
		{
			if(z!=(user_Pokemons[i]+1) ){
				count3++;
			}
		}
		if (count3==count)
		{
			x=rand()%2+6;
			y=rand()%7;
			flag=yerlestirme(area,x,y,z);
			if(flag==1){
				count2++;
			l++;
			}
		}
		
			}
		count3=0;
		count4=0;
		i=0;
	}

	if (area[0][0]>10)
	{
		area[0][0]=0;
	}
	num1=0,num2=0,i=0,j=0;

	while(num1<8){
		while(num2<8){
			if (area[num1][num2]!=0)
			{
				x=area[num1][num2];
				pokemon_staminas[i][j]=stamina[x-1];
				j++;
				if (j==4)
				{
					i++;
					j=0;
				}
			}
			num2++;
		}
		num2=0;
		num1++;
	}
	
//---------------The Tournoument--------------------------------------
		show_area(Pokemon_name,area,pokemon_staminas);
		i=0,j=0;
//switch fonksiyon yap,staminas saydır 1 olana kadar,atak yaptır
		do{
			show_pokemons(Pokemon_name,user_Pokemons,count_pokemon(user_Pokemons));
			printf("\nEnter the pokemon number\n");
			scanf("%d",&num1);
			printf("Enter the distance(0 or 1 or 2)\n");
			scanf("%d",&num2);
			printf("Pick the way(1-2-3-4-6-7-8-9)\n");
			scanf("%d",&num3);

			switch(num3){
				case 1:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
						 i++;
						 j--;
						}
						else if (num2==0)
						{
							
						}
						else{
							i=i+2;
							j=j-2;
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
						
				break;
				case 2:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
						 i++;
						 
						}
						else if (num2==0)
						{
							
						}
						else{
							i=i+2;
						
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
										

				break;
				case 3:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
						 i++;
						 j++;
						}
						else if (num2==0)
						{
							
						}
						else{
							i=i+2;
							j=j+2;
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
						
						break;
						case 4:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
						
						 j--;
						}
						else if (num2==0)
						{
							
						}
						else{
						
							j=j-2;
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
						
						break;
						case 6:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
						 
						 j++;
						}
						else if (num2==0)
						{
							
						}
						else{
							
							j=j+2;
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
					//	show_area(Pokemon_name,area,pokemon_staminas);
						
						break;
						case 7:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
						 i--;
						 j--;
						}
						else if (num2==0)
						{
							
						}
						else{
							i=i-2;
							j=j-2;
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
												
						break;
						case 8:
						while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
						 i--;
						 
						}
						else if (num2==0)
						{
							
						}
						else{
							i=i-2;
							
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
						
						break;
						case 9:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
						 i--;
						 j++;
						}
						else if (num2==0)
						{
							
						}
						else{
							i=i-2;
							j=j+2;
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
						
						break;																		
			}
			count=1;
				while(count<=range[num1]){
					if (type[num1]==quadratic)
					{	

						if (area[i+count][j-count]!=0 && i+count<8 && j-count<8)
						{
							
						xc=area[i+count][j-count];
						xc--;
						sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
						if (stamina[xc]<=0)
						{
							area[i+count][j-count]=0;
						}
						stamina_reld(area,pokemon_staminas,stamina);
						}
						if (area[i+count][j+count]!=0 && i+count<8 && j+count<8)
						{
							xc=area[i+count][j+count];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
							if (stamina[xc]<=0)
							{
								area[i+count][j+count]=0;							
							}							
							stamina_reld(area,pokemon_staminas,stamina);
						}
						if (area[i-count][j+count]!=0 && i-count<8 && j+count<8)
						{
							xc=area[i-count][j+count];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
							if (stamina[xc]<=0)
							{
								area[i-count][j+count]=0;
							}
							stamina_reld(area,pokemon_staminas,stamina);

						}
						if (area[i-count][j-count]!=0 && i-count<8 && j-count<8)
						{
							xc=area[i-count][j-count];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
							if (stamina[xc]<=0)
							{
								area[i-count][j-count]=0;
							}
							stamina_reld(area,pokemon_staminas,stamina);
						}
					}
					else{
						if (area[i+count][j]!=0 && i+count<8 && j<8)
						{
							xc=area[i+count][j];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
							if (stamina[xc]<0)
							{
								area[i+count][j]=0;
							}
							stamina_reld(area,pokemon_staminas,stamina);
						}
						if (area[i][j+count]!=0 && i<8 && j+count<8)
						{
							xc=area[i][j+count];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;

							if (stamina<=0)
							{
								area[i][j+count]=0;
							}
							stamina_reld(area,pokemon_staminas,stamina);
						}
						if (area[i-count][j]!=0 && i-count<8 && j<8)
						{
							xc=area[i-count][j];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
							if (stamina[xc]<=0)
							{
								area[i-count][j]=0;
							}
							stamina_reld(area,pokemon_staminas,stamina);

						}
						if (area[i][j-count]!=0 && i<8 && j-count<8)
						{
							xc=area[i][j-count];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
							if (stamina[xc]<=0)
							{
								area[i][j-count]=0;
							}
							stamina_reld(area,pokemon_staminas,stamina);
						}
					}
				count++;
				
				}
				show_area(Pokemon_name,area,pokemon_staminas);
				count=1;
				i=0;
				j=0;

				xx=kalan_stamina(pokemon_staminas);

//------------------Bilgisayarın sırası---------------
				flag=1;
				i=0;
				j=0;
			while(flag==1){
				num1=rand()%9+1;
				while(i<4){
				if (num1!=pc_poke[i])
				{
					j++;
					
				}

					i++;
				}
				if (j<4)
				{
					flag=0;
				}
				else{
					i=0;
					j=0;
				}

				}
				i=0;
				j=0;
				
			
			num2=rand()%2;
			num3=rand()%8+1;
			printf("\n pc select  %d move \n",num2);
			if (num3==5)
			{
				num3++;
			}

			switch(num3){
				case 1:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							if((i+1)<8)
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
						if((i+1)<8)
						 i++;
						if((j-1)>0)
						 j--;
						}
						else if (num2==0)
						{
							
						}
						else {
							if ((i+2)<8)							
							i=i+2;
							if ((j-2)>0)
							j=j-2;
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
						
				break;
				case 2:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
							if((i+1)<8)
						 i++;
						 
						}
						else if (num2==0)
						{
							
						}
						else{
							if((i+2)<8)
							i=i+2;
						
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
										

				break;
				case 3:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
							if((i+1)<8)
						 i++;
						if((j+1)<8)
						 j++;
						}
						else if (num2==0)
						{
							
						}
						else{
							if((i+2)<8)
							i=i+2;
							if((j+2)<8)
							j=j+2;
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
						
						break;
						case 4:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
						if((j-1)>0)
						 j--;
						}
						else if (num2==0)
						{
							
						}
						else{
							if((j-2)>0)
							j=j-2;
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
						
						break;
						case 6:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
						 if((j+1)<8)
						 j++;
						}
						else if (num2==0)
						{
							
						}
						else{
							if((j+2)<8)
							j=j+2;
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
					//	show_area(Pokemon_name,area,pokemon_staminas);
						
						break;
						case 7:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
							if((i-1)>0)
						 i--;
						if((j-1)>0)
						 j--;
						}
						else if (num2==0)
						{
							
						}
						else{
							if ((i-2)>0)
							i=i-2;
						if((j-2)>0)
							j=j-2;
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
												
						break;
						case 8:
						while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
							if((i-1)>0)
						 i--;
						 
						}
						else if (num2==0)
						{
							
						}
						else{
							if((i-2)>0)
							i=i-2;
							
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
						
						break;
						case 9:
					while(area[i][j]!=(num1+1)){
						j++;
						if (j==8)
						{
							i++;
							j=0;
						}
					}
						area[i][j]=0;
						if (num2==1)
						{
							if((i-1)>0)
						 i--;
						if((j+1)<8)
						 j++;
						}
						else if (num2==0)
						{
							
						}
						else{
							if((i-2)>0)
							i=i-2;
						if ((j+2)<8)
						
							
						
							j=j+2;
						}
						area[i][j]=num1+1;
						stamina_reld(area,pokemon_staminas,stamina);
						//show_area(Pokemon_name,area,pokemon_staminas);
						
						break;																		
			}
			count=1;
				while(count<=range[num1]){
					if (type[num1]==quadratic)
					{	

						if (area[i+count][j-count]!=0 && i+count<8 && j-count<8)
						{
							
						xc=area[i+count][j-count];
						xc--;
						sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
						if (stamina[xc]<=0)
						{
							area[i+count][j-count]=0;
						}
						stamina_reld(area,pokemon_staminas,stamina);
						}
						if (area[i+count][j+count]!=0 && i+count<8 && j+count<8)
						{
							xc=area[i+count][j+count];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
							if (stamina[xc]<=0)
							{
								area[i+count][j+count]=0;							
							}							
							stamina_reld(area,pokemon_staminas,stamina);
						}
						if (area[i-count][j+count]!=0 && i-count<8 && j+count<8)
						{
							xc=area[i-count][j+count];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
							if (stamina[xc]<=0)
							{
								area[i-count][j+count]=0;
							}
							stamina_reld(area,pokemon_staminas,stamina);

						}
						if (area[i-count][j-count]!=0 && i-count<8 && j-count<8)
						{
							xc=area[i-count][j-count];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
							if (stamina[xc]<=0)
							{
								area[i-count][j-count]=0;
							}
							stamina_reld(area,pokemon_staminas,stamina);
						}
					}
					else{
						if (area[i+count][j]!=0 && i+count<8 && j<8)
						{
							xc=area[i+count][j];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
							if (stamina[xc]<0)
							{
								area[i+count][j]=0;
							}
							stamina_reld(area,pokemon_staminas,stamina);
						}
						if (area[i][j+count]!=0 && i<8 && j+count<8)
						{
							xc=area[i][j+count];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;

							if (stamina<=0)
							{
								area[i][j+count]=0;
							}
							stamina_reld(area,pokemon_staminas,stamina);
						}
						if (area[i-count][j]!=0 && i-count<8 && j<8)
						{
							xc=area[i-count][j];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
							if (stamina[xc]<=0)
							{
								area[i-count][j]=0;
							}
							stamina_reld(area,pokemon_staminas,stamina);

						}
						if (area[i][j-count]!=0 && i<8 && j-count<8)
						{
							xc=area[i][j-count];
							xc--;
							sxc=stamina[xc];
						ap=attack_power[num1];
						nsxc=sxc-ap;
						stamina[xc]=nsxc;
							if (stamina[xc]<=0)
							{
								area[i][j-count]=0;
							}
							stamina_reld(area,pokemon_staminas,stamina);
						}
					}
				count++;
				
				}
				show_area(Pokemon_name,area,pokemon_staminas);
				count=1;
				i=0;
				j=0;

				xx=kalan_stamina(pokemon_staminas);

		}while(xx!=1);

}
int kalan_stamina(int pokemon_staminas[2][4]){
	int i,j,x=0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (pokemon_staminas[i][j]>0)
			{
				x++;
			}
		}
	}
	return x;
}
void stamina_reld(int area[8][8],int pokemon_staminas[2][4],int stamina[]){
	int num1=0,num2=0,i=0,j=0,x=0;

	while(num1<8){
		while(num2<8){
			if (area[num1][num2]!=0)
			{
				x=area[num1][num2];
				pokemon_staminas[i][j]=stamina[x-1];
				j++;
				if (j==4)
				{
					i++;
					j=0;
				}
			}
			num2++;
		}
		num2=0;
		num1++;
	}

}
void print_pokemon_in_area(char Pokemon_name[10][11],int x){
	int i=0;
	while(i<3){
		printf("%c",Pokemon_name[x][i]);
		i++;
	}
}
void show_area(char Pokemon_name[10][11],int area[8][8],int pokemon_staminas[2][4]){
	int i=0,j=0,x,k=0,q=0,a,f=0,g=0;

	while(k<8){
		printf("----------------------------------------------------------\n");
		while(i<8){
			printf("|");
			if (area[k][i]!=0)
			{
				x=area[k][i];
				printf("  ");
				print_pokemon_in_area(Pokemon_name,(x-1));
				printf(" ");
			}
			else{
				printf("      ");
			}
			i++;
		}
		printf("|");
		printf("\n");
		i=0;

		while(q<8){
			printf("|");
			if (area[k][q]!=0)
			{	
				if (pokemon_staminas[f][g]>=1000)
				{
					/* code */
				printf("(%d)",pokemon_staminas[f][g]);
				}
				else if(pokemon_staminas[f][g]>=100)
					printf("(%d )",pokemon_staminas[f][g]);
				else if(pokemon_staminas[f][g]>=0)
					printf("(%d  )",pokemon_staminas[f][g]);
				g++;
				if (g==4)
				{
					g=0;
					f++;
				}
				
			}
			else{
				printf("      ");
			}
			q++;
		}
		printf("|");
		q=0;
		printf("\n");
		k++;
		
			j++;
		

 }
	printf("----------------------------------------------------------\n");
}
//------------------------Part3 Finished---------------------------------------------------------------------------------
void menu(char Pokemon_name[10][11],pokemon Pokemons[],pokemon *My_Pokemons)
{
	int x,y=0;
	int range[NUM]={1,3,4,3,2,2,1,2,3,2};
	int attack_power[NUM]={500,350,300,400,250,250,350,200,250,300};
	int stamina[NUM]={2200,1500,1700,2500,1900,2500,3000,1200,1250,2600};
	attack_type type[NUM]={quadratic,linear,linear,linear,quadratic,linear,quadratic,quadratic,linear,linear};

	do{
		printf("\nPlease select an option\n1-)Open Pokedex\n2-)Go To Oak's laboratory\n3-)Enter The Tournement");
		scanf("%d",&x);
		switch(x){
			case 1:
				pokedex(Pokemon_name,range,type,attack_power,stamina);
				break;
			case 2:	
				oaks_laboratory(Pokemon_name,Pokemons,My_Pokemons);
				break;
			case 3:
				y=count_pokemon(My_Pokemons);
				if (y<4)
				{
					printf("\n You must select %d more poekemon.Please Catch\n",(4-y) );
				}
			else{
				battle(Pokemon_name,range,type,stamina,attack_power,My_Pokemons);
				}
				break;
			default:
				x=4;		
		}
	}while(x!=4);
	}