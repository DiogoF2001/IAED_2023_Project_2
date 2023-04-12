#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_INPUT 65535

typedef struct Info_Carreira
{
	char *nome;
	struct Lista_Paragens *ori, *dest;
	int num_par;
	double cost, dur;
} car;

typedef struct Info_Paragem
{
	char *nome;
	double lat, lon;
	int num_car;
	struct Lista_Carreiras *cars;
} par;

typedef struct Lista_Paragens
{
	par *this;
	double cost, dur;
	struct Lista_Paragens *prev, *next;
} lis_par;

typedef struct Lista_Carreiras
{
	car *this;
	struct Lista_Carreiras *next;
} lis_car;

/*
These functions allocate and initialise new structs or elements of a list
*/

int Init_Glob_Arr(car***, par***);

car** Res_Car(car**,int);
par** Res_Par(par**,int);

car* Init_Car();
par* Init_Par();

void Free_Car(car*);
void Free_Par(par*);

void Free_Car_in_Par(car*,par*);

void Free_All(car**,int,par**,int);

lis_par* Init_lis_par_cell();
lis_car* Init_lis_car_cell();

/*
These functions return the indice of the element they're looking for
or the indice for the first open slot
*/

int Find_Car(car**,char*,int);
int Find_Par(par**,char*,int);

lis_car* Find_Car_in_Lis(car*,lis_car*);
lis_par* Find_Par_in_Lis(par*,lis_par*);

/*
Adds a new line to the list of lines that the stop belongs to
*/

int Add_to_Car_lis(car*,par*);

/*
These functions deal with the output from Modes C and P
*/

void Print_Car(car**,car*,int,int);
void Print_Par(par**, par*,int);

/*
Returns 1 if the link is valid, 0 if not
*/

int Check_Lig(car*,par*,par*);


/*
Gets the name of something even if it's delimited by "" 
*/
char** Get_Name(int,char*);

/*
Returns the number of arguments in the input read
*/
int Count_Args(char*);

/*
Returns 1 if its a digit, a letter, or a dot
*/
int Is_Text(char);

/*
These functions receive the input read and process the various commands
*/
int Modo_C(char*,car***,int*);
int Modo_P(char*,par***,int*);
int Modo_L(char*,car**,int,par**,int);
void Modo_I(par**,int);

int Modo_R(char*,car**,int*);
int Modo_E(char*,par**,int*);

#endif