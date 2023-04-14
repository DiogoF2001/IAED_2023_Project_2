#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_INPUT 65535
#define BUFFER_SIZE 256
#define MEM_ERR_MSG printf("No memory.\n");
#define SORT_ERR_MSG printf("incorrect sort option.\n");
#define NO_STOP_ERR_MSG "%s: no such stop.\n"
#define DUP_STOP_ERR_MSG "%s: stop already exists.\n"
#define NO_LINE_ERR_MSG "%s: no such line.\n"
#define DUP_LINE_ERR_MSG "%s: line already exists.\n"
#define VAL_ERR_MSG printf("negative cost or duration.\n");
#define LINK_ERR_MSG printf("link cannot be associated with bus line.\n");

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
*	This function allocates the 'global' variables of the program
*/
int Init_Glob_Arr(car***, par***);

/*
*	These functions reallocate and initialise structs
*/
car** Res_Car(car**,int);
par** Res_Par(par**,int);

/*
*	These functions allocate and initialise new structs or elements of a list
*/
car* Init_Car();
par* Init_Par();
lis_par* Init_lis_par_cell();
lis_car* Init_lis_car_cell();

/*
*	These functions free structs.
*/
void Free_Car(car*);
void Free_Par(par*);

/*
*	This function free's an element of a list of lines inside a stop.
*/
void Free_Car_in_Par(car*,par*);

/*
*	This function free's every stop, every line an every link.
*/
void Free_All(car**,int,par**,int);

/*
* 	Funtion: Find_Car
* 
*	Description: Finds the line in the array of lines.
* 
*	Arguments: 
*		- car**: a pointer to the first element of our 'global' array of pointers
*			to every active line ('carreira') in the current state of the program;
*		- char*: a string with the name of the line;
*		- int: the value of the size of our 'global' array of lines ('carreiras').
*
*	Return Value:
*		- -1, in case it DOSEN'T exist in the array;
*		- The position of the line in the array.
*/
int Find_Car(car**,char*,int);

/*
* 	Funtion: Find_Par
* 
*	Description: Finds the stop in the array of stops.
* 
*	Arguments: 
*		- par**: a pointer to the first element of our 'global' array of pointers
*			to every active stop ('paragem') in the current state of the program;
*		- char*: a string with the name of the stop;
*		- int: the value of the size of our 'global' array of stops ('paragens').
*
*	Return Value:
*		- -1, in case it DOSEN'T exist in the array;
*		- The position of the stop in the array.
*/
int Find_Par(par**,char*,int);

/*
* 	Funtion: Find_Car_in_Lis
* 
*	Description: Finds the line in the list of lines
* 
*	Arguments: 
*		- car*: a pointer to a line;
*		- lis_car*: a pointer to the header of a list of pointers to lines;
*
*	Return Value:
*		- NULL, in case it DOSEN'T exist in the list;
*		- The address of the element in the list if it DOES.
*/
lis_car* Find_Car_in_Lis(car*,lis_car*);

/*
* 	Funtion: Find_Par_in_Lis
* 
*	Description: Finds the stop in the list of stops
* 
*	Arguments: 
*		- par*: a pointer to a stop;
*		- lis_par*: a pointer to the header of a list of pointers to stops;
*
*	Return Value:
*		- NULL, in case it DOSEN'T exist in the list;
*		- The address of the element in the list if it DOES.
*/
lis_par* Find_Par_in_Lis(par*,lis_par*);

/*
* 	Funtion: Add_to_Car_lis
* 
*	Description: Adds a new line ('carreira') to the stop's ('paragem') list
*		of lines in order.
* 
*	Arguments: 
*		- car*: a pointer to a line;
*		- par*: a pointer to a stop;
*
*	Return Value:
*		- 0, in case of success;
*		- 1, if any error occurs with memory allocation.
*/
int Add_to_Car_lis(car*,par*);

/*
These functions deal with the output from Modes C and P
*/
void Print_Car(car**,car*,int,int);
void Print_Par(par**, par*,int);

/*
* 	Funtion: Check_Lig
* 
*	Description: Checks if a link is valid in this line ('carreira').
* 
*	Arguments: 
*		- car*: the max size the name can have;
*		- par*: a pointer to the stop of origin;
*		- par*: a pointer to the stop of destination.
*
*	Return Value:
*		- 0, if it ISN'T valid;
*		- 1, if it IS valid.
*/
int Check_Lig(car*,par*,par*);


/*
* 	Funtion: Get_Name
* 
*	Description: Retrieves a name from a string:
*		- If it is delimited by '"', the name retrieved is everythin inside;
*		- If it isn't, the name retrieved is a string delimited by whit spaces;
* 
*	Arguments: 
*		- int: the max size the name can have;
*		- char*: a string.
*
*	Return Value:
*		- An array of size 2 with 2 pointers to char:
*			- In the first position, a pointer to a string of size max with
*				the name read;
*			- In the second position, a pointer to the position in the original
*				string immediatly after the name read.
*/
char** Get_Name(int,char*);

/*
* 	Funtion: Count_Args
* 
*	Description: Counts how many arguments separated by either spaces or tabs
*		exist in a string.
* 
*	Arguments: 
*		- char*: a string.
*
*	Return Value:
*		- An integer, the number of arguments found.
*/
int Count_Args(char*);

/*
* 	Funtion: Is_Text
* 
*	Description: Checks if a character is a letter, a number or a '.'
* 
*	Arguments: 
*		- char: a character.
*
*	Return Value:
*		- 0, if it ISN'T;
*		- 1, if it IS.
*/
int Is_Text(char);

/*
These functions receive the input read and process the various commands
*/

/*
* 	Funtion: Modo_C
* 
*	Description: Handles the execution of the program if the command 'c' is
*		called in the following order:
*			- Checks if the line passed in the input is valid;
*			- Depending on the number of arguments(besides the mode):
*				- if it's 0: it prints every line active in the current state
*					of the program;
*				- if it's 1: it checks if that line already exists, if it DOES,
*					prints that line content, if it DOSEN'T, creates it;
*				- If it's 2: the same as if it's 1, except that if the stop
*					exists and the second argument is an abreviation of the word
*					'inverso' with at least 3 letters, it prints that line with
*					it's stops in upside down order;
*			- Finally, it updates the pointer to the first element of the 
*				'global' array of lines, because if a new line was created it
*				might now be different.
* 
*	Arguments: 
*		- char*: a string that contains the whole line of input;
*		- car***: a pointer to the address of the first element of our 'global'
*			array of pointers to every active line ('carreira') in the current
*			state of the program;
*		- int*: a pointer to the value of the size of our 'global' array of
*			lines ('carreiras').
*
*	Return Value:
*		- 0, in case of success;
*		- 1, if any error occurs with memory allocation.
*/
int Modo_C(char*,car***,int*);

/*
* 	Funtion: Modo_P
* 
*	Description: Handles the execution of the program if the command 'p' is
*		called in the following order:
*			- Checks if the stop passed in the input is valid;
*			- Depending on the number of arguments(besides the mode):
*				- if it's 0: it prints every stop active in the current state
*					of the program;
*				- if it's 1: it checks if that stop already exists, if it DOES,
*					prints that stop content, if it DOSEN'T, prints an error
*					message.
*				- If it's 4: the same as if it's 1, except that if the stop
*					doesn't exist and the remaining arguments are numbers it
*					creates it.
*			- Finally, it updates the pointer to the first element of the 
*				'global' array of stops, because if a new stop was created it
*				might now be different.
* 
*	Arguments: 
*		- char*: a string that contains the whole line of input;
*		- par***: a pointer to the address of the first element of our 'global'
*			array of pointers to every active stop ('paragem') in the current
*			state of the program;
*		- int*: a pointer to the value of the size of our 'global' array of
*			stops ('paragens').
*
*	Return Value:
*		- 0, in case of success;
*		- 1, if any error occurs with memory allocation.
*/
int Modo_P(char*,par***,int*);

/*
* 	Funtion: Modo_L
* 
*	Description: Handles the execution of the program if the command 'l' is
*		called in the following order:
*			- Checks if the line and two stops passed in the input are valid;
*			- Checks if the cost and duration of the link is valid;
*			- If the line is empty, it adds the 2 stops as the first and last,
*				if it isn't it checks if the link is valid:
*				- If it is, add's the new stop to the line and add's the line to the
*					stop if it wasn't already added;
*				- If it isn't, prints an error message;
* 
*	Arguments: 
*		- char*: a string that contains the whole line of input;
*		- car**: a pointer to the first element of our 'global' array of pointers
*			to every active line ('carreira') in the current state of the program;
*		- int: the value of the size of our 'global' array of lines ('carreiras').
*		- par**: a pointer to the first element of our 'global' array of pointers
*			to every active stop ('paragem') in the current state of the program;
*		- int: the value of the size of our 'global' array of stops ('paragens').
*
*	Return Value:
*		- 0, in case of success;
*		- 1, if any error occurs with memory allocation.
*/
int Modo_L(char*,car**,int,par**,int);

/*
* 	Funtion: Modo_I
* 
*	Description: Handles the execution of the program if the command 'i' is
*		called in the following order:
*			- Prints every stop that belongs to more than 1 line and if so
*				the lines it belongs to.
* 
*	Arguments: 
*		- par**: a pointer to the first element of our 'global' array of pointers
*			to every active stop ('paragem') in the current state of the program;
*		- int: the value of the size of our 'global' array of stops ('paragens').
*
*	Return Value:
*		- No return value (void).
*/
void Modo_I(par**,int);

/*
* 	Funtion: Modo_R
* 
*	Description: Handles the execution of the program if the command 'r' is
*		called in the following order:
*			- Checks if the line passed in the input is valid;
*			- Removes the line from every stop in it, adjusting their lists
*				of lines accordingly;
*			- Removes the line from our 'global' array of lines by freeing
*				it and shifting every line to the right of it 1 position to
*				the left and then dcreasing the array size.
* 
*	Arguments: 
*		- char*: a string that contains the whole line of input;
*		- car**: a pointer to the first element of our 'global' array of pointers
*			to every active line ('carreira') in the current state of the program;
*		- int*: a pointer to the value of the size of our 'global' array of
*			lines ('carreiras').
*
*	Return Value:
*		- 0, in case of success;
*		- 1, if any error occurs with memory allocation.
*/
int Modo_R(char*,car**,int*);

/*
* 	Funtion: Modo_E
* 
*	Description: Handles the execution of the program if the command 'e' is
*		called in the following order:
*			- Checks if the stop passed in the input is valid;
*			- Removes the stop from every line it belongs to, adjusting
*				their links accordingly;
*			- Removes the stop from our 'global' array of stops by freeing
*				it and shifting every stop to the right of it 1 position to
*				the left and then dcreasing the array size.
* 
*	Arguments: 
*		- char*: a string that contains the whole line of input;
*		- par**: a pointer to the first element of our 'global' array of pointers
*			to every active stop ('paragem') in the current state of the program;
*		- int*: a pointer to the value of the size of our 'global' array of
*			stops ('paragens').
*
*	Return Value:
*		- 0, in case of success;
*		- 1, if any error occurs with memory allocation.
*/
int Modo_E(char*,par**,int*);

#endif