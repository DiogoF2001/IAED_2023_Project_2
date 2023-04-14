#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"functions.h"

/*
In success returns a pointer to a new array for the stops
In failure returns NULL
*/

car** Res_Car(car** c, int new_size){
	car **new = NULL;
	if(c == NULL || new_size == 0)
		return NULL;
	new = realloc(c, sizeof(car*)*new_size);
	
	/*If the realloc() returns NULL, that is what
	 we want the function to return*/
	return new;
}

par** Res_Par(par** p, int new_size){
	par **new = NULL;
	if(p == NULL || new_size == 0)
		return NULL;
	if(new_size == 1)
		return p;
	new = realloc(p, sizeof(par*)*new_size);
	
	/*If the realloc() returns NULL, that is what
	 we want the function to return*/
	return new;
}

car* Init_Car(){
	car *c = NULL;
	c = malloc(sizeof(car));
	if(c==NULL){
		return NULL;
	}
	c->nome = NULL;
	c->dest = NULL;
	c->ori = NULL;
	c->num_par = 0;
	c->cost = 0;
	c->dur = 0;
	return c;
}

par* Init_Par(){
	par* p = NULL;
	p = malloc(sizeof(par));
	if(p==NULL){
		return NULL;
	}
	p->nome = NULL;
	p->lat = 0;
	p->lon = 0;
	p->num_car = 0;
	p->cars = NULL;
	return p;
}

lis_car* Init_lis_car_cell(){
	lis_car *c = NULL;
	c = malloc(sizeof(lis_car));
	if(c==NULL){
		return NULL;
	}
	c->next = NULL;
	c->this = NULL;
	
	return c;
}

lis_car* Find_Car_in_Lis (car* c, lis_car* l){
	lis_car *temp = l;
	while(temp!=NULL){
		if(temp->this == c)
			break;
		else
			temp = temp->next;
	}
	return temp;
}

lis_par* Find_Par_in_Lis(par* p, lis_par* l){
	lis_par *temp = l;
	while(temp!=NULL){
		if(temp->this == p)
			break;
		else{
			temp = temp->next;
			if(temp == l){
				temp = NULL;
				break;
			}
		}
	}
	return temp;
}

int Add_to_Car_lis(car* c, par* p){
	lis_car *temp = p->cars, *new = NULL, *aux = NULL;

	new = Init_lis_car_cell();

	if(new == NULL)
		return 1;

	new->this = c;
	if(temp == NULL){
		p->cars = new;
	}
	else {
		aux = NULL;
		while(temp !=NULL){
			if(strcmp(c->nome,temp->this->nome)>=0){
				aux = temp;
				temp = temp->next;
				continue;
			}
			break;
		}
		if(aux == NULL){
			new->next = p->cars;
			p->cars = new;
		}
		else{
			new->next = aux->next;
			aux->next = new;
		}
		
	}
	return 0;
}

lis_par* Init_lis_par_cell(){
	lis_par *c = NULL;

	c = malloc(sizeof(lis_par));
	if(c==NULL){
		return NULL;
	}
	c->cost = 0;
	c->dur = 0;
	c->next = NULL;
	c->this = NULL;
	c->prev = NULL;
	
	return c;
}

int Check_Lig(car* c, par* ori, par *dest){
	if(c->ori->this == dest || c->dest->this == ori)
		return 1;
	else
		return 0;
}


char** Get_Name(int max, char* str){
	int i = 0, size = 0;
	char *temp = NULL, **ret = NULL;

	ret = malloc(sizeof(char*)*2);
	if(ret==NULL)
		return NULL;

	ret[0] = malloc(sizeof(char)*(max+1));
	if(ret[0]==NULL){
		free(ret);
		return NULL;
	}
	ret[0][0]='\0';

	temp = str+1;
	for(i=0;temp[i] == ' '; i++);

	if(temp[i] == '"'){
		i++;
		while(temp[i] != '"' && size<max){
			ret[0][size]=temp[i];
			i++;
			size++;
		}
		ret[0][size] = '\0';
		ret[1]=temp+i+1;
	}
	else{
		sscanf(temp,"%s", ret[0]);
		ret[1]=temp+strlen(ret[0])+1;
	}
	return ret;
}

void Print_Car(car** c_l, car* c, int inv, int size){
	int i;
	lis_par* next = NULL;
	
	/*If it's a single bus line*/
	if(c != NULL && c_l == NULL){
		/*REVIEW*******************************************************/
		if(c->ori != NULL && c->dest != NULL){
			switch (inv){
				/*If it IS supposed to invert the order*/
				case 1:
					next = c->dest;
					while(next!=c->ori){
						printf("%s, ", next->this->nome);
						next = next->prev;
					}
					printf("%s", c->ori->this->nome);
					break;
				/*If it IS NOT supposed to invert the order*/
				case 0:
					next = c->ori;
					while(next!=c->dest){
						printf("%s, ", next->this->nome);
						next = next->next;
					}
					printf("%s", c->dest->this->nome);
					break;
				default:
					break;
			}
			printf("\n");
		}
	}
	/*If it's all the bus lines*/
	if(c == NULL && c_l != NULL){
		for(i=0; i<size; i++){
			printf("%s ", c_l[i]->nome);
			if(c_l[i]->ori != NULL && c_l[i]->dest != NULL){
				printf("%s ", c_l[i]->ori->this->nome);
				printf("%s ", c_l[i]->dest->this->nome);
			}
			printf("%d %.2f %.2f\n",c_l[i]->num_par, c_l[i]->cost, c_l[i]->dur);
		}
	}
}

void Print_Par(par** p_l, par* p, int size){
	int i;
	
	/*If it's a single stop*/
	if(p != NULL && p_l == NULL){
		printf("%16.12f %16.12f\n", p->lat, p->lon);
	}
	/*If it's all the stops*/
	if(p == NULL && p_l != NULL){
		for(i=0; i<size; i++){
			printf("%s: %16.12f ", p_l[i]->nome, p_l[i]->lat);
			printf("%16.12f %d\n", p_l[i]->lon, p_l[i]->num_car);
		}
	}
}


/* Tries to find the bus line with the name "s":
if it DOES FIND, returns the index to that bus line in the array
if it DOESN'T, returns -1 */

int Find_Car(car** c,char* s, int size){
	int i;
	for(i=0;i<size;i++){
		if(c[i]!=NULL){
			if(strcmp(c[i]->nome, s) == 0)
				return i;
		}
	}
	return(-1);
}

/* Tries to find the stop with the name "s":
if it DOES FIND, returns the index to that stop in the array
if it DOESN'T, returns -1 */

int Find_Par(par** p,char* s, int size){
	int i;
	for(i=0;i<size;i++){
		if(p[i]!=NULL){
			if(strcmp(p[i]->nome, s) == 0)
				return i;
		}
	}
	return(-1);
}

int Is_Text(char c){
	if(c >= '0' && c <= '9')
		return 1;
	if(c >= 'A' && c <= 'Z')
		return 1;
	if(c >= 'a' && c <= 'z')
		return 1;
	if(c == '.' || c == ',')
		return 1;
	return 0;
}

int Count_Args(char* str){
	int i = 0, args = 0, in = 0, special = 0;
	while(i < (int) strlen(str)){
		if(!special && str[i] == '"'){
			special = 1;
			i++;
			continue;
		}
		if(special){
			if(str[i] == '"'){
				special = 0;
				args++;
				i++;
				continue;
			}
			else{
				i++;
				continue;
			}
		}
		if(Is_Text(str[i])){
			i++;
			if(in == 0){
				args++;
				in = 1;
			}
			continue;
		}
		else{
			in = 0;
			i++;
		}
	}
	return args;
}


void Free_Car(car* c){
	lis_par* temp_p = NULL;
	if(c->ori!=NULL)
		for(temp_p=c->ori->next;temp_p!=NULL;temp_p=temp_p->next)
			free(temp_p->prev);
	if(c->dest!=NULL)
		free(c->dest);
	free(c->nome);
	free(c);
}

void Free_Par(par* p){
	lis_car *temp_c = NULL;
	if(p->cars != NULL){
		for(temp_c=p->cars->next;temp_c!=NULL;temp_c=temp_c->next){
			free(p->cars);
			p->cars = temp_c;
		}
		free(p->cars);
	}
	free(p->nome);
	free(p);
}

void Free_All(car** c, int c_size, par** p, int p_size){
	int i=0;

	if(c != NULL){
		for(i=0;i<c_size;i++){
			Free_Car(c[i]);
		}
	}

	if(p != NULL){
		for(i=0;i<p_size;i++){
			Free_Par(p[i]);
		}
	}

}

int Init_Glob_Arr(car ***c, par ***p){
	car **c_temp = NULL;
	par **p_temp = NULL;

	if(*c != NULL || *p != NULL)
		return 1;

	c_temp = malloc(sizeof(car*));
	if(c_temp == NULL)
		return 1;
	c_temp[0] = NULL;
	
	p_temp = malloc(sizeof(par*));
	if(p_temp == NULL){
		free(c_temp);
		return 1;
	}
	p_temp[0] = NULL;

	*c = c_temp;
	*p = p_temp;
	return 0;
}

void Free_Car_in_Par(car *c, par *p){
	lis_car *temp, *aux;

	for(temp = p->cars, aux = NULL;
	temp != NULL && temp->this != c; 
	aux = temp, temp = temp->next);

	if(temp == NULL)
		return;
	else if(aux == NULL){
		aux = temp->next;
		free(temp);
		p->cars = aux;
	}
	else{
		aux->next = temp->next;
		free(temp);
	}
	p->num_car--;
}