#ifndef DEF_H
#define DEF_H

// Element tabele simbola
typedef struct entry {
	char * name;          // ime variable
	char * param1;          // parametar1
	char * param2;          // parametar2
	char * value1;
	char * value2;
} VARIABLE_ENTRY;

typedef struct sym_table {
	char * simbol;          //simbol
	char * znacenje;          // znacenje
	int vrednost;          // vrednost
	
} SYM_TABLE;

//Ubacuje novu variablu 
//i vraca index ubacenog elementa u tabelu
// ili -1 u slucaju da nema slobodnog elementa
int insert_variable(char *name, char *param1,char *param2,char *value1,char *value2);
void print_res(char *name, char *string,char *arop1,char *arop2);
void init_table();
void print_table();
//Vraca index pronadjenog simblola ili vraca -1
int lookup_variable(char *name);
void print_variable_list(void);
/*
//set i get metode za polja strukture
void set_name(int index,char *name);
char* get_name(int index);
void set_param1(int index,char *param1);
char* get_param1(int index);
void set_param2(int index, char *param2);
char* get_param2(int index);

//ispisuje sve elemente
void print_symtab(void);

//Inicijalizacija
void init_varable(void);

*/
#endif