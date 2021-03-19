#include <stdio.h>
#include <string.h>      // map terminal tam erkan değilse ilk çalıştığında bozuk gözküyor tam ekran ekran halinde diğer çalıştıklarında veya 
#include <time.h>        // ilk çlıştığında da doğru çalışıyr hocam bilgilerinize
#include <stdlib.h>
#define PROPERTY_COUNT 13
typedef enum block_type{start=0,property,fortune,tax,punish}b_type;
typedef enum player_type{noone=-1,car,cap}player_type; // none

struct fortune{
	b_type type;
	int block_id;
	struct fortune *next;
};

struct player
{
	player_type type;
	int current_block_id;
	int owned_block_ids[PROPERTY_COUNT];
	int account;
	int turn_to_wait;
	char *name;
};

struct block
{
    int block_id;
    char * name;
    int price;
    int rent;
    int rent_1;
    int rent_2;
    int rent_3;
    int house_price;
    int house_count;
    struct player owner;
    b_type type;
    struct block *next;
};
int roll_dice()
{

    int i=rand()%6+1;
    return i;
}
void init_player(struct player *player_one,struct player *player_two){
	player_one->type=car;
	player_one->current_block_id=0;
	player_one->owned_block_ids[0]=0;
	player_one->owned_block_ids[1]=0;
	player_one->owned_block_ids[2]=0;
	player_one->owned_block_ids[3]=0;
	player_one->owned_block_ids[4]=0;
	player_one->owned_block_ids[5]=0;
	player_one->owned_block_ids[6]=0;
	player_one->owned_block_ids[7]=0;
	player_one->owned_block_ids[8]=0;
	player_one->owned_block_ids[9]=0;
	player_one->owned_block_ids[10]=0;
	player_one->owned_block_ids[11]=0;
	player_one->owned_block_ids[12]=0;
	player_one->owned_block_ids[13]=0;
	player_one->account=100000;
	player_one->turn_to_wait=0;
	player_one->name="car";

	player_two->type=cap;
	player_two->current_block_id=0;
	player_two->owned_block_ids[0]=0;
	player_two->owned_block_ids[1]=0;
	player_two->owned_block_ids[2]=0;
	player_two->owned_block_ids[3]=0;
	player_two->owned_block_ids[4]=0;
	player_two->owned_block_ids[5]=0;
	player_two->owned_block_ids[6]=0;
	player_two->owned_block_ids[7]=0;
	player_two->owned_block_ids[8]=0;
	player_two->owned_block_ids[9]=0;
	player_two->owned_block_ids[10]=0;
	player_two->owned_block_ids[11]=0;
	player_two->owned_block_ids[12]=0;
	player_two->owned_block_ids[13]=0;
	player_two->account=100000;
	player_two->turn_to_wait=0;
	player_two->name="cap";


}

void init_board(struct block *root)
{
    struct block *board;
 
    
    board=root;

    board->block_id=0;
    board->price=0;  
    board->rent=0;   
    board->rent_1=0; 
    board->rent_2=0; 
    board->rent_3=0; 
    board->house_price=0;
    board->house_count=0;
    board->owner.type=noone;
    board->type=start;   
    board->name="Start";
    board->next=malloc(sizeof(struct block));
    board=board->next;

    //----------------------------------------

    board->owner.type=noone;
    board->block_id=1;
    board->price=16000;
    board->rent=800;
    board->rent_1=4000;
    board->rent_2=9000;
    board->rent_3=25000;
    board->house_price=10000;
    board->house_count=0;
    board->type=property;
    board->name="Esenyurt";
    board->next=malloc(sizeof(struct block));
    board=board->next; 

    //-----------------------------
    board->owner.type=noone;
    board->block_id=2;
    board->price=0;
    board->rent=1500;
    board->rent_1=0;
    board->rent_2=0;
    board->rent_3=0;
    board->house_price=0;
    board->house_count=0;   
    board->type=tax;
    board->name="Car Park";
    board->next=malloc(sizeof(struct block));
    board=board->next;

    //---------------------------

    board->block_id=3;
    board->name="Fortune";
    board->type=fortune;
    board->next=malloc(sizeof(struct block));
    board=board->next;

    //------------------------------------

    board->owner.type=noone;
    board->block_id=4;
    board->price=16500;
    board->rent=850;
    board->rent_1=4250;
    board->rent_2=9500;
    board->rent_3=26000;
    board->house_price=12000;
    board->house_count=0;
    board->type=property;
    board->name="Tuzla";
    board->next=malloc(sizeof(struct block));
    board=board->next;
    //-----------------------------------------
    
    board->owner.type=noone;
    board->block_id=5;
    board->price=17000;
    board->rent=875;
    board->rent_1=4500;
    board->rent_2=10000;
    board->rent_3=28000;
    board->house_price=12000;
    board->house_count=0;
    board->type=property;
    board->name="Arnavutkoy";
    board->next=malloc(sizeof(struct block)); 
    board=board->next;

    //--------------------------

    board->owner.type=noone;
    board->house_count=0; 
    board->block_id=6;
    board->price=0;
    board->rent=2;
    board->rent_1=0;
    board->rent_2=0;
    board->rent_3=0;
    board->house_price=0;
    board->type=punish;
    board->name="Wait 2 trn";
    board->next=malloc(sizeof(struct block));
    board=board->next;

    //---------------------------------

    board->house_count=0;
    board->owner.type=noone;  
    board->block_id=7;
    board->price=20000;
    board->rent=1000;
    board->rent_1=5000;
    board->rent_2=12000;
    board->rent_3=30000;
    board->house_price=13000;
    board->type=property;
    board->name="Catalca";
    board->next=malloc(sizeof(struct block));
    board=board->next;

    //-----------------------------

    board->house_count=0;
    board->owner.type=noone;  
    board->block_id=8;
    board->price=23000;
    board->rent=1100;
    board->rent_1=5500;
    board->rent_2=12500;
    board->rent_3=33000;
    board->house_price=13000;
    board->type=property;
    board->name="Beykoz";
    board->next=malloc(sizeof(struct block));
    board=board->next;
//-------------------------------
    board->block_id=9;
    board->name="Fortune";
    board->type=fortune;
    board->next=malloc(sizeof(struct block));
    board=board->next;
//--------------------------------
    board->house_count=0;
    board->owner.type=noone;
    board->block_id=10;
    board->price=0;
    board->rent=1750;
    board->rent_1=0;
    board->rent_2=0;
    board->rent_3=0;
    board->house_price=0;
    board->type=tax;
    board->name="Car Fix";
    board->next=malloc(sizeof(struct block));
    board=board->next;

    //--------------------------

    board->house_count=0;
    board->owner.type=noone;  
    board->block_id=11;
    board->price=30000;
    board->rent=1350;
    board->rent_1=7000;
    board->rent_2=15000;
    board->rent_3=40000;
    board->house_price=15000;
    board->type=property;
    board->name="Maltepe";
    board->next=malloc(sizeof(struct block));
    board=board->next;

    //------------------------

    board->house_count=0;
    board->owner.type=noone;
    board->block_id=12;
    board->price=0;
    board->rent=2000;
    board->rent_1=0;
    board->rent_2=0;
    board->rent_3=0;
    board->house_price=0;
    board->type=tax;
    board->name="Bills";
    board->next=malloc(sizeof(struct block));
    board=board->next;

    //----------------------

    board->house_count=0;
    board->owner.type=noone;
    board->block_id=13;
    board->price=33000;
    board->rent=1500;
    board->rent_1=8000;
    board->rent_2=16000;
    board->rent_3=42000;
    board->house_price=16000;
    board->type=property;
    board->name="Sisli";
    board->next=malloc(sizeof(struct block));     
    board=board->next;

    //---------------------

    board->house_count=0;
    board->owner.type=noone;
    board->block_id=14;
    board->price=0;
    board->rent=2250;
    board->rent_1=0;
    board->rent_2=0;
    board->rent_3=0;
    board->house_price=0;
    board->type=tax;
    board->name="Oil"; 
    board->next=malloc(sizeof(struct block));  
    board=board->next;

    //-----------------------
    board->block_id=15;
    board->name="Fortune";
    board->next=malloc(sizeof(struct block));
    board->type=fortune;
    board=board->next;

    //-----------------------

    board->house_count=0;
    board->owner.type=noone; 
    board->block_id=16;
    board->price=35000;
    board->rent=1600;
    board->rent_1=8500;
    board->rent_2=17000;
    board->rent_3=45000;
    board->house_price=17500;
    board->type=property;
    board->name="Atasehir"; 
    board->next=malloc(sizeof(struct block)); 
    board=board->next;

    //-------------------------

    board->house_count=0;
    board->owner.type=noone;
    board->block_id=17;
    board->price=40000;
    board->rent=1750;
    board->rent_1=9500;
    board->rent_2=19000;
    board->rent_3=48000;
    board->house_price=19000;
    board->type=property;
    board->name="Sariyer";
    board->next=malloc(sizeof(struct block));
    board=board->next;

    //--------------------

    board->house_count=0;
    board->owner.type=noone;
    board->block_id=18;
    board->price=0;
    board->rent=1;
    board->rent_1=0;
    board->rent_2=0;
    board->rent_3=0;
    board->house_price=0;
    board->type=punish;
    board->name="Wait 1 trn";
    board->next=malloc(sizeof(struct block));
    board=board->next;

    //---------------------------

    board->house_count=0;
    board->owner.type=noone;
    board->block_id=19;
    board->price=43000;
    board->rent=1900;
    board->rent_1=11000;
    board->rent_2=21500;
    board->rent_3=55000;
    board->house_price=23000;
    board->type=property;
    board->name="Kadikoy";
    board->next=malloc(sizeof(struct block));
    board=board->next;
    //------------------------
    board->house_count=0;
    board->owner.type=noone;
    board->block_id=20;
    board->price=60000;
    board->rent=2500;
    board->rent_1=15000;
    board->rent_2=28000;
    board->rent_3=60000;
    board->house_price=30000;
    board->type=property;
    board->name="Besiktas";
    board->next=malloc(sizeof(struct block));
    board=board->next;  
//-------------------------------
    board->block_id=21;
    board->name="Fortune";
    board->next=malloc(sizeof(struct block));
    board->type=fortune;
    board=board->next;
    //------------------------------
    board->house_count=0;
    board->owner.type=noone;
    board->block_id=22;
    board->price=0;
    board->rent=5000;
    board->rent_1=0;
    board->rent_2=0;
    board->rent_3=0;
    board->house_price=0;
    board->type=tax;
    board->name="Vocation";
    board->next=malloc(sizeof(struct block));   
    board=board->next;
    //--------------------------
    board->house_count=0;
    board->owner.type=noone;
    board->block_id=23;
    board->price=70000;
    board->rent=3500;
    board->rent_1=20000;
    board->rent_2=35500;
    board->rent_3=65000;
    board->house_price=35000;
    board->type=property;
    board->name="Bebek";
    board->next=root;
}

//-------------------------------------------------------

//------------------------------------------------------
void show_properties(struct block *board){  
	int i;
	int a;
	struct block *board2;
	do{
		board2=board;
		printf("Please select a property to see details\n");
	for (i = 0; i < 24; ++i)
	{
		if(board2->type==property){
			printf("%d . %s \n",i,board2->name );
		}
		board2=board2->next;
	}
	printf("%d . Exit \n",0);
	scanf("%d",&a);
	board2=board;
	i=0;
if(a!=0){
		while(i<a){
			i++;
			board2=board2->next;
		}
	printf("------------------------------\n");
	printf("|%15s             |\n",board2->name);
	printf("------------------------------\n");
	printf("|   RENT    %5d$           |\n",board2->rent );
	printf("|   RENT1   %5d$           |\n",board2->rent_1 );
	printf("|   RENT2   %5d$           |\n",board2->rent_2 );
	printf("|   RENT3   %5d$           |\n",board2->rent_3 );
	printf("------------------------------\n");
	printf("|   HOUSE PRICE  %7d$    |",board2->house_price);
	printf("\n------------------------------\n");
}
}while(a!=0);
}
//-----------------------------------------------------------------------------------------------------------------
void show_property_deed(struct block *board){
	show_properties(board);
}
//-------------------------------------------------------------------------------
void show_my_properties(struct block *board,struct player current_player){
	int j=0,properties[13],i,q=0;
	struct block *board2;
	board2=board;
	for (int i = 0; i < 13; i++)
	{
		if(current_player.owned_block_ids[i]!=0){
			properties[j]=current_player.owned_block_ids[i];
			j++;
		}
	}
	i=0;
	while(i<j){
		while(q<properties[i]){
			q++;
			board2=board2->next;

		}
		q=0;
		printf("%s\n",board2->name );
		i++;
		board2=board;
	}
}
//-------------------------------------------------
void s_m_p(struct block *board,struct player *current_player){
    int j=0,properties[13],i,q=0;
    struct block *board2;
    board2=board;
    for (int i = 0; i < 13; i++)
    {
        if(current_player->owned_block_ids[i]!=0){
            properties[j]=current_player->owned_block_ids[i];
            j++;
        }
    }
    i=0;
    while(i<j){
        while(q<properties[i]){
            q++;
            board2=board2->next;

        }
        q=0;
        printf(" %d-)%s\n",board2->block_id,board2->name );
        i++;
        board2=board;
    }
}
//-------------------------------------------------
void buy_house(struct block *current_block,struct player *current_player){
	int a;
	printf("How many house want you build(1-2-3)\n");
	scanf("%d",&a);
	if(a==1){
		if(current_player->account>current_block->house_price){
			current_player->account-=current_block->house_price;
			current_block->house_count++;
			current_block->price+=current_block->house_price;
		}
		else
			printf("Your account is not enough");
	}
	else if(a==2){
		if(current_player->account>(current_block->house_price)*2){
			current_player->account-=(current_block->house_price*2);
			current_block->house_count=current_block->house_count+2;
			current_block->price+=(current_block->house_price*2);
		}
		else
			printf("Your account is not enough");		
	}
	else if (a==3)
	{
		if(current_player->account>(current_block->house_price)*3){
			current_player->account-=(current_block->house_price*3);
			current_block->price+=(current_block->house_price*3);
			current_block->house_count=current_block->house_count+3;
		}
		else
			printf("Your account is not enough");		
	}
}
//---------------------------------------------------
void buy_properties(struct block *current_block,struct player *current_player){
	int i=0,a,c;
	  if(current_block->owner.type==noone){	
		printf("\n Do you want to buy this property(1-yes 2-no)\n");
		scanf("%d",&a);
		if(a==1){
			if(current_player->account>=current_block->price){
				while(current_player->owned_block_ids[i]!=0){
					i++;
					}	
			current_player->owned_block_ids[i]=current_block->block_id;
			current_block->owner.type=current_player->type;
			current_player->account-=current_block->price;
			printf("Do you want to build any house(1-yes 2-no)\n");
			scanf("%d",&c);
				if (c==1)
				{
				buy_house(current_block,current_player);
				}
			}
			else{
				printf("Your Account is not enough\n");
			}
			printf("\n");
	}
  }
}
//------------------------------------------------
void sell_property(struct block *board, struct player* current_player){
	struct block *board2;
	int i=0,a,q=1,x=0,d=0,b;
	board2=board;
	while(q==1){
	printf("Which property want you sell\n");
	s_m_p(board,current_player);
	scanf("%d",&a);
        while(x<a){
            board2=board2->next;
            x++;
        }
        x=0;
        current_player->account+=(board2->price)/2;
        board2->price-=board2->house_count*board2->house_price;
        board2->house_count=0;
        board2->owner.type=noone;
        while(board2->block_id!=current_player->owned_block_ids[d]){
            d++;
        }
        board2=board;
        b=0;
        while(current_player->owned_block_ids[b]!=0){
            b++;
        }
        for (i = d; i <=b; i++)
        {
            current_player->owned_block_ids[i]=current_player->owned_block_ids[i+1];
        }
        b=0;
        d=0;
        while(current_player->owned_block_ids[b]!=0){
            b++;
        }
        if(b!=0){
        printf("\nDo you want to sell another property (1-yes 0-no)\n");
        scanf("%d",&q);
    }
    else{
        q=0;
        printf("You have not a property\n");
    }
    b=0;
  }
	}

 //----------------------------------------------------------------------------------------------------------------

void show_board(struct block *board,struct player player_one,struct player player_two)
{
    struct block *board2;
    board2=board;
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    int i=0,space_flag=0,j=0;
    for (i=0;i<7;i++)
    {
        if (strlen(board2->name)<8)
            printf("|\t%s\t\t",board2->name);
        else
            printf("|\t%s\t",board2->name);
        board2=board2->next;
    }
    printf("|\n");
    board2=board;
    for (i=0;i<7;i++)
    {
        if (board2->type==property || board2->type==tax)
            printf("|\t%d$ \t\t",board2->price);
        else if (strlen(board2->name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
        board2=board2->next;
    }
    printf("|\n");
    board2=board;
    for (i=0;i<7;i++)
    {
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.name,player_two.name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(board2->name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }
        board2=board2->next;
    }
    board2=board;
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    //Middle
    j=0;
    for (i=0;i<5;i++)
    {
        //Names
        while(j<23-i){
            board2=board2->next;
            j++;
        }
        j=0;
        if (strlen(board2->name)<8)
            printf("|\t%s\t\t|",board2->name);
        else
            printf("|\t%s\t|",board2->name);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        board2=board;
        while(j<i+7){
            board2=board2->next;
            j++;
        }
        j=0;
        if (strlen(board2->name)<8)
            printf("|\t%s\t\t|",board2->name);
        else
            printf("|\t%s\t|",board2->name);
        printf("\n");
        
        board2=board;
        //prices
        while(j<23-i){
            board2=board2->next;
            j++;
        }
        j=0;
        if (board2->type==property || board2->type==tax)
            printf("|\t%d$ \t\t|",board2->price);
        else if (strlen(board2->name)<8)
            printf("|\t         \t|");
        else
            printf("|\t\t\t\t|");

        board2=board;
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

        while(j<i+7){
            board2=board2->next;
            j++;
        }
        j=0;

        if (board2->type==property || board2->type==tax)
            printf("|\t%d$ \t\t",board2->price);
        else if (strlen(board2->name)<8)
            printf("|\t         \t");
        else
            printf("|\t\t\t\t");

        printf("|\n");
        //spaces
        board2=board;
        while(j<23-i){
            board2=board2->next;
            j++;
        }
        j=0;

        space_flag=0;
        printf("|\t");
        if (23-i==player_one.current_block_id && 23-i==player_two.current_block_id)
        {
            printf("%s, %s \t|",player_one.name,player_two.name);
            space_flag=1;
        }
        else {
            if (23 - i == player_one.current_block_id) {
                printf("%s \t\t|", player_one.name);
                space_flag = 1;
            }
            if (23 - i == player_two.current_block_id) {
                printf("%s \t\t|", player_two.name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(board2->name)<8)
                printf("\t\t|");
            else
                printf("    \t\t|");
        }

        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        space_flag=0;
        printf("|\t");
        if (7+i==player_one.current_block_id && 7+i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.name,player_two.name);
            space_flag=1;
        }
        else {

            if (7+i==player_one.current_block_id)
            {
                printf("%s \t\t",player_one.name);
                space_flag=1;
            }
            if (7+i==player_two.current_block_id)
            {
                printf("%s \t\t",player_two.name);
                space_flag=1;
            }
        }
        board2=board;
        while(j<i+7){
            board2=board2->next;
            j++;
        }
        j=0;
        if (space_flag==0) {
            if (strlen(board2->name)<8)
                printf("\t\t");
            else
                printf("    \t\t");
        }

        printf("|\n");
        if (i!=4) {
            printf("-------------------------");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            printf("-------------------------");
            printf("\n");
        }

    board2=board;
    }
    //bottom row
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i=18;i>=12;i--)
    {
        while(j<i){
            board2=board2->next;
            j++;
        }
        j=0;
        if (strlen(board2->name)<8)
            printf("|\t%s\t\t",board2->name);
        else
            printf("|\t%s\t",board2->name);
        board2=board;
    }
    printf("|\n");
    for (i=18;i>=12;i--)
    {   
        while(j<i){
            board2=board2->next;
            j++;
        }
        j=0;
        if (board2->type==property || board2->type==tax)
            printf("|\t%d$ \t\t",board2->price);
        else if (strlen(board2->name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t\t");
        board2=board;
    }
    printf("|\n");
    for (i=18;i>=12;i--)
    {
        while(j<i){
            board2=board2->next;
            j++;
        }
        j=0;
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.name,player_two.name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(board2->name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }

    }
    board2=board;
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}//---------------------------------------------
int count_properties(struct player current_player)
{
    int i=0,count=0;
    while(current_player.owned_block_ids[i]!=0){
        	i++;
            count++;
    }
    
    return count;
}//----------------------------------------------------
int insufficient_fund(struct block *board,struct player* current_player,int required_money)
{
    int selection,flag=1;
    while (selection!=4 && current_player->account<required_money && count_properties(*current_player)!=0)
    {
        printf("You don't have enough money to continue your transaction.You need %d$ more. Please select an option to continue: \n",required_money-current_player->account);
        printf("1- Sell Property\n");
        printf("2- Show my Properties\n");
        printf("3- Show my Account\n");
        printf("0- Back\n");
        scanf("%d",&selection);
        switch (selection)
        {
            case 1:
                sell_property(board,current_player);
                break;
            case 2:
                show_my_properties(board,*current_player);
                break;
            case 3:
                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                break;
            case 0:
                flag=0;
                break;
            default:
                printf("You made a wrong selection!\n");
                break;

        }
    }
    return flag;

}
//----------------------------------------------
void pay_rent(struct block *board,struct player* current_player,struct player * owner)
{
    int rent=0,owned_property_count,i=0;
    struct block *board2;
    while(i<current_player->current_block_id){
    	i++;
    	board2=board2->next;
    }

    rent=board2->rent;
    if (board2->house_count==1)rent=board2->rent_1;
    if (board2->house_count==2)rent=board2->rent_2;
    if (board2->house_count==3)rent=board2->rent_3;
    if (rent>current_player->account)
    {
        owned_property_count=count_properties(*current_player);
        while(rent>current_player->account && owned_property_count!=0)
        {
            insufficient_fund(board,current_player,rent);
            owned_property_count=count_properties(*current_player);
        }
    }
    if (rent<current_player->account)
    {
        current_player->account-=rent;
        owner->account+=rent;
    } else
        current_player->account=0;
}
//---------------------------------------------------------
void show_menu(){
    printf("%d-) Roll the dice \n",1 );
    printf("%d-) Show my account \n",2 );
    printf("%d-) Show my properties \n",3 );
    printf("%d-) Show property deeds \n",4 );
    printf("%d-) Buy property \n",5 );
    printf("%d-) Buy house \n",6 );
    printf("%d-) Sell property \n",7 );
    printf("Please select an option to continue\n");
}//--------------------------------------------------------------------------------------
void fortunes(struct block *board,struct player *current_player,struct player *other){
	int dice=0,dice_2=0,i=0;
	struct block *board2;
	board2=board;
	dice=roll_dice();
	if (dice==1)
	{
		if (current_player->type==cap)
		{
			while(i<current_player->owned_block_ids[0]){
				i++;
				board2=board2->next;
			}
			board2->house_count++;
		}
		else if(current_player->type==car){
			printf("which property want you build on house\n");
			show_my_properties(board,*current_player);
		}
	}
	else if(dice==2){
		dice_2=roll_dice();
		if(dice_2<=3){ 
			current_player->current_block_id+=2;
			current_player->current_block_id%24;
	}
	else{
		current_player->current_block_id-=2;
	}
	}
	else if(dice==3){
		current_player->account-=5000;
	}
	else if(dice==4){
		current_player->account-=10000;
		other->account+=10000;
	}
	else if(dice==5){
		current_player->account+=20000;
	}
}
//----------------------------------------------------------------------------------------
void after_dice_menu(struct block *board,struct player* current_player,struct player* other)
{
    int selection,insuf_flag=1,i=0;
    struct block *board2;
    board2=board;
    while(i<current_player->current_block_id){
        board2=board2->next;
        i++;
    }
    switch (board2->type)
    {
        case property:
            printf("%s has arrived %s \n",current_player->name,board2->name);
            if (board2->owner.type==noone)
            {
                printf("Do you want to buy %s ?\n",board2->name);
                printf("1- Yes\n");
                printf("2- No\n");
                scanf("%d",&selection);
                if (selection==1)
                {

                    if (current_player->account<board2->price)
                    {
                        while (count_properties(*current_player)!=0 && current_player->account<board2->price && insuf_flag==1 )
                        {
                            insuf_flag=insufficient_fund(board,current_player,board2->price);
                        }
                    }
                    buy_properties(board2,current_player);
                    if (current_player->type==board2->owner.type)
                    {
                        buy_house(board2,current_player);
                    }

                }

            } else
            {
                pay_rent(board2,current_player,other);
            }
            break;
        case tax:
            printf("%s has arrived tax block(%s)\n",current_player->name,board2->name);
            while (count_properties(*current_player)!=0 && current_player->account<board2->rent) {
                insuf_flag = insufficient_fund(board, current_player,
                                               board2->price);
                if (insuf_flag == 0 && current_player->account < board2->rent)
                    printf("You must pay your tax!\n");
            }
            if (current_player->account>board2->price)
                current_player->account=current_player->account-board2->rent;
            else
            {
                current_player->account=0;
            }
            break;
        case punish:
            printf("%s has punished for %d turn. \n",current_player->name,board2->rent);
            current_player->turn_to_wait+=board2->rent;
            break;
         case fortune:
           	fortunes(board,current_player,other); 
           	break;
    }
}
//------------------------------------------------------------------------------------------
void turn(struct block *board,struct player* current_player,struct player * other)
{
    int flag=1,next_block,i=0;
    struct block *board2;
    board2=board;
    while(flag)
    {
        int selection;
        show_menu();
        printf("Please select an option to continue (%s):\n",current_player->name);
        scanf("%d",&selection);
        switch(selection)
        {
            case 1:
                if (current_player->turn_to_wait==0) {
                    next_block=(current_player->current_block_id + roll_dice());
                    if (next_block>=24)current_player->account+=10000;
                    current_player->current_block_id = next_block % 24;
                    after_dice_menu(board,current_player,other);
                    flag = 0;
                } else
                {
                    printf("You need to wait %d turn to continue.\n",current_player->turn_to_wait);
                    current_player->turn_to_wait-=1;
                    flag=0;
                }
                break;
            case 2:
                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                break;
            case 3:
                show_my_properties(board,*current_player);
                break;
            case 4:
                show_property_deed(board);
                break;
            case 5:
                while(i<current_player->current_block_id){
                    board2=board2->next;
                    i++;
                }
                i=0;
                if (board2->type==property && board2->owner.type==noone)
                buy_properties(board,current_player);
                else
                {

                    printf("You don't have permission to buy this block!\n");
                }
                board2=board;
                break;
            case 6:
                while(i<current_player->current_block_id){
                    board2=board2->next;
                    i++;
                }
                i=0;
                if (current_player->type==board2->owner.type) {
                    buy_house(board2,current_player);
                }else
                {
                    printf("You don't have permission to build house on this block!\n");
                }
                board2=board;
                break;
            case 7:
            while(i<current_player->current_block_id){
                    board2=board2->next;
                    i++;
                }
                i=0;
                sell_property(board,current_player);
                board2=board;
                break;
            default:
                printf("Wrong selection!\n");
        }
    }
}//--------------------------------------------------------------------------------------
void buy_pc_house(struct block *board,struct player *current_player){
	int i=0,dice;
	while(current_player->owned_block_ids[i]!=0){
		i++;
	}
	if(i>4){
		dice=roll_dice();
		if(dice<=3){
			if (0<current_player->account-board->house_price)
			{
				current_player->account-=board->house_price;
				board->house_count++;
				board->price+=board->house_price;
			}
		}
	}

}


void buy_pc_properties(struct block *board,struct player *current_player){
	int i=0;
	if (current_player->account > board->price)
	{
	current_player->account-=board->price;
	board->owner.type=current_player->type;
	while(current_player->owned_block_ids[i]!=0){
		i++;
	}
	current_player->owned_block_ids[i]=board->block_id;
	printf("Comp. has told the %s\n",board->name );
	}

}
//--------------------------------------------------------------------------------------
void sell_pc_property(struct block *board,struct player *current_player){
	int i,max=0,j=0,k=0;
	struct block *board2;
	board2=board;
	while(current_player->owned_block_ids[i]!=0){
			while(k<current_player->owned_block_ids[i]){
				board2=board2->next;
				k++;
			}
			if (board2->price>max)
			{
				j=i;
			}
			k=0;
			board2=board;
		i++;
	}
	while(k<j){

		board2=board2->next;
		k++;
	}
	current_player->account+=(board2->price)/2;

	board2->owner.type=noone;
	board2->house_count=0;
	for (k = j; k <= i; k++)
	{
		current_player->owned_block_ids[k]=current_player->owned_block_ids[k+1];
	}

}//----------------------------------------------------------------------------------
void pay_rent_pc(struct block *board,struct player *current_player,struct player *other){
	int i,x=1;
	i=board->house_count;
	while(x==1 && current_player->owned_block_ids[0]!=0){

	if(i==0){
		if(current_player->account-board->rent>0){
			current_player->account=current_player->account - board->rent;
			other->account=other->account +board->rent;
			x=0;
		}
		else{
			sell_pc_property(board,current_player);
		}
	}
	else if(i==1){
		if(current_player->account-board->rent_1>0){
			current_player->account=current_player->account - board->rent_1;
			other->account+=board->rent_1;
			x=0;
		}
		else{
			sell_pc_property(board,current_player);
		}

	}
	else if(i==2){
		if(current_player->account-board->rent_2>0){
			current_player->account=current_player->account - board->rent_2;
			other->account+=board->rent_2;
			x=0;
		}
		else{
			sell_pc_property(board,current_player);
		}
	}
	else if (i==3)
	{
		if(current_player->account-board->rent_3>0){
			current_player->account=current_player->account - board->rent_3;
			other->account+=board->rent_3;
			x=0;
		}
		else{
			sell_pc_property(board,current_player);
		}
	}
	}
}
//-----------------------------------------------------------------------------------------
void pc_turn(struct block *board,struct player* current_player,struct player * other)
{
    int flag=1,next_block,i=0,dice;
    double average=0.0;
    struct block *board2;
    board2=board;
    while(flag){

                if (current_player->turn_to_wait==0) {
                	dice=roll_dice();
                	printf("Computer rolled the dice : %d\n",dice);
                    next_block=(current_player->current_block_id + dice);
                    if (next_block>=24)current_player->account+=10000;
                    current_player->current_block_id = next_block % 24;
                    flag = 0;
                } else
                {
                    printf("Computer need to wait %d turn to continue.\n",current_player->turn_to_wait);
                    current_player->turn_to_wait-=1;
                    flag=0;
                }
                while(i<24){
                	if(board2->type==property){
                		average+=board2->price;
                	}
                	i++;
                	board2=board2->next;
                }
                board2=board;
                average/=PROPERTY_COUNT;

            
                while(i<current_player->current_block_id){
                    board2=board2->next;
                    i++;
                }
                i=0;
                if (board2->type==property && board2->owner.type==noone){
                	if (board2->price < average)
                	{
               		 buy_pc_properties(board2,current_player);
                	}
                	else{
                		dice=roll_dice();
                		if (dice<=3)
                		{
                			buy_pc_properties(board2,current_player);
                		}
                		else{
                			return;
                		}
                	}
                }
                board2=board;
         
                while(i<current_player->current_block_id){
                    board2=board2->next;
                    i++;
                }
 				if(board2->type==fortune){
 					fortunes(board,current_player,other);
 				}
                i=0;
                if (current_player->type==board2->owner.type) {
                    buy_pc_house(board2,current_player);
                }
                board2=board;
              
            while(i<current_player->current_block_id){
                    board2=board2->next;
                    i++;
                }
                i=0;

                if (board2->type==tax)
                {
                	current_player->account-=board2->rent;
                	while(current_player->account<0 && current_player->owned_block_ids[0]!=0){
		                sell_pc_property(board,current_player);
                	}
                }
                
                if (board2->type==car)
                {
                	pay_rent_pc(board2,current_player,other);
                }
 				if (board2->type==punish)
 				{
 					current_player->turn_to_wait+=board2->rent;
 				}
        }
    }



//----------------------------------------------------------------------------------------
int check_end(struct player current_player)
{
    int owned_property_count=count_properties(current_player);
    if (current_player.account<=0 && owned_property_count==0)return 1;
    else return 0;
}
//----------------------------------------------------------------------------------------
void game_play(struct block *board,struct player* player_one,struct player* player_two)
{
    int is_end=0;
    printf("Welcom to Monopoly! %s will roll the dice first.\n",player_one->name);
    while(is_end!=1)
    {
        printf("%s :%d$ , %s:%d$\n",player_one->name,player_one->account,player_two->name,player_two->account);
        turn(board,player_one,player_two);
        show_board(board,*player_one,*player_two);
        is_end=check_end(*player_one);
        if (is_end==0)
        {
            printf("%s :%d$ , %s:%d$\n",player_one->name,player_one->account,player_two->name,player_two->account);
            pc_turn(board,player_two,player_one);
            show_board(board,*player_one,*player_two);
            is_end=check_end(*player_two);
            if (is_end==1)
                printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_two->name,player_two->name);
        } else
            printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_one->name,player_one->name);

    }

}



//------------------------------------------------------------------------------------------
int main(){ 

int i=0; //player_two==computer

struct block *root=malloc(sizeof(struct block));
struct player player_one,player_two;
init_player(&player_one,&player_two);
init_board(root);
srand(time(NULL));


//show_property_deed(root);
//show_my_properties(root,player_one);
//sell_property(root,&player_one);
show_board(root,player_one,player_two);
game_play(root,&player_one,&player_two);
}