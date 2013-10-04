#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include<unistd.h>

/* we assume that every grammar is written in separate line */
/* we assume that character 'e' means null that means empty string */
/* do not press enter at the end of last grammar */
/* do not press enter before starting first grammar */
/* do not leave space after completion of production */
/* do not leave space between grammar symbols */



/*instance of abstract Interpreter top most level */
/*Abstraction 1 and 2:true and  false are indication of top most level of abstraction whether grammar has parsed or not and whether symbol on left side are non terminal or not */
/*Abstraction 3:Null abstraction */
/*Abstraction 4:abstraction if terminal is now found in terminal list i.e. array taken in this interpreter name of the arrya is terminals */
void *abstract_interpreter_instance(char l_type,int e,char lhs){
	if(l_type=='f'){
		printf("False\n"); // grammar not parsed or left side symbol is not non terminal
		exit(0);
	}
	if(l_type=='t'){
		printf("True\n"); // grammar parsed and ledft side symbols are all non terminal
		exit(0);
	}
	if(e==1){
		printf("Null abstraction for %c is NULL\n",lhs);
	}
	if(e!=1){
		printf("Null abstraction for %c is NOT-NULL\n",lhs);
	}
}


void *abstract_interpreter_parsed(char g){
	char lan_type = 't'; // l means not null i.e -e
	int pass=2; //to match parameter length
	char x='z'; //to match parameter length
	abstract_interpreter_instance(lan_type,pass,x);

}


/* This function is  quivalent of :: lembda(M). (M==A? lembda(r)T(a).e:_|_) */
void *abstract_interpreter(char *non, char _c){
	int ak,y=0;
	for(ak=0;non[ak]!='\0';ak++){
		if(_c==non[ak]){
			y=1;
		}
	}
	if(y){
		return;
	}
	else{
		char lan_type = 'f';
		int pass=2; //to match parameter length
		char x='z'; //to match parameter length
		abstract_interpreter_instance(lan_type,pass,x);
	}

}


int main(){
FILE *grammar,*m_grammar;
int _c;
int count_lines=0,count_characters=0;
char* left_hand_sides;

grammar = fopen("grammar.txt","r");
if(grammar == NULL){
	printf("ERROR FOUND: FILE DOES NOT EXISTS\n");
	exit(0);
}

		while((_c=fgetc(grammar))!=EOF){
			count_characters+=1;
			printf("%c",(char)_c);
			if((char)_c=='\n'){
				count_lines+=1;
			}
		}
		
		if(count_characters<6){
			printf("ERROR FOUND: NOT ENOUGH CHARACTERS\n");
			exit(0);
		}

fclose(grammar);
char non_terminals[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char terminals[]     = "abcdefghijklmnopqrstuvwxyz|";
grammar = fopen("grammar.txt","r");
	if(count_lines!=0){
		int _i=0; /* variable to traverse left_hand_sides array */
		int NON; /* variable to traverse non terminals */
		left_hand_sides = (char*)(calloc(count_lines,sizeof(char))); /* initializing array to store all non terminals on left hand side*/
		_c=fgetc(grammar);
		abstract_interpreter(non_terminals,_c);		
		left_hand_sides[_i] = (char)_c;
		_i++;	
		_c=fgetc(grammar);
		if((char)_c!=':'){
			printf("ERROR FOUND: ':' EXPECTED\n");
			exit(0);
		}
		_c=fgetc(grammar);
		if((char)_c!=':'){
			printf("ERROR FOUND: ':' EXPECTED\n");
			exit(0);
		}
		_c=fgetc(grammar);
		if((char)_c!='='){
			printf("ERROR FOUND: '=' EXPECTED\n");
			exit(0);
		}
		
			while((_c=fgetc(grammar))!=EOF){
				if((char)_c=='\n'){
					if((_c=fgetc(grammar))==EOF){	
						break;
					}
						abstract_interpreter(non_terminals,_c);		
						left_hand_sides[_i] = (char)_c;
						_i++;

					_c=fgetc(grammar);
						if((char)_c!=':'){
							printf("ERROR FOUND: ':' EXPECTED\n");
							exit(0);
						}
					_c=fgetc(grammar);
						if((char)_c!=':'){
							printf("ERROR FOUND: ':' EXPECTED %c\n",(char)_c);
							exit(0);
						}
					_c=fgetc(grammar);
						if((char)_c!='='){
							printf("ERROR FOUND: '=' EXPECTED\n");
							exit(0);
						}
					
				}
			}
			int _j;
			
	}

fclose(grammar);

/*check right sides of grammar for any undefined nonterminal if any */
	
grammar = fopen("grammar.txt","r");
	while((_c=fgetc(grammar))!=EOF){
		if((char)_c=='='){
			while((_c=fgetc(grammar))!='\n'){
				int i,found_non_terminal=0;
				for(i=0;non_terminals[i]!='\0';i++){
					if((char)_c == non_terminals[i]){
						abstract_interpreter(left_hand_sides,_c);
					}
				}
				
			}
		}
	}
fclose(grammar);
		
grammar = fopen("grammar.txt","r");
	
	int i; // loop variable
	int count_char_each_line=0; /* counts characters in each line of grammar excluding white spaces*/
	int count_for_seek = 0; /* counts characters in each line of grammar including while spaces */
	for(i=0;i<count_lines;i++){
		count_char_each_line=0; 
		count_for_seek = 0;
			if(i>=1){
				_c=fgetc(grammar);
			}
		while((_c=fgetc(grammar))!='\n'){
			count_for_seek+=1;
			if(!isspace(_c)){
				count_char_each_line+=1;
			}		
		}
		
		char *production = (char*) (calloc(count_char_each_line,sizeof(char))); // array to store each production
		if(production == '\0'){
			exit(0);
		}
		fseek(grammar,-(count_for_seek+1),SEEK_CUR);
		int j=0; // loop variable
		for(j=0;j<count_char_each_line;j++){			
			_c=fgetc(grammar);
			production[j] = (char)_c;
				
		}
		        
		
		for(j=0;j<count_char_each_line;j++){
			if(production[j]=='='){
					j++;
					if(production[j]=='\0'){
						exit(0);
					}
					j--;
				}	
		}
		
			int k;//loop variable
			int s_is_n=0; // symbol on right is non terminal
			int s_is_t=0; // symbol on right is terminal
			int s_is_e=0; // symbol on right is 'e'
			int s_is_d=0; // symbol on right is '|'
		for(j=4;production[j]!='\0';j++){
			
			s_is_n=0;
			s_is_t=0;
			
			for(k=0;k<count_lines;k++){
				if(production[j]==left_hand_sides[k]){
					s_is_n=1;
				}
			}
			for(k=0;terminals[k]!='\0';k++){
				if(production[j]==terminals[k]){
					if(production[j]=='e'){
						s_is_e=1;
					}
					else{
						s_is_t=1;
					}
				}
			}
			if(!s_is_t && !s_is_n && !s_is_e){
				char l_type= 'f';
				int pass =2;
				char x='z';
				abstract_interpreter_instance(l_type,pass,x);
			}
			else{
				
				if(production[j]=='|'){
					s_is_d=1;
					j++;
					if(production[j]=='\0'){
						printf("ERROR FOUND: TERMINAL OR NON TERMINAL OR EMPTY STRING 'e' IS EXPECTED AFTER '|'\n");
						exit(0);
					}
					j--;
				}
				
				else{
					production[j] = 'S';
				}			
			}

					
		}
		production[j]='\0';
	
	char *temp;		
			if(count_char_each_line>=6){
				
				if(s_is_d==1){
					
					temp = (char*)calloc(6,sizeof(char));
					temp="RS|ARS";
					
				}
				else{
					
					temp = (char*)calloc(3,sizeof(char));
					temp = "SRS";
				}
			}
			else{
				temp = (char*)calloc(1,sizeof(char));
				temp = "S";
			}


	char pass_lhs = production[0];
	char undefined = 'u'; // pass these just to match number of arguments of function
	abstract_interpreter_instance(undefined,s_is_e,pass_lhs);
		
	free(production);
	
		
	}
			
char g='G';
abstract_interpreter_parsed(g);		
return 0;
}



