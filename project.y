%{
  #include <stdio.h>
  #include "def.c"
	#include <errno.h>

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);
  
  extern int yylineno;
  int word_counter=0;
  int count=0;
  int error_count = 0;

%}


%union {
  int i;
  char *s;
}

%token <s> _PROPERTY
%token <s> _ID
%token <s> _TEXT
%token <s> _NUMBER
%token _LPAREN
%token _RPAREN
%token _COLON
%token _DOT
%token _ASSIGN
%token _SEMICOLON
%token <s> _AROP
%token _RELOP
%token _COMMA

%type <s> param

%%


program
  : 
	| variable_list _DOT
	| variable_list _DOT statement_list
  ;


variable_list
  : variable
  | variable_list variable
  ;

variable
	:  _LPAREN _PROPERTY _COLON _NUMBER _COMMA _PROPERTY _COLON _NUMBER _RPAREN _RELOP _ID
		{
			errno=1;
			int idx = lookup_variable($11);
			if(idx  == -1){
			
				idx = insert_variable($11,$2,$6,$4,$8);
			}else{
				perror("Variable allready defined\n");
				exit(EXIT_FAILURE);
			}
		}
	;



statement_list
	: statement
	| statement_list statement
	;

statement
	: _ID _COLON _AROP param _COMMA _AROP param _ASSIGN _ID _SEMICOLON
		{
			printf("ovo je _text %s", $9);
			int idx = check_variable($1,$4,$7);
			
			if(idx == -1){
				errno=1;
				perror("Variable not defined");
				exit(EXIT_FAILURE);
			}else{
				print_res($1,$9,$3,$6);
				
			}
						
		}
	;

param
	: _PROPERTY
	{
		$$=$1;
	}
	;

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s\n", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  //warning_count++;
}

int main() {
	init_table();
	print_table();
	printf("Postignut rezultat: \n");
	yyparse();

	
  	return yyparse();
}
