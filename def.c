#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "def.h"
#define LENGTH   64
#define LENGTH_TABLE 4
VARIABLE_ENTRY variable_list[LENGTH];
SYM_TABLE sym_table[LENGTH_TABLE];
int first_empty=0;



int get_next_empty_element(void){
	if(first_empty<LENGTH){
		return first_empty++;
	}else{
		printf("Compiler error! variable_list overflow!");
		exit(EXIT_FAILURE);
	}
}

int insert_variable(char *name, char *param1,char *param2,char *value1,char *value2){
	int index=get_next_empty_element();
	variable_list[index].name=name;
	variable_list[index].param1=param1;
	variable_list[index].param2=param2;
	variable_list[index].value1=value1;
	variable_list[index].value2=value2;
	
	return index;
	
}
//nije samo da moramo name proveriti vec i param1 i param2 jer se oni moraju javiti u istoj kombinciji
int lookup_variable(char *name){
	
	int i;
	for(i=0;i<first_empty;i++){
		if(strcmp(variable_list[i].name,name)==0){
			return i;
		}
	}

		return -1;
}

int check_variable(char *name, char *param1, char *param2){
		int i;
	for(i=0;i<first_empty;i++){
		if(strcmp(variable_list[i].name,name)==0 && strcmp(variable_list[i].param1,param1)==0 && strcmp(variable_list[i].param2,param2)==0){
			return i;
		}
	}

		return -1;
}


void print_variable_list(void){
	int i;
	for(i=0;i<first_empty;i++){
		printf("\n %2d  %s %s %s %s %s",i,variable_list[i].name, variable_list[i].param1, variable_list[i].param2, variable_list[i].value1,variable_list[i].value2);
		
	}
	
}



void init_table(){
	
	sym_table[0].simbol="*";
	sym_table[0].znacenje="odlicno";
	sym_table[0].vrednost=3;
	
	sym_table[1].simbol="+";
	sym_table[1].znacenje="dobro";
	sym_table[1].vrednost=2;
	
	sym_table[2].simbol="/";
	sym_table[2].znacenje="dovoljno";
	sym_table[2].vrednost=1;
	
	sym_table[3].simbol="-";
	sym_table[3].znacenje="nedovoljno";
	sym_table[3].vrednost=0;
	
}

void print_table(){
	int i;
	for(i=0;i<LENGTH_TABLE;i++){
		printf("\nTABELA: %s , %d \n",sym_table[i].simbol,i);
	}
	
}
int sym_lookup(char *arop){
	int i;
	for(i=0;i<LENGTH_TABLE;i++){
		if(strcmp(arop,sym_table[i].simbol)==0){
			return sym_table[i].vrednost;
		}
	}
	
	return -1;
	
}
void print_res(char *name,char *string,char *arop1,char *arop2){
	int index = lookup_variable(name);
	//printf("%d ", sym_lookup(arop1) );
	int res = sym_lookup(arop1)*atoi(variable_list[index].value1) + sym_lookup(arop2)*atoi(variable_list[index].value2);
	
	printf(" %s : %d \n",string,res);
	
	
}







