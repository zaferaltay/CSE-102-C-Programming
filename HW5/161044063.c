#include<stdio.h>
#include<stdlib.h>

#define DICT_SIZE 15		
#define WORD_LEN 10			
#define LINE_LEN 18		
							
int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}
int str_len(char word[16]){
	int i=0;
	while(word[i] != '\0'){
		i++;
	}
	return i;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n' && *ch_iter!=13) {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}

void fill_puzzle_map(char puzzle_map[15][16]) {
	int i, j;
	for(i = 0 ; i < 15 ; i++) {
		for (j = 0; j < 16; j++) {
			puzzle_map[i][j] = ' ';
		}
	}
}
void fill_puzzle_map_on_random(char puzzle_map[15][16]){
	int i=0,j=0;
	char c;
	while(i<15){
		while(j<15){
			if (puzzle_map[i][j]==' ')
			{
				c=97+rand()%26;
				puzzle_map[i][j]=c;

			}
			j++;
		}
		i++;
		j=0;
	}
}

void print_puzzle_map(char puzzle_map[15][16]) {
	int i, j;
	for(i = 0 ; i < 15 ; i++) {
		for (j = 0; j < 15; j++) {
			printf("%c  ",puzzle_map[i][j]);
			printf(" ");
		}
		printf("\n");
	}
}
int comp_word(char word[],char *dict[]){
	int i=0,j=0,k=0;
	while(i<15){
		while(j<get_line_size(word)){
			if(word[j]==dict[i][j]){
				k++;
			}
			j++;
		}
		if(k==get_line_size(word)){
			break;
		}
		else{
			k=0;
			j=0;
		}
		i++;
	}
	return i;
}
int exit_control(char control[16]){
	char a[]="exit game";
	int i=0,j=0;
	while(i<4){
		if(control[j]==a[j] ){
			j++;
		}
		i++;
	}
	if(i==j){
		return 1;
	}
	return 0;
}
void game_play(char puzzle_map[15][16],int coord[DICT_SIZE][4],char *dict[]){
	int k1,k2,x1,x2,y1,y2,count=0,i=0,j=0,k=0,temp,control=0;
	char word[16];
do{
	printf("Enter a word\n");
	scanf("%s",word);
	control=exit_control(word);
	if(control==1){
		break;
	}

	k=comp_word(word,dict);
	printf("Enter X and Y coordinates\n");
	scanf("%d %d",&k1,&k2);
		x1=coord[k][0];
		y1=coord[k][1];
		x2=coord[k][2];
		y2=coord[k][3];
	if((k1==x1 && k2==y1) || (k1==x2 && k2==y2)){ 
		if(k1==x1 || k1==x2){  // ---------------------------------BAŞLANGIÇ NOKTASI BAŞLANGIÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇ --------------------
			if(y1==y2){ //-------------------------------------------x leri eşit ise y ye göre kontrol aşağı yada yukarı-------------------
				if(x1<x2){// başlangıç noktası küçükse aşağı doğru
					while(j<get_line_size(word)){
						if(word[j]==dict[k][j]){
							i++;
						}
						j++;
						}
						if(i==j){
							printf("CORRECTT\n");
							j=0;
							count++;
							while(j<get_line_size(word)){
								temp=122-word[j];
								puzzle_map[x1][y1]=90-temp;
								j++;
								x1++;
							}
							i=0;
							j=0;
						}
						else{//ilk harf tuttu devamı gelmedi
							i=0;
							j=0;
						}

				}
				else{
						while(j<get_line_size(word)){
						if(word[j]==dict[k][j]){
							i++;
						}
						j++;
						}
						if(i==j){
							printf("CORRECTT\n");
							j=0;
							count++;
							while(j<get_line_size(word)){
								temp=122-word[j];
								puzzle_map[x1][y1]=90-temp;
								j++;
								x1--;
							}
							i=0;
							j=0;	
						}
						else{
							i=0;
							j=0;
						}
				}
			}
			//------------------------------------- y ler aynı x e göre kontrol sola veya sağa doğru -----------------------------------------------------		
			else if(x1==x2){
				if(y1<y2){// başlangıç noktası küçükse sağa doğru
					while(j<get_line_size(word)){
						if(word[j]==dict[k][j]){
							i++;
						}
						j++;
						}
						if(i==j){
							printf("CORRECTT\n");
							j=0;
							count++;
							while(j<str_len(word)){
								temp=122-word[j];
								puzzle_map[x1][y1]=90-temp;
								j++;
								y1++;
							}
							i=0;
							j=0;
							
						}
						else{//ilk harf tuttu devamı gelmedi
							i=0;
							j=0;
						}

				}
				else{
					while(j<get_line_size(word)){ // sola doğruuuuuuu
						if(word[j]==dict[k][j]){
							i++;
						}
						j++;
						}
						if(i==j){
							printf("CORRECTT\n");
							j=0;
							count++;
							while(j<get_line_size(word)){
								temp=122-word[j];
								puzzle_map[x1][y1]=90-temp;
								j++;
								y1--;
							}
							i=0;
							j=0;
							
						}
						else{//ilk harf tuttu devamı gelmedi
							i=0;
							j=0;
						}					
				}					
			}		
				// ------------------------ y'ler x'ler aynı değil çapraz-----------------------------
		else{
			//---------------------sağ alta doğru çapraz-------------------------
			if(y2>y1 && x2>x1){
				while(j<get_line_size(word)){ 
						if(word[j]==dict[k][j]){
							i++;
						}
						j++;
						}
						if(i==j){
							printf("CORRECTT\n");
							j=0;
							count++;
							while(j<get_line_size(word)){
								temp=122-word[j];
								puzzle_map[x1][y1]=90-temp;
								j++;
								y1++;
								x1++;
							}
							i=0;
							j=0;
							
						}
						else{//ilk harf tuttu devamı gelmedi
							i=0;
							j=0;
						}					

			}//---------------------------sağ üste doğru çapraz---------------------------------
			else if(y2>y1 && x1>x2){
				while(j<get_line_size(word)){ 
						if(word[j]==dict[k][j]){
							i++;
						}
						j++;
						}
						if(i==j){
							printf("CORRECTT\n");
							j=0;
							count++;
							while(j<get_line_size(word)){
								temp=122-word[j];
								puzzle_map[x1][y1]=90-temp;
								j++;
								y1++;
								x1--;
							}
							i=0;
							j=0;
							
						}
						else{//ilk harf tuttu devamı gelmedi
							i=0;
							j=0;
						}									
			}//--------------------------sol üste doğru çapraz-----------------------------------------
			else if(y1>y2 && x1>x2){
				while(j<get_line_size(word)){ 
						if(word[j]==dict[k][j]){
							i++;
						}
						j++;
						}
						if(i==j){
							printf("CORRECTT\n");
							j=0;
							count++;
							while(j<str_len(word)){
								temp=122-word[j];
								puzzle_map[x1][y1]=90-temp;
								j++;
								y1--;
								x1--;
							}
							i=0;
							j=0;
						}
						else{//ilk harf tuttu devamı gelmedi
							i=0;
							j=0;
						}													
			}//---------------------sol alta doğru çapraz------------------------------------------------
			else if(y1>y2 && x2>x1){
				while(j<get_line_size(word)){ 
						if(word[j]==dict[k][j]){
							i++;
						}
						j++;
						}
						if(i==j){
							printf("CORRECTT\n");
							j=0;
							count++;
							while(j<str_len(word)){
								temp=122-word[j];
								puzzle_map[x1][y1]=90-temp;
								j++;
								y1--;
								x1--;
							}
							i=0;
							j=0;
						}
						else{//ilk harf tuttu devamı gelmedi
							i=0;
							j=0;
						}						
					}


		}
	}

	}//---------------------------------------BAŞLANGIÇ KOORDİNATLAARINI GİRMİŞSE BİTİŞŞ-----------------------------


	
	

	else{
		printf("!!!!!!!!!!!!!!WRONG!!!!!!!!!!!!!\n");
	}
	print_puzzle_map(puzzle_map);

}while(count<15);
	if(count==15)
	printf("YOU WON THE GAME");


}

void assign_words_on_puzzle(char *dict[],int coord[DICT_SIZE][4], char puzzle_map[15][16]){
	int i=0,j=0,x1=0,x2=0,y1=0,y2=0,q=0,pmi=0,pmj=0,z;
    char word[16];
    
	while(i<15){
		q = 0;
		j = 0;
		while(dict[i][j]!='\0'){
			word[q]=dict[i][j];
			q++;
			j++;
		}
			
		word[q]='\0';
		

		x1=coord[i][0];
		y1=coord[i][1];
		x2=coord[i][2];
		y2=coord[i][3];
		q=0;
		z=0;
		//------------------yatay kelimeler başlangıç-------------------	
		if(x1==x2){								
			if(y2>y1){
			
				while(z<get_line_size(word)){
					z++;
					puzzle_map[x1][y1] = word[q];
					q++;
					y1++;
					
				}
				
		    } else{
		    	
		    	while(z<get_line_size(word)){
		    		puzzle_map[x1][y1] = word[q];
		    		q++;
		    		y1--;
		    		z++;
		    	}	
		    		    	
		    }

		    
		}
//--------------------yatay kelimeler bitiş---------------------------

		//--------------------dikey kelimeler başlangıç-----------------------
		if(y1==y2){
			if(x1>x2){
				while(z<get_line_size(word)){
					puzzle_map[x1][y1]=word[q];
					q++;
					x1--;
					z++;
				}
				
				
			
			
			}
			else{
				while(z<get_line_size(word)){
					puzzle_map[x1][y1]=word[q];
					q++;
					x1++;
					z++;
				}
				
				
			
			}
		}
//--------------------dikey kelimeler bitiş---------------------------
//-------------------çapraz kelimeler başlangıç-----------------------
		else{
			if(y2>y1){
				if(x1>x2){
					while(z<get_line_size(word)){
					puzzle_map[x1][y1]=word[q];
					y1++;
					x1--;
					q++;
					z++;
					
				 }
				 	
				
				}
				else{
					while(z<get_line_size(word)){
					puzzle_map[x1][y1]=word[q];
					y1++;
					x1++;
					q++;
					z++;
					
				}
					
				

				}
			}
			else{
				if(x1>x2){
					while(z<get_line_size(word)){
						puzzle_map[x1][y1]=word[q];
						x1--;
						y1--;
						q++;
						z++;
						
					}
					
					
				}
				else{
					while(z<get_line_size(word)){
						puzzle_map[x1][y1]=word[q];
						y1--;
						x1++;
						q++;
						z++;
					}
				
				}
			}
		}

//-------------------çapraz kelimeler bitiş---------------------------		
		 
		i++;
	}
	print_puzzle_map(puzzle_map);
	game_play(puzzle_map,coord,dict);
}

int main(){
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4],i=0,j=0;    
    char line[LINE_LEN];
	FILE *fp = fopen("word_hunter.dat", "r");
	char puzzle_map[15][16];
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);

	fill_puzzle_map(puzzle_map);
	printf("--------------Random character only------------------\n");
	fill_puzzle_map_on_random(puzzle_map);
	print_puzzle_map(puzzle_map);	
	printf("---------------Game Starting-------------------------\n");
	assign_words_on_puzzle(dict,coord, puzzle_map);


		
	return 0;
}