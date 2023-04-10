/* iaed-23 - ist196191 - project2 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"functions.h"

#define BUFFER_SIZE 256
#define MEM_ERR_MSG printf("No memory.\n");

int main(){
	int /*i,*/ car_size = 0, par_size = 0, ret = 0;
	char mode, *temp = NULL, *s = NULL;
	car **carreiras_all = NULL;
	par **paragens_all = NULL;
	/*lis_par *temp_p = NULL;
	lis_car *temp_c = NULL;*/

	s = malloc(sizeof(char)*(MAX_INPUT+1));
	if(s==NULL){
		MEM_ERR_MSG
		return 0;
	}

	if(Init_Glob_Arr(&carreiras_all,&paragens_all)){
		free(s);
		MEM_ERR_MSG;
		return 0;
	}

	/*carreiras_all = malloc(sizeof(car*));
	if(carreiras_all == NULL){
		free(s);
		MEM_ERR_MSG
		return 0;
	}
	carreiras_all[0] = NULL;
	
	paragens_all = malloc(sizeof(par*));
	if(paragens_all == NULL){
		free(s);
		free(carreiras_all);
		MEM_ERR_MSG
		return 0;
	}
	paragens_all[0] = NULL;*/
	
	s = fgets(s,MAX_INPUT,stdin);
	
	while(s != NULL){
		if(sscanf(s,"%c",&mode)!=1)
			exit(-1);
		switch (mode){
			case 'a':
				Free_All(carreiras_all,&car_size,paragens_all,&par_size);
				carreiras_all = NULL;
				paragens_all = NULL;
				ret = Init_Glob_Arr(&carreiras_all,&paragens_all);
				par_size = 0;
				car_size = 0;
				break;
			case 'q':
				Free_All(carreiras_all,&car_size,paragens_all,&par_size);
				free(s);
				s=NULL;
				break;
			
			case 'c':
				ret = Modo_C(s,&carreiras_all, &car_size);
				break;
			
			case 'p':
				ret = Modo_P(s,&paragens_all, &par_size);
				break;

			case 'l':
				ret = Modo_L(s,carreiras_all, car_size, paragens_all, par_size);
				break;
			
			case 'i':
				Modo_I(paragens_all, par_size);
				break;
			
			case 'r':
				ret = Modo_R(s,carreiras_all,&car_size);
				break;
			
			case 'e':
				ret = Modo_E(s,paragens_all,&par_size);
				break;

			default:
				break;
		}
		if(ret){
			MEM_ERR_MSG
			break;
		}
		if(s != NULL)
			s = fgets(s,MAX_INPUT,stdin);
	}
	/*for(i=0;i<car_size;i++){
		if(carreiras_all[i]->ori!=NULL)
			for(temp_p = carreiras_all[i]->ori->next; temp_p != NULL;
			temp_p = temp_p->next)
				free(temp_p->prev);
		if(carreiras_all[i]->dest!=NULL)
			free(carreiras_all[i]->dest);
		free(carreiras_all[i]->nome);
		free(carreiras_all[i]);
	}
	for(i=0;i<par_size;i++){
		if(paragens_all[i]->cars != NULL){
			for(temp_c = paragens_all[i]->cars->next;
			temp_c != NULL;
			temp_c = temp_c->next){
				free(paragens_all[i]->cars);
				paragens_all[i]->cars = temp_c;
			}
			free(paragens_all[i]->cars);
		}
		free(paragens_all[i]->nome);
		free(paragens_all[i]);
	}*/
	free(carreiras_all);
	free(paragens_all);
	free(temp);
	free(s);
	return 0;
}
